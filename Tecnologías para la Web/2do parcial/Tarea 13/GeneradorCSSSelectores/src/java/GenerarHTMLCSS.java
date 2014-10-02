import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
/*
    SOLUCION:
    - Leer archivo: chmod 777 multiaportes (directorio en .../build/web/)
    - Escribir en archivo: chmod 666 nombres.xml (archivo en .../build/web/multiaportes/nombres.xml)
*/

public class GenerarHTMLCSS extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        HttpSession sesion = request.getSession();
        String css = sesion.getServletContext().getRealPath("/multiaportes/estilos.css");
        PrintWriter p = response.getWriter();
        FileWriter estilo = new FileWriter(css);
        
        p.println("<html><head><link rel='stylesheet' type='text/css' href='/GeneradorCSSSelectores/multiaportes/estilos.css'/></head><body>");
        
        try
        {
            p.println("<h3>Selector universal</h3>");
            p.println("<span>...</span><br/>");
            estilo.write("* {"+request.getParameter("cssSelUniv")+"}\n");
            p.println("<h3>Elementos HTML</h3>");
            for(int i = 0; i < Integer.parseInt(request.getParameter("cantidadElementosHTML")); i++)
            {
                if(!request.getParameter("nombreEHTML"+i).equals("body"))
                    p.println("<"+request.getParameter("nombreEHTML"+i)+">Texto</"+request.getParameter("nombreEHTML"+i)+"><br/>");
                estilo.write(request.getParameter("nombreEHTML"+i)+"{"+request.getParameter("cssEHTML"+i)+"}\n");
            }
            p.println("<h3>ID</h3>");
            for(int i = 0; i < Integer.parseInt(request.getParameter("cantidadID")); i++)
            {
                p.println("<span id='"+request.getParameter("nombreID"+i)+"'>Texto ID</span><br/>");
                estilo.write("#"+request.getParameter("nombreID"+i)+"{"+request.getParameter("cssID"+i)+"}\n");
            }
            p.println("<h3>Clases</h3>");
            for(int i = 0; i < Integer.parseInt(request.getParameter("cantidadCLASS")); i++)
            {
                p.println("<span class='"+request.getParameter("nombreCLASS"+i)+"'>Texto CLASS</span><br/>");
                estilo.write("."+request.getParameter("nombreCLASS"+i)+"{"+request.getParameter("cssCLASS"+i)+"}\n");
            }
            p.println("<h3>Before</h3>");
            p.println("<span id='"+request.getParameter("beforeID")+"'>Texto en el span</span><br/>");
            estilo.write("#"+request.getParameter("beforeID")+":before {"+request.getParameter("cssIDBefore")+"}\n");
            p.println("<h3>After</h3>");
            p.println("<span id='"+request.getParameter("afterID")+"'>Texto en el span</span><br/>");
            estilo.write("#"+request.getParameter("afterID")+":after {"+request.getParameter("cssIDAfter")+"}\n");
            p.println("<h3>Atributo</h3>");
            p.println("<span "+request.getParameter("atributo")+">Elemento SPAN con atributo</span><br/>");
            p.println("<span "+request.getParameter("atributo")+"2>Elemento SPAN sin atributo</span><br/>");
            p.println("<p "+request.getParameter("atributo")+">Elemento P con atributo</p><br/>");
            p.println("<p "+request.getParameter("atributo")+"2>Elemento P sin atributo</p><br/>");
            estilo.write("["+request.getParameter("atributo")+"] {"+request.getParameter("cssAtributo")+"}\n");
            p.println("<h3>Seleccion</h3>");
            p.println("<span id='seleccionMultiAportesDotCom'>Selecciona este texto...</span><br/>");
            estilo.write("#seleccionMultiAportesDotCom::selection {"+request.getParameter("cssSeleccion")+"}\n");
            estilo.write("#seleccionMultiAportesDotCom::-moz-selection {"+request.getParameter("cssSeleccion")+"}\n");
        }
        catch(IOException x)
        {
            p.println(x.getMessage());
        }
        finally
        {
            estilo.flush();
            estilo.close();
            p.println("</body></html>");
        }
    }
}
