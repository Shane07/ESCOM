import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.JDOMException;
import org.jdom2.input.SAXBuilder;
import org.jdom2.output.XMLOutputter;

/*
    SOLUCION:
    - Leer archivo: chmod 777 multiaportes (directorio en .../build/web/)
    - Escribir en archivo: chmod 666 nombres.xml (archivo en .../build/web/multiaportes/nombres.xml)
*/

public class AddNombre extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        HttpSession sesion = request.getSession();
        SAXBuilder sax = new SAXBuilder();
        String salida = sesion.getServletContext().getRealPath("/multiaportes/nombres.xml");
        PrintWriter p = response.getWriter();
        
        try
        {
            Element raiz, nuevoNombre = new Element("persona");
            Document d;
            XMLOutputter s = new XMLOutputter();
            
            d = (Document) sax.build(salida);
            raiz = d.getRootElement();
            
            nuevoNombre.setAttribute("nombre", request.getParameter("n"));
            raiz.addContent(nuevoNombre);
            
            s.output(d, new FileWriter(salida));
        }
        catch(JDOMException | IOException x)
        {
            p.println(x.getMessage());
        }
    }
}
