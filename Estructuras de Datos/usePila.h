#include <stdlib.h>
#define MAX 20
/*
    Definición de estructuras
*/
//Pila estatica
typedef struct
{
    int nums[MAX];
    int c;
} Pi;
//Pila dinamica
typedef struct nodo
{
    int info;
    struct nodo *next;
} Nodo;
typedef struct pila
{
    Nodo *tope;
} Pila;

/*
    Métodos de una pila estatica
*/
void createPila(Pi *pila)
{
    pila->c = -1; // La flecha se usa solamente en un puntero a estructura, caso contrario usar estruct.var = algo;
}
int pilaSize(Pi *pila)
{
    return pila->c + 1;
}
int pilaIsEmpty(Pi *pila)
{
    return pila->c == -1; // Comparacion (retorna 1 si pila->c == -1; es decir, pila vacia)
}
int pilaIsFull(Pi *pila)
{
    return pila->c == (MAX-1); // Comparacion (retorna 1 si pila->c == MAX-1; es decir, pila llena)
}
void pilaTop(Pi *pila)
{
    if(pilaIsEmpty(pila))
    {
        printf("\tError: Pila vacia\n");
    }
    else
    {
        printf("TOP: %d\n", pila->nums[pila->c]);
    }
}
void push(Pi *pila, int val)
{
    if(pilaIsFull(pila)) // El puntero pila se pasa directamente a pilaIsFull() sin necesidad de usar asterisco
    {
        printf("\tError: Pila llena\n");
    }
    else
    {
        pila->nums[pila->c+1] = val;
        pila->c ++;
    }
}
int pop(Pi *pila)
{
    if(pilaIsEmpty(pila))
    {
        printf("Error: Pila vacia\n");
    }
    else
    {
        int z = pila->nums[pila->c];
        pila->nums[pila->c] = 0; // Eliminar el contenido del elemento vaciado
        pila->c --;
        return z;
    }
}

/*
    Métodos de una pila dinamica
*/
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
void pushDin(Pila *p, int dato)
{
    Nodo *n;
    n = hacerNodo(dato);
    n->next = p->tope;
    p->tope = n;
    n = NULL;
}
void popDin(Pila *p, int *val)
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
