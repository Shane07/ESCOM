using System;

namespace Practica3
{
    class Matriz
    {
        // No son necesarias las variables estáticas int para filas y columnas

        // Atributos
        private int[,] array;
        private int filaz, columnaz;

        // Constructores
        public Matriz(int fl, int cl)
        {
            filaz = fl;
            columnaz = cl;
            array = new int[filaz, columnaz];
        }
        public Matriz(int[,] nums)
        {
            filaz = nums.GetLength(0); // Dimension 0 -> Filas (cantidad de arreglos unidimensionales (cajas))
            columnaz = nums.GetLength(1); // Dimension 1 -> Columnas (cantidad de elementos de cada arreglo unidimensional (sodas))
            array = nums; // Igualando el contenido de las matrices
        }

        // Métodos Set-Get
        public int Filas
        {
            get
            {
                return filaz;
            }
            set
            {
                filaz = value;
            }
        }
        public int Columnas
        {
            get
            {
                return columnaz;
            }
            set
            {
                columnaz = value;
            }
        }

        // Métodos generales
        public void printMatriz()
        {
            int x, y;
            for (y = 0; y < filaz; y++)
            {
                for (x = 0; x < columnaz; x++)
                    Console.Write(array[y, x] + "\t"); // Print caja M: elemento N
                Console.WriteLine();
            }
        }

        // Sobrecarga de operadores (Suma, resta, multiplicación y matriz transpuesta)
        public static Matriz operator +(Matriz a, Matriz b)
        {
            int x, y;
            Matriz r = new Matriz(a.filaz, a.columnaz);

            for (y = 0; y < a.filaz; y++)
                for (x = 0; x < a.columnaz; x++)
                    r.array[y, x] = a.array[y, x] + b.array[y, x];
            return r;
        }
        public static Matriz operator -(Matriz a, Matriz b)
        {
            int x, y;
            Matriz r = new Matriz(a.filaz, a.columnaz);

            for (y = 0; y < a.filaz; y++)
                for (x = 0; x < a.columnaz; x++)
                    r.array[y, x] = a.array[y, x] - b.array[y, x];
            return r;
        }
        public static Matriz operator *(Matriz a, Matriz b)
        {
            // A[m x n] * B [n x p] = R [m x p]
            int suma = 0, mult = 0, w, x, y;
            Matriz r = new Matriz(a.filaz, b.columnaz);

            for (w = 0; w < a.Filas; w++)
            {
                for (x = 0; x < b.Columnas; x++)
                {
                    suma = 0;
                    for (y = 0; y < b.Filas; y++)
                    {
                        mult = a.array[w, y] * b.array[y, x];
                        suma = mult + suma;
                    }
                    r.array[w, x] = suma;
                }
            }
            return r;
        }
        public static Matriz operator !(Matriz a)
        {
            int x, y;
            Matriz r = new Matriz(a.columnaz, a.filaz);

            for (y = 0; y < a.filaz; y++)
            {
                for (x = 0; x < a.columnaz; x++)
                    r.array[x, y] = a.array[y, x];
            }
            return r;
        }
        public static Matriz operator ++(Matriz a)
        {
            int x, y;
            Matriz r = new Matriz(a.columnaz, a.filaz);

            for (y = 0; y < a.filaz; y++)
            {
                for (x = 0; x < a.columnaz; x++)
                    r.array[x, y] = a.array[y, x];
            }
            return r;
        }
    }
}
