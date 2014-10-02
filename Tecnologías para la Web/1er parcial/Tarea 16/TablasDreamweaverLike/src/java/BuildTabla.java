import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class BuildTabla extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        PrintWriter p = response.getWriter();
        HttpSession s = request.getSession();
        String celda_st = "", celda_fn = "", percent = "", tabla;
        int flag = -1;
        
        if(s.getAttribute("eA").toString().equals("porcent"))
            percent = "%";
        
        tabla = "<table width=\""+s.getAttribute("aT")+percent+"\" border=\""+s.getAttribute("gB")+"\" cellspacing=\""+s.getAttribute("eC")+"\" cellpadding=\""+s.getAttribute("rC")+"\" summary=\""+s.getAttribute("sA")+"\">";
        
        if(s.getAttribute("en").equals("none"))
        {
            celda_st = "<td>";
            celda_fn = "</td>";
            flag = 0;
        }
        else if(s.getAttribute("en").equals("izq"))
        {
            celda_st = "<th scope=\"row\">";
            celda_fn = "</th>";
            flag = 1;
        }
        else if(s.getAttribute("en").equals("sup"))
        {
            celda_st = "<th scope=\"col\">";
            celda_fn = "</th>";
            flag = 2;
        }
        else if(s.getAttribute("en").equals("both"))
            flag = 3;
        
        p.print("<html><head></head><body>"+tabla);
        p.print("<caption>"+s.getAttribute("tA")+"</caption>");
        for(int a = 0; a < Integer.parseInt((String) s.getAttribute("t")); a++)
        {
            p.print("<tr>");
            for(int b = 0; b < Integer.parseInt((String) s.getAttribute("c")); b++)
            {
                if(flag == 0)
                    p.print("<td>"+request.getParameter("datos"+a+b)+"</td>");
                if(flag == 1)
                {
                    if(b == 0)
                        p.print(celda_st+request.getParameter("datos"+a+b)+celda_fn);
                    else
                        p.print("<td>"+request.getParameter("datos"+a+b)+"</td>");
                }
                else if(flag == 2)
                {
                    if(a == 0)
                        p.print(celda_st+request.getParameter("datos"+a+b)+celda_fn);
                    else
                        p.print("<td>"+request.getParameter("datos"+a+b)+"</td>");
                }
                else if(flag == 3)
                {
                    if(a == 0)
                        p.print("<th scope=\"col\">"+request.getParameter("datos"+a+b)+"</th>");
                    else
                        if(b == 0)
                            p.print("<th scope=\"row\">"+request.getParameter("datos"+a+b)+"</th>");
                        else
                            p.print("<td>"+request.getParameter("datos"+a+b)+"</td>");
                }
            }
            p.print("<tr/>");
        }
        p.print("</table></body></html>");
    }
}
