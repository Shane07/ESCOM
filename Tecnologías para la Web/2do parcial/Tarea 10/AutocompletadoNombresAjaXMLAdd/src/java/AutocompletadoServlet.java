import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class AutocompletadoServlet extends HttpServlet{
	private ArrayList palabras;

	public AutocompletadoServlet(){System.out.println("AutocompletadoServlet()");}
		
	public void init(ServletConfig config){}
	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException
        {
            HttpSession s = request.getSession();
		String prefijo = request.getParameter("names");
		
		//Obteniendo la lista de palabras del servicio de bd
		ServicioAutocompletado sa = new ServicioAutocompletado();
		palabras = sa.obtListaPalabras(s.getServletContext().getRealPath("/multiaportes/nombres.xml"));
                /*
                PrintWriter salida = response.getWriter();
                salida.println();
                salida.println("Excepcion IO: "+sa.exc1());
                salida.println("Excepcion JDOM: "+sa.exc2());*/
                for(int i = 0; i < palabras.size(); i++){
				String palabra = (String)palabras.get(i);
				//salida.println(palabra);	
			}

		//Obteniendo palabras similares
		ServicioComparador sc = ServicioComparador.obtInstancia(palabras);
		ArrayList similares = sc.buscarPalabras(prefijo);	
                for(int i = 0; i < similares.size(); i++){
				String palabra = (String)similares.get(i);
				//salida.println(palabra);	
			}
		
		if(similares.size() > 0){
			response.setContentType("text/xml");
			response.setHeader("Cache-Control","no-cache");
			
			PrintWriter salida = response.getWriter();
			salida.println("<response>");
			
			for(int i = 0; i < similares.size(); i++){
				String palabra = (String)similares.get(i);
				salida.println("<name>" + palabra + "</name>");	
			}
			
			salida.println("</response>");
                        
			palabras = null;
			similares = null;
			sc = null;
			
			salida.close();	
		}else{
			response.setStatus(HttpServletResponse.SC_NO_CONTENT);
		}		
	}
}