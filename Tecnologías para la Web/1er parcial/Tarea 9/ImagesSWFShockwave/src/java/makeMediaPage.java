import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class makeMediaPage extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        String extension = "";
        
        if(request.getParameter("tipoArchivo").equals("img"))
            extension = ".jpg";
        else if(request.getParameter("tipoArchivo").equals("app"))
            extension = ".class";
        else if(request.getParameter("tipoArchivo").equals("fla"))
            extension = ".swf";
        else if(request.getParameter("tipoArchivo").equals("shw"))
            extension = ".dcr";
        
        p.print("<html><head></head><body>");
        p.print("<embed src='"+request.getParameter("fichero")+extension+"'/>");
        p.print("</body></html>");
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
