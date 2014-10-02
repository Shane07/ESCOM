#include <stdlib.h>
#define MODO_DEBUG 1

/*
	Autor: Eder Or
	Website: www.multiaportes.com
*/

/* Estructura de datos: Cola (Queue) */
typedef char Dato;
struct nodo
{
	Dato dato;
	struct nodo *siguiente;
};
typedef struct nodo Nodo;
struct cola
{
	Nodo *primero;
	Nodo *ultimo;
};
typedef struct cola Cola;

/* Prototipos de la función */
Nodo* crearNodo(Dato);
void crearCola(Cola *);
unsigned int getTamanio(Cola *);
int ColaVacia(Cola *);
void recorrer(Cola *);
void push(const Dato, Cola *);
//void pop(Dato *, Cola *);

/* Definición de las funciones */
void crearCola(Cola *q)
{
	q->primero = q->ultimo = NULL;
}
Nodo* crearNodo(Dato d)
{
	Nodo *tmp;
	tmp = (Nodo *) malloc(sizeof(Nodo));
	if(tmp != NULL)
	{
		tmp->dato = d;
		tmp->siguiente = NULL;
		if(MODO_DEBUG)
			printf("\tMensaje: dato guardado = %c\n", tmp->dato);
	}
	else
		fprintf(stderr, "\tError: no se pudo asignar un nuevo nodo\n");
	return tmp;
}
int colaVacia(Cola *q)
{
	if(q->primero == NULL)
		return 1;
	else
		return 0;
}
unsigned int getTamanio(Cola *q)
{
	unsigned int k = 0;
	Nodo *zzz;
	zzz = q->primero;
	while(zzz != NULL)
	{
		k++;
		zzz = zzz->siguiente;
	}
	zzz = NULL;
	return k;
}
void recorrer(Cola *q)
{
	if(MODO_DEBUG)
	{
		Nodo *zzz;
		zzz = q->primero;
		while(zzz != NULL)
		{
			printf("%c\n", zzz->dato);
			zzz = zzz->siguiente;
		}
		zzz = NULL; // Importante para evitar que nuevas llamadas a esta funcion apunten al ultimo nodo de la pila
	}
}
void push(const Dato d, Cola *q)
{
	Nodo *nuevoNodo;
	nuevoNodo = crearNodo(d);
	if(nuevoNodo != NULL)
	{
		if(colaVacia(q))
			q->primero = q->ultimo = nuevoNodo; // Los apuntadores de primer/ultimo nodo apuntan al nuevo y único nodo
		else
			q->ultimo->siguiente = q->ultimo = nuevoNodo; // El apuntador 'siguiente' del último nodo existente y el apuntador al último nodo ahora apuntan al nuevo nodo
		nuevoNodo = NULL; // Como ya no usaremos la referencia al nuevo nodo, entonces le eliminamos
	}
}
void pop(Dato *d, Cola *s)
{
	if(!colaVacia(s))
	{
		Nodo *cabezal;
		cabezal = s->primero;
		*d = s->primero->dato;
		s->primero = s->primero->siguiente;
		free(cabezal);
	}
	else
		fprintf(stderr, "\tAviso: Cola vacia");
}
