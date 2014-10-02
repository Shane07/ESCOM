#include <stdio.h>
#include <stdlib.h>

int sSumas_itr(int v, int n)
{
    int a = n;
    if(n == 0 || v == 0)
        return 0;
    else
    {
    while(v > 1)
    {
        n = n + a;
        v--;
    }
    return n;
    }
}
int sSumas_rec(int v, int n)
{
    if(v == 0)
        return 0;
    else if(v == 1)
        return n;
    else
        return sSumas_rec(--v, n) + n;
}
int main()
{
    int o, c, veces, num;
    while(1)
    {
        printf("\t1. Serie de sumas iterativo\n\t2. Serie de sumas recursivo\n\t3. Salir\n\n\tOpcion: ");
        fflush(stdin);
        scanf("%d", &o);
        switch(o)
        {
            case 1:
                system("cls");
                fflush(stdin);
                printf("Veces: ");
                scanf("%d", &veces);
                fflush(stdin);
                printf("Numero: ");
                scanf("%d", &num);
                printf("%d x %d = %d\n", veces, num, sSumas_itr(veces, num));
                break;
            case 2:
                system("cls");
                fflush(stdin);
                printf("Veces: ");
                scanf("%d", &veces);
                fflush(stdin);
                printf("Numero: ");
                scanf("%d", &num);
                printf("%d x %d = %d", veces, num, sSumas_rec(veces, num));
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