#include <stdio.h>

// Detectar si un numero binario es par o impar de acuerdo con 2^0

int main()
{
	int num; // 4 bytes
	char a, a1, a2; // 1 byte
	short int b; // 2 bytes
	unsigned char x; // 1 byte (0 a 255)
	long int c; // 8 bytes

	char nombre[6] = {0x4e, 0x69, 0x64, 0x69, 0x61};

	a = 0x64; // Almacena el 64 en hexadecimal
	a1 = 'd';
	a2 = 100;

	// Imprimir valores char
	printf("a = %c\n", a);
	printf("a1 = %c\n", a1);
	printf("a2 = %c\n", a2);

	// Imprimir valores int
	printf("a = %d\n", a);
	printf("a1 = %d\n", a1);
	printf("a2 = %d\n", a2);

	// Imprimir valores hex
	printf("a = %x\n", a);
	printf("a1 = %x\n", a1);
	printf("a2 = %x\n", a2);

	fprintf(stdout, "%s", nombre);

	printf("Num: ");
	scanf("%d", &num);

	if(num != 1)
		printf("Impar");
	else
		printf("Par");
}
