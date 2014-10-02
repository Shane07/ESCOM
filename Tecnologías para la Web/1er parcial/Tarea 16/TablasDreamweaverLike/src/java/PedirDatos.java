import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class PedirDatos extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        
        s.setAttribute("t", request.getParameter("filas"));
        s.setAttribute("c", request.getParameter("columnas"));
        s.setAttribute("aT", request.getParameter("anchoTabla"));
        s.setAttribute("eA", request.getParameter("escalaAncho"));
        s.setAttribute("gB", request.getParameter("grosorBorde"));
        s.setAttribute("rC", request.getParameter("rellenoCelda"));
        s.setAttribute("eC", request.getParameter("espacioCelda"));
        s.setAttribute("en", request.getParameter("encabezado"));
        s.setAttribute("tA", request.getParameter("textoAcces"));
        s.setAttribute("sA", request.getParameter("summaryAcces"));
        
        p.print("<html><head></head><body><form action=\"BuildTabla\" method=\"POST\">");
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("t")); a++)
        {
            for(int b = 0; b < Integer.parseInt((String) s.getAttribute("c")); b++)
                p.print("<input type='text' name='datos"+a+b+"' style=\"width: 90px;\">");
            p.print("<br/>");
        }
        p.print("<br/><input type=\"submit\" name=\"send\" value=\"Validar\"></form></body></html>");
    }
}
