#include <iostream>
#include <cmath>
#include <string>
#include <vector>


using namespace std;

vector <int> OrdenarVetor1(int TamanhoNumero, vector <int> Numero);
class Simon
{
	public:
	string input;
	long int aux;
	int tamanhoVetor;
	Simon ()
	{
		aux = 0;
		tamanhoVetor = 0;
		cout<<"Objeto criado"<<endl;
	}
	~Simon ()
	{
		cout<<"Objeto destruido"<<endl;
	}
	void getTamanhoVetor ()
	{
		tamanhoVetor = input.length();
	}
	void OrdenarVetor ()
	{
		int j = tamanhoVetor-1;
		for (int i = 0; i <=j ; i++)
		{
			char auxiliar = input[i];
			input[i] = input[j];
			input[j] = auxiliar;
			j=j-1;
		}
	}
	void TransformarString ()
	{
		for (int i = 0; i < tamanhoVetor; i++)
		{
			switch (input[i])
			{
				case 'S':
				aux += (pow(5,i)) * 2;
				break;
				case 'I':
				aux += (pow(5,i)) * 1;
				break;
				case 'M':
				break;
				case 'O':
				aux += (pow(5,i)) * -1;
				break;
				case 'N':
				aux += (pow(5,i)) * -2;
				break;
			}
		}
	}
vector<int> decimalToBase5(long int decimal) {
    vector<int> base5Representation;
    
    while (decimal> 0) {
        int remainder = decimal % 5;
        base5Representation.push_back(remainder);
        decimal /= 5;
    }
    if (base5Representation.empty()) {
        base5Representation.push_back(0);
    }
    
    
    return base5Representation;
}
};

int main () {
	Simon simon;
	while (1)
	{
	getline(cin, simon.input);
	simon.getTamanhoVetor();
	simon.OrdenarVetor();
	simon.TransformarString();
	if (!getline (cin, simon.input))
	{
		break;
	}
	}
	cout<<simon.aux<<endl;
	vector<int> base5Representation = simon.decimalToBase5(simon.aux);
	int TamanhoNumero = base5Representation.size();
	base5Representation = OrdenarVetor1(TamanhoNumero, base5Representation);
	for (int i = 0; i < TamanhoNumero; i++)
	{
	cout<<base5Representation[i];
	}
	cout<<endl;
}

vector <int> OrdenarVetor1(int TamanhoNumero, vector <int> Numero)
{
		int j = TamanhoNumero-1;
		for (int i = 0; i <=j ; i++)
		{
			int auxiliar = Numero[i];
			Numero[i] = Numero[j];
			Numero[j] = auxiliar;
			j=j-1;
		}
		return Numero;
}