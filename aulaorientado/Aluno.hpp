//Aluno.hpp
#ifndef _ALUNO_HPP
#define _ALUNO_HPP

#include <iostream>

#define MAX_PRESENCAS 100

class Aluno {
	private:
	std::string nome;
	int numPresencas;
	char presencas[MAX_PRESENCAS];
	public:
		Aluno(std::string n = "");
		~Aluno();

		std::string obtemNome();
		int obtemNumPresencas();
		char obtemPresenca(int d);
		std::string str();
		
		void defineNome(std::string n);
		bool definePresenca(int i, char p);
		bool realizaChamada(char p);
};

#endif