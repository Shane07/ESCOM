#include <iostream>
#define FLAG_DEBUG false

/*
	Algoritmo: busqueda binaria iterativa y recursiva
	Por Eder Or - multiaportes.com
*/

using namespace std;

// Definicion de clases
class AlgoritmoBB
{
	private:
		int *arreglo;
		unsigned int i, j, k, valor;
		unsigned int getTamanio();
		bool bBin(int, int, int);
	public:
		AlgoritmoBB(const int, unsigned int, int *);
		bool bBin(); // Sobrecarga de metodos
		bool bB();
};

// Implementacion de constructores y metodos
AlgoritmoBB::AlgoritmoBB(const int valor, unsigned int tamanio, int *arreglo)
{
	this->arreglo = arreglo;
	this->valor = valor;
	this->i = 0;
	this->j = tamanio;
	this->k = (i+j)/2;
}
bool AlgoritmoBB::bBin()
{
	while(i <= j)
	{
		if(FLAG_DEBUG)
			cout<<arreglo[k]<<"=="<<valor<<"?"<<endl;
		
		if(arreglo[k] == valor)
			return true;
		else
		{
			if(valor > arreglo[k])
				i = k+1;
			else
				j = k-1;
			k = (i+j) / 2;
		}
			
	}
	return false;
}
bool AlgoritmoBB::bB()
{
	return (this->bBin(this->i, this->j, this->k))? true: false;
}
bool AlgoritmoBB::bBin(int i, int j, int k)
{
	if(i <= j)
	{
		if(arreglo[k] == valor)
			return true;
		else
		{
			(valor > arreglo[k])? i = k+1: j = k-1;
			this->k = (i+j)/2;
			this->bBin(i, j, this->k);
		}
	}
	else
		return false;
}
unsigned int AlgoritmoBB::getTamanio()
{
	return sizeof(this->arreglo) / sizeof(this->arreglo[0]);
}

int main(int argc, char **argv)
{
	int v[]={1,2,3,4,5};
	AlgoritmoBB *a;

	cout<<"Por Eder Ortega - multiaportes.com"<<endl;

	/*
		Forma 1: AlgoritmoBB h; -> Usa el constructor por defecto
		Forma 2: ALgoritmoBB h = Algoritmo();
		Forma 3: AlgoritmoBB *h = new Algoritmo(); -> 'new' retorna un puntero
	*/
	
	for(int w = 1; w <= 6; w++)
	{
		a = new AlgoritmoBB(w, sizeof(v)/sizeof(v[0]), v); // Si se pasa a 'v' como argumento de funcion, el tamanio calculado cambia debido a que ahora se hace referencia al tamanio de los punteros
		(a->bBin())? cout<<"\t"<<w<<": encontrado!\t\t(iterativo)"<<endl:cout<<"\t"<<w<<": no encontrado\t(iterativo)"<<endl;
		(a->bB())? cout<<"\t"<<w<<": encontrado!\t\t(recursivo)"<<endl:cout<<"\t"<<w<<": no encontrado\t(recursivo)"<<endl;
	}

	return 0;
}
