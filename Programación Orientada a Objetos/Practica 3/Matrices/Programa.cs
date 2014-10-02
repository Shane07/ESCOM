using System;

namespace Practica3
{
    class Programa
    {
        static void Main(string[] args)
        {
            int[,] a1 = { { 3, 4, 7 }, { 8, 1, 9 }, { 6, 2, 1 }, { 4, 5, 6 } }; // 4 cajas de 3 elementos c/u
            int[,] a2 = { { 7, 5, 2 }, { 1, 0, 1 }, { 9, 3, 7 }, { 4, 2, 9 } };
            int[,] a3 = { { 2, 3, 5 }, { 6, 1, 2 } }; // 2 cajas de 3 elementos c/u
            int[,] a4 = { { 4, 8, 4, 0 }, { 5, 4, 1, 1 }, { 6, 1, 1, 0} }; // 3 cajas de 4 elementos c/u

            Matriz m1 = new Matriz(a1);
            Matriz m2 = new Matriz(a2);
            Matriz m3 = new Matriz(a3);
            Matriz m4 = new Matriz(a4);

            Console.WriteLine("Suma de matrices:");
            if(m1.Filas == m2.Filas && m1.Columnas == m2.Columnas)
                (m1 + m2).printMatriz();
            else
                Console.WriteLine("\tError: no se pueden sumar las matrices\n");

            Console.WriteLine("Resta de matrices:");
            if (m1.Filas == m2.Filas && m1.Columnas == m2.Columnas)
                (m1 - m2).printMatriz();
            else
                Console.WriteLine("\tError: no se pueden restar las matrices\n");

            Console.WriteLine("Multiplicación de matrices:");
            if (m3.Columnas == m4.Filas)
                (m3 * m4).printMatriz();
            else
                Console.WriteLine("\tError: no se pueden multiplicar las matrices\n");

            Console.WriteLine("Matriz transpuesta (operador !):");
            (!m4).printMatriz();

            Console.WriteLine("Matriz transpuesta (operador ++):");
            (m4++).printMatriz();

            Console.ReadKey(); // Esperar a que se pulse una tecla
            Console.Beep();
        }
    }
}
