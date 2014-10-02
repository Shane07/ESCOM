#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usePila.h"
#define MAX_SP 20

int detectOp(char *tk)
{
    if(*tk == 42 || *tk == 43 || *tk == 45)
        return 1;
    else
        return 0;
}
void realizarOperacion(char datos[], Pi *nmz)
{
    char *tok = NULL;
    int tmp;
    tok = strtok(datos, " ");
    while(tok != NULL)
    {
        if(!detectOp(tok))
        {
            push(nmz, atoi(tok));
        }
        else
        {
            if(*tok == 42)
            {
                push(nmz, pop(nmz) * pop(nmz));
            }
            if(*tok == 43)
            {
                push(nmz, pop(nmz) + pop(nmz));
            }
            if(*tok == 45)
            {
                tmp = (pop(nmz) - pop(nmz));
                tmp = (-1) * tmp; // Invertir el signo de la resta realizada (se realiza en orden inverso debido al pop)
                push(nmz, tmp);
            }
        }
        tok = strtok(NULL, " ");
    }
    printf("\t\t%d", pop(nmz));
}
int main()
{
    char o[MAX_SP];
    Pi n;
    createPila(&n);
    printf("Operacion a realizar: ");
    fflush(stdin);
    gets(o);
    realizarOperacion(o, &n);
    return 0;
}
