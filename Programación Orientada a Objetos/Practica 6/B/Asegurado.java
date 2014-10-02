public class Asegurado
{
    private String nombre;
    private int edad, licencia;
    
    public Asegurado(String nombre, int edad, int licencia)
    {
        this.nombre = nombre;
        this.edad = edad;
        this.licencia = licencia;
    }
    public String getNombre()
    {
        return this.nombre;
    }
    public int getEdad()
    {
        return this.edad;
    }
    public int getLicencia()
    {
        return this.licencia;
    }
    public void setNombre(String nombre)
    {
        this.nombre = nombre;
    }
    public void setEdad(int edad)
    {
        this.edad = edad;
    }
    public void setLicencia(int licencia)
    {
        this.licencia = licencia;
    }
}
