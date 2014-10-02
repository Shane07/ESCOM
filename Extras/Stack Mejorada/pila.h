#include <stdlib.h>
#define MODO_DEBUG 1

/*
	Autor: Eder Or
	Website: www.multiaportes.com
*/

/* Estructura de datos: Pila (Stack) */
typedef char Dato;
struct nodo
{
	Dato dato;
	struct nodo *anterior;
};
typedef struct nodo Nodo;
struct pila
{
	Nodo *ultimo;
};
typedef struct pila Pila;

/* Prototipos de la función */
Nodo* crearNodo(Dato);
void crearPila(Pila *);
unsigned int getTamanio(Pila *);
int pilaVacia(Pila *);
void recorrer(Pila *);
void push(const Dato, Pila *);
void pop(Dato *, Pila *);

/* Definición de las funciones */
void crearPila(Pila *s)
{
	s->ultimo = NULL;
}
Nodo* crearNodo(Dato d)
{
	Nodo *tmp;
	tmp = (Nodo *) malloc(sizeof(Nodo));
	if(tmp != NULL)
	{
		tmp->dato = d;
		tmp->anterior = NULL;
		if(MODO_DEBUG)
			printf("\tMensaje: dato guardado = %c\n", tmp->dato);
	}
	else
		fprintf(stderr, "\tError: no se pudo asignar un nuevo nodo\n");
	return tmp;
}
int pilaVacia(Pila *s)
{
	if(s->ultimo == NULL)
		return 1;
	else
		return 0;
}
unsigned int getTamanio(Pila *s)
{
	unsigned int k = 0;
	Nodo *zzz;
	zzz = s->ultimo;
	while(zzz != NULL)
	{
		k++;
		zzz = zzz->anterior;
	}
	zzz = NULL;
	return k;
}
void recorrer(Pila *s)
{
	if(MODO_DEBUG)
	{
		Nodo *zzz;
		zzz = s->ultimo;
		while(zzz != NULL)
		{
			printf("%c\n", zzz->dato);
			zzz = zzz->anterior;
		}
		zzz = NULL; // Importante para evitar que nuevas llamadas a esta funcion apunten al ultimo nodo de la pila
	}
}
void push(const Dato d, Pila *s)
{
	Nodo *nuevoNodo;
	nuevoNodo = crearNodo(d);
	if(nuevoNodo != NULL)
	{
		nuevoNodo->anterior = s->ultimo; // Apunta al nodo que era el último antes de agregar a este nuevo nodo
		s->ultimo = nuevoNodo; // La pila ahora apunta al nuevo nodo creado
		nuevoNodo = NULL; // Como ya no usaremos la referencia al nuevo nodo, entonces le eliminamos
	}
}
void pop(Dato *d, Pila *s)
{
	if(!pilaVacia(s))
	{
		Nodo *superior;
		superior = s->ultimo; // Apunta al último nodo de la pila
		*d = s->ultimo->dato; // Se recupera el dato y se guarda en la variable externa
		s->ultimo = s->ultimo->anterior; // Ahora el penúltimo nodo será el último ya que el actual último nodo desaparecerá
		free(superior); // Se liberará el último nodo
	}
	else
		fprintf(stderr, "\tAviso: pila vacia");
}