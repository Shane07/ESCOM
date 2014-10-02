#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

void q0(char *, int *);
void q1(char *, int *);
void q2(char *, int *);
void q3(char *, int *);
void q4(char *, int *);
void initAutomata(char *, int *);
void automataFromCadena(char *, int *);
void automataFromFichero(char *, int *);

void q0(char *cad, int *p)
{
	fprintf(stdout, "Q0 cad[%d] - %s\n", *p, cad);
	cad[*p] = 'X';
	(*p)++;
	if(cad[*p] == '1')
		q2(cad, p);
	else if(cad[*p] == 'X' || cad[*p] == 'Y' || cad[*p] == '0')
		q1(cad, p);
	else
		q4(cad, p);
}
void q1(char *cad, int *p)
{
	fprintf(stdout, "Q1 cad[%d] - %s\n", *p, cad);
	(*p)++;
	if(cad[*p] == '1')
		q2(cad, p);
	else if(cad[*p] == 'X' || cad[*p] == 'Y' || cad[*p] == '0')
		q1(cad, p);
	else
		q4(cad, p);
}
void q2(char *cad, int *p)
{
	fprintf(stdout, "Q2 cad[%d] - %s\n", *p, cad);
	cad[*p] = 'Y';
	(*p)--;
	if(cad[*p] == '0')
		q0(cad, p);
	else if(cad[*p] == 'X' || cad[*p] == 'Y' || cad[*p] == '1')
		q3(cad, p);
	else
		q4(cad, p);
}
void q3(char *cad, int *p)
{
	fprintf(stdout, "Q3 cad[%d] - %s\n", *p, cad);
	(*p)--;
	if(cad[*p] == '0')
		q0(cad, p);
	else if(cad[*p] == 'X' || cad[*p] == 'Y' || cad[*p] == '1')
		q3(cad, p);
	else
		q4(cad, p);
}
void q4(char *cad, int *p)
{
	fprintf(stdout, "Terminado\n");
	exit(2);
}
void initAutomata(char *cad, int *p)
{
	if(*p < strlen(cad))
		if(cad[0] == '0')
			q0(cad, p);
		else
			fprintf(stderr, "Cadena no aceptada\n");
	exit(1);
}
void automataFromCadena(char *cad, int *p)
{
	initAutomata(cad, p);
}
void automataFromFichero(char *fich, int *p)
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