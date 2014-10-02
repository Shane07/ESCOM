#include <stdio.h>
#include <string.h>
#include "alfabetoBin.h"
#define MAX_SIZE 1024

void abrirArchivo(char *n, FILE **f)
{
	*f = fopen(n, "rt");

	if(*f == NULL)
	{
		perror("Error [Fichero]");
		exit(-3);
	}
}
void cerrarArchivo(FILE **f)
{
	fclose(*f);
}
unsigned long int getValorNumericoCadena(const char *cd)
{
	unsigned long int i, cont = 0;

	for(i = 0; i < strlen(cd); i++)
		cont = cont + (int) cd[i];
	return cont/100;
}

int main(int args, char **argv)
{
	FILE *entrada;
	char cadena[MAX_SIZE];

	if(argv[1] == NULL)
	{
		printf("Cadena: ");
		fgets(cadena, MAX_SIZE, stdin);
	}
	else
	{
		if(strcmp(argv[1], "--archivo") == 0)
		{
			if(argv[2] == NULL)
			{
				fprintf(stderr, "Archivo no especificado\n");
				return -2;
			}
			else
			{
				abrirArchivo(argv[2], &entrada);
				fgets(cadena, MAX_SIZE, entrada);
				cerrarArchivo(&entrada);
			}
		}
		else
		{
			fprintf(stderr, "Argumento invalido\n");
			return -1;
		}
	}

	ejercicioDos(getValorNumericoCadena(cadena));

	return 0;
}