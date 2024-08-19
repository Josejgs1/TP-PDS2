#include "lig4.hpp"
Lig4::Lig4()
    : JogoDeTabuleiro(), _jogador1(nullptr), _jogador2(nullptr), _jogador_atual(1){};

Lig4::Lig4(int linhas, int colunas, Jogador& jogador1, Jogador& jogador2)
    : JogoDeTabuleiro(linhas, colunas), _jogador1(&jogador1), _jogador2(&jogador2), _jogador_atual(1)
{
    if (linhas < 4 || colunas < 4)
    {
        throw std::invalid_argument("O tamanho mínimo do tabuleiro é 4x4.");
    }
    _tabuleiro.resize(_linhas, std::vector<int>(_colunas, 0));
}

Lig4::~Lig4() {}

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

std::string Lig4::apelido_atual()
{
    std::string apelido;
    if (_jogador_atual == 1)
    {
        return _jogador1->get_apelido();
    }
    else
    {
        return _jogador2->get_apelido();
    }
}

bool Lig4::checar_vitoria()
{
    // Verificar vitória horizontal
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

    // Verificar vitória vertical
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

    // Verificar vitória diagonal descendente (\)
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

    // Verificar vitória diagonal ascendente (/)
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

void Lig4::partida()
{
    imprimir_tabuleiro();
    while (!checar_vitoria() && !checar_final())
    {
        int x;
        std::cout << apelido_atual() << ", faça sua jogada: ";
        std::cin >> x;
        fazer_jogada(x);
    }
    if (checar_vitoria())
    {
        alternar_jogador();
        if (_jogador_atual == 1)
        {
            _jogador1->soma_vitoria_lig4(); //não funciona
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
};