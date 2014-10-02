#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int QueueEntry;
typedef struct nodo
{
    QueueEntry info;
    struct nodo *next;
} Nodo;
typedef struct queue
{
    Nodo *front;
    Nodo *tail;
} Queue;

Nodo* makeNode(QueueEntry v);
int size(Queue *q);
int isEmpty(Queue *q);
int compareQ(Queue *q, Queue *qi);
int findQ(Queue *q, QueueEntry dato);
void printQ(Queue *q);
void createQ(Queue *q);
void enqueue(Queue *q, QueueEntry val);
void dequeue(Queue *q, QueueEntry *val);
void copyQ(Queue *origen, Queue *destino);
void appendQ(Queue *origen, Queue *destino);

void createQ(Queue *q)
{
    q->front = q->tail = NULL; // Ambos punteros apuntan a NULL
}
Nodo* makeNode(QueueEntry v)
{
    Nodo *newNode;
    newNode = (Nodo*) malloc(sizeof(Nodo));
    if(newNode == NULL)
    {
        printf("\tNo hay memoria disponible\n");
        exit(-1);
    }
    newNode->info = v;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(Queue *q)
{
    return q->front == NULL;
}
int size(Queue *q)
{
    Queue aux;
    createQ(&aux);
    int j, i = 0;
    QueueEntry x;
    while(!isEmpty(q))
    {
        dequeue(q, &x);
        enqueue(&aux, x);
        i++;
    }
    while(!isEmpty(&aux))
    {
        dequeue(&aux, &x);
        enqueue(q, x);
    }
    return i;
}
void enqueue(Queue *q, QueueEntry val)
{
    Nodo *newNode;
    newNode = makeNode(val);
    if(isEmpty(q))
    {
        q->front = q->tail = newNode;
        newNode = NULL;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
        newNode = NULL;
    }
}
void dequeue(Queue *q, QueueEntry *val)
{
    Nodo *aux;
    if(isEmpty(q))
    {
        q->tail = NULL;
        printf("\tCola vacia\n");
    }
    else
    {
        *val = q->front->info;
        aux = q->front;
        q->front = aux->next;
        aux->next = NULL;
    }
    free(aux);
}
void printQ(Queue *q)
{
    Queue aux;
    createQ(&aux);
    int j, i = 0;
    QueueEntry x;
    while(isEmpty(q)==0)
    {
        dequeue(q,&x);
        printf("%d\n",x);
        enqueue(&aux,x);
        i++;
    }
    for(j = 0; j<i; j++)
    {
        dequeue(&aux,&x);
        enqueue(q,x);
    }
}
int compareQ(Queue *q, Queue *qi)
{
    Queue aux, auxi;
    int j=0, r=0, i = 0, val = 1;
    QueueEntry x, y;
    createQ(&aux);
    createQ(&auxi);
    i = size(q);
    j = size(qi);
    if(i != j)
        return 0;
    while(isEmpty(q)==0)
    {
        dequeue(q,&x);
        dequeue(qi,&y);
        enqueue(&aux,x);
        enqueue(&auxi,y);
        if(x != y)
            val = 0;
        r++;
    }
    for(j = 0; j<r; j++)
    {
        dequeue(&aux,&x);
        enqueue(q,x);
        dequeue(&auxi,&y);
        enqueue(qi,y);
    }
    return val;
}
void appendQ(Queue *origen, Queue *destino) // Anexar datos queue origen al queue destino
{
    int j, i = 0;
    QueueEntry aux2[20];
    QueueEntry x;
    while(isEmpty(origen)==0)
    {
        dequeue(origen, &x);
        enqueue(destino, x);
        aux2[i] = x;
        i++;
    }
    for(j = 0; j<i; j++)
        enqueue(origen,aux2[j]);
}
int findQ(Queue *q, QueueEntry dato)
{
    Queue aux;
    int j, i = 0, rta = 0;
    QueueEntry x;
    createQ(&aux);
    while(isEmpty(q)==0)
    {
        dequeue(q,&x);
        if(x == dato)
            rta = 1;
        enqueue(&aux,x);
        i++;
    }
    for(j = 0; j<i; j++)
    {
        dequeue(&aux,&x);
        enqueue(q,x);
    }
    return rta;
}
void copyQ(Queue *origen, Queue *destino)
{
    int j, i = 0;
    QueueEntry aux2[20];
    QueueEntry x;
    while(isEmpty(origen) == 0)
    {
        dequeue(origen, &x);
        enqueue(destino, x);
        aux2[i] = x;
        i++;
    }
    for(j = 0; j<i; j++)
        enqueue(origen, aux2[j]);
}
int main()
{
    Queue c1, c2;
    QueueEntry valor;
    createQ(&c1);
    createQ(&c2);
    enqueue(&c1, 25);
    enqueue(&c1, 50);
    enqueue(&c1, 75);
    enqueue(&c2, 10);
    appendQ(&c1, &c2);
    printQ(&c1);
    printf("\n");
    printQ(&c2);
    return 0;
}
