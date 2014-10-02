public abstract class Transporte implements Deducible
{
    protected float precio, montoSeguro;
    protected char modelo;
    protected String color;
    protected Asegurado propietario;
    protected boolean isCamion;
    
    public char getModelo()
    {
        return this.modelo;
    }
    public String getColor()
    {
        return this.color;
    }
    public float getPrecio()
    {
        return this.precio;
    }
    public void setModelo(char modelo)
    {
        this.modelo = modelo;
    }
    public void setColor(String color)
    {
        this.color = color;
    }
    public void setPrecio(float precio)
    {
        this.precio = precio;
    }
    public float calcularMontoSeguro()
    {
        float monto;
        
        if(propietario.getEdad() < 26)
            monto = this.precio + (this.precio * 0.25f);
        else if((propietario.getEdad() > 25 && propietario.getEdad() < 31) || (propietario.getEdad() > 65))
            monto = this.precio + (this.precio * 0.1f);
        else
            monto = this.precio;
        
        if(propietario.getLicencia() < 2)
            monto = monto + (monto *0.25f);
        
        return monto;
    }
}
