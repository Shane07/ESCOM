import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class propiedadesFrame extends HttpServlet
{   
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        s.setAttribute("fr", request.getParameter("frames"));
        
        p.print("<html><head></head><body><form action=\"DrawFrame\" method=\"POST\">");
        p.print("Filas: <input type='text' name='filas'><br/>");
        p.print("Columnas: <input type='text' name='columnas'><br/>");
        p.print("Espaciado: <input type='text' name='esp'><br/>");
        p.print("<br/><input type=\"submit\" name=\"send\" class=\"enviar\" value=\"Validar\" class=\"boton\"></form></body></html>");
    }
}
