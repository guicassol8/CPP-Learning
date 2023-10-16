#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Decodificador {
private:
int registrador;
int ciclo;
int valorFinal;
string transmissao;
public:
	Decodificador(){
		cout << "Objeto Criado" << endl;
		registrador = 1;
		ciclo = 0;
		valorFinal = 1;
		transmissao.resize(240);
	}
	void addx(int valor){
		registrador = registrador + valor;
	}
	void cicloIncrement(){
		ciclo = ciclo + 1;
		setTransmissao();
		if (ciclo == 20|| ciclo == 60 || ciclo == 100 || ciclo == 140 || ciclo == 180 || ciclo == 220){
			incrementarAux();
		}

		ciclo = ciclo + 1;
		setTransmissao();
			if (ciclo == 20|| ciclo == 60 || ciclo == 100 || ciclo == 140 || ciclo == 180 || ciclo == 220){
			incrementarAux();
		}
	}
	void noop (){
		ciclo = ciclo + 1;
		setTransmissao();
		if (ciclo == 20|| ciclo == 60 || ciclo == 100 || ciclo == 140 || ciclo == 180 || ciclo == 220){
			incrementarAux();
		}
	}
	int getValorCiclo (){
		return ciclo;
	}
	void incrementarAux (){
		valorFinal+= ciclo*registrador;
	}
	int getValorFinal(){
		return valorFinal;
	}
	int getRegistrador(){
		return registrador;
	}
	void setTransmissao(){
		cout<<"Ciclo: "<<ciclo<<endl;
		cout<<"Registrador: "<<registrador<<endl;
		int cicloRelativo = ciclo/40;
		int registrador1 = registrador + 1;
		if (ciclo == registrador1 + (40*cicloRelativo)|| ciclo == registrador1 +1 + (40*cicloRelativo) || ciclo == registrador1 -1 + (40*cicloRelativo)){
			transmissao[ciclo-1] = '#';
		}
		else{
			transmissao[ciclo-1] = '.';
		}
		cout<<transmissao[ciclo-1]<<endl;
	}
	void printTransmissao(){
		for (int i = 1; i <=240; i++){
			cout << transmissao[i-1];
			if (i== 40||i == 80||i == 120||i == 160||i == 200||i == 240){
				cout << endl;
			}
		}
	}
};

int main(){
	string input;
	int aux;
	Decodificador decodificador;
	while (1){
		cin >> input;
		if (input == "exit"){
			break;
		}
		if (input == "addx"){
			cin >> aux;
			decodificador.cicloIncrement();
			decodificador.addx(aux);
		}
		if (input == "noop"){
			decodificador.noop();
		}
	}
	cout<<decodificador.getValorFinal()<<endl;
	decodificador.printTransmissao();
	return 0;
}