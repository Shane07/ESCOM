public class Cuadrado
{
	// Atributos
	private double lado, area, perimetro;
	
	// Constructor
	public Cuadrado()
	{
		lado = 10.0;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	public Cuadrado(double ladoo)
	{
		lado = ladoo;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	
	// Métodos (get, set, ...)
	public double getLado()
	{
		return lado;
	}
	public void setLado(double la)
	{
		lado = la;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	
	public double calcularPerimetro()
	{
		return perimetro = lado * 4.0;
	}
	public double calcularArea()
	{
		return area = lado * lado;
	}
	public void imprimirInfo()
	{
		System.out.println("Cuadrado:\n\tLado = " + lado + "\n\tPerimetro = " + perimetro + "\n\tArea = " + area);
	}
}
