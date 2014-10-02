import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class PedirMultimedia extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        for(int k = 1; k <= Integer.parseInt((String) s.getAttribute("cL")); k++)
        {
            s.setAttribute("name"+k, request.getParameter("nombre"+k));
            s.setAttribute("link"+k, request.getParameter("url"+k));
        }
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head><body>");
        p.print("<form action=\"DibujarFrames\" method=\"POST\">");
        for(int k = 1; k <= Integer.parseInt((String) s.getAttribute("cL")); k++)
            p.print("<span class=\"texto\">"+k+".</span><br/>\n" +
"           <label for=\"img"+k+"\" class=\"texto pequenio\">Imagen</label><input id=\"img"+k+"\" type=\"radio\" name=\"tipoArchivo"+k+"\" value=\"img\" checked><label for=\"app"+k+"\" class=\"texto pequenio\">Applet</label><input id=\"app"+k+"\" type=\"radio\" name=\"tipoArchivo"+k+"\" value=\"app\"><label for=\"fla"+k+"\" class=\"texto pequenio\">Flash</label><input id=\"fla"+k+"\" type=\"radio\" name=\"tipoArchivo"+k+"\" value=\"fla\"><label for=\"shw"+k+"\" class=\"texto pequenio\">Shockwave</label><input id=\"shw"+k+"\" type=\"radio\" name=\"tipoArchivo"+k+"\" value=\"shw\"><br/>\n"+
"           <span class=\"texto pequenio\">Nombre:</span><input type=\"text\" class=\"caja bordeada texto pequenio\" name=\"nombreArchivo"+k+"\"><br/><br/><br/><br/>");
        p.print("<input type=\"submit\" name=\"enviar\" class=\"boton texto\" value=\"Validar\"></form></body></html>");
    }
}
