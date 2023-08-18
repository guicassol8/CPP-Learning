#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Simon 
{
	public:
	long int aux;
	string input;
	string output;
	vector <int> base5Number;
	Simon()
	{
		aux = 0;
		cout<<"Objeto criado"<<endl;
	}
	~Simon()
	{
		cout<<"Objeto destruido"<<endl;
	}
	void OrdenarInput ()
	{
		int j = input.size()-1;
		for (int i = 0; i <=j ; i++)
		{
			char auxiliar = input[i];
			input[i] = input[j];
			input[j] = auxiliar;
			j=j-1;
		}
	}
	void TransformarInput ()
	{
		for (int i = 0; i < input.size() ; i++)
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
	void DecimalTo5Base ()
	{
		while (aux > 0) {
			int remainder = aux % 5;
			base5Number.push_back(remainder);
			aux /= 5;
		}
		if (base5Number.empty()) {
			base5Number.push_back(0);
		}
	}
	void Base5ToSimon ()
	{
		short int sobra = 0;
		for (int i = 0; i < base5Number.size(); ++i)
		{
			base5Number[i] += sobra;
			cout<<"Base5:"<<base5Number[i]<<endl;
			if (base5Number[i] > 2)
			{
				base5Number[i] -= 5;
				sobra = 1;
			}
			else if (base5Number[i] < -2)
			{
				base5Number[i] += 5;
				sobra = -1;
			}
			else
			{
				sobra = 0;	
			}
			cout<<"Simon:"<<base5Number[i]<<endl;
		}
	}
	void SimonLToSimonS ()
	{
		for (int i = 0; i < base5Number.size(); ++i)
		{
			input.resize(base5Number.size());
			switch (base5Number[i])
			{
				case 2:
				input[i] = 'S';
				break;
				case 1:
				input[i] = 'I';
				break;
				case 0:
				input[i] = 'M';
				break;
				case -1:
				input[i] = 'O';
				break;
				case -2:
				input[i] = 'N';
				break;
			}
		}
	}
};

int main ()
{
	Simon simon;
	//laco para captar inputs
	while (1)
	{
	//recebe o input
	getline(cin,simon.input);
	//quebra o laco caso o input seja 0
	if (simon.input == "\0")
	{
		break;
	}
	//ordena o vetor
	simon.OrdenarInput();
	//transforma o input em  numero
	simon.TransformarInput();
	//imprime o output
	cout<<"INPUT:"<<simon.input<<endl;
	cout<<"DECIMAL:"<<simon.aux<<endl;
	}
	//imprime o output
	cout<<"INPUT:"<<simon.input<<endl;
	cout<<"DECIMAL:"<<simon.aux<<endl;
	//transforma o numero em base 5
	simon.DecimalTo5Base();
	cout<<"BASE5:";
	for (int i = 0; i < simon.base5Number.size(); ++i)
	{
	cout<<simon.base5Number[i];
	}
	cout<<endl;
	//transforma o base 5 em simon
	simon.Base5ToSimon();
	cout<<"SIMON:";
	for (int i = 0; i < simon.base5Number.size(); ++i)
	{
		cout<<simon.base5Number[i];
	}
	cout<<endl;
	//transforma o simon numero em simon letra
	simon.SimonLToSimonS();
	//printa o SiMON letra desordenado
	cout<<"SIMON LETRA:";
	for (int i = 0; i < simon.input.size(); ++i)
	{
		cout<<simon.input[i];
	}
	cout<<endl;
	//reeordena o vetor
	simon.OrdenarInput();
	cout<<"SIMON LETRA ORDENADO:";
	for (int i = 0; i < simon.input.size(); ++i)
	{
		cout<<simon.input[i];
	}
	cout<<endl;
	return 0;
}