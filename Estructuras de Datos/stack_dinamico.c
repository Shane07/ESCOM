#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *next;
} Nodo;

typedef struct Pila
{
    Nodo *tope;
} Pila;

void create(Pila *p)
{
    p->tope = NULL;
}
Nodo* hacerNodo(int val)
{
    Nodo *n;
    n = (Nodo *) malloc(sizeof(Nodo));
    if(n == NULL)
    {
        printf("\tError: no se pudo asignar memoria\n");
    }
    else
    {
        n->info = val;
        n->next = NULL;
    }
    return n;
}
int isEmpty(Pila *p)
{
    return p->tope == NULL;
}
void top(Pila *p)
{
    if(isEmpty(p))
    {
        printf("\tError: Pila vacia\n");
    }
    else
    {
        printf("TOP: %d\n", p->tope->info);
    }
}
void push(Pila *p, int dato)
{
    Nodo *n;
    n = hacerNodo(dato);
    n->next = p->tope;
    p->tope = n;
    n = NULL;
}
void pop(Pila *p, int *val)
{
    Nodo *aux;
    if(isEmpty(p))
    {
        printf("\tError: Pila vacia\n");
    }
    else
    {
        aux = p->tope;
        *val = aux->info;
        p->tope = aux->next;
    }
    free(aux);
}
int main()
{
    Pila st;
    int v;
    create(&st);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    push(&st, 70);
    push(&st, 80);
    pop(&st, &v);
    top(&st);
    printf("Valor: %d\n", v);
    return 0;
}
