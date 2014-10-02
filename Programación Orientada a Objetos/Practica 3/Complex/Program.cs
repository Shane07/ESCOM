using System;

namespace SobreOperMasMenos
{
    class Program
    {
        static void Main(string[] args)
        {
            Complejo a = new Complejo(10, 12);
            Complejo b = new Complejo(8, 9);
            Console.WriteLine("Complejo a: ");
            a.imprimirComplejo();
            Console.WriteLine("Complejo b: ");
            b.imprimirComplejo();

            Console.WriteLine("Resultado suma: ");
            Complejo sum = a + b;
            sum.imprimirComplejo();

            Console.WriteLine("Resultado resta: ");
            Complejo resta = a - b;
            resta.imprimirComplejo();

            Console.ReadLine();
        }
    }
}
