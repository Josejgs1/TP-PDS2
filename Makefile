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

reversi.o: reversi.hpp reversi.cpp
	${CC} ${CFLAGS} -c reversi.cpp

campoMinado.o: campoMinado.hpp campoMinado.cpp
	${CC} ${CFLAGS} -c campoMinado.cpp

main.o: jogador.hpp jogoDaVelha.hpp jogoDeTabuleiro.hpp lig4.hpp reversi.hpp campoMinado.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o jogador.o jogoDaVelha.o jogoDeTabuleiro.o lig4.o reversi.o campoMinado.o
	${CC} ${CFLAGS} main.o jogador.o jogoDaVelha.o jogoDeTabuleiro.o lig4.o reversi.o campoMinado.o -o main

clean:
	rm -f main *.o
