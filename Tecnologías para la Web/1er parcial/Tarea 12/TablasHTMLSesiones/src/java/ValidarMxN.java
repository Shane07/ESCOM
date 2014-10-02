import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ValidarMxN extends HttpServlet
{   
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        s.setAttribute("t", request.getParameter("filas"));
        s.setAttribute("c", request.getParameter("columnas"));
        
        p.print("<html><head><link rel=\"stylesheet\" href=\"estilos.css\" type=\"text/css\"></head><body><form action=\"ShowTabla\">");
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("t")); a++)
        {
            for(int b = 0; b < Integer.parseInt((String) s.getAttribute("c")); b++)
                p.print("<input type='text' name='datos"+a+b+"' class=\"cajaTxt\">");
            p.print("<br/>");
        }
        p.print("<br/><input type=\"submit\" name=\"send\" class=\"enviar\" value=\"Validar\" class=\"boton\"></form></body></html>");
    }
}
