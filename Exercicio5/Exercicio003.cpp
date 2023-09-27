//Exercicio003.cpp,Guilherme Roth Cassol,Exercicio 003, 12/09/2023
#include <iostream>
#include <sstream>

using namespace std;    

class Pessoa {
private:
    string nome;
    int idade;
public:
    Pessoa(string n="", int i=0){
        nome = n;
        idade = i;
    }
    ~Pessoa(){

    }
    string obtemNome() const{
        return nome;
    }
    int obtemIdade() const{
        return idade;
    }
    void defineNome(string n){
        nome = n;
    }
    void defineIdade(int i){
        idade = i;
    }
    void fazAniversario(){
        idade++;
    }
    string str() const{
        stringstream ss;
        ss << nome << " (" << idade << ")";
        return  ss.str();
    }

    Pessoa operator+(const int i) const{
        return Pessoa(nome, idade+i);
    }
    void operator+=(const int i){
        idade+=i;
    }
    Pessoa operator++(){
        idade++;
        return Pessoa(nome, idade);
    } // pre-incremento
    Pessoa operator++(int){
        Pessoa aux = Pessoa(nome, idade);
        idade++;
        return aux;
    } // pos-incremento

    bool operator>(const Pessoa &p) const{
        if (idade > p.idade){
            return true;
        }
        return false;
    }
    bool operator<(const Pessoa &p) const{
        if (idade < p.idade){
            return true;
        }
        return false;
    }
    bool operator==(const Pessoa &p) const{
        if (idade == p.idade){
            return true;
        }
        return false;
    }
    bool operator!=(const Pessoa &p) const{
        if (idade != p.idade){
            return true;
        }
        return false;
    }
    bool operator>=(const Pessoa &p) const{
        if (idade >= p.idade){
            return true;
        }
        return false;
    }
    bool operator<=(const Pessoa &p) const{
        if (idade <= p.idade){
            return true;
        }
        return false;
    }
    bool operator>(const int i) const{
        if (idade > i){
            return true;
        }
        return false;
    }
    bool operator<(const int i) const{
        if (idade < i){
            return true;
        }
        return false;
    }
    bool operator==(const int i) const{
        if (idade == i){
            return true;
        }
        return false;
    }
    bool operator!=(const int i) const{
        if (idade != i){
            return true;
        }
        return false;
    }
    bool operator>=(const int i) const{
        if (idade >= i){
            return true;
        }
        return false;
    }
    bool operator<=(const int i) const{
        if (idade <= i){
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &out, const Pessoa &p);
    friend istream &operator>>(istream &in, Pessoa &p);
};

ostream &operator<<(ostream &out, const Pessoa &p){
    out << p.str();
    return out;
}
istream &operator>>(istream &in, Pessoa &p){
    getline (in,p.nome);
    string aux;
    getline (in,aux);
    p.idade = stoi(aux);
    return in;
}

int main() {
    
    Pessoa batman;
    cout << "Nome = " << batman.obtemNome() << endl;
    cout << "Idade = " << batman.obtemIdade() << endl;
    batman.defineNome("Bruce Wayne");
    batman.defineIdade(34);
    cout << batman << endl;
    cout << endl;
    
    Pessoa homemAranha("Peter Parker",35);
    cout << "Nome = " << homemAranha.obtemNome() << endl;
    cout << "Idade = " << homemAranha.obtemIdade() << endl;
    homemAranha.fazAniversario();
    cout << homemAranha << endl << endl;

    cout << (batman >= homemAranha?"ERRO":"OK") << " ";
    cout << (batman > homemAranha?"ERRO":"OK")<< " ";
    cout << (batman <= homemAranha?"OK":"ERRO") << " ";
    cout << (batman < homemAranha?"OK":"ERRO") << " ";
    cout << (batman != homemAranha?"OK":"ERRO") << " ";
    cout << (batman == homemAranha?"ERRO":"OK") << endl << endl;

    cout << batman << endl;
    batman = batman + 2;
    cout << batman << endl;
    cout << endl;

    cout << (batman >= homemAranha?"OK":"ERRO") << " ";
    cout << (batman > homemAranha?"ERRO":"OK") << " ";
    cout << (batman <= homemAranha?"OK":"ERRO") << " ";
    cout << (batman < homemAranha?"ERRO":"OK") << " ";
    cout << (batman != homemAranha?"ERRO":"OK") << " ";
    cout << (batman == homemAranha?"OK":"ERRO") << endl << endl;

    cout << batman << endl;
    ++batman;
    cout << batman << endl;
    cout << endl;

    cout << (batman >= homemAranha?"OK":"ERRO") << " ";
    cout << (batman > homemAranha?"OK":"ERRO") << " ";
    cout << (batman <= homemAranha?"ERRO":"OK") << " ";
    cout << (batman < homemAranha?"ERRO":"OK") << " ";
    cout << (batman != homemAranha?"OK":"ERRO") << " ";
    cout << (batman == homemAranha?"ERRO":"OK") << endl << endl;

    cout << batman << endl;
    batman += 2;
    cout << batman << endl;
    cout << endl;

    cout << (batman >= 40?"ERRO":"OK") << " ";
    cout << (batman > 40?"ERRO":"OK") << " ";
    cout << (batman <= 40?"OK":"ERRO") << " ";
    cout << (batman < 40?"OK":"ERRO") << " ";
    cout << (batman != 40?"OK":"ERRO") << " ";
    cout << (batman == 40?"ERRO":"OK") << endl << endl;

    batman.fazAniversario();
    cout << (batman >= 40?"OK":"ERRO") << " ";
    cout << (batman > 40?"ERRO":"OK") << " ";
    cout << (batman <= 40?"OK":"ERRO") << " ";
    cout << (batman < 40?"ERRO":"OK") << " ";
    cout << (batman != 40?"ERRO":"OK") << " ";
    cout << (batman == 40?"OK":"ERRO") << endl << endl;

    batman.fazAniversario();
    cout << (batman >= 40?"OK":"ERRO") << " ";
    cout << (batman > 40?"OK":"ERRO") << " ";
    cout << (batman <= 40?"ERRO":"OK") << " ";
    cout << (batman < 40?"ERRO":"OK") << " ";
    cout << (batman != 40?"OK":"ERRO") << " ";
    cout << (batman == 40?"ERRO":"OK") << endl << endl;

    Pessoa p1, p2;
    cin >> p1;
    p2 = p1++;
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    p2 = ++p1;
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p1 << endl;
    
    return 0;
}
