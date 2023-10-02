
#include "Aplicacao.hpp"

Aplicacao::Aplicacao(){
	numCinemas = 0;
	numFilmes = 0;
	numProgramacao = 0;
	#ifdef DEBUG
	cout << "Aplicacao criada" << endl;
	#endif
}

Aplicacao::~Aplicacao(){
	
	
	
	#ifdef DEBUG
	cout << "Aplicacao destruida" << endl;
	#endif
}

/**/
bool Aplicacao::carregaFilmes(string nomeArquivo){

		if (numFilmes == MAX_FILMES){
			return false;
		}
	fstream file(nomeArquivo);

		if (!file.is_open()){
			return false;
		}
		if (file.eof()){
			return false;
		}
		while (!file.eof()){
			string aux = "";
			string titulo, estilo;
			int numero, faixaEtaria;
			getline(file, aux);
			numero = stoi(aux);
			getline (file, titulo);
			getline (file, aux);
			faixaEtaria = stoi(aux);
			getline (file, estilo);
			filmes[numFilmes] = new Filme(numero, titulo, faixaEtaria, estilo);
			numFilmes++;
		}
		file.close();
		return true;
}

bool Aplicacao::salvaFilmes(string nomeArquivo){

		if (numFilmes == 0){
			return false;
		}
	ofstream outputFile(nomeArquivo);
		if (!outputFile.is_open()){
			return false;
		}
		for (int i = 0; i < numFilmes; i++){
			outputFile << filmes[i]->obtemNumero() << endl;
			outputFile << filmes[i]->obtemTitulo() << endl;
			outputFile << filmes[i]->obtemFaixaEtaria() << endl;
			outputFile << filmes[i]->obtemEstilo() << endl;
		}
		outputFile.close();
		return true;
}

void Aplicacao::mostraFilmes(){
	if (numFilmes == 0){
		return;
	}
	for (int i = 0; i < numFilmes; i++){
		cout << filmes[i]->str() << endl;
	}
}

void Aplicacao::ordenaFilmes(){
	//Bubble Sort
	for (int i = 0; i < numFilmes; i++){
		for (int j = i+1; j < numFilmes; j++){
			if (!(*filmes[i] < *filmes[j])){
				Filme *aux = filmes[i];
				filmes[i] = filmes[j];
				filmes[j] = aux;
			}
		}
	}
}

Filme* Aplicacao::obtemFilme(int id){
	if (id < 0 || id >= numFilmes){
		return nullptr;
	}
	return filmes[id-1];
}

/*  
  int numero;    
  string nome;
  Endereco endereco;
  int salas;
  */
bool Aplicacao::carregaCinemas(string nomeArquivo){
	if (numCinemas == MAX_CINEMAS){
			return false;
		}
	fstream file(nomeArquivo);

		if (!file.is_open()){
			return false;
		}
		if (file.eof()){
			return false;
		}
		while (!file.eof()){
			Endereco endereco;
			string aux = "";
			string nome;
			int numero, salas;

			getline(file, aux);
			numero = stoi(aux);

			getline (file, nome);

			file >> endereco;
			
			getline (file, aux);
			salas = stoi(aux);

			if (aux == ""){
				return false;
			}
			cinemas[numCinemas] = new Cinema(numero, nome, endereco, salas);
			numCinemas++;
		}
		file.close();
		return true;
}

bool Aplicacao::salvaCinemas(string nomeArquivo){

		if (numCinemas == 0){
			return false;
		}
	ofstream outputFile(nomeArquivo);
		if (!outputFile.is_open()){
			return false;
		}
		for (int i = 0; i < numCinemas; i++){
			outputFile << cinemas[i]->obtemNumero() << endl;
			outputFile << cinemas[i]->obtemNome() << endl;
			outputFile << cinemas[i]->obtemEndereco() << endl;
			outputFile << cinemas[i]->obtemSalas() << endl;
		}
		outputFile.close();
		return true;
}

void Aplicacao::mostraCinemas(){
	if (numCinemas == 0){
		return;
	}
	for (int i = 0; i < numCinemas; i++){
		cout << cinemas[i]->str() << endl << endl;
	}
}

void Aplicacao::ordenaCinemas(){
	//Bubble Sort
	for (int i = 0; i < numCinemas; i++){
		for (int j = i+1; j < numCinemas; j++){
			if (!(*cinemas[i] < *cinemas[j])){
				Cinema *aux = cinemas[i];
				cinemas[i] = cinemas[j];
				cinemas[j] = aux;
			}
		}
	}
}

Cinema* Aplicacao::obtemCinema(int id){
	if (id < 0 || id >= numCinemas){
		return nullptr;
	}
	return cinemas[id-1];
}
/*
bool carregaProgramacao(string nomeArquivo): carrega a programação da
exibição de filmes do arquivo especificado, retornando true em caso de sucesso ou false em
caso de fracasso – as programações são armazenadas em um arquivo texto no formato
especificado mais adiante nesta definição de trabalho (neste formato, cinemas e filmes são
identificados por seus respectivos identificadores inteiros, sendo necessário usar os métodos
obtetmFilme() e obtemCinema() para obter as respectivas referências);
*/
bool Aplicacao::carregaProgramacao(string nomeArquivo){
	if (numProgramacao == MAX_PROGRAMACAO){
		return false;
	}
	fstream file(nomeArquivo);

		if (!file.is_open()){
			return false;
		}
		if (file.eof()){
			return false;
		}
		while (!file.eof()){
			string aux = "";
			string horarios;
			int sala,tipoDeExibicao,indiceCinema,indiceFilme;

			getline(file, aux);
			indiceCinema = stoi(aux);

			getline (file, aux);
			sala = stoi(aux);
			
			getline(file,aux);
			indiceFilme = stoi(aux);

			getline (file, aux);
			tipoDeExibicao = stoi(aux);

			getline (file, horarios);

			if (aux == ""){
				return false;
			}
			programacao[numProgramacao] = new Programacao(obtemCinema(indiceCinema),sala,obtemFilme(indiceFilme),tipoDeExibicao,horarios);
			numProgramacao++;
		}
		file.close();
		return true;
}
/*
void mostraProgramacao(): este método gera uma cadeia de caracteres com um
relatório da programação – para cada cinema é mostrado o seu nome (método obtemNome()
da classe Cinema), seguido de toda programação para este cinema (método str(false) da
classe Programacao).
*/
void Aplicacao::mostraProgramacao(){
	if (numProgramacao == 0){
		return;
	}
	for (int i = 0; i < numCinemas; i++){
		cout << cinemas[i]->obtemNome() << endl;
		for (int j = 0; j < numProgramacao; j++){
			if (programacao[j]->obtemCinema() == cinemas[i]){

			}
		}
	}
}