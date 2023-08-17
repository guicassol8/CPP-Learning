#include <iostream>
#include <cmath>
#include <string>


using namespace std;
class Simon
{
	public:
	string input;
	int aux;
	short int tamanhoVetor;
	Simon ()
	{
		aux = 0;
	}
};

int main () {
	Simon simon;
	scanf ("%s", simon.input);
}