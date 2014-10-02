import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import org.jdom2.*;
import org.jdom2.input.SAXBuilder;

public class ServicioAutocompletado
{ private String excepcion1, excepcion2;
    public ServicioAutocompletado()
    {
        excepcion1 = "NINGUNA";
        excepcion2 = "NINGUNA";
    }

    //Obteniendo la lista de palabras
    public ArrayList obtListaPalabras(String ruta)
    {
        ArrayList palabras = new ArrayList();
        SAXBuilder sb = new SAXBuilder();
        File xml = new File(ruta);
        List tmp;
        
        try
        {
            Document doc = (Document) sb.build(xml);
            Element raiz = doc.getRootElement();
            tmp = raiz.getChildren();
            
            for(int a = 0; a < tmp.size(); a++)
            {
                Element persona = (Element) tmp.get(a);
                palabras.add(persona.getAttribute("nombre").getValue());
            }
        }
        catch(IOException x)
        {
            excepcion1 = x.getMessage();
            System.err.println(x.getMessage());
        }
        catch(JDOMException y)
        {
            excepcion2 = y.getMessage();
            System.err.println(y.getMessage());
        }
        
        return palabras;
    }
    
    public String exc1()
    {
        return excepcion1;
    }
    public String exc2()
    {
        return excepcion2;
    }
}