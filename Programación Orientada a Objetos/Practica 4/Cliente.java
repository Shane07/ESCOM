package com.multiaportes.practica4POO;

import java.util.GregorianCalendar;
import java.util.Date;
import java.text.DateFormat;

/**
 * @author Ortega Ortunio Eder - 2CV7
 */

public class Cliente
{
    // Atributos
    private String nombreCliente, paternCliente, maternCliente, direccion;
    private GregorianCalendar fechaNacimiento;
    private Date fNac;
    private DateFormat fN;
    
    
    // Constructor
    public Cliente(String nombreCliente, String paternCliente, String maternCliente, String direccion, GregorianCalendar fechaNacimiento)
    {
        this.nombreCliente = nombreCliente;
        this.paternCliente = paternCliente;
        this.maternCliente = maternCliente;
        this.direccion = direccion;  
        this.fechaNacimiento = fechaNacimiento;
        this.fNac = this.fechaNacimiento.getTime(); // Obtener la fecha gregoriana
        this.fN = DateFormat.getDateInstance(); // Dar formato a la fecha de acuerdo a la configuración regional del sistema
    }
    
    // Metodos
    public String getNombre()
    {
    	return nombreCliente+" "+paternCliente;
    }
    public void printInfoCliente()
    {
    	System.out.println("Informacion del cliente:");
    	System.out.println("\tNombre: "+nombreCliente+" "+paternCliente+" "+maternCliente);
    	System.out.println("\tDireccion: "+direccion);
    	System.out.println("\tEdad: "+getEdad());
    	System.out.println("\tFecha de nacimiento: "+fN.format(fNac));
    }
    public int getEdad()
    {
    	return new GregorianCalendar().get(GregorianCalendar.YEAR) - fechaNacimiento.get(GregorianCalendar.YEAR); //GregorianCalendar() sin parametros establece la fecha actual en la que es creado
    }
}