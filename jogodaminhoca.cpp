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
	void AumentarTamanho ()
	{
		tamanho++;
	}
	void AvaliarInput (char input)
	{
		switch (input){
		case 'w':
			posicaoColuna--;
			break;
		case 's':
			posicaoColuna++;
			break;
		case 'a':
			posicaoLinha--;
			break;
		case 'd':
			posicaoLinha++;
			break;
		}
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
	tabuleiro1 [TAMANHOTABULEIRO/2][TAMANHOTABULEIRO/2] = 'o';
	}
	
	void AtualizarTabuleiro (short int linha, short int coluna)
	{
		tabuleiro1 [coluna][linha] = 'o';
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
	char input;
	tabuleiro1.ImprimirTabuleiro();
	while (1)
	{
		scanf ("%c", &input);
		minhoca1.AvaliarInput(input);
		tabuleiro1.AtualizarTabuleiro(minhoca1.posicaoLinha, minhoca1.posicaoColuna);
		tabuleiro1.ImprimirTabuleiro();
	}
	return 0;
}