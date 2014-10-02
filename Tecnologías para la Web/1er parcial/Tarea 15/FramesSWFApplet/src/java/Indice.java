import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Indice extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head><body>");
        for(int c = 1; c <= Integer.parseInt((String) s.getAttribute("cL")); c++)
            p.print("<a href='DibujarPagina?u="+(String) s.getAttribute("link"+c)+"&n="+c+"' target='marco' class='texto'>"+(String) s.getAttribute("name"+c)+"</a><br/><br/>");
        p.print("</body></html>");
    }
}
