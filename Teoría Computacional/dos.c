#include <stdio.h>
#include "alfabetoBin.h"

int main()
{
	unsigned long int pot;
	char opc;

	printf("Potencia: ");
	scanf("%lu", &pot);

	ejercicioDos(pot);

	printf("Realizar otra operacion? s/n: ");
	cleanStdin();
	scanf("%c", &opc);
	if(opc == 's')
		main();
	else
		exit(0);
	return 0;
}