import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class indiceLinks extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head><body>");
        for(int c = 1; c <= Integer.parseInt(request.getParameter("u")); c++)
            p.print("<a href='drawPagina?n="+c+"' target='marco' class='texto'>> Enlace "+c+"</a><br/><br/>");
        p.print("</body></html>");
    }
}
