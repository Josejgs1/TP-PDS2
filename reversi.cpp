#include "reversi.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

Reversi::Reversi(int linhas, int colunas) : JogoDeTabuleiro(linhas, colunas)
{
    if (linhas != colunas || linhas < 6 || linhas > 10 || linhas % 2 != 0)
    {
        throw std::invalid_argument("O tabuleiro deve ser quadrado, no mínimo 6x6, no máximo 10x10, e com dimensões pares.");
    }
    inicializarTabuleiro();
}

void Reversi::inicializarTabuleiro()
{
    JogoDeTabuleiro::inicializar_tabuleiro();
    int meio = _linhas / 2;
    int valores[2][2] = {{1, 2}, {2, 1}};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            _tabuleiro[meio - 1 + i][meio - 1 + j] = valores[i][j];
        }
    }
}

bool Reversi::movimentoValido(int linha, int coluna, int jogador)
{
    if (_tabuleiro[linha][coluna] != 0)
    {
        return false;
    }

    int oponente;
    if (jogador == 1)
    {
        oponente = 2;
    }
    else
    {
        oponente = 1;
    }

    for (int _deltaLinha = -1; _deltaLinha <= 1; ++_deltaLinha)
    {
        for (int _deltaColuna = -1; _deltaColuna <= 1; ++_deltaColuna)
        {
            int _novaLinha = linha + _deltaLinha;
            int _novaColuna = coluna + _deltaColuna;

            if (_novaLinha >= 0 && _novaLinha < _linhas && _novaColuna >= 0 && _novaColuna < _colunas && _tabuleiro[_novaLinha][_novaColuna] == oponente)
            {
                while (_novaLinha >= 0 && _novaLinha < _linhas && _novaColuna >= 0 && _novaColuna < _colunas)
                {
                    _novaLinha += _deltaLinha;
                    _novaColuna += _deltaColuna;
                    if (_novaLinha >= 0 && _novaLinha < _linhas && _novaColuna >= 0 && _novaColuna < _colunas)
                    {
                        if (_tabuleiro[_novaLinha][_novaColuna] == jogador)
                        {
                            return true;
                        }
                        else if (_tabuleiro[_novaLinha][_novaColuna] == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    return false;
}

void Reversi::realizarMovimento(int linha, int coluna, int jogador)
{
    if (!movimentoValido(linha, coluna, jogador))
    {
        throw std::invalid_argument("Movimento inválido.");
    }

    int oponente;
    if (jogador == 1)
    {
        oponente = 2;
    }
    else
    {
        oponente = 1;
    }

    _tabuleiro[linha][coluna] = jogador;

    for (int _deltaLinha = -1; _deltaLinha <= 1; ++_deltaLinha)
    {
        for (int _deltaColuna = -1; _deltaColuna <= 1; ++_deltaColuna)
        {
            if (_deltaLinha == 0 && _deltaColuna == 0)
                continue;

            int _novaLinha = linha + _deltaLinha;
            int _novaColuna = coluna + _deltaColuna;
            bool _casaOcupadaAdversario = false;
            std::vector<std::pair<int, int>> pecasQueInvertem;

            while (_novaLinha >= 0 && _novaLinha < _linhas && _novaColuna >= 0 && _novaColuna < _colunas)
            {
                if (_tabuleiro[_novaLinha][_novaColuna] == oponente)
                {
                    _casaOcupadaAdversario = true;
                    pecasQueInvertem.push_back({_novaLinha, _novaColuna});
                }
                else if (_tabuleiro[_novaLinha][_novaColuna] == jogador && _casaOcupadaAdversario)
                {
                    for (const auto &peca : pecasQueInvertem)
                    {
                        _tabuleiro[peca.first][peca.second] = jogador;
                    }
                    break;
                }
                else
                {
                    break;
                }
                _novaLinha += _deltaLinha;
                _novaColuna += _deltaColuna;
            }
        }
    }
}

bool Reversi::temMovimentosValidos(int jogador)
{
    for (int i = 0; i < _linhas; ++i)
    {
        for (int j = 0; j < _colunas; ++j)
        {
            if (_tabuleiro[i][j] == 0 && movimentoValido(i, j, jogador))
            {
                return true;
            }
        }
    }
    return false;
}

bool Reversi::tabuleiroCheio()
{
    for (int i = 0; i < _linhas; ++i)
    {
        for (int j = 0; j < _colunas; ++j)
        {
            if (_tabuleiro[i][j] == 0)
                return false;
        }
    }
    return true;
}

int Reversi::contarPecas(int jogador)
{
    int count = 0;
    for (int i = 0; i < _linhas; ++i)
    {
        for (int j = 0; j < _colunas; ++j)
        {
            if (_tabuleiro[i][j] == jogador)
            {
                count++;
            }
        }
    }
    return count;
}

void Reversi::imprimir_tabuleiro(int jogadorAtual)
{
    std::cout << "   ";
    for (int j = 0; j < _colunas; ++j)
    {
        std::cout << std::setw(3) << (j + 1) << " ";
    }
    std::cout << std::endl;

    std::cout << "   -";
    for (int j = 0; j < _colunas; ++j)
    {
        std::cout << "----";
    }
    std::cout << std::endl;

    for (int i = 0; i < _linhas; ++i)
    {
        std::cout << std::setw(2) << (i + 1) << " |";
        for (int j = 0; j < _colunas; ++j)
        {
            if (_tabuleiro[i][j] == 0)
            {
                if (this->movimentoValido(i, j, jogadorAtual))
                {
                    if (jogadorAtual == 1)
                    {
                        std::cout << "\033[32m . \033[0m";
                    }
                    else
                    {
                        std::cout << "\033[31m . \033[0m";
                    }
                }
                else
                {
                    std::cout << "   ";
                }
            }
            else if (_tabuleiro[i][j] == 1)
            {
                std::cout << "\033[34m X \033[0m";
            }
            else
            {
                std::cout << "\033[33m O \033[0m";
            }
            std::cout << "|";
        }
        std::cout << std::endl;

        std::cout << "   -";
        for (int j = 0; j < _colunas; ++j)
        {
            std::cout << "----";
        }
        std::cout << std::endl;
    }
}

void Reversi::jogar()
{
    int jogadorAtual = 1;
    while (!tabuleiroCheio())
    {
        int linha, coluna;
        std::cout << "\033[2J\033[1;1H";
        imprimir_tabuleiro(jogadorAtual);

        if (jogadorAtual == 1)
        {
            std::cout << "\033[32mJogador 1 (X), é sua vez.\033[0m" << std::endl;
        }
        else
        {
            std::cout << "\033[31mJogador 2 (O), é sua vez.\033[0m" << std::endl;
        }

        if (temMovimentosValidos(jogadorAtual))
        {
            bool movimentoValido = false;
            while (!movimentoValido)
            {
                std::cout << "Insira a linha e a coluna onde deseja colocar sua peça : ";
                std::cin >> linha >> coluna;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida. Tente novamente." << std::endl;
                    continue;
                }

                linha--;
                coluna--;

                if (linha >= 0 && linha < _linhas && coluna >= 0 && coluna < _colunas && this->movimentoValido(linha, coluna, jogadorAtual))
                {
                    realizarMovimento(linha, coluna, jogadorAtual);
                    movimentoValido = true;
                }
                else
                {
                    std::cout << "Movimento inválido. Tente novamente." << std::endl;
                }
            }
        }
        else
        {
            if (jogadorAtual == 1)
            {
                std::cout << "\033[32mJogador " << jogadorAtual << " Não possui jogada válida. Passou a vez.\033[0m" << std::endl;
            }
            else
            {
                std::cout << "\033[31mJogador " << jogadorAtual << " Não possui jogada válida. Passou a vez.\033[0m" << std::endl;
            }
        }

        if (!temMovimentosValidos(1) && !temMovimentosValidos(2))
        {
            break;
        }

        if (jogadorAtual == 1)
        {
            jogadorAtual = 2;
        }
        else
        {
            jogadorAtual = 1;
        }
    }

    int pontosJogador1 = contarPecas(1);
    int pontosJogador2 = contarPecas(2);
    std::cout << std::endl;
    std::cout << "Fim de jogo!" << std::endl;
    std::cout << "Jogador 1 (X) tem " << pontosJogador1 << " peças." << std::endl;
    std::cout << "Jogador 2 (O) tem " << pontosJogador2 << " peças." << std::endl;
    std::cout << std::endl;

    if (pontosJogador1 > pontosJogador2)
    {
        std::cout << "Jogador 1 (X) vence!" << std::endl;
    }
    else if (pontosJogador2 > pontosJogador1)
    {
        std::cout << "Jogador 2 (O) vence!" << std::endl;
    }
    else
    {
        std::cout << "Empate!" << std::endl;
    }
    std::cout << std::endl;
}

bool Reversi::checar_vitoria()
{
    int pontosJogador1 = contarPecas(1);
    int pontosJogador2 = contarPecas(2);
    return pontosJogador1 > pontosJogador2 || pontosJogador2 > pontosJogador1;
}

void Reversi::partida()
{
    jogar();
}


//--Casos extremos-- 
//1° - Tabuleiro fica completamente cheio;
//2° - Um jogador não possui movimentos válidos e passa sua vez;
//3° - Um jogador não possui nenhuma "peça" e o jogo termina;
//4° - Ambos os jogadores não possuem movimentos válidos, o jogo termina e contabiliza o número de peças de cada um;


