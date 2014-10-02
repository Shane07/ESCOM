
// MODIFICADO MARTES 11 FEB: Validar que los numeros esten entre 0 y 255 (no negativos)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	unsigned char ipp[4];
} Dirip;

void parsearIP(char *x, Dirip *s)
{
	int p = 0, c = 0;
	char tmp[4];

	strcat(x, ".");

	while(*x != '\0')
	{
		if(*x != '.')
		{
			tmp[p] = *x;
			p++;
		}
		else
		{
			tmp[p] = '\0';
			s->ipp[c] = (char) atoi(tmp);
			p = 0;
			c++;
		}
		x++;
	}
}

char getClase(Dirip *s)
{
	int t = s->ipp[0];

	if((t & 128) == 0)
		return 'A';
	if((t & 192) == 128)
		return 'B';
	else if((t & 224) == 192)
		return 'C';
	else
		return 'X';
}

char getTipo(Dirip *s, const char cl)
{
	if(cl == 'A' && s->ipp[1] == 0 && s->ipp[2] == 0 && s->ipp[3] == 0)
		return 'R';
	else if(cl == 'A' && s->ipp[1] == 255 && s->ipp[2] == 255 && s->ipp[3] == 255)
		return 'B';
	else if(cl == 'B' && s->ipp[2] == 0 && s->ipp[3] == 0)
		return 'R';
	else if(cl == 'B' && s->ipp[2] == 255 && s->ipp[3] == 255)
		return 'B';
	else if(cl == 'C' && s->ipp[3] == 0)
		return 'R';
	else if(cl == 'C' && s->ipp[3] == 255)
		return 'B';
	else
		return 'H';
}

void getMascaraRed(const char cl, Dirip *mr)
{
	int k;

	if(cl == 'A')
	{
		mr->ipp[0] = 255;
		for(k = 1; k < 4; k++)
			mr->ipp[k] = 0;
	}
	else if(cl == 'B')
	{
		for(k = 0; k < 2; k++)
			mr->ipp[k] = 255;
		for(k = 2; k < 4; k++)
			mr->ipp[k] = 0;
	}
	else if(cl == 'C')
	{
		mr->ipp[3] = 0;
		for(k = 2; k >= 0; k--)
			mr->ipp[k] = 255;
	}
}

void getDireccionRed(Dirip *s, Dirip *mr, Dirip *dr, const char tp)
{
	int k;

	if(tp == 'R')
		for(k = 0; k < 4; k++)
			dr->ipp[k] = s->ipp[k];
	else
		for(k = 0; k < 4; k++)
			dr->ipp[k] = s->ipp[k] & mr->ipp[k];
}

void getDireccionBroadcast(Dirip *s, Dirip *mr, Dirip *dr, const char tp)
{
	int k;

	if(tp == 'B')
		for(k = 0; k < 4; k++)
			dr->ipp[k] = s->ipp[k];
	else
		for(k = 0; k < 4; k++)
			dr->ipp[k] = s->ipp[k] | ~mr->ipp[k];
}

void getRango(Dirip *dr, Dirip *db, Dirip *in, Dirip *fn)
{
	int k;

	for(k = 0; k < 4; k++)
	{
		if(k < 3)
		{
			in->ipp[k] = dr->ipp[k];
			fn->ipp[k] = db->ipp[k];
		}
		else
		{
			in->ipp[k] = 1;
			fn->ipp[k] = 254;
		}
	}
}

int main()
{
	char ip[16], clase, tipo;
	Dirip dip, mask, dred, dbr, rin, rfn;

	printf("IP: ");
	fgets(ip, 16, stdin);

	parsearIP(ip, &dip);

	clase = getClase(&dip);
	tipo = getTipo(&dip, clase);
	getMascaraRed(clase, &mask);
	getDireccionRed(&dip, &mask, &dred, tipo);
	getDireccionBroadcast(&dip, &mask, &dbr, tipo);
	getRango(&dred, &dbr, &rin, &rfn);

	printf("Clase: %c\n", clase);
	if(tipo == 'R')
		printf("Tipo: Red\n");
	else if(tipo == 'B')
		printf("Tipo: Broadcast\n");
	else
		printf("Tipo: Host\n");
	printf("Mascara de red: %d.%d.%d.%d\n", mask.ipp[0], mask.ipp[1], mask.ipp[2], mask.ipp[3]);
	printf("Direccion de red: %d.%d.%d.%d\n", dred.ipp[0], dred.ipp[1], dred.ipp[2], dred.ipp[3]);
	printf("Direccion de broadcast: %d.%d.%d.%d\n", dbr.ipp[0], dbr.ipp[1], dbr.ipp[2], dbr.ipp[3]);
	printf("Rango: %d.%d.%d.%d - %d.%d.%d.%d\n", rin.ipp[0], rin.ipp[1], rin.ipp[2], rin.ipp[3], rfn.ipp[0], rfn.ipp[1], rfn.ipp[2], rfn.ipp[3]);

	printf("\nPor Ortega Ortunio Eder - 2CM9 | multiaportes.com");
	return 0;
}
