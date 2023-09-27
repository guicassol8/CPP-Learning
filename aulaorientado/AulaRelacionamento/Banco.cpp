#include <iostream>
#define MAXCONTAS 100

using namespace std;

class Conta{
	private:
		int numero;
		double saldo;
	public:
		Conta(int n = 0, double s = 0){
			numero = n;
			saldo = s;
		}
		int obtemNumero(){
			return numero;
		}
		double obtemSaldo(){
			return saldo;
		}
		void depositar(double valor){
			saldo += valor;
		}
		double retirar (double valor){
			saldo -= valor;
			return valor;
		}
		bool excluir (double valor){
			if (valor > saldo){
				return false;
			}
			saldo -= valor;
			return true;
		}
};
	

class Banco {
	private:
		string nome;
		int numContas;
		Conta contas[MAXCONTAS];
	public:
		Banco(string n = ""){
			nome = n;
			numContas = 0;
		}
		string getNome(){
			return nome;
		}
		bool adicionaConta (const Conta &c){
			if (numContas == MAXCONTAS){
				return false;
			}
			contas [numContas] = c;
			numContas++;
			return true;
		}
		Conta* obtemConta(int i){
			if (i < 0 || i >= numContas){
				return NULL;
			}
			return &contas[i-1];
		}
		bool transferir(Conta &deCC, Conta &paraCC, double valor){
			if (!deCC.excluir(valor)){
				return false;
			}
			paraCC.depositar(valor);
			return true;
		}
		double obtemSaldoTotal(){
			double total = 0;
			for (int i = 0; i < numContas; i++){
				total += contas[i].obtemSaldo();
			}
			return total;
		}
		int getNumContas(){
			return numContas;
		}
		string str(const Conta &c){}
};


int main (){
	Banco b("Banco do Brasil");
	while (1){
		int input = 0;
		int saldo = 0;
		cout<< "Menu" << endl << "1 - Adicionar Conta"<< endl <<"2 - Obter Conta"<< endl <<
		"3 - Transferir"<< endl <<"4 - Obter Saldo Total"<< endl <<"5 - Sair"<< endl;
		cin>>input;
		if (input == 5){
			break;
		}
		switch (input){
			case 1:
				cout << "Digite o Saldo Inicial: "<<endl;
				cin >> saldo;
				Conta c(b.getNumContas(), saldo);
				break;
			case 2:
				cout << "Digite o numero da conta: "<<endl;
				cin >> saldo;
				b.obtemConta(saldo);
		}
	}
}
