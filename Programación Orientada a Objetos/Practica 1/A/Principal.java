public class Principal
{
	public static void main(String args[])
	{
		Cuadrado c1, c2, c3;
		Circulo k1, k2, k3;
		Triangulo t1, t2, t3;
		Separador sp = new Separador();
		
		// Cuadrados
		c1 = new Cuadrado(); // Valores default
		c2 = new Cuadrado(12.0); // Valores definidos
		c3 = new Cuadrado(); // Valores distintos
		System.out.println("Lado c3 = " + c3.getLado());
		c3.setLado(200.0);
		System.out.println("Lado c3 = " + c3.getLado());
		c1.imprimirInfo();
		c2.imprimirInfo();
		c3.imprimirInfo();
		
		sp.drawSeparador();

		// Círculos
		k1 = new Circulo(); // Valores default
		k2 = new Circulo(17.0); // Valores definidos
		k3 = new Circulo(); // Valores distintos
		System.out.println("Radio k3 = " + k3.getRadio());
		k3.setRadio(200.0);
		System.out.println("Radio k3 = " + k3.getRadio());
		k1.imprimirInfo();
		k2.imprimirInfo();
		k3.imprimirInfo();
		
		sp.drawSeparador();
		
		// Triángulos
		t1 = new Triangulo(); // Equilátero
		t2 = new Triangulo(5.0, 12.0, 22.0, 7.0); // Valores definidos
		t3 = new Triangulo(); // Valores distintos
		System.out.println("Base t3 = " + t3.getBase());
		t3.setBase(200.0);
		System.out.println("Base t3 = " + t3.getBase());
		t1.imprimirInfo();
		t2.imprimirInfo();
		t3.imprimirInfo();
	}
}
class Separador
{
	public Separador()
	{
		
	}
	public void drawSeparador()
	{
		System.out.println("\n----------------------------------------\n");
	}
}