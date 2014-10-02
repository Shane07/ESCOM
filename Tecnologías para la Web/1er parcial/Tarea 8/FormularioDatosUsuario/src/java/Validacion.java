import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Validacion extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest pet, HttpServletResponse resp) throws ServletException, IOException 
    {
        PrintWriter salida = resp.getWriter();
        String img = "", sexo, anios;
        int an;
        
        sexo = pet.getParameter("sexo");
        anios = pet.getParameter("anio");
        
        an = 2014 - Integer.parseInt(anios);
        
        if(sexo.equals("hombre"))
        {
            sexo = "un hombre";
            img = "macho.png";
        }
        else if(sexo.equals("mujer"))
        {
            sexo = "una mujer";
            img = "hembra.png";
        }
        
        salida.println("<html><head><title>Informacion del usuario</title><style type='text/css'>@import url('estilos.css');</style></head><body><img src='"+img+"'><h1>"+pet.getParameter("nombre")
                +" "+pet.getParameter("apellido")+"</h1><h6>http://perfiles.multiaportes.com/"+pet.getParameter("username")+"</h6><br/>Es "+sexo+" de "+an+" a&ntilde;os que naci&oacute; en "+pet.getParameter("dia")+" de "+pet.getParameter("mes")+"</body></html>");
    }
}