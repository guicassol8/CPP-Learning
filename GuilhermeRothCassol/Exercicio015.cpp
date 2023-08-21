//Exercicio015.cpp,Guilherme Roth Cassol,Exercicio 15, 21/08/2023
#include <iostream>

using namespace std;

int main ()
{
	int linha, coluna;
	cin >> linha >> coluna;
	int matriz[linha][coluna];
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			cin >> matriz[i][j];
		}
	}
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			cout << abs(matriz[i][j]) << " ";
		}
		cout << endl;
	}
}