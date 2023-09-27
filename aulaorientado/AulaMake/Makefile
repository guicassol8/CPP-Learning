CFLAGS = -c -std=c++11 #-DDEBUG

all:		app

app:		app.o Pessoa.o Aluno.o
			g++ -o app app.o Pessoa.o Aluno.o

app.o:		app.cpp Aluno.hpp
			g++ ${CFLAGS} app.cpp

Pessoa.o:	Pessoa.cpp Pessoa.hpp
			g++ ${CFLAGS} Pessoa.cpp

Aluno.o: 	Aluno.cpp Aluno.hpp
			g++ ${CFLAGS} Aluno.cpp

clean:
			rm -f app app.o Pessoa.o Aluno.o