//Exercicio011.cpp,Guilherme Roth Cassol,Exercicio 11, 21/08/2023
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Pessoa {
    string nome;
    double altura;
    Data nascimento;
};

int main() {
    int mes = 0;
    int quantidade = 0;
    Pessoa pessoas [10];
    string line;
    int quantPessoas = 0;

    while (true) {
        string input;
        getline(cin, input);
        
        if (input == "+") {
                Pessoa novaPessoa;
                getline(cin, novaPessoa.nome);
                getline(cin, line);
                novaPessoa.altura = stod(line);
                getline(cin, line);
                novaPessoa.nascimento.dia = stoi(line);
                getline(cin, line);
                novaPessoa.nascimento.mes = stoi(line);
                getline(cin, line);
                novaPessoa.nascimento.ano = stoi(line);
                if (quantPessoas == 10) {
                    cout<<"> VETOR CHEIO"<<endl;
                    continue;
                }
                pessoas [quantPessoas].nome = novaPessoa.nome;
                pessoas [quantPessoas].altura = novaPessoa.altura;
                pessoas [quantPessoas].nascimento.dia = novaPessoa.nascimento.dia;
                pessoas [quantPessoas].nascimento.mes = novaPessoa.nascimento.mes;
                pessoas [quantPessoas].nascimento.ano = novaPessoa.nascimento.ano;
				cout<<"> OK"<<endl;
                quantPessoas++;
        } else if (input == ".") {
            cin >> mes;
            for (int i = 0; i < quantPessoas; i++) {
                if (pessoas [i].nascimento.mes == mes) {
                    quantidade++;
                    cout << fixed << setprecision(4);
                    cout << pessoas [i].nome << ";" << pessoas [i].altura << ";" << pessoas [i].nascimento.dia << ","
                         << pessoas [i].nascimento.mes << "," << pessoas [i].nascimento.ano << endl;
                }
            }
            if (quantidade == 0) {
                cout << "> SEM ANIVERSARIOS" << endl;
            }
            break;
        } else {
            cout << "> OPCAO INVALIDA" << endl;
        }
    }

    return 0;
}