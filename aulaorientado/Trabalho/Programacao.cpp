
#include "Programacao.hpp"

/*
Construtor que recebe parametros e cria Programacao
Possui tambem um construtor default, que inicializa com valores nulos
Se definido DEBUG, printa que o objeto foi criado
@param c Cinema
@param s sala
@param f Filme
@param t tipoDeExibicao
@param h horarios
*/
Programacao::Programacao(Cinema *c, int s, Filme *f, int t, string h){
	cinema = c;
	sala = s;
	filme = f;
	tipoDeExibicao = t;
	horarios = h;
	#ifdef DEBUG
	cout << "Programacao criada" << endl;
	#endif
}

/*
Destrutor que printa que o objeto foi destruido se DEBUG estiver definido
*/
Programacao::~Programacao(){
	#ifdef DEBUG
	cout << "Programacao destruida" << endl;
	#endif
}

/*
Metodo que retorna o objeto Cinema
@return Cinema
*/
Cinema* Programacao::obtemCinema() const{
	return cinema;
}

/*
Metodo que retorna sala
@return sala
*/
int Programacao::obtemSala() const{
	return sala;
}

/*
Metodo que retorna o objeto Filme
@return Filme
*/
Filme* Programacao::obtemFilme() const{
	return filme;
}

/*
Metodo que retorna tipoDeExibicao
@return tipoDeExibicao
*/
int Programacao::obtemTipoDeExibicao() const{
	return tipoDeExibicao;
}

/*
Metodo que retorna horarios
@return horarios
*/
string Programacao::obtemHorarios() const{
	return horarios;
}


/*
Metodo que retorna uma string com os dados da Programacao
Tendo a opcao de incluir o nome do cinema dependendo da variavel incluiCinema
@return string
*/
string Programacao::str(bool incluiCinema) const{
	stringstream ss;

	if(incluiCinema){
		ss << cinema->obtemNome() << " - ";
	}
	ss << "Sala " << sala << ": " << filme->obtemTitulo() << " | ";
	ss << horarios << " | ";

	switch(tipoDeExibicao){
		case 1:
			ss << "LEG";
			break;
		case 2:
			ss << "DUB";
			break;
		case 3:
			ss << "3D LEG";
			break;
		case 4:
			ss << "3D DUB";
			break;
		case 5:
			ss << "NAC";
			break;
	}
	ss << " | ";
	if (filme->obtemFaixaEtaria()){
		ss << "[" << filme->obtemFaixaEtaria() << "]";
	}
	else {
		ss << "[LIVRE]";
	}
	ss << " | " << filme->obtemEstilo();
	return ss.str();
}

/*
Metodo que define cinema
@param c cinema
*/
void Programacao::defineCinema(Cinema *c){
	cinema = c;
}

/*
Metodo que define sala
@param s sala
*/
void Programacao::defineSala(int s){
	sala = s;
}

/*
Metodo que define Filme
@param f file
*/
void Programacao::defineFilme (Filme *f){
	filme = f;
}

/*
Metodo que define tipoDeExibicao
@param t tipoDeExibicao
*/
void Programacao::defineTipoDeExibicao(int t){
	tipoDeExibicao = t;
}

/*
Metodo que define horarios
@param h horarios
*/
void Programacao::defineHorarios (string h){
	horarios = h;
}