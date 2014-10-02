public class Principal
{
	public static void main(String args[])
	{
		Cuenta c1, c2, c3, c4;
		
		c1 = new Cuenta();
		// Consultar saldo
		c1.operacion();
		// Cambiar NIP
		if(c1.operacion("2075"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
		// Retirar efectivo
		if(c1.operacion(5200.0))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c1.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		// Imprimir información de la cuenta
		c1.imprimirInfo();
		
		c2 = new Cuenta(6987454, "4582", 22365.64, 4.32, "Roger Waters");
		// Consultar saldo
		c2.operacion();
		// Cambiar NIP
		if(c2.operacion("409688"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
		// Retirar efectivo
		if(c2.operacion(-58000.0))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c2.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		// Transferir dinero
		if(c2.operacion(c1, 10000.0))
			System.out.println("\tTransferencia exitosa");
		else
			System.out.println("\tError al intentar transferir");
		// Imprimir información de la cuenta
		c2.imprimirInfo();
		System.out.println("\tRetiro exitoso\n\tEl saldo actual de C1 ahora es de $"+c1.getSaldo());
		
		
		c3 = new Cuenta(6987455, "9697", 69874.32, 6.69, "Kim Dotnet");
		// Consultar saldo
		c3.operacion();
		// Cambiar NIP
		if(c3.operacion("9697"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
		// Retirar efectivo
		if(c3.operacion(190638.09))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c3.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		// Transferir dinero
		if(c3.operacion(c2, -0.1))
			System.out.println("\tTransferencia exitosa");
		else
			System.out.println("\tError al intentar transferir");
		// Imprimir información de la cuenta
		c3.imprimirInfo();
		
		c4 = new Cuenta(6987456, "0110", 666666.66, 8.69, "Jimmy Plagio");
		// Consultar saldo
		c4.operacion();
		// Cambiar NIP
		if(c4.operacion("0111"))
			System.out.println("\tNIP cambiado exitosamente");
		else
			System.out.println("\tError al intentar cambiar el NIP");
		// Retirar efectivo
		if(c4.operacion(0.0))
			System.out.println("\tRetiro exitoso\n\tEl saldo actual ahora es de $"+c4.getSaldo());
		else
			System.out.println("\tError en la transaccion");
		// Transferir dinero
		if(c4.operacion(c2, 0.0))
			System.out.println("\tTransferencia exitosa");
		else
			System.out.println("\tError al intentar transferir");
		// Imprimir información de la cuenta
		c4.imprimirInfo();
	}
}