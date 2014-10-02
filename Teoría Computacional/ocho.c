#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graficos.h"
#define MAX_SIZE 1024

void q0(const char *, int *, int *);
void q1(const char *, int *, int *);
void q2(const char *, int *, int *);
void q3(const char *, int *, int *);
void initAutomata(const char *, int *, int *);
void automataFromCadena(const char *, int *, int *);
void automataFromFichero(const char *, int *, int *);

void q0(const char *cad, int *p, int *c)
{
	if(cad[*p] == '\0')
	{
		*c = 1;
		return;
	}
	else if(cad[*p] == '0')
	{
		(*p)++;
		q3(cad, p, c);
	}
	else if(cad[*p] == '1')
	{
		(*p)++;
		q1(cad, p, c);
	}
	else
	{
		fprintf(stderr, "Cadena no reconocida\n");
		exit(-2);
	}
}
void q1(const char *cad, int *p, int *c)
{
	if(cad[*p] == '\0')
		return;
	if(cad[*p] == '0')
	{
		(*p)++;
		q2(cad, p, c);
	}
	else if(cad[*p] == '1')
	{
		(*p)++;
		q0(cad, p, c);
	}
	else
	{
		fprintf(stderr, "Cadena no reconocida\n");
		exit(-2);
	}
}
void q2(const char *cad, int *p, int *c)
{
	if(cad[*p] == '\0')
		return;
	if(cad[*p] == '0')
	{
		(*p)++;
		q1(cad, p, c);
	}
	else if(cad[*p] == '1')
	{
		(*p)++;
		q3(cad, p, c);
	}
	else
	{
		fprintf(stderr, "Cadena no reconocida\n");
		exit(-2);
	}
}
void q3(const char *cad, int *p, int *c)
{
	if(cad[*p] == '\0')
		return;
	if(cad[*p] == '0')
	{
		(*p)++;
		q0(cad, p, c);
	}
	else if(cad[*p] == '1')
	{
		(*p)++;
		q2(cad, p, c);
	}
	else
	{
		fprintf(stderr, "Cadena no reconocida\n");
		exit(-2);
	}
}
void initAutomata(const char *cad, int *p, int *c)
{
	*c = 0;
	if(*p < strlen(cad))
		q0(cad, p, c);

	if(*c == 1)
		fprintf(stdout, "La cadena tiene todos los valores pares de ceros y unos\n");
	else
		fprintf(stdout, "La cadena no cumple con la paridad de ceros y unos\n");

	inicializar();
	colorearPantalla();
	tituloVentana();

	estadoFinal(250.0, 150.0, "q0");
	estadoCualquiera(500.0, 150.0, "q1");
	estadoCualquiera(250.0, 400.0, "q3");
	estadoCualquiera(500.0, 400.0, "q2");
	grafoDirigido(250.0+40.0, 180.0, 500.0-40.0, 180.0, 1, "1");
	grafoDirigido(250.0+40.0, 130.0, 500.0-40.0, 130.0, -1, "1");
	grafoDirigido(250.0-30, 200.0, 250.0-30, 360, 11, "0");
	grafoDirigido(250.0+30, 200.0, 250.0+30, 360, -11, "0");
	grafoDirigido(250.0+40.0, 430.0, 500.0-40.0, 430.0, 1, "1");
	grafoDirigido(250.0+40.0, 370.0, 500.0-40.0, 370.0, -1, "1");
	grafoDirigido(500.0-30.0, 200.0, 500.0-30, 360, 11, "0");
	grafoDirigido(500.0+30.0, 200.0, 500.0+30, 360, -11, "0");

	al_flip_display();

	while(1)
	{
		al_wait_for_event(queue_evento, &evento);
		if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
	}

	about();
	finalizar();
}
void automataFromCadena(const char *cad, int *p, int *c)
{
	initAutomata(cad, p, c);
}
void automataFromFichero(const char *fich, int *p, int *c)
{
	char str[MAX_SIZE];
	FILE *fichero = fopen(fich, "r");

	if(fichero == NULL)
	{
		perror("Error [Fichero]");
		exit(-1);
	}

	fgets(str, MAX_SIZE, fichero);
	initAutomata(str, p, c);

	fclose(fichero);
}

int main(int argc, char **argv)
{
	int posicion = 0, contador = 0;

	if(argv[1] == NULL)
		fprintf(stderr, "No hay argumentos\n");
	else
	{
		if(strcmp(argv[1], "--cadena") == 0)
			automataFromCadena(argv[2], &posicion, &contador);
		else if(strcmp(argv[1], "--archivo") == 0)
			automataFromFichero(argv[2], &posicion, &contador);
		else
			fprintf(stderr, "Argumento invalido\n");
	}
	return 0;
}