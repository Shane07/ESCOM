import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class DibujarPagina extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        String extension = "", tipo = "tA"+request.getParameter("n"), nombre = "nA"+request.getParameter("n");
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head><body>");
        if(request.getParameter("n") == null || request.getParameter("n").equals("0"))
            p.print("<span class='texto'>P&aacute;gina sin contenido</span>");
        else
        {
            if(s.getAttribute(tipo).equals("img"))
                extension = ".jpg";
            else if(s.getAttribute(tipo).equals("app"))
                extension = ".class";
            else if(s.getAttribute(tipo).equals("fla"))
                extension = ".swf";
            else if(s.getAttribute(tipo).equals("shw"))
                extension = ".dcr";

            p.print("<embed src='"+s.getAttribute(nombre)+extension+"'/>");
        }
        p.print("</body></html>");
    }
}