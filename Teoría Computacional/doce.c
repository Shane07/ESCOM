#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Opciones:
  	1. P -> e
  	2. P -> 0
  	3. P -> 1
  	4. P -> 0P0
  	5. P -> 1P1
*/

int semilla()
{
	__asm__ __volatile__("rdtsc");
}
int al(int z)
{
	return random() % z; // Devolver entre cero y z-1
}
void generarAleatorio(int n, int *r)
{
	int k;
	for(k = 0; k < n; k++)
		r[k] = al(2);
	r[n] = '\0';
}
void finalizarPalindromo(int n, int *c, int *r, char *sp)
{
	int k, tmp = (al(3) == 0)? 1:((al(3) == 1)?2:3);
	fprintf(stdout, "Final: Escogiendo opcion %d\n\t", tmp);
	for(k = 0; k < sizeof(sp); k++)
		if(sp[k] != '\0')
			fprintf(stdout, "%c", sp[k]);
		else
			break;
	fprintf(stdout, "%s", (tmp == 1)? " \b":((tmp == 2)?"0":"1"));
	for(k = sizeof(sp)-2; k >= 0; k--)
		if(sp[k] == '0' || sp[k] == '1')
			fprintf(stdout, "%c", sp[k]);
	fprintf(stdout, "\n");
}
void generarNuevoPalindromo(int n, int *c, int *r, char *sp)
{
	int k;

	sp[*c] = (r[*c] == 0)? '0':'1';
	sp[*c+1] = '\0';

	fprintf(stdout, "%d. Escogiendo opcion %d\n\t", *c+1, (r[*c] == 0)? 4:5);
	for(k = 0; k < sizeof(sp); k++)
		if(sp[k] != '\0')
			fprintf(stdout, "%c", sp[k]);
		else
			break;
	fprintf(stdout, "P");
	for(k = sizeof(sp)-2; k >= 0; k--)
		if(sp[k] == '0' || sp[k] == '1')
			fprintf(stdout, "%c", sp[k]);
	fprintf(stdout, "\n");

	(*c)++;
	if(*c < n)
		generarNuevoPalindromo(n, c, r, sp);
	else if(*c == n)
		finalizarPalindromo(n, c, r, sp);
}
void initPalindromo(const char *num)
{
	int c = 0, n = atoi(num), selecciones[n+1];
	char semiPal[n*2 + 2];

	generarAleatorio(n, selecciones);
	generarNuevoPalindromo(n, &c, selecciones, semiPal);
}

int main(int argc, char **argv)
{
	srand(semilla());

	if(argv[1] == NULL)
		fprintf(stderr, "No hay argumentos\n");
	else
	{
		if(strcmp(argv[1], "-n") == 0)
			initPalindromo(argv[2]);
		else
			fprintf(stderr, "Argumento invalido\n");
	}
	return 0;
}