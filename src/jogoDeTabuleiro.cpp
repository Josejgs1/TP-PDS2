#include "jogoDeTabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro() : JogoDeTabuleiro(0, 0) {}

/**
 * @brief Construtor da classe JogoDeTabuleiro com dimensoes especificas.
 * @param linhas Numero de linhas do tabuleiro.
 * @param colunas Numero de colunas do tabuleiro.
 * @throws std::invalid_argument Se as dimensoes forem negativas.
 */
JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : _linhas(linhas), _colunas(colunas)
{
    if (linhas < 0 || colunas < 0)
    {
        throw std::invalid_argument("O tabuleiro deve ter valores positivos para as dimensoes.");
    }
    _tabuleiro.resize(_linhas, std::vector<int>(_colunas, 0));
}

/**
 * @brief Retorna o valor da coordenada especificada no tabuleiro.
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @return Valor na coordenada especificada.
 * @throws std::out_of_range Se as coordenadas estiverem fora dos limites.
 */
int JogoDeTabuleiro::get_coordenada(int x, int y) const {
    if (x < 0 || x >= _linhas || y < 0 || y >= _colunas)
    {
        throw std::out_of_range("Coordenada fora dos limites.");
    }
    return _tabuleiro[x][y];
}

/**
 * @brief Inicializa o tabuleiro com zeros.
 */
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

/**
 * @brief Imprime o tabuleiro no console.
 */
void JogoDeTabuleiro::imprimir_tabuleiro()
{   
    for (int j = 0; j < _colunas; ++j)
    {
        std::cout << std::setw(3) << (j + 1) << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {   
            std::cout << "|";
            if (_tabuleiro[i][j] == 0)
            {
                std::cout << "   ";
            }
            else if (_tabuleiro[i][j] == 1)
            {
                std::cout << "\033[34m X \033[0m";
            }
            else if (_tabuleiro[i][j] == 2)
            {
                std::cout << "\033[33m O \033[0m";
            }

            if (j == _colunas - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;

        std::cout << "-";
        for (int j = 0; j < _colunas; ++j)
        {
            std::cout << "----";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Limpa o terminal.
 */
void limpar_terminal()
{
    std::cout << "\033[2J\033[1;1H";
}
