//Exercicio001.cpp, Guilherme Cassol, Exercicio 001, 10/09/2023
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#define MAX_ALUNOS 10

class Aluno {
    private:
        int matricula;
        string nome;
        float nota;
    public:
        Aluno (int ma = 0, string no = "", float na = -1.0) {
            matricula = ma;
            nome = no;
            nota = na;
        }
        int obtemMatricula (){
            return matricula;
        }
        string obtemNome (){
            return nome;
        }
        float obtemNota (){
            return nota;
        }
        void defineMatricula (int ma){
            matricula = ma;
        }
        void defineNome (string no){
            nome = no;
        }
        void defineNota (float na){
            nota = na;
        }
        string str (){
            stringstream ss;
            ss << nome << " (" << setw(10) << setfill('0') << matricula << ")";
            if (nota != -1.0){
                ss << ": " << fixed << setprecision(4)<< nota;
            }
            return ss.str();
        }
};

class Turma {
    private:
        int numTurma;
        string nomDisciplina;
        string professor;
        Aluno *alunos[MAX_ALUNOS];
        int numAlunos;
    public:
        Turma (int nt = 0, string nd = "", string pr = "", int na = 0) {
            numTurma = nt;
            nomDisciplina = nd;
            professor = pr;
            numAlunos = na;
        }
        int obtemNumero (){
            return numTurma;
        }
        string obtemDisciplina (){
            return nomDisciplina;
        }
        string obtemProfessor (){
            return professor;
        }
        Aluno* obtemAluno (int indice){
            if (indice >= 0 && indice < numAlunos){
                return alunos[indice];
            }
            return nullptr;
        }
        int obtemNumAlunos (){
            return numAlunos;
        }
        void defineNumero (int nt){
            numTurma = nt;
        }
        void defineDisciplina (string nd){
            nomDisciplina = nd;
        }
        void defineProfessor (string pr){
            professor = pr;
        }
        bool adicionaAluno (Aluno *al){
            if (numAlunos < MAX_ALUNOS){
            alunos [numAlunos] = al;
            numAlunos++;
            return true;
            }
            return false;
        }
        float calculaMedia (){
            if (numAlunos == 0){
                return -1.0;
            }
            float media = 0.0;
            int teste = 0;
            for (int i = 0; i < numAlunos; i++){
                if (alunos[i]->obtemNota() == -1.0){
                    teste+= -1;
                    continue;
                }
                media += alunos[i]->obtemNota();
            }
            return media/ (numAlunos + teste);
        }
        string str (){
            stringstream ss;
            ss << numTurma << " - " << nomDisciplina << " - Prof. " << professor;
            for (int i = 0; i < numAlunos; i++){
                ss << endl << alunos[i]->str();
            }
            if (calculaMedia() != -1.0){
            ss << endl << fixed << setprecision(4) <<  "MEDIA = "<< calculaMedia();
            }
            ss << endl;
            return ss.str();
        }
};

int main() {
    Aluno *discente[] = {
        new Aluno(1,"Benedito",9.1),
        new Aluno(2,"Carlos",8.2),
        new Aluno(3,"Daniela",7.3),
        new Aluno(4,"Elisabeth",6.4),
        new Aluno(5,"Fernanda",5.5),
        new Aluno(6,"Gilson",9.6),
        new Aluno(7,"Heitor",8.5),
        new Aluno(8,"Irineu",7.4),
        new Aluno(9,"Joana",3.2),
        new Aluno(10,"Klaus",-1.0),
        new Aluno(11,"Laura",9.8)
    };
    int numDiscentes = sizeof(discente)/sizeof(Aluno *);
    Turma *turma = new Turma(0,"SEM ALUNOS","INDEFINIDO");
    int a;
    cout << turma->str() << endl;
    turma->defineNumero(123);
    turma->defineDisciplina("Linguagem C");
    turma->defineProfessor("Alberto");
    for (a=0; a<5; ++a)
        if (!turma->adicionaAluno(discente[a])) { cerr << "ERRO"; exit(1); }
    for (a=0; a<5; ++a)
        if (turma->obtemAluno(a) != discente[a]) { cerr << "ERRO"; exit(1); }
    for (; a<numDiscentes; ++a)
        if (turma->obtemAluno(a) != nullptr) { cerr << "ERRO"; exit(1); }
    cout << turma->str() << endl;
        for (a=5; a<MAX_ALUNOS; ++a)
        if (!turma->adicionaAluno(discente[a])) { cerr << "ERRO"; exit(1); }
    for (; a<numDiscentes; ++a)
        if (turma->adicionaAluno(discente[a])) { cerr << "ERRO"; exit(1); }
    for (a=0; a<MAX_ALUNOS; ++a)
        if (turma->obtemAluno(a) != discente[a]) { cerr << "ERRO"; exit(1); }
    cout << turma->str() << endl;
    delete turma;
    for (int i=0; i<numDiscentes; ++i)
        delete discente[i];
    return 0;
}
