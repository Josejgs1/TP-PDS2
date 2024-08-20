#include "lig4.hpp"

/**
 * @brief Construtor padrão da classe Lig4.
 */
Lig4::Lig4()
    : JogoDeTabuleiro(), _jogador1(nullptr), _jogador2(nullptr), _jogador_atual(1) {}

/**
 * @brief Construtor da classe Lig4 com dimensoes e jogadores especificos.
 * @param linhas Numero de linhas do tabuleiro.
 * @param colunas Numero de colunas do tabuleiro.
 * @param jogador1 Referencia para o jogador 1.
 * @param jogador2 Referencia para o jogador 2.
 * @throws std::invalid_argument Se as dimensoes forem menores que 4 ou maiores que 20.
 */
Lig4::Lig4(int linhas, int colunas, Jogador& jogador1, Jogador& jogador2)
    : JogoDeTabuleiro(linhas, colunas), _jogador1(&jogador1), _jogador2(&jogador2), _jogador_atual(1)
{
    if (linhas < 4 || colunas < 4)
    {
        throw std::invalid_argument("O tamanho minimo do tabuleiro e 4x4.");
    }

    if (linhas > 20 || colunas > 20)
    {
        throw std::invalid_argument("O tamanho maximo do tabuleiro e 20x20.");
    }

    _tabuleiro.resize(_linhas, std::vector<int>(_colunas, 0));
}

/**
 * @brief Destrutor da classe Lig4.
 */
Lig4::~Lig4() {}

/**
 * @brief Faz uma jogada na coluna especificada.
 * @param x Numero da coluna onde a jogada sera feita.
 */
void Lig4::fazer_jogada(int x)
{
    if (x < 1 || x > _colunas)
    {
        std::cout << "Jogada invalida! Por favor, escolha uma coluna entre 1 e " << _colunas << "." << std::endl;
        return;
    }

    if (_tabuleiro[0][x - 1] != 0)
    {
        std::cout << "Coluna cheia! Por favor, escolha outra coluna." << std::endl;
        return;
    }

    for (int i = 0; i < _linhas; i++)
    {
        if (_tabuleiro[_linhas - 1 - i][x - 1] == 0)
        {
            _tabuleiro[_linhas - 1 - i][x - 1] = _jogador_atual;
            break;
        }
    }

    alternar_jogador();

    limpar_terminal();
    imprimir_tabuleiro();
}

/**
 * @brief Alterna o jogador atual.
 */
void Lig4::alternar_jogador()
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

/**
 * @brief Retorna o apelido do jogador atual.
 * @return Apelido do jogador atual.
 */
std::string Lig4::apelido_atual()
{
    if (_jogador_atual == 1)
    {
        return _jogador1->get_apelido();
    }
    else
    {
        return _jogador2->get_apelido();
    }
}

/**
 * @brief Checa se ha uma vitoria no tabuleiro.
 * @return True se houver vitoria, False caso contrario.
 */
bool Lig4::checar_vitoria()
{
    // Verificar vitoria horizontal
    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j <= _colunas - 4; j++)
        {
            if (_tabuleiro[i][j] != 0 &&
                _tabuleiro[i][j] == _tabuleiro[i][j + 1] &&
                _tabuleiro[i][j] == _tabuleiro[i][j + 2] &&
                _tabuleiro[i][j] == _tabuleiro[i][j + 3])
            {
                return true;
            }
        }
    }

    // Verificar vitoria vertical
    for (int i = 0; i <= _linhas - 4; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if (_tabuleiro[i][j] != 0 &&
                _tabuleiro[i][j] == _tabuleiro[i + 1][j] &&
                _tabuleiro[i][j] == _tabuleiro[i + 2][j] &&
                _tabuleiro[i][j] == _tabuleiro[i + 3][j])
            {
                return true;
            }
        }
    }

    // Verificar vitoria diagonal descendente (\)
    for (int i = 0; i <= _linhas - 4; i++)
    {
        for (int j = 0; j <= _colunas - 4; j++)
        {
            if (_tabuleiro[i][j] != 0 &&
                _tabuleiro[i][j] == _tabuleiro[i + 1][j + 1] &&
                _tabuleiro[i][j] == _tabuleiro[i + 2][j + 2] &&
                _tabuleiro[i][j] == _tabuleiro[i + 3][j + 3])
            {
                return true;
            }
        }
    }

    // Verificar vitoria diagonal ascendente (/)
    for (int i = 3; i < _linhas; i++)
    {
        for (int j = 0; j <= _colunas - 4; j++)
        {
            if (_tabuleiro[i][j] != 0 &&
                _tabuleiro[i][j] == _tabuleiro[i - 1][j + 1] &&
                _tabuleiro[i][j] == _tabuleiro[i - 2][j + 2] &&
                _tabuleiro[i][j] == _tabuleiro[i - 3][j + 3])
            {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Checa se o jogo terminou (se o tabuleiro esta cheio).
 * @return True se o tabuleiro esta cheio, False caso contrario.
 */
bool Lig4::checar_final()
{
    for (int i = 0; i < _colunas; i++)
    {
        if (_tabuleiro[0][i] == 0)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Controla a partida, gerenciando jogadas e verificando vitoria e final.
 */
void Lig4::partida()
{
    imprimir_tabuleiro();
    while (!checar_vitoria() && !checar_final())
    {
        int x;
        std::cout << apelido_atual() << ", faca sua jogada: ";
        std::cin >> x;
        fazer_jogada(x);
    }
    if (checar_vitoria())
    {
        alternar_jogador();
        if (_jogador_atual == 1)
        {
            _jogador1->soma_vitoria_lig4();
            _jogador2->soma_derrota_lig4();
        }
        else
        {
            _jogador2->soma_vitoria_lig4();
            _jogador1->soma_derrota_lig4();
        }

        std::cout << "Parabens " << apelido_atual() << ", voce venceu!" << std::endl;
        _jogador1->imprimir_informacoes_lig4();
        _jogador2->imprimir_informacoes_lig4();
        return;
    }
    if (checar_final())
    {
        std::cout << "Empate!" << std::endl;
        _jogador1->imprimir_informacoes_lig4();
        _jogador2->imprimir_informacoes_lig4();
        return;
    }
}
