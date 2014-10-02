#include <stdio.h>
#include <stdlib.h>

double sFibonacci_itr(double f)
{
    double a = 1, b = 0, x = 0, c;
    while(x <= f)
    {
        c = a + b;
        b = a;
        a = c;
        x++;
    }
    return c;
}
double sFibonacci_rec(double f)
{
    if(f == 0)
        return 0;
    else if(f == 1)
        return 1;
    else
        return sFibonacci_rec(f-1) + sFibonacci_rec(f-2);
}
int main()
{
    int o, c;
    double num;
    while(1)
    {
        printf("\t1. Fibonacci iterativo\n\t2. Fibonacci recursivo\n\t3. Imprimir toda la serie\n\t4. Salir\n\n\tOpcion: ");
        fflush(stdin);
        scanf("%d", &o);
        switch(o)
        {
            case 1:
                system("cls");
                fflush(stdin);
                printf("Numero: ");
                scanf("%lf", &num);
                printf("Resultado: %.0f", sFibonacci_itr(num));
                break;
            case 2:
                system("cls");
                fflush(stdin);
                printf("Numero: ");
                scanf("%lf", &num);
                printf("Resultado: %.0f", sFibonacci_rec(num));
                break;
            case 3:
                system("cls");
                fflush(stdin);
                printf("Numero: ");
                scanf("%lf", &num);
                for(c = (int) num; c >= 0; c--)
                    printf("%.0f\n", sFibonacci_rec(c));
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
        system("pause>nul");
        system("cls");
    }
    return 0;
}
