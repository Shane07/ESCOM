/**
 * @author Ortega Ortunio Eder - 2CV7
 */
public class Cuadrado extends Figura
{
    protected float lado;
    
    public Cuadrado(float lado)
    {
        super("Cuadrado"); // Llamando al constructor de la clase padre
        this.lado = lado;
        area = calcularArea();
        perimetro = calcularPerimetro();
    }
    
    public float calcularArea() // Implementacion del metodo abstracto (override)
    {
        return lado * lado;
    }
    public float calcularPerimetro() // Implementacion del metodo abstracto (override)
    {
        return lado * 4;
    }
    public void verInfo() // Redefinicion del metodo abstracto (override)
    {
        super.verInfo();
        System.out.println("Lado: "+lado);
    }
}
