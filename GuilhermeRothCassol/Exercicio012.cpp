//Exercicio012.cpp,Guilherme Roth Cassol,Exercicio 12, 21/08/2023
#include <iostream>

using namespace std;

int main ()
{
	int tamanhaMatriz;
	cin>>tamanhaMatriz;
	int matriz[tamanhaMatriz][tamanhaMatriz];
	for (int i=0;i<tamanhaMatriz;i++){
		for (int j=0;j<tamanhaMatriz;j++){
			cin>>matriz[i][j];
	}
	}
	int menor = 1000;
	int linhaMenor = 0;
	for (int i=0;i<tamanhaMatriz;i++)
	{
		for (int j=0;j<tamanhaMatriz;j++)
		{
			if (matriz[i][j]<menor)
			{
				menor = matriz[i][j];
				linhaMenor = i ;
			}
		}
	}
	cout<<linhaMenor<<endl;
}