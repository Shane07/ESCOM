import java.util.Calendar;

public class Vivere extends Producto
{
    private Calendar fCad;
    
    public Vivere(int id, int existencias, String marca, String descripcion, float precio, Calendar fCad)
    {
        super(id, existencias, marca, descripcion, precio);
        this.fCad = fCad;
    }
    public String getInfo()
    {
    	return super.getInfo()+"\nFecha de caducidad: "+fCad.get(Calendar.DATE)+"/"+(fCad.get(Calendar.MONTH)+1)+"/"+fCad.get(Calendar.YEAR);
    }
}