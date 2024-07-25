#include "campoMinado.hpp"

CampoMinado::CampoMinado(int linhas, int colunas, Jogador jogador, int n_bombas)
    : JogoDeTabuleiro(linhas, colunas), _jogador(jogador), _n_bombas(n_bombas)
{
    srand(time(0)); 
    colocar_bombas();
}

CampoMinado::~CampoMinado() {}

void CampoMinado::imprimir_tabuleiro()
{
    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if (_tabuleiro[i][j] == 0)
            {
                if (bombas_em_volta(i, j) == 0)
                {
                    std::cout << "   ";
                } else
                {
                    std::cout << " " << bombas_em_volta(i, j) << " ";
                }
            }
            else if (_tabuleiro[i][j] == 1)
            {
                std::cout << " * ";
            }
            // else if (_tabuleiro[i][j] == 2)
            // {
            //     std::cout << " O ";
            // }

            if (j != _colunas - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void CampoMinado::colocar_bombas()
{
    int bombas_colocadas = 0;
    while (bombas_colocadas < _n_bombas)
    {
        int x = rand() % _linhas;
        int y = rand() % _colunas;

        if (_tabuleiro[x][y] == 0)
        {
            _tabuleiro[x][y] = 1;
            bombas_colocadas++;
        }
    }
}

int CampoMinado::bombas_em_volta(int x, int y)
{
    int bombas_adjacentes = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i < _linhas && j >= 0 && j < _colunas && (i != x || j != y))
            {
                if (_tabuleiro[i][j] == 1)
                {
                    bombas_adjacentes++;
                }
            }
        }
    }
    return bombas_adjacentes;
}