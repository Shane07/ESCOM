public class Circulo
{
	// Atributos
	private double radio, area, perimetro;
	
	// Constructor
	public Circulo()
	{
		radio = 90.0;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	public Circulo(double radioo)
	{
		radio = radioo;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	
	// Métodos (get, set, ...)
	public double getRadio()
	{
		return radio;
	}
	public void setRadio(double rad)
	{
		radio = rad;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	
	public double calcularPerimetro()
	{
		return perimetro = java.lang.Math.PI * 2.0 * radio;
	}
	public double calcularArea()
	{
		return area = java.lang.Math.PI * radio * radio;
	}
	public void imprimirInfo()
	{
		System.out.println("Circulo:\n\tRadio = " + radio + "\n\tPerimetro = " + perimetro + "\n\tArea = " + area);
	}
}
