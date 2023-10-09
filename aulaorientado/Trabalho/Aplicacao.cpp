
#include "Aplicacao.hpp"
/*
Construtor padrao que atribui valores nulos a todas variaveis
Se DEBUG estiver definido ira printar a criacao da classe
*/
Aplicacao::Aplicacao(){

	numCinemas = 0;
	numFilmes = 0;
	numProgramacao = 0;
	#ifdef DEBUG
	cout << "Aplicacao criada" << endl;
	#endif

}

/*
Destrutor que desaloca o espaco de todas variaveis (cinemas, filmes e programacao)
*/
Aplicacao::~Aplicacao(){

	for (int i = 0; i < numCinemas; i++){
		delete cinemas[i];
	}
	for (int i = 0; i < numFilmes; i++){
		delete filmes[i];
	}
	for (int i = 0; i < numProgramacao; i++){
		delete programacao[i];
	}

	#ifdef DEBUG
	cout << "Aplicacao destruida" << endl;
	#endif
}

/*
Metodo que abre um arquivo atraves do parametro nomeArquivo
carregando todos dados e arquivos do texto, criando um novo objeto Filme, o alocando em mais um espaco do vetor
@param nomeArquivo
@return true se o arquivo foi aberto com sucesso e todas atribuicoes deram certo
@return false se houve algum problema no caminho
*/
bool Aplicacao::carregaFilmes(string nomeArquivo){

	// verifica se foi alcancado o limite maximo de filmes
	if (numFilmes == MAX_FILMES){
		return false;
	}

	//abre o arquivo
	fstream file(nomeArquivo);
		//verifica se o arquivo foi aberto com sucesso
		if (!file.is_open()){
			return false;
		}
		// verifica se o arquivo chegou no fim, consequentemente estando vazio
		if (file.eof()){
			return false;
		}
		
		//laco que so acaba quando chegar no final  do arquivo
		while (!file.eof()){
			//variaveis auxiliares
			string aux = "";
			string titulo, estilo;
			int numero, faixaEtaria;
			//atribuicao das variaveis auxiliares
			getline(file, aux);
			numero = stoi(aux);
			getline (file, titulo);
			getline (file, aux);
			faixaEtaria = stoi(aux);
			getline (file, estilo);
			//cria o novo objeto vetor, alocando o ultimo espaco do vetor e aumentando a quantidade de filmes
			filmes[numFilmes] = new Filme(numero, titulo, faixaEtaria, estilo);
			numFilmes++;
		}

		file.close();
		return true;
}
/*
Metodo que salva todas informacoes de filmes no arquivo atraves do parametro nomeArquivo
@param nomeArquivo
@return true se o arquivo foi salvo com sucesso
@return false se houve algum problema no caminho
*/
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

/*
Metodo que printa todos os filmes no vetor
@return void
*/
void Aplicacao::mostraFilmes(){

	if (numFilmes == 0){
		return;
	}
	
	for (int i = 0; i < numFilmes; i++){
		cout << filmes[i]->str() << endl;
	}
}

/*
Metodo que ordena os filmes pela ordem alfabetica, usando o Bubble Sort
@return void
*/
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

/*
Metodo que retorna um objeto filme baseado no seu id propiro
@param id
@return Filme
*/
Filme* Aplicacao::obtemFilme(int id){

	if (id < 0 || id > numFilmes){
		return nullptr;
	}

	for (int i = 0; i < numFilmes ; i++){
		if (filmes[i]->obtemNumero () == id){
			return filmes[i];
		}
	}

	return nullptr;
}

/*
Metodo que abre um arquivo atraves do parametro nomeArquivo
carregando todos dados e arquivos do texto, criando um novo objeto Cinema, o alocando em mais um espaco do vetor
@param nomeArquivo
@return true se o arquivo foi aberto com sucesso e todas atribuicoes deram certo
@return false se houve algum problema no caminho
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

			cinemas[numCinemas] = new Cinema(numero, nome, endereco, salas);
			numCinemas++;
		}

		file.close();
		return true;
}

/*
Metodo que salva todas informacoes de cinema no arquivo atraves do parametro nomeArquivo
@param nomeArquivo
@return true se o arquivo foi salvo com sucesso
@return false se houve algum problema no caminho
*/
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

/*
Metodo que printa todos os filmes no vetor
@return void
*/
void Aplicacao::mostraCinemas(){

	if (numCinemas == 0){
		return;
	}

	for (int i = 0; i < numCinemas; i++){
		cout << cinemas[i]->str() << endl << endl;
	}
}

/*
Metodo que ordena os cinemas pela ordem alfabetica, usando o Bubble Sort
@return void
*/
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

/*
Metodo que retorna um objeto cinema baseado no seu id propiro
@param id
@return cinema
*/
Cinema* Aplicacao::obtemCinema(int id){

	if (id < 0 || id >= numCinemas){
		return nullptr;
	}
	
	for (int i = 0; i < numCinemas ; i++){
		if (cinemas[i]->obtemNumero() == id){
			return cinemas[i];
		}
	}

	return nullptr;
}
/*
Metodo que carrega a Programacao, baseado no arquivo passado pelo parametro.
O metodo ira procurar os filmes e cinemas correspondentes aos parametros passados e ira criar uma nova programacao no vetor, aumentando sua quantidade
@param nomeArquivo
@return true se o arquivo foi aberto com sucesso e todas atribuicoes deram certo
@return false se houve algum problema no caminho
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

			programacao[numProgramacao] = new Programacao(obtemCinema(indiceCinema),sala,obtemFilme(indiceFilme),tipoDeExibicao,horarios);
			numProgramacao++;
		}

		file.close();
		return true;
}
/*
Metodo printa o nome do cinema e todos filmes e suas programacoes
*/
void Aplicacao::mostraProgramacao(){

	if (numProgramacao == 0){
		return;
	}

	for (int i = 0; i < numCinemas; i++){
		cout << cinemas[i]->obtemNome() << endl << endl;
		for (int j = 0; j < numProgramacao; j++){
			if (cinemas[i] == programacao[j]->obtemCinema()){
				cout << programacao[j]->str(false) << endl;
			}
		}
		cout << endl;
	}
}