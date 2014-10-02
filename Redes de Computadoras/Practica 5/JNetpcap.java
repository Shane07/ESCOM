import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.io.*;

import org.jnetpcap.*;
import org.jnetpcap.PcapIf;
import org.jnetpcap.packet.*;
import org.jnetpcap.packet.PcapPacketHandler;
import org.jnetpcap.PcapBpfProgram;
import org.jnetpcap.protocol.lan.*;
import org.jnetpcap.protocol.tcpip.*;
import org.jnetpcap.protocol.network.*;
import org.jnetpcap.nio.*;
import org.jnetpcap.packet.*;
import org.jnetpcap.protocol.network.*;
import org.jnetpcap.protocol.lan.IEEE802dot2;
import org.jnetpcap.protocol.lan.IEEE802dot3;

import com.itextpdf.text.*;
import com.itextpdf.text.pdf.*;

// Compilar y ejecutar como root

public class JNetpcap
{
	static Document documento;

	public JNetpcap(int cantidadTramas)
	{
		corePcap(cantidadTramas, null);
	}
	public JNetpcap(String archivo)
	{
		corePcap(666, archivo);
	}
    private static String asString(final byte[] mac)
    {
        final StringBuilder buf = new StringBuilder();
        for (byte b : mac)
        {
            if (buf.length() != 0)
            {
                buf.append(':');
            }
            if (b >= 0 && b < 16)
            {
                buf.append('0');
            }
            
            buf.append(Integer.toHexString((b < 0) ? b + 256 : b).toUpperCase());
        }
        return buf.toString();
    }

