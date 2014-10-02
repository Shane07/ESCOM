#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#define MAX_SIZE 1024

void q0(const char *, int *, Pila *stack);
void q1(const char *, int *, Pila *stack);
void initAutomata(const char *, int *);
void automataFromCadena(const char *, int *);
void automataFromFichero(const char *, int *);

void q0(const char *cad, int *p, Pila *stack)
{
	push(stack, 'X');
	fprintf(stdout, "Estado de la pila [%c]: ", cad[*p]);
	imprimir(stack);
	(*p)++;
	if(cad[*p] == '0')
		q0(cad, p, stack);
	else if(cad[*p] == '1')
		q1(cad, p, stack);
	else
		exit(2);
}
void q1(const char *cad, int *p, Pila *stack)
{
	char tmp;
	if(pop(stack, &tmp) == 1)
	{
		fprintf(stdout, "Estado de la pila [%c]: ", cad[*p]);
		imprimir(stack);
	}
	else
		fprintf(stdout, "Estado de la pila [%c]: Vacia\n", cad[*p]);
	(*p)++;
	if(cad[*p] == '0')
		q0(cad, p, stack);
	else if(cad[*p] == '1')
		q1(cad, p, stack);
	else
		exit(2);
}
void initAutomata(const char *cad, int *p)
{
	Pila stack;
	crearPila(&stack);

	if(*p < strlen(cad))
	{
		if(cad[*p] == '0')
			q0(cad, p, &stack);
		else if(cad[*p] == '1')
			q1(cad, p, &stack);
		else
			exit(2);
	}
}
void automataFromCadena(const char *cad, int *p)
{
	initAutomata(cad, p);
}
void automataFromFichero(const char *fich, int *p)
{
	char str[MAX_SIZE];
	FILE *fichero = fopen(fich, "r");

	if(fichero == NULL)
	{
		perror("Error [Fichero]");
		exit(-1);
	}

	fgets(str, MAX_SIZE, fichero);
	initAutomata(str, p);

	fclose(fichero);
}

int main(int argc, char **argv)
{
	int posicion = 0;

	if(argv[1] == NULL)
		fprintf(stderr, "No hay argumentos\n");
	else
	{
		if(strcmp(argv[1], "--cadena") == 0)
			automataFromCadena(argv[2], &posicion);
		else if(strcmp(argv[1], "--archivo") == 0)
			automataFromFichero(argv[2], &posicion);
		else
			fprintf(stderr, "Argumento invalido\n");
	}
	return 0;
}