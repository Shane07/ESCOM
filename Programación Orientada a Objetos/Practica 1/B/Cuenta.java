public class Cuenta
{
	private long numero;
	private double saldo, interesAnual;
	private String titular, nip;
	
	public Cuenta()
	{
		numero = 666666666;
		saldo = 666.66;
		interesAnual = 6.0;
		titular = new String("Usuario Default");
		nip = new String("6666");
	}
	public Cuenta(int num, String key, double sald, double ia, String t)
	{
		numero = num;
		saldo = sald;
		interesAnual = ia;
		titular = new String(t);
		nip = new String(key);
	}
	
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
	
	public void depositar(double cnt)
	{
		saldo += cnt;
	}
	public boolean retirarSaldo(double cnt)
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
	public void consultarSaldo()
	{
		System.out.println("\tSaldo disponible: $"+getSaldo());
	}
	public boolean cambiarNip(String nuevo)
	{
		if(nuevo.length() == 4 && !nuevo.equals(nip))
		{
			nip = nuevo;
			return true;
		}
		else
			return false; // Si el NIP no tiene 4 caracteres
	}
	public void imprimirInfo()
	{
		System.out.println("\tNumero ID: "+getNumero());
		System.out.println("\tCliente: "+getCliente());
		consultarSaldo();
		System.out.println("\tInteres anual: "+getInteres()+"%");
	}
}
