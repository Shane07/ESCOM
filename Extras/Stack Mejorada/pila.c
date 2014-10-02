#include <stdio.h>
#include <string.h>
#include "pila.h"

/*
	Autor: Eder Or
	Website: www.multiaportes.com
*/

void checkPila(Pila *www)
{
	if(pilaVacia(www))
		printf("Pila vacia\n");
}

int main(int argc, char **argv)
{
	Pila p;
	Dato ddd;
	crearPila(&p);
	push('c', &p);
	push('o', &p);
	push('g', &p);
	push('e', &p);
	push('r', &p);
	recorrer(&p);
	pop(&ddd, &p);
	printf("Dato extraido: %c\n", ddd);
	recorrer(&p);
	return 0;
}