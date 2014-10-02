import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.jdom2.JDOMException;
import org.jdom2.input.SAXBuilder;

public class AnalizarDocumento extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter p = response.getWriter();
        SAXBuilder b = new SAXBuilder();
        String ruta = getServletContext().getRealPath("/multiaportes").concat("/"+request.getParameter("archivo")+".xml");
        
        p.println("<html><head></head><body><style type='text/css'>body{font-size:26px;font-weight: bolder;}.ok{color: #07E500}.advertencia{color: #FFD800}.error{color: #E20000}#fichero{color: #727272}</style>");
        p.println("<span id='fichero'>Archivo: "+request.getParameter("archivo")+".xml</span><br/>");
        
        try
        {
            checarConformidad(b, ruta);
            p.println("<span class='ok'>El documento est&aacute; correctamente formado.</span>"); // Si ocurre una excepcion, esta linea no se ejecuta
        }
        catch(JDOMException j)
        {
            p.println("<span class='advertencia'>El documento no est&aacute; correctamente formado.</span>");//+j.getMessage());
        }
        catch(IOException i)
        {
            p.println("<span class='error'>Error al abrir el fichero: </span><span id='errorFichero'>"+i.getMessage()+"</span>");
        }
        
        p.println("<br/>");
        
        try
        {
            checarValidez(b, ruta);
            p.println("<span class='ok'>El documento es v&aacute;lido.</span>");
        }
        catch(JDOMException j)
        {
            p.println("<span class='advertencia'>El documento no es v&aacute;lido.</span>");//+j.getMessage());
        }
        catch(IOException i)
        {
            
        }
        finally
        {
            p.println("</body></html>");
        }
    }
    
    private void checarConformidad(SAXBuilder sax, String archivo) throws JDOMException, IOException
    {
        sax.build(archivo);
    }
    private void checarValidez(SAXBuilder sax, String archivo) throws JDOMException, IOException
    {
        sax.setValidation(true);
        sax.build(archivo);
    }
}
