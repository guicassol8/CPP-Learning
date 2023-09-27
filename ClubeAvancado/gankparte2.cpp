#include <iostream>
#include <vector>
#include "Nodo.h"
#include "DoubleLinkedListOfInteger.h"

using namespace std;

class Fila {
	private:
		DoubleLinkedListOfInteger lista;
		DoubleLinkedListOfInteger valor;
	public:
		Fila (){	
			lista.add(1);
			lista.add(1);
			lista.add(1);
			lista.add(1);
			lista.add(1);
			lista.add(1);
			valor.add(2);
			valor.add(4);
			valor.add(1);
			valor.add(5);
			valor.add(2);
			valor.add(3);
		}
		long int getFila (int numCiclos){
			for (int i = 0; i < numCiclos; i++){

				bool sobra = false;
				vector <int> supersobra;
				long int aux = 0;

				for (int i = 0; i < valor.size(); i++){
					aux += lista.get(i);
				}

				if (aux % 2 != 0){
					lista.set(lista.size()-1, lista.get(lista.size()-1)-1);
				}

				for (int j = 0; j < lista.size(); j++){

					if (lista.get(j) == 1 && sobra == false){
						cout << "entrou 1"<<endl;
						sobra = true;
						supersobra.push_back(j);
						continue;
					}

					if (sobra){
						if (lista.get(j) == 1){
							cout << "entrou 2"<<endl;
							sobra = false;
							lista.set(j, valor.get(j-1));
						}
						else if (lista.get(j) % 2 == 0){
							cout << "entrou 3"<<endl;
							sobra = true;
							lista.set(j, ((lista.get(j)-2)/2)*valor.get(j) + valor.get(j-1));
						}
						else{
							cout << "entrou 4"<<endl;
							sobra = false;
							lista.set(j, ((lista.get(j)-1)/2)*valor.get(j) + valor.get(j-1));
						}
					}

					else{
						if (lista.get(j) % 2 == 0){
							cout << "entrou 5"<<endl;
							sobra = false;
							lista.set(j, ((lista.get(j))/2)*valor.get(j));
						}
						else {
							cout << "entrou 6"<<endl;
							sobra = true;
							lista.set(j, ((lista.get(j)-1)/2)*valor.get(j));
						}
					}
				}
				
				for (int i = 0; i < lista.size(); i++){
					cout << lista.get(i) << " ";
				}
				cout<<endl;
				for (int i = 0; i < lista.size(); i++){
					cout << valor.get(i) << " ";
				}
				cout<<endl;
				if (supersobra.size() > 0){
					int aux = supersobra.size();
					for (int i = 0; i < aux; i++){
						cout << "entrou 7"<<endl;
						lista.removeByIndex(supersobra[i]-i);
						valor.removeByIndex(supersobra[i]-i);
					}
				}
				for (int i = 0; i < lista.size(); i++){
					cout << lista.get(i) << " ";
				}
				cout<<endl;
				for (int i = 0; i < lista.size(); i++){
					cout << valor.get(i) << " ";
				}
				cout<<endl;
			}
			long int aux = 0;
			for (int i = 0; i < lista.size(); i++){
				cout << lista.get(i) << " ";
				aux += lista.get(i);
			}
			return aux;
			}
		};

int main (){
	Fila fila;
	long int resultado = fila.getFila(60);
	cout <<endl;
	cout << " numerofinal: " << resultado << endl;
}