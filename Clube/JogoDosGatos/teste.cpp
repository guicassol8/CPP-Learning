#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class Gato {
	public:
		queue <int> gato1;
		queue <int> gato2;
		vector <unordered_set <string>> combinacoes;
		Gato (){
			unordered_set <string> aux;
			combinacoes.push_back(aux);
		}
		void getBaralho (string player){
			vector <int> baralho;
			int num;
			string aux;
			while (1){
				getline (cin, aux);
				num = stoi(aux);
				if (num == -1){
					break;
				}
				baralho.push_back(num);
			}
			if (player == "Player 1:"){
				for (int i = 0; i < baralho.size(); i++){
					gato1.push(baralho[i]);
				}
			}
			else {
				for (int i = 0; i < baralho.size(); i++){
					gato2.push(baralho[i]);
				}	
			}
		}

		// int batalhaDeGatos (){
		// 	while (1){
		// 		if (gato1.size() == 0){
		// 			return ganhador(gato2);
		// 		}
		// 		if (gato2.size() == 0){
		// 			return ganhador(gato1);
		// 		}
		// 		if (gato1.front() > gato2.front()){
		// 			gato1.push(gato1.front());
		// 			gato1.push(gato2.front());
		// 			gato1.pop();
		// 			gato2.pop();
		// 		}
		// 		else {
		// 			gato2.push(gato2.front());
		// 			gato2.push(gato1.front());
		// 			gato2.pop();
		// 			gato1.pop();
		// 		}
		// 	}
		// }
		int batalhaDeGatosRecursiva(int quantVetor){
			//cout << toString() << endl;
			if (gato1.size() == 0){
				//cout << "gato 2 venceu definitivamente" << endl;
				return 2;
			}
			if (gato2.size() == 0){
				//cout << "gato 1 venceu definitivamente" << endl;
				return 1;
			}
			if (inList(quantVetor)){
				//cout << "esse embate ja aconteceu (gato 1 venceu)" << endl;
				return 1;
			}
			else{
				//cout << "esse embate nunca aconteceu" << endl;
				combinacoes[quantVetor].insert(toString());
			}
			if(gato1.front() <= gato1.size()-1 && gato2.front() <= gato2.size()-1){
				//cout << "voltaram no tempo" << endl;
				queue <int> aux1 = gato1;
				queue <int> aux2 = gato2;
				int front1 = aux1.front();
				int front2 = aux2.front();
				gato1.pop();
				gato2.pop();
				queue <int> gatoTeleporte1;
				queue <int> gatoTeleporte2;
				for (int i = 0; i < front1; i++){
					gatoTeleporte1.push(gato1.front());
					gato1.pop();
				}
				gato1 = gatoTeleporte1;
				for (int i = 0; i < front2; i++){
					gatoTeleporte2.push(gato2.front());
					gato2.pop();
				}
				gato2 = gatoTeleporte2;
				unordered_set <string> aux;
				combinacoes.push_back(aux);
				int ganhador = batalhaDeGatosRecursiva(quantVetor + 1);
				combinacoes.pop_back();
				gato1 = aux1;
				gato2 = aux2;
				if (ganhador == 1){
					//cout << "gato 1 venceu (depois de retroceder no tempo)" << endl;
					gato1.push(gato1.front());
					gato1.push(gato2.front());
					gato1.pop();
					gato2.pop();
				}
				else if (ganhador == 2){
					//cout << "gato 2 venceu (depois de retroceder no tempo)" << endl;
					gato2.push(gato2.front());
					gato2.push(gato1.front());
					gato2.pop();
					gato1.pop();
				}
			}
			else if (gato1.front() > gato2.front()){
				//cout << "gato 1 venceu" << endl;
				gato1.push(gato1.front());
				gato1.push(gato2.front());
				gato1.pop();
				gato2.pop();
			}
			else {
				//cout << "gato 2 venceu" << endl;
				gato2.push(gato2.front());
				gato2.push(gato1.front());
				gato2.pop();
				gato1.pop();
			}
			//cout << "fim do combate" << endl;
			return batalhaDeGatosRecursiva(quantVetor);
		}
		int ganhador (int ganhador){
			queue <int> gato;
			if (ganhador == 1){
				gato = gato1;
			}
			else{
				gato = gato2;
			}
			int resultado = 0;
			for (int i = gato.size(); i > 0; i--){
				//cout << gato.front() << " ";
				resultado += gato.front()*i;
				gato.pop();
			}
			//cout << endl;
			return resultado;
		}
		string toString (){
			stringstream ss;
			queue <int> aux1 = gato1;
			queue <int> aux2 = gato2;
			int size1 = aux1.size();
			int size2 = aux2.size();

			for (int i = 0; i < size1; i++){
				ss << to_string(aux1.front()) << " ";
				aux1.pop();
			}
			ss << "/";
			for (int i = 0; i < size2; i++){
				ss << to_string(aux2.front()) << " ";
				aux2.pop();
			}
			return ss.str();
		}
		bool inList (int quantVetor){
			string aux = toString();
			for (int i = 0; i <= quantVetor; i++){
				if (combinacoes[i].find(aux) != combinacoes[i].end()){
					return true;
				}
			}
			return false;
		}
};

int main (){
	Gato NekoCafe;
	string player;
	int quantVetor = 0;
	getline(cin, player);
	NekoCafe.getBaralho(player);
	getline(cin,player);
	NekoCafe.getBaralho(player);
	int ganhador = NekoCafe.batalhaDeGatosRecursiva(quantVetor);
	cout << NekoCafe.ganhador(ganhador) << endl;
	cout << ganhador << endl;
	return 0;
}