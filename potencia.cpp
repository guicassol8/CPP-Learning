#include <iostream>

using namespace std;

int PotenciaNormal (int base, int exp);
int PotenciaRecursiva (int base, int exp);



int main ( )
{
	int base, exp;
	scanf ("%d %d", &base, &exp);
	int potencia = PotenciaNormal (base, exp);
	int potencia2 = PotenciaRecursiva (base, exp);
	cout << potencia << endl;
	cout << potencia2 << endl;
}


int PotenciaNormal (int base, int exp)
{
	int resultado = base;
	if (exp == 0)
	{
		return 1;
	}
	for (int i = 1; i <exp; i++)
	{
		resultado = resultado * base;
	}
	return resultado;
}

int PotenciaRecursiva (int base, int exp)
{
	if (exp == 0)
	{
		return 1;
	}
	return PotenciaRecursiva (base, exp-1)* base;
}