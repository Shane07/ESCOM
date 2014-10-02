/**
 * @author Ortega Ortunio Eder - 2CV7
 */
public class Cubo extends Cuadrado
{
    private float volumen;
    
    public Cubo(float lado)
    {
        super(lado);
        this.nombre= "Cubo"; // Hereda el 'nombre' de la clase Figura previamente heredado por la clase Cuadrado
        this.lado = lado;
    }
    
    public float calcularVolumen()
    {
        return lado * super.calcularArea();
    }
    public float calcularArea() // Implementacion del metodo abstracto (override)
    {
        return 6 * super.calcularArea(); // Se obtiene la suma de las areas del cubo (6 caras)
    }
    public void verInfo() // Redefinicion del metodo abstracto (override)
    {
        super.verInfo();
        System.out.println("Lado: "+lado);
    }
}
