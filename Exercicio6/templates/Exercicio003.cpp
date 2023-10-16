#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Equipe {
private:
    string clube;
    int    pontos;
public:
    Equipe(string c = "", int p = 0) {
        clube = c;
        pontos = p;
    }
    string obtemClube() { return clube; }
    void defineClube(string c) { clube = c; }
    int obtemPontos() { return pontos; }
    void definePontos(int p) { pontos = p; }
    string toString() {
        stringstream ss;
        ss << clube << ": " << pontos << " pontos";
        return ss.str();
    }
    string toCSV() {
        stringstream ss;
        ss << clube << ";" << pontos;
        return ss.str();
    }
};

class Campeonato {
  private:
    class Nodo {
       public:
         Equipe *equipe;
         Nodo *prox, *ant;
         Nodo(Equipe *e){
            equipe = e;
            prox = NULL;
            ant = NULL;
         }
    };
    Nodo *primeiro;
    int numEquipes;
  public:
    Campeonato(){
        primeiro = NULL;
        numEquipes = 0;
    }
    ~Campeonato(){
        limpa();
    }
    int obtemNumEquipes(){
        return numEquipes;
    }
    Equipe *obtemEquipe(int indice){
        if (indice < 0 || indice >= numEquipes){
            return nullptr;
        }
        Nodo *ptr = primeiro;
        for (int i = 0; i < indice; i++){
            ptr = ptr->prox;
        }
        return ptr->equipe;
    }
    void insere(string c, int p){
        insere (new Equipe (c,p));
    }
    void insere(Equipe *e){
        if (numEquipes == 0){
            primeiro = new Nodo(e);
            numEquipes++;
            return;
        }
        Nodo *ptr = primeiro;
        while (1){
            if (ptr->equipe->obtemPontos() < e->obtemPontos()){
                break;
            }
            if (ptr->equipe->obtemPontos() == e->obtemPontos()){
                if (ptr->equipe->obtemClube() > e->obtemClube()){
                    break;
                }
            }
            if (ptr->prox == NULL){
                ptr->prox = new Nodo(e);
                ptr->prox->ant = ptr;
                numEquipes++;
                return;
            }
            ptr = ptr->prox;
        }
        if (ptr == primeiro){
            Nodo *novo = new Nodo(e);
            primeiro = novo;
            novo->prox = ptr;
            ptr->ant = novo;
        }
        else{
            Nodo *aux = ptr->ant;
            aux->prox = new Nodo(e);
            aux->prox->ant = aux;
            aux->prox->prox = ptr;
            ptr->ant = aux->prox;
        }
        numEquipes++;
    }
    void limpa(){
        Nodo *ptr = primeiro;
        while (ptr != NULL){
            Nodo *aux = ptr->prox;
            Nodo *excluido = ptr;
            Equipe *e = ptr->equipe;
            delete e;
            delete excluido;
            ptr = aux;
        }
    }
};

// --- SOLUCAO (inicio) ---
// ...
// --- SOLUCAO (fim) ---

void mostraCampeonato(Campeonato *c) {
  int tam = c->obtemNumEquipes();
  for (int i=0; i<tam; ++i) {
      Equipe *e = c->obtemEquipe(i);
      cout << e->toString() << endl;
  }
  cout << "------------------" << endl;
}

int main() {
    Campeonato *brasileirao2021 = new Campeonato();
    mostraCampeonato(brasileirao2021);
    Equipe *e = new Equipe("Chapecoense",12);
    brasileirao2021->insere(e);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Santos",28);
    brasileirao2021->insere("Bragantino",41);
    brasileirao2021->insere("Atletico Goianiense",31);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Flamengo",42);
    brasileirao2021->insere("Atletico-MG",53);
    brasileirao2021->insere("Internacional",36);
    brasileirao2021->insere("Fluminense",33);
    brasileirao2021->insere("Juventude",28);
    brasileirao2021->insere("Sport",26);
    brasileirao2021->insere("Cuiaba",31);
    brasileirao2021->insere("Gremio",23);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Corinthians",37);
    brasileirao2021->insere("Athletico-PR",33);
    brasileirao2021->insere("Palmeiras",40);
    brasileirao2021->insere("Sao Paulo",30);
    brasileirao2021->insere("Ceara",29);
    brasileirao2021->insere("Fortaleza EC",39);
    brasileirao2021->insere("Bahia",27);
    brasileirao2021->insere("America-MG",31);
    mostraCampeonato(brasileirao2021);
    delete brasileirao2021;
    return 0;
}
