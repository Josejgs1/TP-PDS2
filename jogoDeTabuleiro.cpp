#include "jogoDeTabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : _linhas(linhas), _colunas(colunas), _tabuleiro(colunas, std::vector<int>(linhas)) {}

void JogoDeTabuleiro::imprimir_tabuleiro(){
    for(int i = 0; i < _linhas; i++){
        printf("|");
        for(int j=0; j < _colunas; j++){
            printf(" 0 ");
            printf("|");
        }
    }
}