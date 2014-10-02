/**
 * @author Ortega Ortunio Eder - 2CV7
 */
import java.util.Scanner;
import java.lang.Object;

public class Principal
{
    public static void main(String[] args)
    {
        int opcion;
        
        Scanner read = new Scanner(System.in);
        Circulo s1 = new Circulo(25.6f);
        Cuadrado c1 = new Cuadrado(7.3f);
        Cubo q1 = new Cubo(7.3f);
        Rectangulo r1 = new Rectangulo(9.99f, 8.45f);
        
        System.out.println("\t1. Circulo");
        System.out.println("\t2. Cuadrado");
        System.out.println("\t3. Cubo");
        System.out.println("\t4. Rectangulo");
        System.out.println();
        
        while(true)
        {
            System.out.print("Opcion: ");
            opcion = read.nextInt();
            if(opcion == 1)
            {
                menu(s1);
                break;
            }
            else if(opcion == 2)
            {
                menu(c1);
                break;
            }
            else if(opcion == 3)
            {
                menu(q1);
                break;
            }
            else if(opcion == 4)
            {
                menu(r1);
                break;
            }
            else
                continue;
        }
    }
    
    static void menu(Circulo obj)
    {
        Scanner rd = new Scanner(System.in);
        int opc;
        
        System.out.println("\t1. Calcular area");
        System.out.println("\t2. Calcular perimetro");
        System.out.println();
        
        while(true)
        {
            System.out.print("Opcion: ");
            opc = rd.nextInt();
            if(opc == 1)
            {
                System.out.println("El area es: "+obj.calcularArea());
                break;
            }
            else if(opc == 2)
            {
                System.out.println("El perimetro es: "+obj.calcularPerimetro());
                break;
            }
            else
                continue;
        }
    }
    static void menu(Cuadrado obj)
    {
        Scanner rd = new Scanner(System.in);
        int opc;
        
        System.out.println("\t1. Calcular area");
        System.out.println("\t2. Calcular perimetro");
        System.out.println();
        
        while(true)
        {
            System.out.print("Opcion: ");
            opc = rd.nextInt();
            if(opc == 1)
            {
                System.out.println("El area es: "+obj.calcularArea());
                break;
            }
            else if(opc == 2)
            {
                System.out.println("El perimetro es: "+obj.calcularPerimetro());
                break;
            }
            else
                continue;
        }
    }
    static void menu(Cubo obj)
    {
        Scanner rd = new Scanner(System.in);
        int opc;
        
        System.out.println("\t1. Calcular area");
        System.out.println("\t2. Calcular volumen");
        System.out.println();
        
        while(true)
        {
            System.out.print("Opcion: ");
            opc = rd.nextInt();
            if(opc == 1)
            {
                System.out.println("El area es: "+obj.calcularArea());
                break;
            }
            else if(opc == 2)
            {
                System.out.println("El volumen es: "+obj.calcularVolumen());
                break;
            }
            else
                continue;
        }
    }
    static void menu(Rectangulo obj)
    {
        Scanner rd = new Scanner(System.in);
        int opc;
        
        System.out.println("\t1. Calcular area");
        System.out.println("\t2. Calcular perimetro");
        System.out.println();
        
        while(true)
        {
            System.out.print("Opcion: ");
            opc = rd.nextInt();
            if(opc == 1)
            {
                System.out.println("El area es: "+obj.calcularArea());
                break;
            }
            else if(opc == 2)
            {
                System.out.println("El perimetro es: "+obj.calcularPerimetro());
                break;
            }
            else
                continue;
        }
    }
}
