import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class DibujarFrames extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        for(int k = 1; k <= Integer.parseInt((String) s.getAttribute("cL")); k++)
        {
            s.setAttribute("tA"+k, request.getParameter("tipoArchivo"+k));
            s.setAttribute("nA"+k, request.getParameter("nombreArchivo"+k));
        }
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head>");
        p.print("<frameset cols=\"180, *\" frameborder=\"no\" border=\"0\" framespacing=\"0\">\n" +
"        <frame src=\"Indice?u="+(String) s.getAttribute("cL")+"\" scrolling=\"yes\" noresize=\"noresize\">\n" +
"        <frame src=\"DibujarPagina\" name='marco' scrolling=\"no\" noresize=\"noresize\">\n" +
"    </frameset>");
        p.print("</html>");
    }
}
