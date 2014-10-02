#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10
#define PAUSA "pause>nul" //"read 0 -ers" //win: pause>nul
#define LIMPIAR "cls" //"clear"//"cls"
#define __xD__ __asm__ __volatile__("rdtsc")
//IF LINUX #define __xD__ time(NULL);

typedef struct contacto
{
    char nombre[50];
    char telefono[15];
    char hora[10];
    char estado[20];
} Contacto;
typedef Contacto QueueEntry;
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

const char nombres[][50] = {"Angus Young", "Axl Rose", "Carlos Santana", "Eddie Van Halen", "James Hetfield", "Jimmy Page", "Klauss Meine", "Robert Plant", "Roger Waters", "Steve Harris"};

Nodo* makeNode(QueueEntry v);
int size(Queue *q);
int isEmpty(Queue *q);
void printQ(Queue *q);
void createQ(Queue *q);
void enqueue(Queue *q, QueueEntry val);
void dequeue(Queue *q, QueueEntry *val);

int aleatorio(void)
{
    __xD__;
}
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
    QueueEntry x;
    createQ(&aux);
    int j, i = 0;
    while(isEmpty(q)==0)
    {
        dequeue(q,&x);
        printf("Nombre: %s\n",x.nombre);
        printf("Telefono: %s\n",x.telefono);
        printf("Hora: %s\n",x.hora);
        printf("Estado: %s\n",x.estado);
        printf("\n");
        enqueue(&aux,x);
        i++;
    }
    for(j = 0; j<i; j++)
    {
        dequeue(&aux,&x);
        enqueue(q,x);
    }
}
void generarNombres(Contacto array[10])
{
    int a;
    for(a = 0; a <= 9; a++)
        strcpy(array[a].nombre, nombres[a]);
}
void generarTelefonos(Contacto array[10])
{
    const char ladaMX = 55;
    char tel[17];
    int phone[4], cnt, a, inicio = 10, fin = 99;
    for(a = 0; a <= 9; a++)
    {
        for(cnt = 0; cnt <= 4; cnt++)
        phone[cnt] = rand() % (fin-inicio+1)+inicio;
        sprintf(tel, "%d-%d-%d-%d-%d", ladaMX, phone[0],  phone[1],  phone[2],  phone[3]);
        strcpy(array[a].telefono, tel);
    }
    puts(array[0].telefono);
}
void generarHora(Contacto *a)
{
    int hora, minuto, inicio = 0, finh = 23, finm = 59;
    hora = rand() % (finh-inicio+1)+inicio;
    minuto = rand() % (finm-inicio+1)+inicio;
    sprintf(a->hora, "%02d:%02d hrs", hora, minuto);
}
void generarEstado(Contacto *a, int e)
{
    if(e == 0)
        sprintf(a->estado, "Llamada saliente");
    else if(e == 1)
        sprintf(a->estado, "Llamada entrante");
}
void hacerLlamada(Queue *q, Contacto *w)
{
    system(LIMPIAR);
    if(size(q) < 5)
    {
        generarHora(w);
        generarEstado(w, 0);
        printf("Llamando a:\n\t%s (%s)\n", w->nombre, w->telefono);
        printf("Llamada hecha a las %s\n", w->hora);
        enqueue(q, *w);
    }
    else
        printf("No se pueden realizar mas llamadas.\n");
}
void recibirLlamada(Queue *q, Contacto *w)
{
    system(LIMPIAR);
    if(size(q) < 5)
    {
        generarHora(w);
        generarEstado(w, 1);
        printf("Llamada de:\n\t%s (%s)\n", w->nombre, w->telefono);
        printf("Llamada recibida a las %s\n", w->hora);
        enqueue(q, *w);
    }
    else
        printf("No se pueden recibir mas llamadas.\n");
}
void printLlamadas(Queue *q)
{
    system(LIMPIAR);
    if(isEmpty(q))
        printf("Lista de llamadas vacia.");
    else
        printQ(q);
}
void listarContactos(Contacto c[10])
{
    int b;
    system(LIMPIAR);
    for(b = 0; b < 10; b++)
    {
        printf("Contacto %d:\n", b+1);
        printf("\t");
        puts(c[b].nombre);
        printf("\t");
        puts(c[b].telefono);
        printf("\n");
    }
}
void borrarLlamada(Queue *q)
{
    Contacto tmp;
    system(LIMPIAR);
    if(isEmpty(q))
        printf("No se puede borrar una lista de llamadas vacia.");
    else
    {
        dequeue(q, &tmp);
        printf("Llamada borrada exitosamente.");
    }
}
int main()
{
    int opcion, posicion;
    Contacto c[10];
    Queue registro_calls;
    createQ(&registro_calls);
    srand(aleatorio());
    generarNombres(c);
    generarTelefonos(c);
    while(1)
    {
        system(LIMPIAR);
    //    xdd: //TMP ANDROID
        fflush(stdin);
        printf("\t1. Lista de contactos\n\t2. Hacer llamada\n\t3. Recibir llamada\n\t4. Ver lista de llamadas\n\t5. Borrar llamada\n\t6. Salir\n\n");
        printf("\tOpcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                listarContactos(c);
                break;
            case 2:
                system(LIMPIAR);
                fflush(stdin);
                printf("Numero del contacto: ");
                scanf("%d", &posicion);
                system(LIMPIAR);
                if(posicion >= 0 && posicion < 10)
                    hacerLlamada(&registro_calls, &c[posicion]);
                else
                    printf("Contacto no existente.");
                break;
            case 3:
                system(LIMPIAR);
                fflush(stdin);
                printf("Numero del contacto: ");
                scanf("%d", &posicion);
                system(LIMPIAR);
                if(posicion >= 0 && posicion < 10)
                    recibirLlamada(&registro_calls, &c[posicion]);
                else
                    printf("Contacto no existente.");
                break;
            case 4:
                printLlamadas(&registro_calls);
                break;
            case 5:
                borrarLlamada(&registro_calls);
                break;
            case 6:
                exit(0);
                break;
            default:
                break;
        }
        system(PAUSA);
    }
    //goto xdd; //TMP ANDROID
    return 0;
}
