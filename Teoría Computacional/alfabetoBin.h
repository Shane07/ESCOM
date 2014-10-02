#include <stdlib.h>
#include <math.h>
#include <gmp.h>

/*
 * IPN - ESCOM
 *
 * Libreria de funciones para el calculo de alfabetos binarios
 *
 * Ortega Ortunio Eder - 2CM6 | multiaportes.com
*/

typedef mpz_t entero;

double logBase2(unsigned long int n)
{
	return (log10((double) n) / log10((double) 2));
}
int esPrimo(unsigned long int num)
{
	int v;
	entero n;

	mpz_init(n);
	mpz_set_ui(n, num);

	v = mpz_probab_prime_p(n, 25);

	if(v == 2 || v == 1)
		return 1;
	else
		return 0;
}
void cleanStdin()
{
	getchar();
}

void ejercicioUno(const unsigned long int pot)
{
	unsigned long int k, z;
	entero p, tmp;

	mpz_init(p);
	mpz_init(tmp);

	for(unsigned long int a = 0; a <= pot; a++)
	{
		z = 1;

		printf("E^%lu = {", a);
		if(a == 0)
		{
			printf("}\n\n");
			continue;
		}
		mpz_ui_pow_ui(p, 2, a);
		for(unsigned long int b = 0; b < mpz_get_ui(p); b++)
		{
			if(a > 1)
			{
				if(b < mpz_get_ui(p)/2)
				{
					for(unsigned long int c = a - z; c > 0; c--)
						printf("0");
					if(b == 3)
						z++;
					else if(b == 4)
						z--;
					if(fmod(logBase2(b), 1.0) == 0.0 && b != 2) // Si logBase2(b) % 1 es cero entonces logBase2(b) es entero y b es potencia de dos
						z++;
				}
			}
			mpz_set_ui(tmp, b);
			mpz_out_str(stdout, 2, tmp);
			printf(", ");
		}
		printf("}\n\n");
	}

	mpz_clear(tmp);
	mpz_clear(p);
}

void ejercicioDos(const unsigned long int pot)
{
	unsigned long int k, z;
	entero p, tmp;

	mpz_init(p);
	mpz_init(tmp);

	for(unsigned long int a = 0; a <= pot; a++)
	{
		z = 1;

		printf("E^%lu = {", a);
		if(a == 0)
		{
			printf("}\n\n");
			continue;
		}
		mpz_ui_pow_ui(p, 2, a);
		for(unsigned long int b = 0; b < mpz_get_ui(p); b++)
		{
			if(a > 1)
			{
				if(b < mpz_get_ui(p)/2)
				{
					if(esPrimo(b))
						for(unsigned long int c = a - z; c > 0; c--)
							printf("0");
					if(b == 3)
						z++;
					else if(b == 4)
						z--;
					if(fmod(logBase2(b), 1.0) == 0.0 && b != 2) // Si logBase2(b) % 1 es cero entonces logBase2(b) es entero y b es potencia de dos
						z++;
				}
			}
			mpz_set_ui(tmp, b);
			if(esPrimo(b))
			{
				mpz_out_str(stdout, 2, tmp);
				printf(", ");
			}
		}
		printf("}\n\n");
	}

	mpz_clear(tmp);
	mpz_clear(p);
}