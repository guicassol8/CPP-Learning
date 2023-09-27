//Exercicio013.cpp,Guilherme Roth Cassol,Exercicio 13, 13/09/2023
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class UnidadeFederativa {
  private:
    string nome;
    string sigla;
    string capital;
    double area;
    int populacao;
    double densidade;
  public:
    UnidadeFederativa(string n = "",string c = "",string s = "", double a = 0,int p = 0) {
      nome = n;
      sigla = c;
      capital = s;
      area = a;
      populacao = p;
    }
    string obtemNome() {
      return nome;
    }
    void defineNome(string n) {
      nome = n;
    }
    string obtemSigla() {
      return sigla;
    }
    void defineSigla(string s) {
      sigla = s;
    }
    string obtemCapital() {
      return capital;
    }
    void defineCapital(string c) {
      capital = c;
    }
    double obtemArea() {
      return area;
    }
    void defineArea(double a) {
      area = a;
    }
    int obtemPopulacao() {
      return populacao;
    }
    void definePopulacao(int p) {
      populacao = p;
    }
    double obtemDensidade (){
      if (area == 0){
        return 0;
      }
      return populacao/area;
    }
};

void mostraUF(UnidadeFederativa &uf) {
  cout << uf.obtemNome() << " (" << uf.obtemSigla() << ") - " << uf.obtemCapital();
  cout << " - Area = " << fixed << setprecision(4) << uf.obtemArea();	
  cout << " - Pop. = " << uf.obtemPopulacao();
  cout << " - Densidade = " << fixed << setprecision(4) << uf.obtemDensidade() << endl;
}

int main() {
  UnidadeFederativa rs;
  mostraUF(rs);
  rs.defineNome("Rio Grande do Sul");
  rs.defineSigla("RS");
  rs.defineCapital("Porto Alegre");
  rs.defineArea(281748.5);
  rs.definePopulacao(11228091);
  mostraUF(rs);
  UnidadeFederativa sc("Santa Catarina","SC","Florianopolis",95346.2,6734568);
  mostraUF(sc);
  for (int i=0; i<10; ++i) {
      sc.definePopulacao( sc.obtemPopulacao()+100000 );
      mostraUF(sc);
  }
  return 0;
}
