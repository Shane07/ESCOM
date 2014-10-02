import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class GenerarCSS extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        HttpSession sesion = request.getSession();
        String salida = sesion.getServletContext().getRealPath("/multiaportes/estilos.css");
        PrintWriter p = response.getWriter();
        FileWriter w = new FileWriter(salida);
        
        try
        {
            w.write(request.getParameter("codigoCSS"));
            p.println(request.getParameter("codigoCSS"));
            w.flush();
            w.close();
        }
        catch(IOException x)
        {
            p.println(x.getMessage());
        }
    }
}
