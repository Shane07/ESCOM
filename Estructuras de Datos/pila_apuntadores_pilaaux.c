#include <stdio.h>
#include <stdlib.h>
#include "usePila.h"
void createPila(Pi *pila)
{
    pila->c = -1; // La flecha se usa solamente en un puntero a estructura, caso contrario usar estruct.var = algo;
}
int main(void)
{
    Pi pA, pB;
    int o, v, ck;
    char w, e;
    createPila(&pA);
    createPila(&pB);
    do
    {
        system("cls");
        printf("\n\t1. Agregar valor\n\t2. Quitar valor\n\t3. Tamanio pilas\n\t4. Imprimir valores\n\t5. Salir\n\nOpcion: ");
        fflush(stdin);
        scanf("%d", &o);
        switch(o)
        {
            case 1:
                do
                {
                    system("cls");
                    printf("Introduce el valor: ");
                    fflush(stdin);
                    scanf("%d", &v);
                    push(&pA, v);
                    push(&pB, v);
                    printf("Agregar otro valor? s/n: ");
                    fflush(stdin);
                    scanf("%c", &w);
                }
                while(w == 's');
                break;
            case 2:
                do
                {
                    system("cls");
                    pop(&pB);
                    printf("Valor eliminado.\nEliminar otro valor? s/n: ");
                    fflush(stdin);
                    scanf("%c", &e);
                }
                while(e == 's');
                break;
            case 3:
                system("cls");
                printf("La pila principal contiene %d elementos.\n", pilaSize(&pA));
                printf("La pila auxiliar contiene %d elementos.", pilaSize(&pB));
                system("pause>nul");
                break;
            case 4:
                system("cls");
                printf("Pila principal\n");
                for(ck = pilaSize(&pA)-1; ck >= 0; ck--)
                {
                    printf("\tpA[%d] = %d\n", ck,  pA.nums[ck]);
                }
                printf("Pila auxiliar\n");
                for(ck = pilaSize(&pB)-1; ck >= 0; ck--)
                {
                    printf("\tpB[%d] = %d\n", ck,  pB.nums[ck]);
                }
                system("pause>nul");
                break;
            case 5:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }
    while(o <= 5);
    return 0;
}
