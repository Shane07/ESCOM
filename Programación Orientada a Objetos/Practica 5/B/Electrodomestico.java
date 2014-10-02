public class Electrodomestico extends Producto
{
    private int mesesG;
    
    public Electrodomestico(int id, int existencias, String marca, String descripcion, float precio)
    {
        super(id, existencias, marca, descripcion, precio);
        this.mesesG = 12;
    }
    
    public void setGarantia(int mesesG)
    {
        this.mesesG = mesesG;
    }
    public String getInfo()
    {
    	return super.getInfo()+"\nGarantia: "+mesesG+" meses\n";
    }
}