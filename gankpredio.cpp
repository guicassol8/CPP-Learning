#include <iostream>
#include <vector>

using namespace std;

int contador = 0;

class fila{
	private:

	public:
	fila(){
	}
	vector<int> comparar(vector<int> filecaOriginal){
		vector<int> fileca;
		cout<<"valor size: "<<filecaOriginal.size()<<endl;
		if (filecaOriginal.size()%2 > 0){
			filecaOriginal.resize(filecaOriginal.size()-1);
		}
		for (int i = 1; i < filecaOriginal.size();){
			for (int j = 0; j < filecaOriginal[i-1]; j++){
			fileca.push_back(filecaOriginal[i]);
			}
			i = i + 2;
		}
		return fileca;
	}
};

int main (){
	vector <int> filecaOriginal;
	fila fileca;
	int input;
	for (int i = 0; i < 6; i++){
		cin >> input;
		filecaOriginal.push_back(input);
	}
	for (int i = 0; i < 20; i++){
		filecaOriginal = fileca.comparar(filecaOriginal);
		cout<<"Ciclo:"<<i<<endl;
	}
	cout<<"valor size: "<<filecaOriginal.size()<<endl;
	}