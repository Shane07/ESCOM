using System;
using System.Collections.Generic;

namespace SobreOperMasMenos
{
    /*Definicion de la clase y atributos*/
    public class Complejo
    {
        private int real;
        private int imag;
    
        /*Constructor  por omision y por paramtros de la clase Complejo*/
        public Complejo()
        {
            real = 0;
            imag = 0;
        }
        public Complejo(int r, int i)
        {
            real = r;
            imag = i;
        }
        //Sobrecarga operador +:
        public static Complejo operator +(Complejo a, Complejo b)
        {
            Complejo c;
            int x, y;
            x = a.real + b.real;
            y = a.imag + b.imag;
            c = new Complejo(x, y);
            return c;
        }
        //Sobrecarga operador -:
        public static Complejo operator -(Complejo a, Complejo b)
        {
            Complejo c;
            int x, y;
            x = a.real - b.real;
            y = a.imag - b.imag;
            c = new Complejo(x, y);
            return c;
        }
        //Imprimir Complejo
        public void imprimirComplejo()
        {
            Console.WriteLine("real: " + real + " imag: " + imag);
        }  

    }
}
