#include <stdio.h>
#include <string.h>
#include "cola.h"

/*
	Autor: Eder Or
	Website: www.multiaportes.com
*/

int main(int argc, char **argv)
{
	Cola c;
	Dato ddd;
	crearCola(&c);
	push('c', &c);
	push('o', &c);
	push('m', &c);
	push('e', &c);
	push('r', &c);
	recorrer(&c);
	pop(&ddd, &c);
	printf("Tamanio: %u\n", getTamanio(&c));
	recorrer(&c);
	return 0;
}