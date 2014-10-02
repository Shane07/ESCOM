typedef struct nodo
{
    char info;
    struct nodo *next;
} Nodo;
typedef struct pila
{
    Nodo *tope;
} Pila;
void crearPila(Pila *p)
{
    p->tope = NULL;
}
Nodo* crearNodo(char val)
{
    Nodo *n;
    n = (Nodo *) malloc(sizeof(Nodo));
    if(n == NULL)
    {
        fprintf(stderr, "\tError al asignar memoria\n");
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
void push(Pila *p, char dato)
{
    Nodo *n;
    n = crearNodo(dato);
    n->next = p->tope;
    p->tope = n;
    n = NULL;
}
int pop(Pila *p, char *val)
{
    Nodo *aux;
    if(isEmpty(p))
        return -1; // Pila vacia
    else
    {
        aux = p->tope;
        *val = aux->info;
        p->tope = aux->next;
        free(aux);
        return 1;
    }
}
void imprimir(Pila *pi)
{
    Pila aux;
    char c;
    int x = 0;
  
    while(!isEmpty(pi))
    {
        pop(pi, &c);
        push(&aux, c);
        x++;
    }
    while(x != 0)
    {
        pop(&aux, &c);
        printf("%c", c);
        push(pi, c);
        x--;
    }
    printf("\n");
} 