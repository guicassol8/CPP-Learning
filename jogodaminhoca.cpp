#include <iostream>
#define TAMANHOTABULEIRO 9

using namespace std;

class minhoca {
	public:
	short int tamanho;
	short int posicaoColuna;
	short int posicaoLinha;
	minhoca (){
		tamanho = 1;
		posicaoColuna = TAMANHOTABULEIRO/2;
		posicaoLinha = TAMANHOTABULEIRO/2;
	}
	void AtualizarPosicao (short int coluna, short int linha)
	{
		posicaoColuna += coluna;
		posicaoLinha += linha;
	}
};
class tabuleiro {
	public:
	char tabuleiro1[TAMANHOTABULEIRO][TAMANHOTABULEIRO];
	tabuleiro ()
	{
	for (int i = 0; i < TAMANHOTABULEIRO; i++){
		for (int j = 0; j < TAMANHOTABULEIRO; j++){
			tabuleiro1[i][j] = '.';
		}
	}
	}
	
	void AtualizarTabuleiro (short int linha, short int coluna)
	{
		tabuleiro1 [linha][coluna] = 'o';
	}
	
	void ImprimirTabuleiro ()
	{
	for (int i = 0; i < TAMANHOTABULEIRO; i++)
	{
		for (int j = 0; j < TAMANHOTABULEIRO; j++)
		{
			cout << tabuleiro1[i][j] << " ";
		}
		cout << endl;
	}
	}

};
int main()
{
	tabuleiro tabuleiro1;
	minhoca minhoca1;
	tabuleiro1.AtualizarTabuleiro(minhoca1.posicaoLinha, minhoca1.posicaoColuna);
	tabuleiro1.ImprimirTabuleiro();

	return 0;
}