CC=g++
CFLAGS=-std=c++11 -Wall

all: main

jogador.o: jogador.hpp jogador.cpp
	${CC} ${CFLAGS} -c jogador.cpp

jogoDaVelha.o: jogoDaVelha.hpp jogoDaVelha.cpp
	${CC} ${CFLAGS} -c jogoDaVelha.cpp

jogoDeTabuleiro.o: jogoDeTabuleiro.hpp jogoDeTabuleiro.cpp
	${CC} ${CFLAGS} -c jogoDeTabuleiro.cpp

lig4.o: lig4.hpp lig4.cpp
	${CC} ${CFLAGS} -c lig4.cpp

main.o: jogador.hpp jogoDaVelha.hpp jogoDeTabuleiro.hpp lig4.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o jogador.o jogoDaVelha.o jogoDeTabuleiro.o lig4.o
	${CC} ${CFLAGS} main.o jogador.o jogoDaVelha.o jogoDeTabuleiro.o lig4.o -o main

clean:
	rm -f main *.o
