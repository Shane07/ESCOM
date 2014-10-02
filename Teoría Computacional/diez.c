#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graficos.h"
#define MAX_SIZE 1024

void q0(const char *, int *, int *, int *);
void q1(const char *, int *, int *, int *);
void q2(const char *, int *, int *, int *);
void q3(const char *, int *, int *, int *);
void q4(const char *, int *, int *, int *);
void q5(const char *, int *, int *, int *);
void q6(const char *, int *, int *, int *);
void q7(const char *, int *, int *, int *);
void showResultados(int *, int *);
void initAutomata(const char *, int *, int *, int *);
void automataFromCadena(const char *, int *, int *, int *);
void automataFromFichero(const char *, int *, int *, int *);

void showResultados(int *web, int *ebay)
{
	fprintf(stdout, "Coincidencias encontradas:\n\tWeb: %d\n\tEbay: %d\n", *web, *ebay);
	exit(0);
}
void q0(const char *cad, int *p, int *web, int *ebay)
{
	//printf("\tEstoy en q0 [%c = %d]\n", cad[*p], cad[*p]);
	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else if(cad[*p] == 'w')
	{
		(*p)++;
		q1(cad, p, web, ebay);
	}
	else if(cad[*p] == 'e')
	{
		(*p)++;
		q4(cad, p, web, ebay);
	}
	else
	{
		(*p)++;
		q0(cad, p, web, ebay);
	}
}
void q1(const char *cad, int *p, int *web, int *ebay)
{
	//printf("\tEstoy en q1 [%c = %d]\n", cad[*p], cad[*p]);
	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else if(cad[*p] == 'e')
	{
		(*p)++;
		if(cad[*p] == 'b' && cad[*p+1] != 'a')
			q2(cad, p, web, ebay);
		else if(cad[*p] == 'b' && cad[*p+1] == 'a')
			q4(cad, p, web, ebay);
		else
			q0(cad, p, web, ebay);
	}
	else
	{
		(*p)++;
		q0(cad, p, web, ebay);
	}
}
void q2(const char *cad, int *p, int *web, int *ebay)
{
	//printf("\tEstoy en q2 [%c = %d]\n", cad[*p], cad[*p]);
	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else if(cad[*p] == 'b')
	{
		(*p)++;
		if(cad[*p] != 'a')
			q3(cad, p, web, ebay);
		else if(cad[*p] == 'a')
			q5(cad, p, web, ebay);
		else
			q0(cad, p, web, ebay);
	}
	else
	{
		(*p)++;
		q0(cad, p, web, ebay);
	}
}
void q3(const char *cad, int *p, int *web, int *ebay)
{
	(*web)++;

	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else
	{
		//printf("\tEstoy en q3 [%c = %d]\n", cad[*p], cad[*p]);
		//(*p)++;
		if(cad[*p] == 'e' && cad[*p+2] != 'a')
			q4(cad, p, web, ebay);
		else if(cad[*p] == 'a' && cad[*p+2] == 'a')
			q6(cad, p, web, ebay);
		else
		{
			(*p)--;
			q0(cad, p, web, ebay);
		}
	}
}
void q4(const char *cad, int *p, int *web, int *ebay)
{
	//printf("\tEstoy en q4 [%c = %d]\n", cad[*p], cad[*p]);
	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else if(cad[*p] == 'b')
	{
		(*p)++;
		q5(cad, p, web, ebay);
	}
	else
	{
		(*p)++;
		q0(cad, p, web, ebay);
	}
}
void q5(const char *cad, int *p, int *web, int *ebay)
{
	//printf("\tEstoy en q5 [%c = %d]\n", cad[*p], cad[*p]);
	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else if(cad[*p] == 'a')
	{
		(*p)++;
		q6(cad, p, web, ebay);
	}
	else
	{
		(*p)++;
		q0(cad, p, web, ebay);
	}
}
void q6(const char *cad, int *p, int *web, int *ebay)
{
	//printf("\tEstoy en q6 [%c = %d]\n", cad[*p], cad[*p]);
	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else if(cad[*p] == 'y')
	{
		(*p)++;
		q7(cad, p, web, ebay);
	}
	else
	{
		(*p)++;
		q0(cad, p, web, ebay);
	}
}
void q7(const char *cad, int *p, int *web, int *ebay)
{
	(*ebay)++;

	if(cad[*p] == '\0')
		showResultados(web, ebay);
	else
	{
		//printf("\tEstoy en q7 [%c = %d]\n", cad[*p], cad[*p]);
		q0(cad, p, web, ebay);
	}
}
void initAutomata(const char *cad, int *p, int *w, int *e)
{
	char c[MAX_SIZE];
	int k = 0;

	while(k < sizeof(cad))
	{
		c[k] = tolower(cad[k]);
		k++;
	}

	c[k] = '\0';


	inicializar();
	colorearPantalla();
	tituloVentana();

	estadoCualquiera(120.0, 250.0, "q0");
	estadoCualquiera(270.0, 150.0, "q1");
	estadoCualquiera(420.0, 150.0, "q2");
	estadoFinal(570.0, 150.0, "q3");
	estadoCualquiera(270.0, 350.0, "q4");
	estadoCualquiera(420.0, 350.0, "q5");
	estadoCualquiera(570.0, 350.0, "q6");
	estadoFinal(720.0, 350.0, "q7");
	grafoDirigido(120.0+40.0, 250.0, 270.0-40.0, 150.0, 1, "w");
	grafoDirigido(270.0+40.0, 150.0, 420.0-40.0, 150.0, 1, "e");
	grafoDirigido(420.0+40.0, 150.0, 570.0-40.0, 150.0, 1, "b");
	grafoDirigido(110.0+40.0, 280.0, 270.0-40.0, 350.0, 1, "e");
	grafoDirigido(270.0+40.0, 350.0, 420.0-40.0, 350.0, 1, "b");
	grafoDirigido(420.0+40.0, 350.0, 570.0-40.0, 350.0, 1, "a");
	grafoDirigido(570.0+40.0, 350.0, 720.0-40.0, 350.0, 1, "y");
	grafoDirigido(120.0, 250.0-40.0, 0.0, 0.0, 0, "E-e-w");
	grafoDirigido(270.0, 150.0-40.0, 0.0, 0.0, 0, "E-w");
	grafoDirigido(270.0, 350.0-40.0, 0.0, 0.0, 0, "E-e");
	grafoDirigido(270.0, 350.0-40, 270.0, 150.0+40, 11, "w");
	grafoDirigido(420.0, 350.0-40, 270.0, 150.0+40, 11, "w");
	grafoDirigido(570.0, 350.0-40, 270.0, 150.0+40, 11, "w");
	grafoDirigido(720.0, 350.0-40, 270.0, 150.0+40, 11, "w");
	grafoDirigido(420.0+15, 150.0+40, 270.0, 350.0-40, 11, "e");
	grafoDirigido(570.0+15, 150.0+40, 270.0, 350.0-40, 11, "e");
	grafoDirigido(120.0+40.0, 250.0-30, 270.0-40.0, 150.0+30, -1, "x");
	grafoDirigido(135.0+40.0, 250.0+30, 270.0-40.0, 350.0-30, -1, "y");
	grafoDirigido(550.0, 350.0-40, 550.0, 150.0+40, 11, "a");
	grafoDirigido(270+40.0, 350.0+30, 720.0-40.0, 350.0+30, -1, "e");
	grafoDirigido(270+40.0, 150.0+30, 570.0-40.0, 150.0+30, -1, "w");

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
		q0(cad, p, w, e);
}
void automataFromCadena(const char *cad, int *p, int *w, int *e)
{
	initAutomata(cad, p, w, e);
}
void automataFromFichero(const char *fich, int *p, int *w, int *e)
{
	char str[MAX_SIZE];
	FILE *fichero = fopen(fich, "r");

	if(fichero == NULL)
	{
		perror("Error [Fichero]");
		exit(-1);
	}

	fgets(str, MAX_SIZE, fichero);
	initAutomata(str, p, w, e);

	fclose(fichero);
}

int main(int argc, char **argv)
{
	int posicion = 0, web = 0, ebay = 0;

	if(argv[1] == NULL)
		fprintf(stderr, "No hay argumentos\n");
	else
	{
		if(strcmp(argv[1], "--cadena") == 0)
			automataFromCadena(argv[2], &posicion, &web, &ebay);
		else if(strcmp(argv[1], "--archivo") == 0)
			automataFromFichero(argv[2], &posicion, &web, &ebay);
		else
			fprintf(stderr, "Argumento invalido\n");
	}
	return 0;
}