import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class GenerarAtributos extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("cantidad")); a++)
        {
            s.setAttribute("n"+a, request.getParameter("nombre"+a));
            s.setAttribute("a"+a, request.getParameter("atrib"+a));
        }
        
        p.print("<html><head></head><body><form action=\"BuildXML\" method=\"POST\">");
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("cantidad")); a++)
        {
            p.print("<h2>"+(String) s.getAttribute("n"+a)+"</h2>");
            for(int b = 0; b < Integer.parseInt((String) s.getAttribute("a"+a)); b++)
            {
                p.print("Nombre atributo: <input type='text' name='at_name"+a+b+"'>");
                p.print("Valor atributo: <input type='text' name='at_val"+a+b+"'>");
                p.print("<br/>");
            }
            p.print("<br/>");
        }
        p.print("<br/><input type=\"submit\" name=\"send\" value=\"Validar\"></form></body></html>");
    }
}
