#include <stdio.h>
#include <stdlib.h>

int sMultip_itr(int n, int p)
{
    int a = n;
    if(p == 0)
        return 1;
    else
    {
    while(p > 1)
    {
        n = n * a;
        p--;
    }
    return n;
    }
}
int sMultip_rec(int n, int p)
{
    if(p == 0 || n == 1)
        return 1;
    else if(p == 1)
        return n;
    else
        return sMultip_rec(n, --p) * n;
}
int main()
{
    int o, c, num, potencia;
    while(1)
    {
        printf("\t1. Serie de multiplicaciones iterativo\n\t2. Serie de multiplicaciones recursivo\n\t3. Salir\n\n\tOpcion: ");
        fflush(stdin);
        scanf("%d", &o);
        switch(o)
        {
            case 1:
                system("cls");
                fflush(stdin);
                printf("Numero: ");
                scanf("%d", &num);
                fflush(stdin);
                printf("Potencia: ");
                scanf("%d", &potencia);
                printf("%d ^ %d = %d\n", num, potencia, sMultip_itr(num, potencia));
                break;
            case 2:
                system("cls");
                fflush(stdin);
                printf("Numero: ");
                scanf("%d", &num);
                fflush(stdin);
                printf("Potencia: ");
                scanf("%d", &potencia);
                printf("%d ^ %d = %d\n", num, potencia, sMultip_rec(num, potencia));
                break;
            case 3:
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