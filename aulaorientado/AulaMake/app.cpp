// app.cpp

#include <iostream>
#include "Aluno.hpp"

using namespace std;

#define NUM_ALUNOS 4

int main (){
	Aluno *alunos[] = {
		new Aluno("Aluno 1", 1),
		new Aluno("Aluno 2", 2),
		new Aluno("Aluno 3",3),
		new Aluno("Aluno 4",4),
		new Aluno("Aluno 5",5)
	};
	int numAlunos = sizeof(alunos) / sizeof(Aluno *);
	for (int i = 0; i <numAlunos; i++){
		cout << alunos[i]->str() << endl;
	}
	for (int i = 0; i<numAlunos;i++){
		delete alunos[i];
	}
}
