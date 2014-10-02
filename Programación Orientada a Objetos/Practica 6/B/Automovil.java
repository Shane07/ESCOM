public class Automovil extends Transporte
{
    private int numPuertas;
    
    public Automovil(String n, int a, int l, char modelo, String color, float precio, int numPuertas)
    {
        propietario = new Asegurado(n, a, l);
        this.modelo = modelo;
        this.color = color;
        this.precio = precio;
        this.numPuertas = numPuertas;
        this.montoSeguro = calcularMontoSeguro();
        this.isCamion = false;
    }
    public int getPuertas()
    {
        return this.numPuertas;
    }
    public void setPuertas(int numPuertas)
    {
        this.numPuertas = numPuertas;
    }
    public float calcularDeducible()
    {
        return precio * particular;
    }
}
