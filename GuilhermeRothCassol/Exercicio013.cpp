//Exercicio013.cpp,Guilherme Roth Cassol,Exercicio 13, 21/08/2023
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	int input;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		cout <<" " << i;
	}
	cout << endl;
	for (int i = 1; i <= (input + 1) / 2; i++) {
    for (int j = 1; j <= input; j++) {
		if (j <= i || j >= input - i + 1)
		{
			cout <<"  ";
		}
		else cout <<" "<< j;
    }
    cout << endl;
    }
}