import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class MetodoPost extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest pet, HttpServletResponse resp) throws ServletException, IOException 
    {
        PrintWriter salida = resp.getWriter();
        
        salida.println("<html><head><title>Respuesta: GET</title></head><body>Texto: <strong>"+pet.getParameter("textopost")+"</strong></body></html>");
    }
}