    public void corePcap(int cant, String ficheroTramas)
    {
        List<PcapIf> alldevs = new ArrayList<PcapIf>(); // Will be filled with NICs
        StringBuilder errbuf = new StringBuilder(); // For any error msgs

        int r = Pcap.findAllDevs(alldevs, errbuf);
        
        if(r == Pcap.NOT_OK || alldevs.isEmpty())
        {
            System.err.printf("Can't read list of devices, error is %s", errbuf.toString());
            return;
        }

        System.out.println("Network devices found:");

        int i = 0;
        
        try
        {
            for(PcapIf device : alldevs) 
            {
                String description = (device.getDescription() != null) ? device.getDescription(): "No description available";
                final byte[] mac = device.getHardwareAddress();
                String dir_mac = (mac==null)?"No tiene direccion MAC":asString(mac);
                System.out.printf("#%d: %s [%s] MAC:[%s]\n", i++, device.getName(), description, dir_mac);
            }

            PcapIf device = alldevs.get(2); // We know we have atleast 1 device
            System.out.printf("\nChoosing '%s' on your behalf:\n", (device.getDescription() != null) ? device.getDescription(): device.getName());

            int snaplen = 64 * 1024;           // Capture all packets, no trucation
            int flags = Pcap.MODE_PROMISCUOUS; // capture all packets
            int timeout = cant * 1000;           // 10 seconds in millis

            Pcap pcap = null;

            if(ficheroTramas == null)
            	pcap = Pcap.openLive(device.getName(), snaplen, flags, timeout, errbuf);
            else if(ficheroTramas != null)
            	pcap = Pcap.openOffline(ficheroTramas, errbuf); //Pcap.openOffline(f.getAbsolutePath(), errbuf);

            if (pcap == null)
            {
                System.err.printf("Error while opening device for capture: " + errbuf.toString());
                return;
            }

            /********F I L T R O********/
            PcapBpfProgram filter = new PcapBpfProgram();
            String expression =""; // "port 80";
            int optimize = 0; // 1 means true, 0 means false
            int netmask = 0;
            int r2 = pcap.compile(filter, expression, optimize, netmask);
            if (r2 != Pcap.OK)
            {
                System.out.println("Filter error: " + pcap.getErr());
            }
            pcap.setFilter(filter);
             /****************/

			try
            {
            	documento = new Document();
            	PdfWriter.getInstance(documento, new FileOutputStream("reporte.pdf", true));
                documento.open();

                Paragraph titulo = new Paragraph("Reporte tramas JNetPcap", FontFactory.getFont("Impact", 16, Font.BOLD, BaseColor.BLACK));
	        	titulo.setAlignment(Element.ALIGN_CENTER);
	        	Paragraph autor = new Paragraph("Ortega Ortuño Eder - 2CM9", FontFactory.getFont("Impact", 12, Font.ITALIC, BaseColor.DARK_GRAY));
	        	autor.setAlignment(Element.ALIGN_CENTER);
	        	Anchor ma = new Anchor("www.multiaportes.com/jnetpcap", FontFactory.getFont("Impact", 9, Font.UNDERLINE, BaseColor.GRAY));
	        	ma.setReference("http://www.multiaportes.com/");
	        	Paragraph url = new Paragraph("");
	        	url.setAlignment(Element.ALIGN_CENTER);
	        	url.add(ma);
	        	documento.add(titulo);
	        	documento.add(autor);
	        	documento.add(url);
	        	documento.add(Chunk.NEWLINE);

            	PcapPacketHandler<String> jpacketHandler = new PcapPacketHandler<String>()
            	{
                	public void nextPacket(PcapPacket packet, String user)
                	{
                    	analizarTrama(packet, user, documento);
                	}
            	};

            	pcap.loop(cant, jpacketHandler, "jNetPcap rocks!");

            	documento.close();
            }
            catch(DocumentException | IOException x)
	        {
	            System.err.println(x.getMessage());
	        }

            /***************************************************************************
             * Last thing to do is close the pcap handle
             **************************************************************************/
            pcap.close();

        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }

    static void analizarTrama(PcapPacket packet, String user, Document documento)
    {
    	try
    	{
			System.out.printf("Received packet at %s caplen=%-4d len=%-4d %s\n",new Date(packet.getCaptureHeader().timestampInMillis()),
	        	packet.getCaptureHeader().caplen(),  // Length actually captured
	        	packet.getCaptureHeader().wirelen(), // Original length
	        	user                                 // User supplied object
	    	);

	        boolean ieee = false;

	        /******Desencapsulado ********/
	        String color = "";
	        for(int i=0;i<packet.size();i++)
	        {
	        	if(i < 14)
	        		color = "\u001B[31m"; // Rojo
	        	else if(i < 33)
	        		color = "\u001B[34m"; // Azul
	        	else if(i < 53)
	        		color = "\u001B[32m"; // Verde
	        	else if(i >= 53)
	        		color = "\u001B[36m"; // Cyan
	        	System.out.printf("%s%02X ", color, packet.getUByte(i));
	        	if(i % 16 == 15)
	        		System.out.println();

	            if(i == 0)
	            {
	            	if(packet.getUByte(12)*256 + packet.getUByte(13) < 1500)
	                {
	                    documento.add(new Paragraph("Trama IEEE 802.2 - LLC (Logical Link Control)", FontFactory.getFont("Impact", 12, Font.BOLD, BaseColor.BLACK)));
	                    ieee = true;
	                }
	                else
	                	documento.add(new Paragraph("Trama IEEE 802.3 - Ethernet", FontFactory.getFont("Impact", 12, Font.BOLD, BaseColor.BLACK)));

	                String tmp = "";
	                for(int z = 0; z < 6; z++)
	                	tmp = tmp + String.format("%02X%s", packet.getUByte(z), (z < 5)? ":":"");
	                Paragraph principal = new Paragraph();
	                Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.RED));
	                Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.RED));
	                campo.add("MAC destino: ");
	                informacion.add(tmp);
	                principal.add(campo);
	                principal.add(informacion);
	                principal.setIndentationLeft(0);
	                documento.add(principal);
	            }
	            else if(i == 6)
	        	{
	        		String tmp = "";
	                for(int z = 6; z < 12; z++)
	                	tmp = tmp + String.format("%02X%s", packet.getUByte(z), (z < 11)? ":":"");
	                Paragraph principal = new Paragraph();
	                Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.RED));
	                Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.RED));
	                campo.add("MAC origen: ");
	                informacion.add(tmp);
	                principal.add(campo);
	                principal.add(informacion);
	                principal.setIndentationLeft(0);
	                documento.add(principal);
	        	}
	            else if(i == 12 && ieee == true)
	            {
	                int a = packet.getUByte(i);
	                int b = packet.getUByte(i+1);
	                int d = (a<<8) | b;
	                Paragraph principal = new Paragraph();
	                Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.RED));
	                Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.RED));
	                campo.add("Tamaño: ");
	                informacion.add(d+" bytes");
	                principal.add(campo);
	                principal.add(informacion);
	                principal.setIndentationLeft(0);
	                documento.add(principal);
	                analizarLLC(documento, packet, d);
	            }
	            else if(i == 12 && ieee == false)
	            {
	                int a = packet.getUByte(i);
	                int b = packet.getUByte(i+1);
	                int d = (a<<8) | b;
	                String tipoo = (d == 2048)? "DOD IP": ((d == 2054)? "ARP": "no_se_cual_xDD");
	                Paragraph principal = new Paragraph();
	                Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.RED));
	                Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.RED));
	                campo.add("Tipo: ");
	                informacion.add(tipoo);
	                principal.add(campo);
	                principal.add(informacion);
	                principal.setIndentationLeft(0);
	                documento.add(principal);

	                if(d == 2048)
	                    analizarIP(documento, packet);
	                else if(d == 2054)
	                    analizarARP(documento, packet);
	            }
	        }
	        System.out.println("\u001B[0m"); // Resetear colores
	        documento.add(Chunk.NEWLINE);
	    	//System.out.println("\nEncabezado: \n"+ packet.toHexdump()); // Mostrar trama like Wireshark
    	}
    	catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }

    static void analizarIP(Document a, PcapPacket p)
    {
    	try
    	{
    		Paragraph principal = new Paragraph();
    		Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.BLUE));
    		Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.BLUE));
    		principal.setIndentationLeft(30);
    		
    		Paragraph subt = new Paragraph("Análisis IP (Internet Protocol)", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.MAGENTA));
    		subt.setIndentationLeft(30);
    		documento.add(subt);

            campo.add("Versión: ");
            informacion.add(Integer.toString(p.getUByte(14)>>>4)); // '>>>' para desplazar sin considerar el signo ('>>' deja intacto el bit de signo)
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Longitud: ");
            informacion.add(Integer.toString((p.getUByte(14)&15)*4)+" bytes");
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            String tServ = "";
            switch(p.getUByte(15))
            {
            	case 0:
            		tServ = "De rutina";
            		break;
            	case 1:
            		tServ = "Prioritario";
            		break;
            	case 2:
            		tServ = "Inmediato";
            		break;
            	case 3:
            		tServ = "Relámpago";
            		break;
            	case 4:
            		tServ = "Invalidación relámpago";
            		break;
            	case 5:
            		tServ = "Procesando llamada crítica y de emergencia";
            		break;
            	case 6:
            		tServ = "Control de trabajo de Internet";
            		break;
            	case 7:
            		tServ = "Control de red";
            		break;
            }

            campo.add("Tipo de servicio: ");
            informacion.add(Integer.toString(p.getUByte(15))+" ("+tServ+")");
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Longitud total: ");
            informacion.add(Integer.toString((p.getUByte(16)<<8 | p.getUByte(17))));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Identificación: ");
            informacion.add(Integer.toString(p.getUByte(18)<<8 | p.getUByte(19)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            String donotfragment = "Fragmentar", morefragments = "Último fragmento";
            int asdfg = p.getUByte(20)>>>5;
			if((asdfg & 2) == 2)
				donotfragment = "No fragmentar";
			if((asdfg & 1) == 1)
				morefragments = "Más fragmentos";

            campo.add("Flags: ");
            informacion.add(Integer.toString(p.getUByte(20)>>>5)+" (Reservado, "+donotfragment+", "+morefragments+")");
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Offset de fragmento: ");
            informacion.add(Integer.toString(((p.getUByte(20)&15)<<8)|p.getUByte(21)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("TTL (Time To Live): ");
            informacion.add(Integer.toString(p.getUByte(22)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Protocolo: ");
            informacion.add((p.getUByte(23) == 0x06)? "TCP": ((p.getUByte(23) == 0x11)? "UDP": ((p.getUByte(23) == 0x01)? "ICMP":"otro_xD")));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Comprobación de cabecera (checksum): ");
            informacion.add(String.format("%02X", p.getUByte(24)<<8 | p.getUByte(25)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Dirección IP origen: ");
            informacion.add(p.getUByte(26)+"."+p.getUByte(27)+"."+p.getUByte(28)+"."+p.getUByte(29));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Dirección IP destino: ");
            informacion.add(p.getUByte(30)+"."+p.getUByte(31)+"."+p.getUByte(32)+"."+p.getUByte(33));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

	        if(p.getUByte(23) == 0x01)
	        	analizarICMP(a, p);
	        else if(p.getUByte(23) == 0x06)
	            analizarTCP(a, p);
	        else if(p.getUByte(23) == 0x11)
	            analizarUDP(a, p);
    	}
    	catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }
    static void analizarICMP(Document a, PcapPacket p)
    {
    	try
    	{
    		Paragraph principal = new Paragraph();
    		Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.GREEN));
    		Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.GREEN));
    		principal.setIndentationLeft(60);

	        Paragraph subt = new Paragraph("Análisis ICMP (Internet Control Message Protocol)", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.MAGENTA));
    		subt.setIndentationLeft(60);
    		documento.add(subt);

	        campo.add("Tipo: ");
            informacion.add(Integer.toString(p.getUByte(34)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Código: ");
            informacion.add(Integer.toString(p.getUByte(35)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Checksum: ");
            informacion.add(String.format("%02X", p.getUByte(36)<<8 | p.getUByte(37)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Identificador: ");
            informacion.add(Integer.toString(p.getUByte(38)<<8 | p.getUByte(39)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Número de secuencia: ");
            informacion.add(Integer.toString(p.getUByte(40)<<8 | p.getUByte(41)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();
    	}
    	catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }
    static void analizarTCP(Document a, PcapPacket p)
    {
    	try
    	{
			Paragraph principal = new Paragraph();
    		Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.GREEN));
    		Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.GREEN));
    		principal.setIndentationLeft(60);

	        Paragraph subt = new Paragraph("Análisis TCP (Transport Control Protocol)", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.MAGENTA));
    		subt.setIndentationLeft(60);
    		documento.add(subt);

	        campo.add("Puerto de origen: ");
            informacion.add(Integer.toString(p.getUByte(34)<<8 | p.getUByte(35)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Puerto de destino: ");
            informacion.add(Integer.toString(p.getUByte(36)<<8 | p.getUByte(37)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Número de secuencia: ");
            informacion.add(Integer.toString(p.getUByte(38)<<24 | p.getUByte(39)<<16 | p.getUByte(40)<<8 | p.getUByte(41)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Número de ACK: ");
            informacion.add(Integer.toString(p.getUByte(42)<<24 | p.getUByte(43)<<16 | p.getUByte(44)<<8 | p.getUByte(45)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Longitud de cabecera: ");
            informacion.add(Integer.toString((p.getUByte(46)>>>4)*4)+" bytes");
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Reservado: ");
            informacion.add(String.format("%01X", p.getUByte(46)>>>4));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            String cwr = "CWR", ece = "ECE", urg = "URG", ack = "ACK", psh = "PSH", rst = "RST", syn = "SYN", fin = "FIN", flgs = "";
            int asdfg = (p.getUByte(46)&15)<<8 | p.getUByte(47);
			if((asdfg & 128) == 128)
				flgs = flgs+" "+cwr;
			if((asdfg & 64) == 64)
				flgs = flgs+" "+ece;
			if((asdfg & 32) == 32)
				flgs = flgs+" "+urg;
			if((asdfg & 16) == 16)
				flgs = flgs+" "+ack;
			if((asdfg & 8) == 8)
				flgs = flgs+" "+psh;
			if((asdfg & 4) == 4)
				flgs = flgs+" "+rst;
			if((asdfg & 2) == 2)
				flgs = flgs+" "+syn;
			if((asdfg & 1) == 1)
				flgs = flgs+" "+fin;

            campo.add("Flags: ");
            informacion.add(String.format("%03X", (p.getUByte(46)&15)<<8 | p.getUByte(47))+" ( "+flgs+" )");
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Tamaño de ventana: ");
            informacion.add(Integer.toString((p.getUByte(48)<<8)|p.getUByte(49)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Checksum: ");
            informacion.add(String.format("%02X", (p.getUByte(50)<<8)|p.getUByte(51)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Puntero urgente: ");
            informacion.add(Integer.toString((p.getUByte(52)<<8)|p.getUByte(53)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();
    	}
    	catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }
    static void analizarUDP(Document a, PcapPacket p)
    {
    	try
    	{
    		Paragraph principal = new Paragraph();
    		Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.GREEN));
    		Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.GREEN));
    		principal.setIndentationLeft(60);

	        Paragraph subt = new Paragraph("Análisis UDP (User Datagram Protocol)", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.MAGENTA));
    		subt.setIndentationLeft(60);
    		documento.add(subt);

	        campo.add("Puerto de origen: ");
            informacion.add(Integer.toString(p.getUByte(34)<<8 | p.getUByte(35)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Puerto de destino: ");
            informacion.add(Integer.toString(p.getUByte(36)<<8 | p.getUByte(37)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Longitud del mensaje: ");
            informacion.add(Integer.toString(p.getUByte(38)<<8 | p.getUByte(39)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Checksum: ");
            informacion.add(String.format("%02X", p.getUByte(40)<<8 | p.getUByte(41)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();
    	}
    	catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }
    static void analizarARP(Document a, PcapPacket p)
    {
    	try
    	{
    		Paragraph principal = new Paragraph();
    		Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.BLUE));
    		Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.BLUE));
    		principal.setIndentationLeft(30);

	        Paragraph subt = new Paragraph("Análisis ARP (Address Resolution Protocol)", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.MAGENTA));
    		subt.setIndentationLeft(30);
    		documento.add(subt);

	        campo.add("Tipo de hardware: ");
            informacion.add(Integer.toString(p.getUByte(14)<<8 | p.getUByte(15)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Tipo de protocolo: ");
            informacion.add(Integer.toString(p.getUByte(16)<<8 | p.getUByte(17)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Longitud de dirección del hardware: ");
            informacion.add(Integer.toString(p.getUByte(18)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Longitud de dirección del protocolo: ");
            informacion.add(Integer.toString(p.getUByte(19)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Opcode: ");
            informacion.add(Integer.toString(p.getUByte(20)<<8 | p.getUByte(21)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Dirección de hardware del emisor: ");
            informacion.add(String.format("%02X", p.getUByte(22))+":"+String.format("%02X", p.getUByte(23))+":"+String.format("%02X", p.getUByte(24))+":"+String.format("%02X", p.getUByte(25))+":"+String.format("%02X", p.getUByte(26))+":"+String.format("%02X", p.getUByte(27)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Dirección de protocolo del emisor: ");
            informacion.add(p.getUByte(28)+"."+p.getUByte(29)+"."+p.getUByte(30)+"."+p.getUByte(31));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Dirección de hardware del receptor: ");
            informacion.add(String.format("%02X", p.getUByte(32))+":"+String.format("%02X", p.getUByte(33))+":"+String.format("%02X", p.getUByte(34))+":"+String.format("%02X", p.getUByte(35))+":"+String.format("%02X", p.getUByte(36))+":"+String.format("%02X", p.getUByte(37)));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();

            campo.add("Dirección de protocolo del receptor: ");
            informacion.add(p.getUByte(38)+"."+p.getUByte(39)+"."+p.getUByte(40)+"."+p.getUByte(41));
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();
    	}
    	catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }
    static void analizarLLC(Document a, PcapPacket p, int d)
    {
    	try
    	{
    		Paragraph principal = new Paragraph();
    		Phrase campo = new Phrase("", FontFactory.getFont("Impact", 10, Font.BOLD, BaseColor.BLACK));
    		Phrase informacion = new Phrase("", FontFactory.getFont("Impact", 10, Font.ITALIC, BaseColor.BLACK));
    		principal.setIndentationLeft(0);

	        if(d == 3)
	        {
	        	campo.add("Campo de control: ");
	            informacion.add(Integer.toString(p.getUByte(16)));
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();
	        }
	        else
	        {
	        	campo.add("Campo de control: ");
	            informacion.add(Integer.toString(p.getUByte(16)+p.getUByte(17)));
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();
	        }

	        int zzz = p.getUByte(16) & 192;
	        int www = p.getUByte(16) & 128;

	        if(zzz == 192)
	        {
	        	campo.add("Tipo de trama: ");
	            informacion.add("U-SABME");
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();
	        }
	        else if(www == 128)
	        {
	        	String tt = "";
	            switch(p.getUByte(16) & 12)
	            {
	                case 0:
	                    tt = "RR";
	                    break;
	                case 1:
	                    tt = "RNR";
	                    break;
	                case 2:
	                    tt = "REJ";
	                    break;
	                case 3:
	                    tt = "SREJ";
	                    break;
	            }
	            campo.add("Tipo de trama: S-");
	            informacion.add(tt);
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();

				campo.add("N(r): ");
	            informacion.add(Integer.toString(voltearBits(p.getUByte(17)&(128+64+32+16+8+4))));
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();
	            //a.add(new Paragraph("N(r): "+voltearBits(p.getUByte(17)&(128+64+32+16+8+4))));
	        }
	        else
	        {
	        	campo.add("Tipo de trama: ");
	            informacion.add("I");
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();

	            campo.add("N(s): ");
	            informacion.add(Integer.toString(voltearBits(p.getUByte(16)&(128+64+32+16+8+4))));
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();

	            campo.add("N(r): ");
	            informacion.add(Integer.toString(voltearBits(p.getUByte(17)&(128+64+32+16+8+4))));
	            principal.add(campo);
	            principal.add(informacion);
	            documento.add(principal);
	            campo.clear();
	            informacion.clear();
	            principal.clear();
	        }

	        int xxx = p.getUByte(15)&1;
	        campo.add("P/F: ");
            informacion.add((xxx == 0)? "P": "F");
            principal.add(campo);
            principal.add(informacion);
            documento.add(principal);
            campo.clear();
            informacion.clear();
            principal.clear();
	    }
	    catch(DocumentException z)
    	{
    		System.err.println(z.getMessage());
    	}
    }
    static int voltearBits(int o)
    {
        int orig = o, tmp1, fin = 0, i;
        for(i = 7; i > 0; i--)
        {
            tmp1 = orig & 1;
            tmp1 <<= i;
            fin = tmp1 | fin;
            orig >>= 1;
        }
        return fin;
    }
}
