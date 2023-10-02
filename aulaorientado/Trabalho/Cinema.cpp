
#include "Cinema.hpp"

Cinema::Cinema(){
	numero = 0;
	nome = "";
	endereco = Endereco();
	salas = 0;
	#ifdef DEBUG
		cout << "Cinema criado" << endl;
	#endif
}

Cinema::Cinema(int n, string nm, Endereco &e, int s){
	numero = n;
	nome = nm;
	endereco = e;
	salas = s;
	#ifdef DEBUG
		cout << "Cinema criado" << endl;
	#endif
}

/*
Destrutor printa que o Cinema foi destruido se DEBUG estiver definido
*/
Cinema::~Cinema(){
	#ifdef DEBUG
		cout << "Cinema destruido" << endl;
	#endif
}

int Cinema::obtemNumero() const{
	return numero;
}

string Cinema::obtemNome() const{
	return nome;
}

Endereco Cinema::obtemEndereco() const{
	return endereco;
}

int Cinema::obtemSalas() const{
	return salas;
}

/*
nome, “ [ ”, número, “] ”,
nova linha, endereço, nova linha, “Cinema(s): ” e número de salas;
*/
string Cinema::str () const{
	stringstream ss;
	ss << nome << " [" << numero << "] " << endl;
	ss << endereco.str() << endl;
	ss << "Cinema(s): " << salas;
	return ss.str();
}

void Cinema::defineNumero(int n){
	numero = n;
}

void Cinema::defineNome(string nm){
	nome = nm;
}

void Cinema::defineEndereco(Endereco &e){
	endereco = e;
}

void Cinema::defineSalas(int s){
	salas = s;
}

bool Cinema::operator<(const Cinema &c) const{
	return this->nome < c.nome;
}

/*
Sobrecarga do operador >> que atribui um input stream ao objeto
@param istream &in
@param Cinema &c
@return in
*/
istream &operator>>(istream &in,Cinema &c){
	string aux;
	Endereco aux2;
	getline (in, aux);
	c.numero = stoi(aux);
	getline (in, c.nome);
	in >> c.endereco;
	getline (in, aux);
	c.salas = stoi(aux);
	return in;
}

ostream &operator<<(ostream &out, Cinema &c){
	out << c.str();
	return out;
}