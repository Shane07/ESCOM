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
        
        p.println("<html><head><link rel='stylesheet' type='text/css' href='/GeneradorCSS/multiaportes/estilos.css'/></head><body>");
        
        try
        {
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
