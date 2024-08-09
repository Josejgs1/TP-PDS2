#include "jogoDaVelha.hpp"

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3) {}

void JogoDaVelha::imprimir_tabuleiro() 
{
    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if(_tabuleiro[i][j] == 0){
                std::cout << "   ";
            } else if (_tabuleiro[i][j] == 1){
                std::cout << " X ";
            }

            if(j != _colunas - 1){
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void JogoDaVelha::fazer_jogada(int x, int y){
    for(int i = 0; i < _linhas; i++){
        for (int j = 0; j < _colunas; j++)
        {
            if(i == y && j == x){
                _tabuleiro[x][y] = 1;
            }
        }
    }
    imprimir_tabuleiro();
}
