#include "jogoDeTabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : _linhas(linhas), _colunas(colunas), _tabuleiro(linhas, std::vector<int>(colunas)) {}

void JogoDeTabuleiro::imprimir_tabuleiro()
{
    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if (_tabuleiro[i][j] == 0)
            {
                std::cout << "   ";
            }
            else if (_tabuleiro[i][j] == 1)
            {
                std::cout << " X ";
            }
            else if (_tabuleiro[i][j] == 2)
            {
                std::cout << " O ";
            }

            if (j != _colunas - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
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

void limpar_terminal()
{
    std::cout << "\033[2J\033[1;1H";
}