#include <stdio.h>

void printBin(const int w, char *cd)
{
	unsigned int z, c;
	for(z = 0; z < w; z++)
	{
		for(c = 0x80; c > 0; c >>= 1)
			(c&cd[z])? printf("1") : printf("0");
		printf("\n");
	}
}
void emisorCRC(void)
{
	unsigned char tramaHex[] = {0xf0, 0x00, 0x00, 0x00, 0x00}; // 4 ceros = 32 bits agregados para CRC32 (polinomio grado 32)
	unsigned int x, y, px = 0x04C11DB7, rsd = 0;

	printBin(sizeof(tramaHex), tramaHex);

	for(x = 0; x < sizeof(tramaHex); x++)
		for(y = 0x80; y > 0; y >>= 1)
		{
			if(rsd & 0x80000000)
			{
				rsd <<= 1;
				rsd ^= px;
			}
			else
			{
				rsd <<= 1;

				if(tramaHex[x] & y)
					rsd |= 1;
			}
		}

	fprintf(stdout, "CRC32: 0x%x\nPor Ortega Ortunio Eder - 2CM9 | multiaportes.com\n", rsd); // %X para imprimir en mayusculas
}

int main(int args, char **argv)
{
	if(strcmp(argv[1], "--tx") == 0)
		emisorCRC();
	//else if(strcmp(argv[1], "--rx") == 0)
		//receptorCRC();
	else
		fprintf(stderr, "Argumento desconocido");
	return 0;
}