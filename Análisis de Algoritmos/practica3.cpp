/*
	Por Ortega Ortuño Eder
	IPN - ESCOM
	Análisis de Algoritmos
	multiaportes.com/proyectos
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
	Errores conocidos: ultimo acarreo es ignorado al crear la tabla de multiplicacion y al sumar en vertical
	82 * 12

	  8 2
	x 1 2
	1 6 4 <-- El '1' es el ultimo acarreo pero el programa lo ignora y no se considera en la suma, por tanto el resultado es incorrecto
	8 2
	9 8 4

*/

class AlgoritmoMult
{
	private:
		int *t1, *t2, **op, MAX;
		char *m1, *m2;
		void rellenarMatriz()
		{
			int a, b;
			for(a = 0; a < *t2; a++)
				for(b = 0; b < *t1+MAX; b++)
					this->op[a][b] = 0;
		}
	public:
		AlgoritmoMult(char *m1, char *m2, int *t1, int *t2)
		{
			int v,w;

			this->m1 = &m1[0];
			this->m2 = &m2[0];
			this->t1 = t1;
			this->t2 = t2;
			this->MAX = *t2-1;

			this->op = new int*[*t2];
			for(w = 0; w < *t1; w++)
				op[w] = new int[*t1+MAX];

			this->rellenarMatriz();
		}
		void multiplicar()
		{
			int a, b, ap_m1, ap_m2 = *t2-1, desplazamiento = 0, acarreo = 0, r = 0;
			vector<int> reversa;

			for(a = 0; a < *t2; a++)
			{
				ap_m1 = *t1-1;
				acarreo = 0;

				for(b = *t1+MAX-1; b >= 0; b--)
				{
					op[a][b-desplazamiento] = (m1[ap_m1] - '0') * (m2[ap_m2] - '0') + acarreo; // Convertir a entero
					acarreo = 0;

					if(op[a][b-desplazamiento] > 9)
					{
						acarreo = op[a][b-desplazamiento] / 10;
						op[a][b-desplazamiento] %= 10;
					}

					ap_m1--;
					if(ap_m1 < 0)
						break;
				}
				desplazamiento++;
				ap_m2--;
			}

// Imprimir tabla
			for(a = 0; a < *t2; a++)
			{
				for(b = 0; b < *t1+MAX; b++)
					cout<<"\t"<<op[a][b];
				cout<<endl;
			}

			acarreo = 0;

			for(b = *t1+MAX-1; b >= 0; b--)
			{
				r = acarreo;

				for(a = 0; a < *t2; a++)
					r += op[a][b];

				if(r > 9 && b > 0)
				{
					acarreo = r / 10;
					r %= 10;
				}
				else
					acarreo = 0;

				reversa.push_back(r);
			}

			for(a = reversa.size() - 1; a >= 0; a--)
				cout<<reversa.at(a);
			cout<<endl;
		}
		/*
		unsigned int multiplicar(unsigned int m1, unsigned int m2)
		{
			cout<<m1<<"*"<<m2<<endl;
			if(m2 % 2 == 0)
				return multiplicar(m1, m2/2) + multiplicar(m1, m2/2);
			else if(m2 != 1)
				return multiplicar(m1, m2/2) + multiplicar(m1, m2/2) + 1;
			else if(m2 == 0)
				return 0;
			else
				return m2;
		}*/
};

void printUso(void)
{
	cout<<"Practica 3: Algoritmo Multiplicacion\nPor Ortega Ortuno Eder - 3CM1\nAnalisis de Algoritmos\n"<<endl;
	cout<<"Uso:\n\t./multiplicar -m1 <numero1> -m2 <numero2> [--modo <clasico|div|gauss>]"<<endl;
}
void init(char m1[], char m2[], int *t1, int *t2)
{
	AlgoritmoMult *w;
	w = new AlgoritmoMult(m1, m2, t1, t2);
	w->multiplicar();
	//cout<<"\n\n\n\n"<<w->multiplicar(200, 40)<<endl;
}
int main(int argc, char **argv)
{
	int t1 = 0, t2 = 0;
	bool flag;

	if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4] != NULL)
		flag = (strcmp(argv[1], "-m1") == 0 && strcmp(argv[3], "-m2") == 0)? true: false;

	if(flag)
	{
		while(argv[2][t1])
			++t1;
		while(argv[4][t2])
			++t2;
		(t1 >= t2)? init(argv[2], argv[4], &t1, &t2):init(argv[4], argv[2], &t2, &t1);
	}
	else
		printUso();

	return 0;
}
