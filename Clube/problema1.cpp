#include <iostream>
#include <cmath>
#include <string>
#include <vector>


using namespace std;

vector <int> OrdenarVetor1(int TamanhoNumero, vector <int> Numero);
class Simon
{
	public:
	string output;
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
	void OrdenarOutput ()
	{
		int j = output.length()-1;
		for (int i = 0; i <=j ; i++)
		{
			char auxiliar = output[i];
			output[i] = output[j];
			output[j] = auxiliar;
			j=j-1;
		}
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
	vector<int> Base5ToSimon (vector<int> base5Representation,int TamanhoNumero) 
	{
		short int sobra = 0;
		for (int i = 0; i < TamanhoNumero; i++)
		{
			base5Representation[i] += sobra;
			if (i == TamanhoNumero-1)
			{
				base5Representation[i] = sobra;
				return base5Representation;
			}
			if (base5Representation[i] > 2)
			{
				sobra = 1;
				base5Representation[i] = (base5Representation[i] - 5);
			}
			else if (base5Representation[i] < -2)
			{
				sobra = -1;
				base5Representation[i] = (5 + base5Representation[i]);
			}
			else
			{
				sobra = 0;
			}
		}
	return base5Representation;
}
	void NumeroToSimon (vector <int> Numero,int TamanhoNumero)
	{
		output.resize(TamanhoNumero);
		for (int i = 0; i < TamanhoNumero; i++)
		{
			switch (Numero[i])
			{
				case 2:
				output[i] = 'S';
				break;
				case 1:
				output[i] = 'I';
				break;
				case 0:
				output[i] = 'M';
				break;
				case -1:
				output[i] = 'O';
				break;
				case -2:
				output[i] = 'N';
				break;
			}
		}
	}
};

int main () {
	Simon simon;
	string output;
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
	if (simon.input == "0")
	{
		break;
	}
	}
	cout<<simon.aux<<endl;
	vector<int> base5Representation = simon.decimalToBase5(simon.aux);
	base5Representation[0] = 1;
	base5Representation[1] = 4;
	int TamanhoNumero = base5Representation.size();
	vector<int> simonNumber = simon.Base5ToSimon(base5Representation,TamanhoNumero);
	TamanhoNumero = simonNumber.size ();
	simon.NumeroToSimon(simonNumber,TamanhoNumero);
	for (int i = 0; i < base5Representation.size(); i++)
		{
			cout<< base5Representation[i];
		}
	cout<<endl;
	for (int i = 0; i < simon.output.size(); i++)
		{
		cout<< simon.output[i];
		}
	cout<<endl;
	for (int i = 0; i < simonNumber.size() - 1; i++)
		{
		cout<< simonNumber[i];
		}
	cout<<endl;
	return 0;
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