#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Opciones:
  	1. e
  	2. n veces '0'
  	3. n veces '1'

  	CORREGIR:
  	1. Random 0, 1: 0->Finaliza; 1->Random 0,1 ->Random entre 0 y 100 -> Generar N veces 0,1
*/

int semilla()
{
	__asm__ __volatile__("rdtsc");
}
int al(int z)
{
	return random() % z;
}
void generarNuevaRegexp()
{
	int tmp, n, r = al(2);
	if(r == 0)
	{
		fprintf(stdout, "[random = %d] (0+1)* = e\n", r);
		exit(2);
	}
	else if(r == 1)
	{
		r = al(2);
		n = al(100) + 1;
		fprintf(stdout, "[random2 = %d, n = %d] (0+1)* = ", r, n);
		if(r == 0)
			for(tmp = 1; tmp <= n; tmp++)
				fprintf(stdout, "%d", r);
		else if(r == 1)
			for(tmp = 1; tmp <= n; tmp++)
				fprintf(stdout, "%d", r);
		fprintf(stdout, "\n");
		generarNuevaRegexp();
	}
/*
	for(k = 1; k <= n; k++)
	{
		int r = al(3);
		fprintf(stdout, "[Opcion %d = %s]: (0+1)* = ", r, (r == 0)?"e":(r == 1)?"0s":"1s");
		if(r == 1)
			for(l = 1; l <= n; l++)
				fprintf(stdout, "0");
		else if(r == 2)
			for(l = 1; l <= n; l++)
				fprintf(stdout, "1");
		fprintf(stdout, "\n");
	}*/
}
void initRegexp()
{
	generarNuevaRegexp();
}

int main(int argc, char **argv)
{
	srand(semilla());
	initRegexp();
	return 0;
}