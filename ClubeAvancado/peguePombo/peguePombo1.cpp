#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>

using namespace std;

struct Ponto{
	public:
		string nome;
		int valorArestra;
		Ponto (string nome, int valorArestra = 0){
			this->nome = nome;
			this->valorArestra = valorArestra;
		}
};


class speedRunner {
	private:
		/*Hash map onde string eh o nome do ponto, e vector armazena os pontos adjacentes (com seus custos de arestra se necessario)*/
		unordered_map<string, vector <Ponto>> pontos;
		int quantPontos;
	public:
		speedRunner(){
		}
		void setPontos (){
			
		}
};

int main (){
    char prevChar = '\0'; // Initialize to a non-uppercase character
    char currentChar;
	vector<Ponto> pontos;
	int valor = 0;

    while (std::cin.get(currentChar)) {
        if (std::isupper(currentChar) && std::isupper(prevChar)) {
            std::cout << "Found two uppercase characters together: " << prevChar << currentChar << std::endl;
			string stringCombinada;
			stringCombinada += prevChar;
			stringCombinada += currentChar;
			pontos.push_back(Ponto(stringCombinada));
        }
		prevChar = currentChar;
		if (isdigit(currentChar)){
			valor = currentChar - '0';
		}
    }
	cout << "Valor: " << valor << endl;

    return 0;
}
