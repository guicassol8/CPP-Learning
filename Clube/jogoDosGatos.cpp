#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Gato {
	public:
		queue <int> gato1;
		queue <int> gato2;
		Gato (){

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

		int batalhaDeGatos (){
			while (1){
				if (gato1.size() == 0){
					return ganhador(gato2);
				}
				if (gato2.size() == 0){
					return ganhador(gato1);
				}
				if (gato1.front() > gato2.front()){
					gato1.push(gato1.front());
					gato1.push(gato2.front());
					gato1.pop();
					gato2.pop();
				}
				else {
					gato2.push(gato2.front());
					gato2.push(gato1.front());
					gato2.pop();
					gato1.pop();
				}
			}
		}
		int ganhador (queue <int> gato){
			int resultado = 0;
			for (int i = gato.size(); i > 0; i--){
				cout << gato.front() << endl;
				resultado += gato.front()*i;
				gato.pop();
			}
			return resultado;
		}
};

int main (){
	Gato NekoCafe;
	string player;
	getline(cin, player);
	NekoCafe.getBaralho(player);
	getline(cin,player);
	NekoCafe.getBaralho(player);
	cout<< NekoCafe.batalhaDeGatos() << endl;
	return 0;
}