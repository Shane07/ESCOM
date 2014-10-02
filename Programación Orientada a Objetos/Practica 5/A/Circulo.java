/**
 * @author Ortega Ortunio Eder - 2CV7
 */
public class Circulo extends Figura
{
    private float radio;
    
    public Circulo(float radio)
    {
        super("Circulo");
        this.radio = radio;
        area = calcularArea();
        perimetro = calcularPerimetro();
    }
    
    public float calcularArea()
    {
        return (float)(Math.PI) * radio * radio; // Haciendo un casting de double a float en PI
    }
    public float calcularPerimetro()
    {
        return 2 * (float)(Math.PI) * radio;
    }
    public void verInfo()
    {
        super.verInfo();
        System.out.println("Radio: "+radio);
    }
}
