public abstract class Producto
{
    protected int id, existencias;
    protected String marca, descripcion;
    protected float precio;
    
    public Producto(int id, int existencias, String marca, String descripcion, float precio)
    {
        this.id = id;
        this.existencias = existencias;
        this.marca = marca;
        this.descripcion = descripcion;
        this.precio = precio;
    }
    
    public boolean venderProd(int cnt)
    {
        if(cnt <= existencias)
        {
            existencias -= cnt;
            return true;
        }
        else
            return false;
    }
    public String getNombre()
    {
    	return descripcion.substring(0, descripcion.indexOf(" "))+" "+marca;
    }
    public String getInfo()
    {
    	return "Marca: "+marca+"\nDescripcion: "+descripcion+"\nPrecio: $"+precio;
    }
    public float getPrecio()
    {
    	return precio;
    }
}