public class Triangulo
{
	// Atributos
	private double base, altura, area, perimetro, ladoA, ladoB, ladoC;
	private String tipoTriangulo = new String("");
	
	// Constructor
	public Triangulo()
	{
		base = 60.0;
		altura = 30.0;
		ladoA = ladoB = ladoC = 56.0;
		tipoTriangulo = "eq";
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	public Triangulo(double ht, double bs, double lA, double lC)
	{
		base = ladoB = bs;
		altura = ht;
		ladoA = lA;
		ladoC = lC;
		area = calcularArea();
		perimetro = calcularPerimetro();
		
		if(ladoA == ladoB && ladoA == ladoC && ladoB == ladoC)
			tipoTriangulo = "eq"; // Triángulo equilátero
		else if(ladoA != ladoB && ladoA != ladoC && ladoB != ladoC)
			tipoTriangulo = "es"; // Triángulo escaleno
		else
			tipoTriangulo = "is"; // Triángulo isósceles
	}
	
	// Métodos (get, set, ...)
	public double getBase()
	{
		return base;
	}
	public void setBase(double b)
	{
		base = ladoB = b;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	public double getAltura()
	{
		return altura;
	}
	public void setAltura(double h)
	{
		altura = h;
		area = calcularArea();
		perimetro = calcularPerimetro();
	}
	
	public double calcularPerimetro()
	{
		if(tipoTriangulo.equals("eq"))
			return ladoB * 3;
		else if(tipoTriangulo.equals("es"))
			return ladoA + ladoB + ladoC;
		else
			return 2 * ladoA + base;
	}
	public double calcularArea()
	{
		if(tipoTriangulo.equals("eq"))
			return ((ladoA * ladoA) * (java.lang.Math.sqrt(3.0) / 4));
		else
			return (base * altura) / 2;
	}
	public void imprimirInfo()
	{
		String tmp = new String("Triangulo ");
		System.out.println(tmp.concat(tipoTriangulo).concat(":\n\tBase = " + base + "\n\tAltura = " + altura + "\n\tPerimetro = " + perimetro + "\n\tArea = " + area));
	}
}
