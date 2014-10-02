import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class drawPagina extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head><body>");
        if(request.getParameter("n") == null || request.getParameter("n").equals("0"))
            p.print("<span class='texto'>P&aacute;gina sin contenido</span>");
        else
            p.print("<span class='texto'>Esta es la p&aacute;gina "+request.getParameter("n")+"</span>");
        p.print("</body></html>");
    }
}