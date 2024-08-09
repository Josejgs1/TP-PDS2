#include "lig4.hpp"
#include <string>
#include <iostream>
#include <vector>

Lig4::Lig4(int linhas, int colunas) : JogoDeTabuleiro(linhas, colunas) {}

void Lig4::fazer_jogada(int x){

    bool invalido = false;

    for(int i = 0; i < _linhas; i++){
        if(_tabuleiro[_linhas - 1 - i][x - 1] == 0){
            _tabuleiro[_linhas - 1 - i][x - 1] = 1;
            invalido = true;
            break;
        }
    }    
    
    if(invalido){
        std::cout << "Movimento inválido." << std::endl;
    }

    imprimir_tabuleiro();
}