
#include "Cinema.hpp"

/*
Construtor sem parametros cria o Cinema
Atribui valores nulos as variaveis
Se definido DEBUG, printa que o Cinema foi criado
*/
Cinema::Cinema(){

	numero = 0;
	nome = "";
	endereco = Endereco();
	salas = 0;
	#ifdef DEBUG
		cout << "Cinema criado" << endl;
	#endif

}

/*
Construtor que recebe os parametros e cria o Cinema
Se definido DEBUG, printa que o Cinema foi criado
@param n numero
@param nm nome
@param e endereco
@param s salas
*/
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

/*
retorna o numero
@return numero
*/
int Cinema::obtemNumero() const{
	return numero;
}

/*
retorna o nome
@return nome
*/
string Cinema::obtemNome() const{
	return nome;
}

/*
retorna o objeto endereco
@return endereco
*/
Endereco Cinema::obtemEndereco() const{
	return endereco;
}

/*
retorna a variavel salas
@return salas
*/
int Cinema::obtemSalas() const{
	return salas;
}

/*
metodo que retorna o Cinema em forma de string
@return string
*/
string Cinema::str () const{

	stringstream ss;
	ss << nome << " [" << numero << "] " << endl;
	ss << endereco.str() << endl;
	ss << "Cinema(s): " << salas;
	return ss.str();

}

/*
define o numero
@param n numero*/
void Cinema::defineNumero(int n){
	numero = n;
}

/*
define o nome
@param nm nome
*/
void Cinema::defineNome(string nm){
	nome = nm;
}

/*
define o endereco
@param e endereco
*/
void Cinema::defineEndereco(Endereco &e){
	endereco = e;
}

/*
define o numero de salas
@param s salas
*/
void Cinema::defineSalas(int s){
	salas = s;
}
/*
sobrecarga do operador < comparando ambos nomes
@return false se o nome for igual ou maior (comparando alfabeticamente)
@return true se o nome for menor (comparando alfabeticamente)
*/
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

/*
Sobrecarga do operador << que imprime o objeto no output stream
@param ostream &out
@param Cinema &c
@return out
*/
ostream &operator<<(ostream &out, Cinema &c){

	out << c.str();
	return out;
	
}