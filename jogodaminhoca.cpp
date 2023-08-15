#include <iostream>
#define TAMANHOTABULEIRO 9

using namespace std;
void IniciarTabuleiro (char tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO]);
void ImprimirTabuleiro (char tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO]);

class minhoca {
	public:
	short int tamanho;
	short int posicao [TAMANHOTABULEIRO][TAMANHOTABULEIRO];
	void MudaPosicao (short int coluna, short int linha)
	{
		
	}
};

int main()
{
	char tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO];
	IniciarTabuleiro(tabuleiro);
	tabuleiro [TAMANHOTABULEIRO/2][TAMANHOTABULEIRO/2] = 'O';
	ImprimirTabuleiro(tabuleiro);
	minhoca minhoca1;
	minhoca1.tamanho = 1;
	minhoca1.posicao[0][0] = 1;
	
	return 0;
}

void IniciarTabuleiro (char tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO])
{
	for (int i = 0; i < TAMANHOTABULEIRO; i++){
		for (int j = 0; j < TAMANHOTABULEIRO; j++){
			tabuleiro[i][j] = '.';
		}
	}
}

void ImprimirTabuleiro (char tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO])
{
	for (int i = 0; i < TAMANHOTABULEIRO; i++)
	{
		for (int j = 0; j < TAMANHOTABULEIRO; j++)
		{
			cout << tabuleiro[i][j] << " ";
		}
		cout << endl;
	}
}