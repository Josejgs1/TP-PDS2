#include "campoMinado.hpp"
#include <cstdlib>
#include <ctime>

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
            if (_tabuleiro[i][j] == 0 || _tabuleiro[i][j] == 1)
            {
                std::cout << " / ";
            }
            else if (_tabuleiro[i][j] == 2)
            {
                if (bombas_em_volta(i, j) == 0)
                {
                    std::cout << "   ";
                }
                else
                {
                    std::cout << " " << bombas_em_volta(i, j) << " ";
                }
            }
            else if (_tabuleiro[i][j] == 3)
            {
                std::cout << " * ";
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

void CampoMinado::fazer_jogada(int x, int y)
{
    if (x < 1 || x > _linhas || y < 1 || y > _colunas)
    {
        std::cout << "Jogada invalida! Por favor, insira dois numeros de 1 a " << _colunas << "." << std::endl;
        return;
    }

    if (_tabuleiro[x - 1][y - 1] == 0)
    {
        _tabuleiro[x - 1][y - 1] = 2;
    }
    else if (_tabuleiro[x - 1][y - 1] == 1)
    {
        _tabuleiro[x - 1][y - 1] = 3;
    }
    else
    {
        std::cout << "Posicao ja ocupada! Tente novamente." << std::endl;
    }
    imprimir_tabuleiro();
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

bool CampoMinado::checar_vitoria()
{
    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if (_tabuleiro[i][j] == 0 && _tabuleiro[i][j] != 2)
            {
                return false;
            }
        }
    }
    return true;
}

void CampoMinado::partida()
{
    imprimir_tabuleiro();
    while (!checar_vitoria())
    {
        int x, y;
        std::cout << _jogador.get_apelido() << ", faça sua jogada: ";
        std::cin >> x >> y;
        fazer_jogada(x, y);
        if (_tabuleiro[x - 1][y - 1] == 3)
        {
            std::cout << "Voce perdeu!" << std::endl;
            int vitorias = _jogador.get_derrotas_cm();
            _jogador.set_derrotas_cm(vitorias + 1);
            _jogador.imprimir_informacoes();
            return;
        }
    }
    if (checar_vitoria())
    {
        int vitorias = _jogador.get_vitorias_cm();
        _jogador.set_vitorias_cm(vitorias + 1);

        std::cout << "Parabens " << _jogador.get_apelido() << ", voce venceu!" << std::endl;
        _jogador.imprimir_informacoes();
        return;
    }
}