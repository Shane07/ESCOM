package com.multiaportes.practica4POO;

import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.Date;
import java.text.DateFormat;

/**
 * @author Ortega Ortunio Eder - 2CV7
 */

public class Cuenta
{
    // Atributos
    private Cliente titular;
    private ArrayList<MovimientoBanc> listaMovimientos = new ArrayList<MovimientoBanc>(); // Arraylist <tipo de dato que se almacenara en la lista> (opcional)
    private int id;
    private double saldoTit;
    private GregorianCalendar fechaVencimiento;
    private Date fVenc;
    private DateFormat fV;
    
    // Constructores
    public Cuenta(int id, double saldoTit, GregorianCalendar fechaVencimiento, Cliente titular)
    {
        this.id = id; // 'this' hace referencia a la var privada 'id' de la clase Cuenta
        this.saldoTit = saldoTit;
        this.fechaVencimiento = fechaVencimiento;
        this.fVenc = this.fechaVencimiento.getTime();
        this.fV = DateFormat.getDateInstance();
        this.titular = titular;
    }
    
    // Metodos que el cliente puede realizar
    public double consultarSaldo(GregorianCalendar z)
    {
    	registrarMovimiento(z, "consulta de saldo", saldoTit, 0.0, saldoTit);
    	return saldoTit;
    }
    public boolean retirar(double cnt, GregorianCalendar z)
    {
    	if(cnt > 0)
		{
			if(cnt < saldoTit)
			{
				if(cnt % 50 == 0.0 || cnt % 100 == 0.0 || cnt % 200 == 0.0 || cnt % 500 == 0.0)
				{
					registrarMovimiento(z, "retiro", saldoTit, cnt, saldoTit-cnt);
					saldoTit = saldoTit - cnt;
					return true;
				}
				else
					return false; // La cantidad no es un multiplo de 50, 100, 200, 500
			}
			else
				return false; // La cantidad es mayor o igual al saldo disponible
		}
		else
			return false; // La cantidad es menor o igual a cero
    }
    public void depositar(double cnt, GregorianCalendar z)
    {
    	registrarMovimiento(z, "deposito", saldoTit, cnt, saldoTit+cnt);
        saldoTit += cnt;
    }
    public void transferir(double cnt, Cuenta destino, GregorianCalendar z)
    {   	
    	registrarMovimiento(z, "transferencia bancaria a "+destino.titular.getNombre(), this.saldoTit, cnt, this.saldoTit-cnt);
    	destino.depositar(cnt, z);
    	this.saldoTit -= cnt;
    }
    public void printMovimientos()
    {
        for(int k = 0; k < listaMovimientos.size(); k++)
        {
        	System.out.println("Movimiento no. "+(k+1));
        	listaMovimientos.get(k).viewInfoMov();
        }
    }
    public void printInfoCuenta()
    {
        System.out.println("Informacion de la cuenta:");
    	System.out.println("\tID: "+id);
    	System.out.println("\tSaldo: "+saldoTit);
    	System.out.println("\tFecha de vencimiento: "+fV.format(fVenc));
    }
    // Metodos exclusivos del sistema bancario
    private void registrarMovimiento(GregorianCalendar fch, String tpo, double sIn, double imp, double nS)
    {
        MovimientoBanc mov = new MovimientoBanc(fch, tpo, sIn, imp, nS);
        listaMovimientos.add(mov);
    }
    
    // Clases embebidas
    private class MovimientoBanc
    {
    	// Atributos
    	private GregorianCalendar fechaMov;
    	private Date fMov;
    	private DateFormat fM;
    	private String tipoMov;
    	private double saldoIn, importe, nuevoSaldo;
    	
    	// Constructor
    	public MovimientoBanc(GregorianCalendar fechaMov, String tipoMov, double saldoIn, double importe, double nuevoSaldo)
    	{
    		this.fechaMov = fechaMov;
    		this.fMov = this.fechaMov.getTime();
            this.fM = DateFormat.getDateInstance();
    		this.tipoMov = tipoMov;
    		this.saldoIn = saldoIn;
    		this.importe = importe;
    		this.nuevoSaldo = nuevoSaldo;
    	}
    	
    	// Metodos
    	public void viewInfoMov()
    	{
    		System.out.println("\tFecha de movimiento: "+fM.format(fMov));
    		System.out.println("\tMovimiento realizado: "+tipoMov);
    		System.out.println("\tSaldo inicial: "+saldoIn);
    		System.out.println("\tImporte: "+importe);
    		System.out.println("\tSaldo restante: "+nuevoSaldo);
    	}
    }
   }