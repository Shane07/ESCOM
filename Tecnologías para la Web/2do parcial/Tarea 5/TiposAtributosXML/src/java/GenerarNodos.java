import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class GenerarNodos extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        s.setAttribute("raiz", request.getParameter("root"));
        s.setAttribute("cantidad", request.getParameter("cant"));
        
        p.print("<html><head></head><body><form action=\"GenerarAtributos\" method=\"POST\">");
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("cantidad")); a++)
        {
            p.print("Nombre: <input type='text' name='nombre"+a+"'>");
            p.print("<br/>");
            p.print("Atributos: <input type='text' name='atrib"+a+"'value='0'>");
            p.print("<br/><br/>");
        }
        p.print("<br/><input type=\"submit\" name=\"send\" value=\"Validar\"></form></body></html>");
    }
}
