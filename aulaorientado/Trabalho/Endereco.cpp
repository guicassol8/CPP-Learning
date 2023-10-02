
#include "Endereco.hpp"
/*
Construtor com configuracao de parametros default (int = -1  e strings = ""). Se DEBUG estiver definido sera printado que o objeto foi criado
@param l  logradouro
@param n  numero
@param c  complemento
@param b  bairro
@param cp  cep
@param cd  cidade
@param e  estado
*/
Endereco::Endereco(string l, int n, string c, string b, string cp, string cd, string e){
	logradouro = l;
	numero = n;
	complemento = c;
	bairro = b;
	cep = cp;
	cidade = cd;
	estado = e;
	#ifdef DEBUG
	cout << "Endereco criado" << endl;
	#endif
}

/*
Destrutor que se DEBUG estiver definido sera printado que o objeto foi destruido
*/
Endereco::~Endereco(){
	#ifdef DEBUG
	cout << "Endereco destruido" << endl;
	#endif
}

/*
Metodo que retorna o logradouro
@return logradouro
*/
string Endereco::obtemLogradouro() const{
	return logradouro;
}

/*
Metodo que retorna o numero
@return numero
*/
int Endereco::obtemNumero() const{
	return numero;
}

/*
Metodo que retorna a cidade
@return cidade
*/
string Endereco::obtemCidade() const{
	return cidade;
}

/*
Metodo que retorna o bairro
@return bairro
*/
string Endereco::obtemBairro() const{
	return bairro;
}

/*
Metodo que retorna o cep
@return cep
*/
string Endereco::obtemCEP() const{
	return cep;
}

/*
Metodo que retorna o complemento
@return complemento
*/
string Endereco::obtemComplemento() const{
	return complemento;
}

/*
Metodo que retorna o estado
@return estado
*/
string Endereco::obtemEstado() const{
	return estado;
}

/*
Metodo que retorna o objeto como string
@return ss.str()
*/
string Endereco::str() const{
	stringstream ss;
	ss << logradouro << ", " << numero << " - " << complemento << " - Bairro " << bairro << " - " << cidade << " - " << estado;
	return ss.str();
}


/*
Metodo que define o logradouro
@param string l
*/
void Endereco::defineLogradouro(string l){
	logradouro = l;
}

/*
Metodo que define o numero
@param int n
*/
void Endereco::defineNumero(int n){
	numero = n;
}

/*
Metodo que define o complemento
@param string c
*/
void Endereco::defineComplemento(string c){
	complemento = c;
}

/*
Metodo que define o bairro
@param string b
*/
void Endereco::defineBairro(string b){
	bairro = b;
}

/*
Metodo que define o cep
@param string cp
*/
void Endereco::defineCEP(string cp){
	cep = cp;
}

/*
Metodo que define a cidade
@param string cd
*/
void Endereco::defineCidade(string cd){
	cidade = cd;
}

/*
Metodo que define o estado
@param string e
*/
void Endereco::defineEstado(string e){
	estado = e;
}

/*
Sobrecarga do operador >> que atribui um input stream ao objeto
@param istream &in
@param Endereco &e
@return in
*/
istream &operator>>(istream &in,Endereco &e){
	getline (in, e.logradouro);
	string aux;
	getline (in, aux);
	e.numero = stoi(aux);
	getline (in, e.complemento);
	getline (in, e.bairro);
	getline (in, e.cep);
	getline (in, e.cidade);
	getline (in, e.estado);
	return in;
}

/*
Sobrecarga do operador << que imprime o objeto
@param ostream &out
@param const Endereco &e
@return out
*/
ostream &operator<<(ostream &out,const Endereco &e){
	out << e.str();
	return out;
}