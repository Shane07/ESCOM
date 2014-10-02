/*
 * Descripcion: esta clase está relacionada con el manejo de cuentas bancarias
 * @author: Eder Ortega Ortuño - 2CV7
 */
public class Cuenta
{
	// Atributos
	private long numero;
	private double saldo, interesAnual;
	private String titular, nip;
	
	// Constructores
	/*
	 * Constructor por default
	 */
	public Cuenta()
	{
		numero = 666666666;
		saldo = 6666.66;
		interesAnual = 6.0;
		titular = new String("Usuario Default");
		nip = new String("6666");
	}
	/*
	 * Constructor por parámetros: círculo
	 * @param: num identificador
	 * @param: key NIP
	 * @param: sald saldo inicial
	 * @param: ia interés anual
	 * @param: t nombre del titular
	 */
	public Cuenta(int num, String key, double sald, double ia, String t)
	{
		numero = num;
		saldo = sald;
		interesAnual = ia;
		titular = new String(t);
		nip = new String(key);
	}
	
	// Métodos (set, get, etc.)
	public long getNumero()
	{
		return numero;
	}
	public void setNumero(int num)
	{
		numero = num;
	}
	public String getNip()
	{
		return nip;
	}
	public void setNip(String key)
	{
		nip = key;
	}
	public double getSaldo()
	{
		return saldo;
	}
	public void setSaldo(double sal)
	{
		saldo = sal;
	}
	public double getInteres()
	{
		return interesAnual;
	}
	public void setInteres(double i)
	{
		interesAnual = i;
	}
	public String getCliente()
	{
		return titular;
	}
	public void setCliente(String cl)
	{
		titular = cl;
	}
	
	// Retirar saldo
	public boolean operacion(double cnt)
	{
		if(cnt > 0)
		{
			if(cnt < saldo)
			{
				if(cnt % 50 == 0.0 || cnt % 100 == 0.0 || cnt % 200 == 0.0 || cnt % 500 == 0.0)
				{
					setSaldo(saldo - cnt);
					return true;
				}
				else
					return false; // La cantidad no es un múltiplo de 50, 100, 200, 500
			}
			else
				return false; // La cantidad es mayor o igual al saldo disponible
		}
		else
			return false; // La cantidad es menor o igual a cero
	}
	// Consultar saldo
	public void operacion()
	{
		System.out.println("\tSaldo disponible: $"+getSaldo());
		System.out.println();
	}
	// Cambiar NIP
	public boolean operacion(String nuevo)
	{
		if(nuevo.length() == 4 && !nuevo.equals(nip))
		{
			nip = nuevo;
			return true;
		}
		else
			return false; // Si el NIP no tiene 4 caracteres
	}
	// Transferencia de plata
	public boolean operacion(Cuenta dest, double cnt)
	{
		if(cnt <= this.saldo && cnt > 0.0) // this.saldo hace referencia al saldo de la cuenta origen
		{
			this.saldo -= cnt;
			dest.saldo += cnt;
			return true;
		}
		else
			return false;
	}
	public void imprimirInfo()
	{
		System.out.println("\tNumero ID: "+getNumero());
		System.out.println("\tCliente: "+getCliente());
		operacion();
		System.out.println("\tInteres anual: "+getInteres()+"%");
		System.out.println();
	}
}
