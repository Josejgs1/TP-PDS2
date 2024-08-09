#include "jogoDeTabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : _linhas(linhas), _colunas(colunas), _tabuleiro(colunas, std::vector<int>(linhas)) {}

void JogoDeTabuleiro::imprimir_tabuleiro()
{
    for (int i = 0; i < _linhas; i++)
    {
        std::cout << "|";
        for (int j = 0; j < _colunas; j++)
        {
            if(_tabuleiro[i][j] == 0){
                std::cout << "   ";
            } else if (_tabuleiro[i][j] == 1){
                std::cout << " X ";
            }
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}

void JogoDeTabuleiro::inicializar_tabuleiro()
{
    for (int i = 0; i < _linhas; ++i)
    {
        for (int j = 0; j < _colunas; ++j)
        {
            _tabuleiro[i][j] = 0;
        }
    }
}