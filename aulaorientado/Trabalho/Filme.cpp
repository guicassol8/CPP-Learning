
#include "Filme.hpp"

/* 
Contrutor que recebe os atributos (numero, titulo, faixaEtaria, estilo).
Todos possuem valor default de -1 para inteiros e "" para strings.
Se DEBUG estiver definido, imprime a mensagem "Filme criado".
@param n numero do filme
@param t titulo do filme
@param f faixaEtaria do filme
@param e estilo do filme
*/
Filme::Filme(int n, string t, int f, string e){
	numero = n;
	titulo = t;
	faixaEtaria = f;
	estilo = e;
	#ifdef DEBUG
	cout << "Filme criado" << endl;
	#endif
}

//Nao faz nada efetivamente, apenas printa sua destruicao se DEBUG estiver definido
Filme::~Filme(){
	#ifdef DEBUG
	cout << "Filme destruido" << endl;
	#endif
}
/*
Retorna o numero do filme
@return numero
*/
int Filme::obtemNumero() const{
	return numero;
}

/*
Retorna o titulo do filme
@return titulo
*/
string Filme::obtemTitulo() const{
	return titulo;
}

/*
Retorna a faixaEtaria do filme
@return faixaEtaria
*/
int Filme::obtemFaixaEtaria() const{
	return faixaEtaria;
}

/*
Retorna o estilo do filme
@return estilo
*/
string Filme::obtemEstilo() const{
	return estilo;
}

/*
Formata em forma de string titulo, numero, faixa etaria (quando for maior que 0 vai imprimir anos e LIVRE se 0) e estilo do filme
@return string
*/
string Filme::str() const{
	stringstream ss;
	ss << titulo << " [" << numero << "] - ";
	if (faixaEtaria > 0){
		ss << faixaEtaria << " anos";
	}
	else{
		ss << "LIVRE";
	}
	ss << " - " << estilo;
	return ss.str();
}
/*
Define o numero do filme
@param n numero
*/
void Filme::defineNumero(int n){
	numero = n;
}

/*
Define o titulo do filme
@param t titulo
*/
void Filme::defineTitulo(string t){
	titulo = t;
}

/*
Define a faixaEtaria do filme
@param f faixaEtaria
*/
void Filme::defineFaixaEtaria(int f){
	faixaEtaria = f;
}

/*
Define o estilo do filme
@param e estilo
*/
void Filme::defineEstilo(string e){
	estilo = e;
}

/*
Metodo que sobrecarga o operador <,que compara os caracteres do atributo titulo de dois objetos, retornando true se o primeiro for menor que o segundo 
(atraves da ordenacao do alfabeto e tabela ASCII)
@return true se o primeiro for menor que o segundo, false se o primeiro for maior ou igual ao segundo
*/
bool Filme::operator<(const Filme &f) const{
	return this->titulo < f.titulo;
}
/*
Funcao friend que sobrecarga o operador <<, que imprime o objeto em forma de string
@return out (objeto como string)
*/
ostream &operator<<(ostream &out, const Filme&f){
    out << f.str();
    return out;
}

/*
Funcao friend que sobrecarga o operador >>, que le um objeto do tipo Filme
@return in
*/
istream &operator>>(istream &in, Filme &f){
	string aux;
	getline (in,aux);
	f.numero = stoi(aux);
	getline (in,f.titulo);
	getline (in,aux);
	f.faixaEtaria = stoi(aux);
	getline (in,f.estilo);
    return in;
}

