import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ShowTabla extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        p.print("<html><head><link rel=\"stylesheet\" href=\"estilos.css\" type=\"text/css\"></head><body><table>");
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("t")); a++)
        {
            p.print("<tr>");
            for(int b = 0; b < Integer.parseInt((String) s.getAttribute("c")); b++)
                p.print("<td>"+request.getParameter("datos"+a+b)+"</td>");
            p.print("<tr/>");
        }
        p.print("</table></body></html>");
    }
}
