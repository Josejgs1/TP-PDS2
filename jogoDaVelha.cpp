#include "jogoDaVelha.hpp"

JogoDaVelha::JogoDaVelha(Jogador jogador1, Jogador jogador2)
    : JogoDeTabuleiro(3, 3), _jogador1(jogador1), _jogador2(jogador2), _jogador_atual(1) {}

void JogoDaVelha::imprimir_tabuleiro()
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

void JogoDaVelha::fazer_jogada(int x, int y)
{
    if (x < 1 || x > 3 || y < 1 || y > 3)
    {
        std::cout << "Jogada invalida! Por favor, insira dois numeros de 1 a 3." << std::endl;
        return;
    }

    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if (i == y - 1 && j == x - 1)
            {
                _tabuleiro[x - 1][y - 1] = _jogador_atual;
                alternar_jogador();
            }
        }
    }
    imprimir_tabuleiro();
}

void JogoDaVelha::alternar_jogador()
{
    if (_jogador_atual == 1)
    {
        _jogador_atual = 2;
    }
    else
    {
        _jogador_atual = 1;
    }
}

// bool JogoDaVelha::checar_vitoria()
// {

// }