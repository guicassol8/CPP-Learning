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
    vector<Pessoa> pessoas;
    string line;

    while (true) {
        string input;
        getline(cin, input);
        
        if (input == "+") {
            if (pessoas.size() < 10) {
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
                pessoas.push_back(novaPessoa);
				cout<<">OK"<<endl;
            } else {
                cout << ">VETOR CHEIO" << endl;
            }
        } else if (input == ".") {
            cin >> mes;
            for (const Pessoa& pessoa : pessoas) {
                if (pessoa.nascimento.mes == mes) {
                    quantidade++;
                    cout << fixed << setprecision(4);
                    cout << pessoa.nome << ";" << pessoa.altura << ";" << pessoa.nascimento.dia << ","
                         << pessoa.nascimento.mes << "," << pessoa.nascimento.ano << endl;
                }
            }
            if (quantidade == 0) {
                cout << ">SEM ANIVERSARIOS" << endl;
            }
            break;
        } else {
            cout << ">OPCAO INVALIDA" << endl;
        }
    }

    return 0;
}