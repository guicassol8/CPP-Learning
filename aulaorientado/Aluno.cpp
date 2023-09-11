//Aluno.cpp

#include "Aluno.hpp"

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif
#include <sstream>

Aluno::Aluno(std::string n, int m) {
	p = new Pessoa (n);
	matricula = m;
	#ifdef DEBUG
	cout << "+ Pesso("<< p->obtemNome() << ") criada..."<< endl;
	#endif
}

Aluno::~Aluno(){
	#ifdef DEBUG
	cout << "- Pesso("<< p->obtemNome() << ") destruida..."<< endl;
	#endif
	delete p;
}
int Aluno::obtemMatricula(){return matricula;}
void Aluno::defineMatricula(int n){matricula = n;}
std::string Aluno::obtemNome(){return p->obtemNome();};
void Aluno::defineNome (std::string n){p->defineNome(n);}
std::string Aluno::str(){
	std::stringstream ss;
	ss << p->obtemNome() << " ("<< matricula << ")";
	return ss.str();
}


