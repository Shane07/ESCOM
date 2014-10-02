package com.multiaportes.practica4POO;

import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 * @author Ortega Ortunio Eder - 2CV7
 */

public class Principal 
{
    public static void main(String[] args)
    {
    	Cliente maur = new Cliente("Mauricio", "Jimenez", "Garcia", "Saltillo 136, Lomas de Chapultepec", new GregorianCalendar(1989, GregorianCalendar.JANUARY, 27));
    	Cliente and = new Cliente("Andrea", "Perez", "Suarez", "Av. Lindavista s/n, Torres Lindavista", new GregorianCalendar(1992, GregorianCalendar.AUGUST, 12));
    	Cliente jos = new Cliente("Jose", "Manuel", "Marquez", "Calle 5 No. 17, Coyoacan", new GregorianCalendar(1972, GregorianCalendar.NOVEMBER, 22));
    	
    	Cuenta m1 = new Cuenta(21545612, 145622.5, new GregorianCalendar(2014, GregorianCalendar.DECEMBER, 5), maur);
        Cuenta m2 = new Cuenta(6512629, 5000.0, new GregorianCalendar(2020, GregorianCalendar.AUGUST, 15), maur);
        Cuenta a1 = new Cuenta(63555655, 61252.8, new GregorianCalendar(2018, GregorianCalendar.JUNE, 6), and);
        Cuenta a2 = new Cuenta(4121852, 58600.0, new GregorianCalendar(2017, GregorianCalendar.APRIL, 3), and);
        Cuenta j1 = new Cuenta(1265655, 12352.8, new GregorianCalendar(2016, GregorianCalendar.AUGUST, 8), jos);
        Cuenta j2 = new Cuenta(1541512, 56022.8, new GregorianCalendar(2017, GregorianCalendar.OCTOBER, 10), jos);
        Cuenta j3 = new Cuenta(123151561, 125236.8, new GregorianCalendar(2014, GregorianCalendar.SEPTEMBER, 15), jos);
        
    	Scanner readFromTeclado = new Scanner(System.in);
    	Scanner tmp = new Scanner(System.in);
    	int opcionTeclado = 0;
    	
    	System.out.println("#### Sistema bancario ###\n");
    	System.out.println("\t1. Tabular datos predefinidos en la practica");
    	System.out.println("\t2. Trabajar con un cliente");
    	System.out.println("\t3. Salir");
    	System.out.printf("\nIntroduce una opcion: ");
    	
    	do
    	{
    		opcionTeclado = readFromTeclado.nextInt();
    		
	    	if(opcionTeclado == 1)
	    	{
    	        maur.printInfoCliente();
    	        m1.printInfoCuenta();
    	        m1.retirar(1500.00, new GregorianCalendar(2013, GregorianCalendar.AUGUST, 10));
    	        m1.depositar(400.5, new GregorianCalendar(2013, GregorianCalendar.SEPTEMBER, 12));
    	        m1.consultarSaldo(new GregorianCalendar(2013, GregorianCalendar.SEPTEMBER, 13));
    	        m1.printMovimientos();
    	        m2.printInfoCuenta();
    	        m2.retirar(200.0, new GregorianCalendar(2013, GregorianCalendar.AUGUST, 8));
    	        m2.printMovimientos();
    	        
    	        System.out.println("-------------------------------------------------------");
    	        
    	        and.printInfoCliente();
    	        a1.printInfoCuenta();
    	        a1.retirar(1500.00, new GregorianCalendar(2013, GregorianCalendar.AUGUST, 10));
    	        a1.transferir(400.5, a2, new GregorianCalendar(2013, GregorianCalendar.SEPTEMBER, 12));
    	        a1.consultarSaldo(new GregorianCalendar(2013, GregorianCalendar.SEPTEMBER, 13));
    	        a1.printMovimientos();
    	        a2.printInfoCuenta();
    	        a2.retirar(200.0, new GregorianCalendar(2013, GregorianCalendar.JANUARY, 18));
    	        a2.retirar(980.0, new GregorianCalendar(2013, GregorianCalendar.JANUARY, 18)); // No se puede retirar esa cantidad por las condiciones del banco (solo se pueden retirar multiplos de 50, 100, 200, 500)
    	        a2.transferir(350.6, a1, new GregorianCalendar(2013, GregorianCalendar.JANUARY, 18));
    	        a2.printMovimientos();
    	        a1.printInfoCuenta();
    	        a2.printInfoCuenta();
    	        
    	        System.out.println("-------------------------------------------------------");
    	        
    	        jos.printInfoCliente();
    	        j1.printInfoCuenta();
    	        j1.consultarSaldo(new GregorianCalendar(2013, GregorianCalendar.JULY, 3));
    	        j1.printMovimientos();
    	        j2.printInfoCuenta();
    	        j2.retirar(500.0, new GregorianCalendar(2013, GregorianCalendar.MAY, 14));
    	        j2.depositar(1250.5, new GregorianCalendar(2013, GregorianCalendar.SEPTEMBER, 11));
    	        j2.printMovimientos();
    	        j3.printInfoCuenta();
    	        j3.depositar(1500.0, new GregorianCalendar(2013, GregorianCalendar.APRIL, 3));
    	        j3.retirar(4025.5, new GregorianCalendar(2013, GregorianCalendar.JUNE, 5)); // Este movimiento tampoco se registra por la condicion anterior
    	        j3.printMovimientos();
    	        
    	        opcionTeclado = 0;
	    	}
	    	else if(opcionTeclado == 2)
	    	{
	    		double op;
	    		
	    		System.out.printf("Cantidad a depositar a la cuenta 1 de Andrea: ");
	    		op = tmp.nextDouble();
	    		a1.depositar(op, new GregorianCalendar());
	    		System.out.printf("Cantidad a retirar de la cuenta 3 de Jose: ");
	    		op = tmp.nextDouble();
	    		j3.depositar(op, new GregorianCalendar());
	    		System.out.printf("Cantidad a transferir de la cuenta 2 de Mauricio a la cuenta 2 de Jose: ");
	    		op = tmp.nextDouble();
	    		m2.transferir(op, j2, new GregorianCalendar());
	    		
	    		System.out.println("Operacion 1");
	    		a1.printMovimientos();
	    		System.out.println("Operacion 2");
	    		j3.printMovimientos();
	    		System.out.println("Operacion 3");
	    		m2.printMovimientos();
	    		j2.printMovimientos();
	    		
	    		opcionTeclado = 0;
	    	}
	    	else if(opcionTeclado == 3)
	    	{
	    		tmp.close();
	    		readFromTeclado.close();
	    		System.exit(0);
	    	}
	    	else
	    		opcionTeclado = 0;
    	}
    	while(opcionTeclado == 0);
    }
}
