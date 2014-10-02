import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class DrawFrame extends HttpServlet
{   
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        String f = "";
        
        if(s.getAttribute("fr").equals("1"))
            f = "<frameset cols='"+request.getParameter("columnas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("2"))
            f = "<frameset cols='*,"+request.getParameter("columnas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("3"))
            f = "<frameset rows='"+request.getParameter("filas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/' />\n" +
"  <frame src='http://localhost/' />\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("4"))
            f = "<frameset rows='*,"+request.getParameter("filas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("5"))
            f = "<frameset rows='*,"+request.getParameter("filas")+"' cols='*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frameset cols='"+request.getParameter("columnas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("6"))
            f = "<frameset rows='*,"+request.getParameter("filas")+"' cols='*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frameset cols='*,"+request.getParameter("columnas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("7"))
            f = "<frameset rows='*' cols='"+request.getParameter("columnas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frameset rows='"+request.getParameter("columnas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("8"))
            f = "<frameset rows='*' cols='"+request.getParameter("columnas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frameset rows='*,"+request.getParameter("filas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("9"))
            f = "<frameset cols='*,"+request.getParameter("columnas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frameset rows='*,"+request.getParameter("filas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("10"))
            f = "<frameset cols='*,80' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frameset rows='"+request.getParameter("filas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("11"))
            f = "<frameset rows='"+request.getParameter("filas")+",*,"+request.getParameter("filas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frame src='http://localhost/'/>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("12"))
            f = "<frameset rows='"+request.getParameter("filas")+",*' cols='*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frameset cols='"+request.getParameter("columnas")+",*' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"</frameset>";
        else if(s.getAttribute("fr").equals("13"))
            f = "<frameset rows='"+request.getParameter("filas")+",*' cols='*' framespacing='"+request.getParameter("esp")+"'>\n" +
"  <frame src='http://localhost/'/>\n" +
"  <frameset cols='*,"+request.getParameter("columnas")+"' framespacing='"+request.getParameter("esp")+"'>\n" +
"    <frame src='http://localhost/'/>\n" +
"    <frame src='http://localhost/'/>\n" +
"  </frameset>\n" +
"</frameset>";
        
        p.print("<html><head></head><body>"+f+"</body></html>");
    }
}
