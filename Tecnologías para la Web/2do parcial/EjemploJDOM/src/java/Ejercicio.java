import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.jdom2.*;
import org.jdom2.output.XMLOutputter;
import java.io.FileWriter;

/**
 * Servlet implementation class Servlet1
 */
public class Ejercicio extends HttpServlet {
//	private static final long serialVersionUID = 1L;
       

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{

		try
		{
			Element root = new Element("boom");
			Element r1 = new Element("r1");
                        Element r2 = new Element("r2");
			r1.setAttribute("a", "5");
                        r1.setAttribute("b", "6");
                        r2.setAttribute("a", "7");
                        r2.setAttribute("b", "9");
			root.addContent(r1);
                        root.addContent(r2);
  
			Document newdoc = new Document(root);
			XMLOutputter fmt = new XMLOutputter();
			FileWriter writer = new FileWriter("c:\\users\\Alumno\\ejercicio.xml");
			fmt.output(newdoc, writer);
            writer.flush();
            writer.close();
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		}
		

	}


}
