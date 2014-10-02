#include <stdio.h>
#include <string.h>
#include "usePila.h"
#define MAX_SP 20

int detectOp(char *tk)
{
    if(*tk == 42 || *tk == 43 || *tk == 45)
        return 1;
    else if(*tk < 48 || *tk > 57)
    {
        printf("Error: caracter incorrecto\n");
        exit(-1);
    }
    else
        return 0;
}
void realizarOperacion(char datos[], Pila *nmz)
{
    char *tok = NULL;
    int tmp1, tmp2, r;
    tok = strtok(datos, " ");
    while(tok != NULL)
    {
        if(!detectOp(tok))
        {
            pushDin(nmz, atoi(tok));
        }
        else
        {
            if(*tok == 42)
            {
                popDin(nmz, &tmp1);
                popDin(nmz, &tmp2);
                pushDin(nmz, tmp1 * tmp2);
            }
            if(*tok == 43)
            {
                popDin(nmz, &tmp1);
                popDin(nmz, &tmp2);
                pushDin(nmz, tmp1 + tmp2);
            }
            if(*tok == 45)
            {
                popDin(nmz, &tmp1);
                popDin(nmz, &tmp2);
                tmp1 = tmp2 - tmp1;
                pushDin(nmz, tmp1);
            }
        }
        tok = strtok(NULL, " ");
    }
    popDin(nmz, &r);
    printf("\t\t%d", r);
}
int main()
{
    char *o;
    int t;
    Pila n;
    create(&n);
    printf("Tamanio del arreglo: ");
    scanf("%d", &t);
    o = (char *) malloc(t * sizeof(char));
    printf("Operacion a realizar: ");
    fflush(stdin);
    gets(o);
    realizarOperacion(o, &n);
    free(o);
    return 0;
}
