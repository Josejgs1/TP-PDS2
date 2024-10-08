#include "reversi.hpp"
#include "jogador.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <sstream>
#include <string>

/**
 * @brief Construtor padrão da classe Reversi.
 */
Reversi::Reversi() : JogoDeTabuleiro(), _jogador1(nullptr), _jogador2(nullptr), _jogador_atual(1) {}

/**
 * @brief Construtor parametrizado da classe Reversi.
 * @param linhas Número de linhas do tabuleiro.
 * @param colunas Número de colunas do tabuleiro.
 * @param jogador1 Referência para o primeiro jogador.
 * @param jogador2 Referência para o segundo jogador.
 */
Reversi::Reversi(int linhas, int colunas, Jogador& jogador1, Jogador& jogador2)
    : JogoDeTabuleiro(linhas, colunas), _jogador1(&jogador1), _jogador2(&jogador2), _jogador_atual(1)
{
    inicializarTabuleiro();
}

/**
 * @brief Destruidor da classe Reversi.
 */
Reversi::~Reversi() {}

/**
 * @brief Inicializa o tabuleiro com as peças iniciais do Reversi.
 */
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

/**
 * @brief Verifica se um movimento é válido.
 * @param linha Linha onde o movimento será realizado.
 * @param coluna Coluna onde o movimento será realizado.
 * @param jogador Identificador do jogador (1 ou 2).
 * @return True se o movimento for válido, False caso contrário.
 */
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

/**
 * @brief Realiza um movimento no tabuleiro.
 * @param linha Linha onde o movimento será realizado.
 * @param coluna Coluna onde o movimento será realizado.
 * @param jogador Identificador do jogador (1 ou 2).
 * @throw std::invalid_argument Se o movimento não for válido.
 */
void Reversi::realizarMovimento(int linha, int coluna, int jogador)
{
    if (!movimentoValido(linha, coluna, jogador))
    {
        throw std::invalid_argument("Movimento invalido.");
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

/**
 * @brief Verifica se o jogador tem movimentos válidos.
 * @param jogador Identificador do jogador (1 ou 2).
 * @return True se o jogador tem movimentos válidos, False caso contrário.
 */
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

/**
 * @brief Verifica se o tabuleiro está cheio.
 * @return True se o tabuleiro estiver cheio, False caso contrário.
 */
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

/**
 * @brief Conta o número de peças de um jogador no tabuleiro.
 * @param jogador Identificador do jogador (1 ou 2).
 * @return Número de peças do jogador.
 */
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

/**
 * @brief Imprime o tabuleiro do jogo.
 * @param jogadorAtual Identificador do jogador atual (1 ou 2).
 */
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

/**
 * @brief Controla o fluxo principal do jogo.
 */
void Reversi::partida()
{
    int jogadorAtual = 1;
    limpar_terminal();
    imprimir_tabuleiro(jogadorAtual);
    std::string mensagemErro;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!tabuleiroCheio())
    {
        int linha, coluna;

        while (true)
        {
            limpar_terminal();

            if (!mensagemErro.empty())
            {
                std::cout << "\033[1;31m" << mensagemErro << "\033[0m" << std::endl;
            }

            imprimir_tabuleiro(jogadorAtual);

            if (jogadorAtual == 1)
            {
                std::cout << "\033[32m" << _jogador1->get_apelido() << " (X), e sua vez.\033[0m" << std::endl;
            }
            else
            {
                std::cout << "\033[31m" << _jogador2->get_apelido() << " (O), e sua vez.\033[0m" << std::endl;
            }

            if (!mensagemErro.empty())
            {
                mensagemErro.clear();
            }

            if (temMovimentosValidos(jogadorAtual))
            {
                std::cout << "Insira a linha e a coluna onde deseja colocar sua peça (formato: linha X coluna) : ";
                std::string entrada;
                std::getline(std::cin, entrada);
                std::istringstream iss(entrada);

                if (!(iss >> linha >> coluna) || !(iss.eof()))
                {
                    mensagemErro = "Entrada invalida. Tente novamente.";
                    continue;
                }

                linha--;
                coluna--;

                if (linha >= 0 && linha < _linhas && coluna >= 0 && coluna < _colunas && this->movimentoValido(linha, coluna, jogadorAtual))
                {
                    realizarMovimento(linha, coluna, jogadorAtual);
                    break;
                }
                else
                {
                    mensagemErro = "Movimento invalido. Tente novamente.";
                }
            }
            else
            {
                if (jogadorAtual == 1)
                {
                    mensagemErro = "Jogador " + _jogador1->get_apelido() + " nao possui jogada valida. Passou a vez.";
                }
                else
                {
                    mensagemErro = "Jogador " + _jogador2->get_apelido() + " nao possui jogada valida. Passou a vez.";
                }
                break;
            }
        }

        if (!temMovimentosValidos(1) && !temMovimentosValidos(2))
        {
            break;
        }

        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }

    limpar_terminal();
    imprimir_tabuleiro(jogadorAtual);

    if (contarPecas(1) == contarPecas(2))
    {
        std::cout << "Empate com " << contarPecas(1) << " pecas para cada jogador." << std::endl;
    }
    else
    {
        int resultado = checar_vitoria();

        if (resultado == 0)
        {
            std::cout << std::endl;
            std::cout << _jogador1->get_apelido() << " (X) venceu com " << contarPecas(1) << " pecas contra " << contarPecas(2) << " pecas de " << _jogador2->get_apelido() << " (O)." << std::endl;
            _jogador1->soma_vitoria_rvs();
            _jogador2->soma_derrota_rvs();
        }
        else if (resultado == 1)
        {
            std::cout << std::endl;
            std::cout << _jogador2->get_apelido() << " (O) venceu com " << contarPecas(2) << " pecas contra " << contarPecas(1) << " pecas de " << _jogador1->get_apelido() << " (X)." << std::endl;
            _jogador2->soma_vitoria_rvs();
            _jogador1->soma_derrota_rvs();
        }
    }
    std::cout << std::endl;
    std::cout << "Estatisticas Atuais:" << std::endl;
    _jogador1->imprimir_informacoes_rvs();
    _jogador2->imprimir_informacoes_rvs();
    std::cout << std::endl;
}

/**
 * @brief Checa quem venceu a partida.
 * @return 0 se o jogador 1 venceu, 1 se o jogador 2 venceu.
 */
bool Reversi::checar_vitoria()
{
    int pecasJogador1 = contarPecas(1);
    int pecasJogador2 = contarPecas(2);

    if (pecasJogador1 > pecasJogador2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//--Casos extremos--
// 1° - Tabuleiro fica completamente cheio;
// 2° - Um jogador nao possui movimentos validos e passa sua vez;
// 3° - Um jogador nao possui nenhuma "peca" e o jogo termina;
// 4° - Ambos os jogadores nao possuem movimentos validos, o jogo termina e contabiliza o numero de pecas de cada um;
