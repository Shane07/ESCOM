/**
 * @author Ortega Ortunio Eder - 2CV7
 */
public abstract class Figura
{
    protected String nombre;
    protected float area, perimetro;
    
    public Figura(String nombre)
    {
        this.nombre = nombre;
    }
    
    // Métodos abstractos (necesario redefinir)
    public abstract float calcularArea();
    public abstract float calcularPerimetro();
    
    public void verInfo()
    {
        System.out.println("Nombre: "+nombre);
        System.out.println("Area: "+area);
        System.out.println("Perimetro: "+perimetro);
    }
}
