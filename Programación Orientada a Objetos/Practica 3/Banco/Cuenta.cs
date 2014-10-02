using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo
{
    /*Definicion de la clase y atributos*/
    public class Cuenta
    {
        /*Atributos*/
        private long numero;
        private double saldo;
        private string titular;

        /*Constructor por omision y por parametros de la clase Cuenta*/
        public Cuenta()
        {
            numero = 123456789;
            saldo = 1500.0;
            titular = "Miriam Pescador";
        }
        public Cuenta(long n, double s, string t)
        {
            numero = n;
            saldo = s;
            titular = t;
        }

        /*Getters y Setters*/
        /*Segunda forma de definir getters y setters*/
        public long Numero
        {
            get { return numero; }
            set { numero = value; }
        }
        public double Saldo
        {
            get { return saldo; }
            set { saldo = value; }
        }
        public string Titular
        {
            get { return titular; }
            set { titular = value; }
        }

        /*Otros metodos de la clase*/
        public double consultarSaldo()
        {
            Console.WriteLine("Saldo = " + saldo);
            return saldo;
        }
        public bool retirar(double cantidad)
        {
            if (cantidad > 0 && cantidad <= saldo)
            {
                saldo -= cantidad;
                return true;
            }
            return false;
        }
        public void depositar(double cantidad)
        {
            saldo += cantidad;
        }

    }
}
