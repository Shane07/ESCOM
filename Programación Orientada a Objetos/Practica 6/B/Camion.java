public class Camion extends Transporte
{
    private String permiso;
    
    public Camion(String n, int a, int l, char modelo, String color, float precio, String permiso)
    {
        propietario = new Asegurado(n, a, l);
        this.modelo = modelo;
        this.color = color;
        this.precio = precio;
        this.permiso = permiso;
        this.montoSeguro = calcularMontoSeguro();
        this.isCamion = true;
    }
    public String getPermiso()
    {
        return this.permiso;
    }
    public void setPermiso(String permiso)
    {
        this.permiso = permiso;
    }
    public float calcularDeducible()
    {
        return precio * publico;
    }
}
