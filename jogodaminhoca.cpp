#include <iostream>
#include <cstdlib>
#include <vector> 
#include <random>
#include <thread>
#define TAMANHOTABULEIRO 8

using namespace std;

void clearConsole();

class apple{
	private:
	int min;
	int max;
	int randomLinha;
	int randomColuna;
	int random;
	public:
	apple(){
		min = 0;
		max = TAMANHOTABULEIRO-1;
		randomLinha = 0;
		randomColuna = 0;
		random = 0;
	}
	void GerarApple(char tabuleiro[TAMANHOTABULEIRO][TAMANHOTABULEIRO]){
		std::random_device rd;
    	std::mt19937 gen(rd());
		uniform_int_distribution<> abs(0, 4);
		random = abs(gen);
		uniform_int_distribution<> dis(min, max);
		randomLinha = dis(gen);
		randomColuna = dis(gen);
		if (random != 3){
			return;
		}
		if (tabuleiro[randomLinha][randomColuna] == 'o'||tabuleiro[randomLinha][randomColuna] == 'I'){
			GerarApple(tabuleiro);
			return;
		}
		else {
		tabuleiro [randomLinha][randomColuna] = '@';
		}
	}
};
class minhoca {
	private:
		vector <short int> posicaoColuna;
		vector <short int> posicaoLinha;
		int tamanhoMinhoca;
		short int posicaoColunaAntiga;
		short int posicaoLinhaAntiga;
		bool cresceu;
		char inputPassado;
	public:
	minhoca (){
		#ifdef DEBUG
		cout<<"Minhoca criada"<<endl;
		#endif
		tamanhoMinhoca = 0;
		posicaoColuna.push_back(TAMANHOTABULEIRO/2);
		posicaoLinha.push_back(TAMANHOTABULEIRO/2);
		cresceu = false;
	}
	bool avaliarDerrota (char tabuleiro [TAMANHOTABULEIRO][TAMANHOTABULEIRO]){
		if (tabuleiro [posicaoColuna[tamanhoMinhoca]][posicaoLinha[tamanhoMinhoca]] == 'o'){
			clearConsole();
			cout<<"Como que perde em joguinho de cobra..."<<endl;
			return true;
		}
		if (posicaoColuna[tamanhoMinhoca] == TAMANHOTABULEIRO || posicaoColuna[tamanhoMinhoca] == -1 ||
		posicaoLinha[tamanhoMinhoca] == TAMANHOTABULEIRO || posicaoLinha[tamanhoMinhoca] == -1){
			clearConsole();
			cout<<"Deu de cara na parede KKKKKKKKK"<<endl;
			return true;
		}
		if (tamanhoMinhoca == (TAMANHOTABULEIRO*TAMANHOTABULEIRO)-1){
			cout<<"Ganhou parabens"<<endl;
			
			return true;
		}
		
		return false;
	}
	void AvaliarInput (char input,char tabuleiro [TAMANHOTABULEIRO][TAMANHOTABULEIRO])
	{
		switch (input){
		case 'w':
			if (tabuleiro [posicaoColuna[tamanhoMinhoca]-1][posicaoLinha[tamanhoMinhoca]] == '@'){
				crescerTamanho();
			}
			if (cresceu == true){
				posicaoColuna.push_back(posicaoColuna[tamanhoMinhoca-1]-1);
				posicaoLinha.push_back(posicaoLinha[tamanhoMinhoca-1]);
				//AtualizarPosicao();
				inputPassado = input;
				break;
			}
			AtualizarPosicao();
			posicaoColuna[tamanhoMinhoca]--;
			inputPassado = input;
			break;
		case 's':
			if (tabuleiro [posicaoColuna[tamanhoMinhoca]+1][posicaoLinha[tamanhoMinhoca]] == '@'){
			crescerTamanho();
			}
			if (cresceu == true){
				posicaoColuna.push_back(posicaoColuna[tamanhoMinhoca-1]+1);
				posicaoLinha.push_back(posicaoLinha[tamanhoMinhoca-1]);
				inputPassado = input;
				//AtualizarPosicao();
				break;
			}
			AtualizarPosicao();
			posicaoColuna[tamanhoMinhoca]++;
			inputPassado = input;
			break;
		case 'a':
			if (tabuleiro [posicaoColuna[tamanhoMinhoca]][posicaoLinha[tamanhoMinhoca]-1] == '@'){
			crescerTamanho();
			}
			if (cresceu == true){
				posicaoColuna.push_back(posicaoColuna[tamanhoMinhoca-1]);
				posicaoLinha.push_back(posicaoLinha[tamanhoMinhoca-1]-1);
				inputPassado = input;
				//AtualizarPosicao();
				break;
			}
			AtualizarPosicao();
			posicaoLinha[tamanhoMinhoca]--;
			inputPassado = input;
			break;
		case 'd':
			if (tabuleiro [posicaoColuna[tamanhoMinhoca]][posicaoLinha[tamanhoMinhoca]+1] == '@'){
			crescerTamanho();
			}
			if (cresceu == true){
				posicaoColuna.push_back(posicaoColuna[tamanhoMinhoca-1]);
				posicaoLinha.push_back(posicaoLinha[tamanhoMinhoca-1]+1);
				inputPassado = input;
				//AtualizarPosicao();
				break;
			}
			AtualizarPosicao();
			posicaoLinha[tamanhoMinhoca]++;
			inputPassado = input;
			break;
		default:
			AvaliarInput(inputPassado = 'w',tabuleiro);
			break;
		}
		cresceu = false;
		
		return;
	}
	void AtualizarPosicao (){
		for (int i = 0; i < tamanhoMinhoca; i++){
			posicaoColuna [i] = posicaoColuna [i+1];
			posicaoLinha [i] = posicaoLinha [i+1];
			
		}
	}
	short int getPosicaoColuna (short int a = 0){
		
		return posicaoColuna[a];
	}
	short int getPosicaoLinha (short int a = 0){
		
		return posicaoLinha[a];
	}
	void crescerTamanho (){
		tamanhoMinhoca++;
		
		cresceu = true;
	}
	bool getCresceu (){
		
		return cresceu;
	}
	int getTamanhoMinhoca (){
		
		return tamanhoMinhoca;
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
	void posicaoAntiga (short int linha, short int coluna, bool cresceu){
		tabuleiro1 [coluna][linha] = '.';
		
	}
	void cauda (short int linha, short int coluna){
		tabuleiro1 [coluna][linha] = 'I';
		
	}
	
	void ImprimirTabuleiro ()
	{
	for (int i = 0; i < TAMANHOTABULEIRO; i++)
	{
		for (int j = 0; j < TAMANHOTABULEIRO; j++)
		{
			if (tabuleiro1[i][j] == 'I' || tabuleiro1[i][j] == 'o'){
				cout<<"\033[1;31m";
			}
			if(tabuleiro1[i][j] == '@'){
				cout<< "\033[1;33m";
			}
			cout << tabuleiro1[i][j] << "\033[0m" << " ";
		}
		cout << endl;
	}
	}

};
int main()
{
	clearConsole();
	tabuleiro tabuleiro1;
	minhoca minhoca1;
	apple apple1;
	char input;
	apple1.GerarApple(tabuleiro1.tabuleiro1);
	tabuleiro1.ImprimirTabuleiro();
	while (1)
	{
		cin >> input;
		tabuleiro1.posicaoAntiga(minhoca1.getPosicaoLinha(0), minhoca1.getPosicaoColuna(0),minhoca1.getCresceu());
		minhoca1.AvaliarInput(input,tabuleiro1.tabuleiro1);
		cin.ignore();
		if (minhoca1.avaliarDerrota(tabuleiro1.tabuleiro1)){
			break;
		}
		for (int i = 0 ; i <= minhoca1.getTamanhoMinhoca(); i++){
		tabuleiro1.AtualizarTabuleiro(minhoca1.getPosicaoLinha(i), minhoca1.getPosicaoColuna(i));
		}
		if (minhoca1.getTamanhoMinhoca() > 0){
		tabuleiro1.cauda(minhoca1.getPosicaoLinha(0), minhoca1.getPosicaoColuna(0));
		}
		clearConsole();
		apple1.GerarApple(tabuleiro1.tabuleiro1);
		tabuleiro1.ImprimirTabuleiro();
	}
	return 0;
}

void clearConsole()
{
	system("clear");
}