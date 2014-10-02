#include <stdio.h>

/*
	Escribir un programa que lea números hasta que se encuentre el cero. El segundo número se
	sumará al primero, luego el tercero se restará, el cuarto se sumará, y así se deberá seguir
	alternado hasta que se llegue al cero. Cuando se llegue a esta condicion deberá imprimir el
	resultado, el total de operandos de la operación (sin incluir el cero), y la suma de los operandos
	que se restaron.
*/

int main()
{
	int entrada = 0, resultado = 0, iteraciones = 0, sumaRestados = 0;

	do
	{
		printf("#: ");
		scanf("%d", &entrada);
		if(++iteraciones%2 == 0) // Preincremento: primero se incrementa y luego se hace la comparación lógica
		{
			resultado += entrada;
		}
		else
		{
			resultado -= entrada;
			sumaRestados += entrada;
		}
	}
	while(resultado != 0);

	fprintf(stdout, "############################\n");
	fprintf(stdout, "Resultado: %d\n", resultado);
	fprintf(stdout, "Operandos realizados: %d\n", iteraciones);
	fprintf(stdout, "Suma de los numeros a restar: %d\n", sumaRestados);

	return 0;
}