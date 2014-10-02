import javax.swing.*;
import javax.swing.event.*;
import javax.swing.filechooser.*;
import java.awt.event.*;
import java.io.File;

public class Ventana extends JFrame
{
	private JButton genPDF;
	private JSlider sld;
	private JFileChooser selector;
	private JRadioButton nic, pcap;
	private ButtonGroup grupo;

	public Ventana()
	{
		this.setLyF();
		this.setTitle("Analizador de tramas Ethernet - multiaportes.com");
		this.setSize(500, 350);
		this.setLayout(null);
		this.setVisible(true);
		this.setResizable(false);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.init();
		this.addForms();
		this.dibujarElementos();
	}
	private void setLyF()
	{
		try
		{
			UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
		}
		catch(ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e)
		{
			System.err.println("Error al establecer el L&F");
		}
	}
	private void init()
	{
		genPDF = new JButton("Generar PDF");
		sld = new JSlider(JSlider.HORIZONTAL, 0, 30, 15);
		selector = new JFileChooser(new File("tramas.pcap")); // Iniciar en directorio actual
		nic = new JRadioButton("Tarjeta de red", true);
		pcap = new JRadioButton("Archivo *.pcap", false);
		grupo = new ButtonGroup();

		grupo.add(nic);
		grupo.add(pcap);
	}
	private void dibujarElementos()
	{
		nic.setBounds(100, 60, 150, 25);
		pcap.setBounds(250, 60, 150, 25);
		sld.setBounds(50, 120, 400, 60);
		genPDF.setBounds(100, 200, 250, 40);

		sld.setPaintTicks(true);
		sld.setPaintLabels(true);
		sld.setMinorTickSpacing(2);
		sld.setMajorTickSpacing(30);

		nic.addItemListener(
			new ItemListener()
			{
				public void itemStateChanged(ItemEvent z)
				{
					if(z.getStateChange() == ItemEvent.SELECTED)
						sld.setEnabled(true);
				}
			}
		);

		pcap.addItemListener(
			new ItemListener()
			{
				public void itemStateChanged(ItemEvent z)
				{
					if(z.getStateChange() == ItemEvent.SELECTED)
						sld.setEnabled(false);
				}
			}
		);

		genPDF.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent z)
				{
					if(nic.isSelected())
					{
						new JNetpcap(sld.getValue());
						JOptionPane.showMessageDialog(null, "Por Eder Ortega - 2CM9\n\nwww.multiaportes.com", "Creditos", JOptionPane.WARNING_MESSAGE);
						System.exit(0);
					}
					else if(pcap.isSelected())
					{
						FileNameExtensionFilter filtro = new FileNameExtensionFilter("Ficheros *.pcap", "pcap");
						selector.setFileFilter(filtro);
						selector.setDialogTitle("Abrir archivo PCAP - multiaportes.com");
						
						int resultado = selector.showOpenDialog(null);

						if(resultado == JFileChooser.APPROVE_OPTION)
						{
							new JNetpcap(selector.getSelectedFile().getAbsolutePath());
							JOptionPane.showMessageDialog(null, "Por Eder Ortega - 2CM9\n\nwww.multiaportes.com", "Creditos", JOptionPane.WARNING_MESSAGE);
							System.exit(0);
						}
					}
				}
			}
		);
	}
	private void addForms()
	{
		super.add(nic);
		super.add(pcap);
		super.add(sld);
		super.add(genPDF);
	}
	public static void main(String args[])
	{
		Ventana v = new Ventana();
	}
}