/*
 * Descripcion: esta clase permite trabajar con figuras
 * @author: Eder Ortega Ortuño - 2CV7
 */

public class Figura
{
	// Atributos
	private String nombre;
	private double area, perimetro;
	
	// Constructores
	/*
	 * Constructor por default
	 */
	public Figura()
	{
		nombre = "";
		area = perimetro = 0.0;
	}
	/*
	 * Constructor por parámetros: círculo
	 * @param: p1 punto central
	 * @param: radio radio del círculo
	 */
	public Figura(Punto p1, double radio)
	{
		nombre = "circulo";
		area = Math.PI * radio * radio;
		perimetro = 2.0 * Math.PI * radio;
	}
	
	/*
	 * Constructor por parámetros: rectángulo
	 * @param: p1 punto 1
	 * @param: p2 punto 2
	 */
	public Figura(Punto p1, Punto p2)
	{
		double base, halt;
		nombre = "rectangulo";
		
		base = p2.getX() - p1.getX();
		halt = p2.getY() - p1.getY();
		
		area = base * halt;
		perimetro = (2.0 * base) + (2.0 * halt);
	}
	
	/*
	 * Constructor por parámetros: triángulo
	 * @param: p1 punto 1
	 * @param: p2 punto 2
	 * @param: p3 punto 3
	 */
	public Figura(Punto p1, Punto p2, Punto p3)
	{
		double a, b, c;
		nombre = "triangulo";
		
		a = calcularDistancia(p1, p2);
		b = calcularDistancia(p2, p3);
		c = calcularDistancia(p1, p3);
		
		perimetro = a + b + c;
		area = calcularArea(a, b, c, calcularSemiperimetro(a, b, c));
	}
	
	// Métodos (set, get, etc.)
	private double calcularDistancia(Punto uno, Punto dos)
	{
		return Math.sqrt(Math.pow((dos.getX() - uno.getX()), 2) + Math.pow((dos.getY() - uno.getY()), 2));
	}
	private double calcularSemiperimetro(double a, double b, double c)
	{
		return (a + b + c) / 2;
	}
	private double calcularArea(double a, double b, double c, double p)
	{
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}
	public void printInfo()
	{
		if(nombre.isEmpty())
			System.out.println("Figura no valida");
		else
		{
			System.out.println("Perimetro del " + nombre + " = " + perimetro);
			System.out.println("Area del " + nombre + " = " + area);
		}
		System.out.println();
	}
}