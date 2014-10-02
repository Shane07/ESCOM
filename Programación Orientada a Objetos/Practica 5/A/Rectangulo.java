/**
 * @author Ortega Ortunio Eder - 2CV7
 */
public class Rectangulo extends Figura
{
    private float base;
    private float altura;
    
    public Rectangulo(float base, float altura)
    {
        super("Rectangulo");
        this.base = base;
        this.altura = altura;
        area = calcularArea();
        perimetro = calcularPerimetro();
    }
    
    public float calcularArea()
    {
        return base * altura; // Haciendo un casting de double a float en PI
    }
    public float calcularPerimetro()
    {
        return 2 * (base + altura);
    }
    public void verInfo()
    {
        super.verInfo();
        System.out.println("Base: "+base);
        System.out.println("Altura: "+altura);
    }
}
