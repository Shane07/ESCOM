import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.jdom2.*;
import org.jdom2.output.XMLOutputter;
import java.io.FileWriter;
import java.io.PrintWriter;
import javax.servlet.http.HttpSession;

public class BuildXML extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
    {
        HttpSession s = request.getSession();
        PrintWriter p = response.getWriter();
        
        Element root = new Element((String) s.getAttribute("raiz"));
        Element elems[] = new Element[Integer.parseInt((String) s.getAttribute("cantidad"))];
        
        String arch = getServletContext().getRealPath("/multiaportes/salida.xml");
        
        Document doc = new Document(root);
        XMLOutputter fmt = new XMLOutputter();
        FileWriter writer = new FileWriter(arch);

        for(int a = 0; a < elems.length; a++)
        {
            elems[a] = new Element((String) s.getAttribute("n"+a));
            for(int b = 0; b < Integer.parseInt((String) s.getAttribute("a"+a)); b++)
            {
                elems[a].setAttribute(request.getParameter("at_name"+a+b), request.getParameter("at_val"+a+b));
            }
            root.addContent(elems[a]);
        }
        
        try
        {
            fmt.output(doc, writer);
            writer.flush();
            writer.close();
        } 
        catch (Exception e)
        {
                p.print(e.getMessage());
        }
        finally
        {
            p.print("<html><head></head><body><h2>Documento XML generado correctamente</h2>Archivo guardado en "+arch+"<br/>Solucion FileWriter Servlet Linux: <code>chmod 777 carpeta</code></body></html>");
        }
        
    }
}
