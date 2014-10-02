import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class drawFrames extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        
        /* Cols = 'n, *' | n es el tamanio y * es el complemento para llenar la pantalla */
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head>");
        p.print("<frameset cols=\"180, *\" frameborder=\"no\" border=\"0\" framespacing=\"0\">\n" +
"        <frame src=\"indiceLinks?u="+request.getParameter("cantidadLinks")+"\" scrolling=\"yes\" noresize=\"noresize\">\n" +
"        <frame src=\"drawPagina\" name='marco' scrolling=\"no\" noresize=\"noresize\">\n" +
"    </frameset>");
        p.print("</html>");
    }
}
