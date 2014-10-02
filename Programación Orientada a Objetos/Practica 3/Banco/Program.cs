using System;
using System.Collections.Generic;

namespace Ejemplo
{
    class Program
    {
        static void Main(string[] args)
        {
            Cuenta c1 = new Cuenta();
            Cuenta c2 = new Cuenta(764859, 8500.0, "Rodolfo Villa");

            Console.WriteLine("Consulta de saldos antes de los movimientos");
            c1.consultarSaldo();
            c2.consultarSaldo();

            c1.retirar(100.0);
            c2.retirar(2000.0);
            c1.depositar(780.0);
            c2.depositar(130.0);

            Console.WriteLine("Consulta de saldos despues de los movimientos");
            c1.consultarSaldo();
            c2.consultarSaldo();
            Console.ReadLine();
        }
    }
}
