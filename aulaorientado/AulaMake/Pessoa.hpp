// Pessoa.hpp

#ifndef _PESSOA_HPP
#define _PESSOA_HPP
#include <string>

class Pessoa{
	private:
	std::string nome;
	public:
	Pessoa(std::string n = "");
	~Pessoa();
	void defineNome(std::string n);
	std::string obtemNome();
};

#endif