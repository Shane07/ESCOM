#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graficos.h"
#define MAX_SIZE 1024

void q0(const char *, int *);
void q1(const char *, int *);
void q2(const char *, int *);
void initAutomata(const char *, int *);
void automataFromCadena(const char *, int *);
void automataFromFichero(const char *, int *);

void q0(const char *cad, int *p)
{
	fprintf(stdout, "\t[%d]\n", *p);
	if(cad[*p] == '\0')
	{
		fprintf(stdout, "La cadena no finaliza con 01\n");
		exit(-2);
	}
	if(cad[*p] == '0')
	{
		(*p)++;
		q1(cad, p);
		(*p)++;
		q0(cad, p);
	}
	else if(cad[*p] == '1')
	{
		(*p)++;
		q0(cad, p);
	}
	else
	{
		fprintf(stdout, "Cadena no reconocida\n");
		exit(-2);
	}
}
void q1(const char *cad, int *p)
{
	fprintf(stdout, "\t[%d]\n", *p);
	if(cad[*p] == '\0')
	{
		fprintf(stdout, "La cadena no finaliza con 01\n");
		exit(-2);
	}
	if(cad[*p] == '1')
	{
		(*p)++;
		q2(cad, p);
		return;
	}
	else if(cad[*p] == '0')
	{
		return;
	}
	else
	{
		fprintf(stderr, "Cadena no reconocida\n");
		exit(-2);
	}
}
void q2(const char *cad, int *p)
{
	fprintf(stdout, "\t[%d]\n", *p);
	if(cad[*p] == '\0')
	{
		fprintf(stdout, "La cadena finaliza con 01\n");
		exit(0);
	}
	else if(cad[*p] == '0' || cad[*p] == '1')
	{
		return;
	}
	else
	{
		fprintf(stderr, "Cadena no reconocida\n");
		exit(-2);
	}
}
void initAutomata(const char *cad, int *p)
{
	inicializar();
	colorearPantalla();
	tituloVentana();

	estadoCualquiera(120.0, 250.0, "q0");
	estadoCualquiera(270.0, 250.0, "q1");
	estadoFinal(420.0, 250.0, "q2");
	grafoDirigido(120.0+40.0, 250.0, 270.0-40.0, 250.0, 1, "0");
	grafoDirigido(270.0+40.0, 250.0, 420.0-40.0, 250.0, 1, "1");
	grafoDirigido(120.0, 250.0-40.0, 0.0, 0.0, 0, "0,1");

	al_flip_display();

	while(1)
	{
		al_wait_for_event(queue_evento, &evento);
		if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
	}

	about();
	finalizar();

	if(*p < strlen(cad))
		q0(cad, p);
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

// err_if_ends_w_001_and_is_impar

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