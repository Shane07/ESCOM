import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class PedirLinks extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        s.setAttribute("cL", request.getParameter("cantidadLinks"));
        
        p.print("<html><head><link href='estilos.css' rel='stylesheet'></head><body>");
        p.print("<form action=\"PedirMultimedia\" method=\"POST\">");
        for(int k = 1; k <= Integer.parseInt((String) s.getAttribute("cL")); k++)
            p.print("<span class=\"texto\">"+k+".</span><br/>\n" +
"           <span class=\"texto pequenio\">Nombre:</span><input type=\"text\" class=\"caja bordeada texto pequenio\" name=\"nombre"+k+"\">\n"+
"           <span class=\"texto pequenio\">Link:</span><input type=\"text\" class=\"caja bordeada texto pequenio\" name=\"url"+k+"\"><br/><br/><br/><br/>");
        p.print("<input type=\"submit\" name=\"enviar\" class=\"boton texto\" value=\"Validar\"></form></body></html>");
    }
}
