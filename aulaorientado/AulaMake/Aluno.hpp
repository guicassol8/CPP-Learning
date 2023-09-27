// Aluno.hpp

#ifndef _ALUNO_HPP
#define _ALUNO_HPP
#include <string>
#include "Pessoa.hpp"
class Aluno{
	private:
		int matricula;
		Pessoa *p; //necessario dar new e delete para usar
	public:
		Aluno (std::string n = "", int m = 0);
		~Aluno();
		int obtemMatricula();
		void defineMatricula(int n);
		std::string obtemNome();
		void defineNome (std::string n);
		std::string str();
};


#endif