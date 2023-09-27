#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Amarelinha
{
private:
	vector<int> quadrados;

public:
	Amarelinha()
	{
		quadrados.clear();
	}
	unsigned long int verificarCorrupcao(vector<int> aux)
	{
		bool ganhou = false;
		int indiceAtual = 0;
		int indiceRelativo = 0;
		int atualVerdadeiro = aux[0];
		int avancado = aux[1];
		int maiorRelativo = 0;
		while (1)
		{	
			bool entrou = false;
			atualVerdadeiro = aux[indiceAtual];
			avancado = aux[indiceAtual + 1];
			maiorRelativo = avancado + indiceAtual + 1;
			//cout<<"indiceAtual: "<<indiceAtual<<endl;
			//cout<<"indiceRelativo: "<<indiceRelativo<<endl;
			//cout<<"atualVerdadeiro: "<<atualVerdadeiro<<endl;
			//cout<<"avancado: "<< avancado <<endl;
			if (atualVerdadeiro == 0){
				return 1;
			}
			if (atualVerdadeiro + indiceAtual >= aux.size() - 1){
				return 0;
			}
			for (int i = 0; i < atualVerdadeiro - 1; i++){
				//cout<< "maiorRelativo: "<< maiorRelativo<<endl;
				//cout << "comparado:"<< aux[indiceAtual + i + 2]<<endl;
				if (maiorRelativo < aux[indiceAtual + i + 2] + indiceAtual + i + 2){
					indiceRelativo = indiceAtual + i + 2;
					maiorRelativo = aux[indiceAtual + i + 2] + indiceAtual + i + 2;
					entrou = true;
				}
			}
			if (entrou == false){
				indiceAtual = indiceAtual + 1;
			}
			if (entrou == true){
				indiceAtual = indiceRelativo;
			}
		}
		}
};

int main()
{
	unsigned long int indiceAmarelinha = 1;
	Amarelinha a;
	int ganhou;
	unsigned long int corrupcao = 1;
	while (1)
	{
		std::string input;
		vector<int> aux;
		std::getline(std::cin, input);
		if (input == "-1")
		{
			break;
		}
		for (int i = 0; i < input.size(); i += 2)
		{
			aux.push_back(input[i] - '0');
		}
		unsigned long int ganhou = a.verificarCorrupcao(aux);
		//cout<<"indiceamarelinha: "<<indiceAmarelinha<<" ganhou: ";
		//cout<<ganhou<<endl;
		if (ganhou == 1)
		{
			corrupcao *= indiceAmarelinha;
			corrupcao = corrupcao % (unsigned long int)(pow(10, 9) + 7);
		}
		aux.clear();
		indiceAmarelinha++;
	}
	cout<<corrupcao<<endl;
	return 0;
}