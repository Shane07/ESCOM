import com.hp.hpl.jena.ontology.*;
import com.hp.hpl.jena.rdf.model.*;
import com.hp.hpl.jena.vocabulary.*;
import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.*;


public class GenerarOWL extends HttpServlet
{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        HttpSession sesion = request.getSession();
        PrintWriter p = response.getWriter();
        String archivo = sesion.getServletContext().getRealPath("/multiaportes/"+request.getParameter("archivo")+".owl");
        FileOutputStream arch;
        
        try
        {
            String plantas = "http://www.linkeddatatools.com/plants";
            OntModel modelo = ModelFactory.createOntologyModel(); // OntModel
            Ontology ontologia = modelo.createOntology(plantas);
            OntClass tipoPlanta = modelo.createClass(plantas+"#planttype");
            
            arch = new FileOutputStream(new File(archivo));
             
            modelo.setNsPrefix("rdf", RDF.getURI()); // Resource Description Framework
            modelo.setNsPrefix("rdfs", RDFS.getURI()); // RDF Schema
            modelo.setNsPrefix("owl", OWL.getURI()); // Web Ontology Language
            modelo.setNsPrefix("dc", DC.getURI()); // DublinCore.org
            //modelo.setNsPrefix("test", "http://www.multiaportes.com/test");
            
            // Las propiedades se escriben en el archivo en orden alfabetico
            
            // Creando ontologia: plantas
            ontologia.addProperty(DC.title, "The LinkedDataTools example plant ontology");
            ontologia.addProperty(DC.description, "An example ontology written for the LinkedDataTools.com RDFS & OWL introduction tutorial");
            
            // Creando clase: tipo planta
            tipoPlanta.addProperty(RDFS.label, "The plant type");
            tipoPlanta.addProperty(RDFS.comment, "The class of plant types");
            
            modelo.write(arch, "RDF/XML-ABBREV"); // OutputStream, lenguaje en el que se va a escribir el fichero
            
            arch.flush();
            arch.close();
        }
        catch(IOException x)
        {
            x.printStackTrace();
        }
        finally
        {
            p.println("<html><head></head><body>");
            p.println("<style type=\"text/css\">\n" +
"            body\n" +
"            {\n" +
"                background-color: #FF0;                \n" +
"            }\n" +
"            h2\n" +
"            {\n" +
"                font-size: 30px;\n" +
"                color: #000;\n" +
"            }\n" +
"            a\n" +
"            {\n" +
"                font-size: 11px; font-family: Consolas; text-decoration: underline;\n" +
"                color: #000;\n" +
"            }\n" +
"        </style>");
            p.println("<h2>Archivo generado exitosamente</h2><span>Guardado en <a href=file://"+archivo+">"+archivo+"</a></span></body></html>");
        }
    }
}