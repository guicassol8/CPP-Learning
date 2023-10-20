#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>

using namespace std;

class speedRunner {
	private:
		/*Hash map onde string eh o nome do ponto, e vector armazena os pontos adjacentes (com seus custos de arestra se necessario)*/
		unordered_map<string,int> valor;
		unordered_map<string,vector<string>> caminhos;
		int quantPontos;
	public:
		speedRunner(){
		}
};

int main (){
	speedRunner speed;
    char prevChar = '\0'; // Initialize to a non-uppercase character
	string nome;
	string linha;
	vector<string> chaves;
	vector <string> caminho;
	int valor = 0;

	while (getline(cin, linha)){
		bool aparicao = true;
		prevChar = linha[0];
		for (int i = 1; i < linha.size(); i++){
			if (isupper(linha[i]) && prevChar == linha[i]){
				string combinada;
				combinada += prevChar;
				combinada += linha[i];
				if (aparicao){
					nome = combinada;
					chaves.push_back(combinada);
					aparicao = false;
				}
				else{
					caminho.push_back(combinada);
				}
			}
			if (isdigit(linha[i])){
				valor = linha[i] - '0';
				if(isdigit(linha[i-1])){
					valor += (linha[i-1] - '0') * 10 ;
				}
			}
			prevChar = linha[i];
		}
		//cout << "String: " << caminho << endl;
		cout << "Valor: " << valor << endl;
	}
    return 0;
}
