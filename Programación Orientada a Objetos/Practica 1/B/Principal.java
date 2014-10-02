public class Principal
{
	public static void main(String args[])
	{
		Separador s = new Separador();
		Cuenta c1, c2, c3;
		
		c1 = new Cuenta();
		c1.imprimirInfo();
		c1.depositar(200.0);
		c1.imprimirInfo();
		if(c1.retirarSaldo(550.0))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c1.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		if(c1.cambiarNip("2048"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
		
		s.drawSeparador();
		
		c2 = new Cuenta();
		c2.setCliente("Roger Waters");
		c2.setNumero(666666667);
		c2.setInteres(6.66);
		c2.setSaldo(6000.0);
		c2.setNip("6666");
		c2.imprimirInfo();
		if(c2.retirarSaldo(9632.35))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c2.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		if(c2.cambiarNip("2048899918"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
		
		s.drawSeparador();
		
		c3 = new Cuenta(6987455, "9697", 69874.32, 6.69, "Kim Dotnet");
		c3.imprimirInfo();
		if(c3.retirarSaldo(-60000.0))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c3.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		if(c3.cambiarNip("69874"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
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