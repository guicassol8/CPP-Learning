//Exercicio007.cpp,Guilherme Roth Cassol,Exercicio 07, 27/08/2023
#include <iostream>

using namespace std;

// implementacao da classe Pessoa
class Pessoa {
  private:
  string nome;
  int nascimento;
  public:
  Pessoa(string i = "", int n = 0) {
    nome = i;
    nascimento = n;
  }
  void defineNome (string i) {
    nome = i;
  }
  string obtemNome(){
    return nome;
  }
  void defineAnoNascimento (int n) {
    nascimento = n;
  }
  int obtemAnoNascimento(){
    return nascimento;
  }
  int obtemIdade (int ano) {
    if (ano < nascimento){
      return -1;
    }
    return ano - nascimento;
  }
  int obtemIdadeEmMeses (int ano) {
    if (ano < nascimento){
      return -1;
    }
    return  ano*12 - nascimento*12;
  }
};

int main() {
  Pessoa *p = new Pessoa();
  cout << "[" << p->obtemNome() << "](" << p->obtemAnoNascimento() << ")" << endl;
  p->defineNome("Friedrich Wilhelm Nietzsche");
  p->defineAnoNascimento(1844);
  cout << "[" << p->obtemNome() << "](" <<
                 p->obtemAnoNascimento() << "/" <<
                 p->obtemIdade(1900) << " anos/" <<
                 p->obtemIdadeEmMeses(1900) << " meses)" << endl;
  delete p;
  Pessoa *rn = new Pessoa("Fulano",2020);
  cout << "Nome = " << rn-> obtemNome() << endl;
  cout << "Ano de Nascimento = " << rn->obtemAnoNascimento() << endl;
  for (int i=2018; i<2025; ++i)
      cout << i << " " << rn->obtemIdade(i) << " " << rn->obtemIdadeEmMeses(i) << endl;
  delete rn;
  return 0;
}
