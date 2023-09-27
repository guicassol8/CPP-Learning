#include "Pessoa.hpp"
#include <iostream>
using namespace std;

	Pessoa::Pessoa(std::string n){
		nome = n;
		#ifdef DEBUG
		cout << "+ Pesso("<< nome << ") criada..."<< endl;
		#endif
	}
	Pessoa::~Pessoa(){
		#ifdef DEBUG
		cout << "- Pesso("<< nome << ") destruida..."<< endl;
		#endif
	}
	void Pessoa::defineNome(std::string n){
		nome = n;
	}
	std::string Pessoa::obtemNome(){return nome;}
