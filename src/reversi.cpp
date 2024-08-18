#include "reversi.hpp"
#include "jogador.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

Reversi::Reversi(int linhas, int colunas, Jogador jogador1, Jogador jogador2)
    : JogoDeTabuleiro(linhas, colunas), _jogador1(jogador1), _jogador2(jogador2), _jogador_atual(1)
{
    inicializarTabuleiro();
}

Reversi::~Reversi() {}

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

    int oponente = (jogador == 1) ? 2 : 1;

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

    int oponente = (jogador == 1) ? 2 : 1;

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

void Reversi::partida()
{
    int jogadorAtual = 1;
    while (!tabuleiroCheio())
    {
        int linha, coluna;
        limpar_terminal();
        imprimir_tabuleiro(jogadorAtual);

        if (jogadorAtual == 1)
        {
            std::cout << "\033[32m" << _jogador1.get_apelido() << " (X), é sua vez.\033[0m" << std::endl;
        }
        else
        {
            std::cout << "\033[31m" << _jogador2.get_apelido() << " (O), é sua vez.\033[0m" << std::endl;
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
                    std::cout << std::endl << "Entrada inválida. Tente novamente." << std::endl;
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
                    std::cout << std::endl << "Movimento inválido. Tente novamente." << std::endl;
                }
            }
        }
        else
        {
            if (jogadorAtual == 1)
            {
                std::cout << "\033[32mJogador " << _jogador1.get_apelido() << " Não possui jogada válida. Passou a vez.\033[0m" << std::endl;
            }
            else
            {
                std::cout << "\033[31mJogador " << _jogador2.get_apelido() << " Não possui jogada válida. Passou a vez.\033[0m" << std::endl;
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
    limpar_terminal();
    imprimir_tabuleiro(jogadorAtual);
    
    int resultado = checar_vitoria();


    if (contarPecas(1) == contarPecas(2))
    {
        std::cout << "Empate com " << contarPecas(1) << " peças para cada jogador." << std::endl;
    }
    else if (resultado == 0)
    {
        std::cout << std::endl;
        std::cout << _jogador1.get_apelido() << " (X) venceu com " << contarPecas(1) << " peças contra " << contarPecas(2) << " peças de " << _jogador2.get_apelido() << " (O)." << std::endl;
        _jogador1.soma_vitoria_rvs();
        _jogador2.soma_derrota_rvs();
    }
    else if (resultado == 1)
    {   
        std::cout << std::endl;
        std::cout << _jogador2.get_apelido() << " (O) venceu com " << contarPecas(2) << " peças contra " << contarPecas(1) << " peças de " << _jogador1.get_apelido() << " (X)." << std::endl;
        _jogador2.soma_vitoria_rvs();
        _jogador1.soma_derrota_rvs();
    }
    std::cout << std::endl;
    std::cout << "Estatísticas Atuais:" << std::endl;
    _jogador1.imprimir_informacoes_rvs();
    _jogador2.imprimir_informacoes_rvs();
    std::cout << std::endl;
}

bool Reversi::checar_vitoria()
{
    int pecasJogador1 = contarPecas(1);
    int pecasJogador2 = contarPecas(2);

    if (pecasJogador1 > pecasJogador2)
    {
        return 0;
    }
    else if (pecasJogador2 > pecasJogador1)
    {
        return 1;
    }
}

//--Casos extremos-- 
//1° - Tabuleiro fica completamente cheio;
//2° - Um jogador não possui movimentos válidos e passa sua vez;
//3° - Um jogador não possui nenhuma "peça" e o jogo termina;
//4° - Ambos os jogadores não possuem movimentos válidos, o jogo termina e contabiliza o número de peças de cada um;