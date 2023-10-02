
#include "Programacao.hpp"

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

Programacao::~Programacao(){
	#ifdef DEBUG
	cout << "Programacao destruida" << endl;
	#endif
}

Cinema* Programacao::obtemCinema() const{
	return cinema;
}

int Programacao::obtemSala() const{
	return sala;
}

Filme* Programacao::obtemFilme() const{
	return filme;
}

int Programacao::obtemTipoDeExibicao() const{
	return tipoDeExibicao;
}

string Programacao::obtemHorarios() const{
	return horarios;
}


/*
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
	if (filme->obtemFaixaEtaria()){
		ss << "[" << filme->obtemFaixaEtaria() << "]";
	}
	else {
		ss << "[LIVRE]";
	}
	ss << " | " << filme->obtemEstilo();
	return ss.str();
}

void Programacao::defineCinema(Cinema *c){
	cinema = c;
}

void Programacao::defineSala(int s){
	sala = s;
}

void Programacao::defineFilme (Filme *f){
	filme = f;
}

void Programacao::defineTipoDeExibicao(int t){
	tipoDeExibicao = t;
}

void Programacao::defineHorarios (string h){
	horarios = h;
}