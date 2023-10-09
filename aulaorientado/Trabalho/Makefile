CFLAGS = -c -std=c++11 #-DDEBUG

all:		app3

app3:		app3.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o
			g++ -o app3 app3.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o

app3.o:		app3.cpp Aplicacao.hpp
			g++ ${CFLAGS} app3.cpp

Aplicacao.o:	Aplicacao.cpp Aplicacao.hpp Cinema.hpp Filme.hpp Programacao.hpp
			g++ ${CFLAGS} Aplicacao.cpp

Filme.o: 	Filme.cpp Filme.hpp
	        g++ ${CFLAGS} Filme.cpp

Cinema.o: 	Cinema.cpp Cinema.hpp Endereco.hpp
	        g++ ${CFLAGS} Cinema.cpp

Endereco.o: 	Endereco.cpp Endereco.hpp
	        g++ ${CFLAGS} Endereco.cpp

Programacao.o: 	Programacao.cpp Programacao.hpp
	        g++ ${CFLAGS} Programacao.cpp

clean:
			rm -f app3 app3.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o 