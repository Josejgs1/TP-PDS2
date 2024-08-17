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
    if (x < 1 || x > _linhas || y < 1 || y > _colunas)
    {
        std::cout << "Jogada invalida! Por favor, insira dois numeros de 1 a 3." << std::endl;
        return;
    }

    if (_tabuleiro[x - 1][y - 1] == 0)
    {
        _tabuleiro[x - 1][y - 1] = _jogador_atual;
        alternar_jogador();
    }
    else
    {
        std::cout << "Posicao ja ocupada! Tente novamente." << std::endl;
    }
    imprimir_tabuleiro();
}

//dar uma olhada depois
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

std::string JogoDaVelha::apelido_atual()
{
    std::string apelido;
    if (_jogador_atual == 1)
    {
        return _jogador1.get_apelido();
    }
    else
    {
        return _jogador2.get_apelido();
    }
}

bool JogoDaVelha::checar_vitoria()
{
    // linhas:
    for (int i = 0; i < _linhas; i++)
    {
        if (_tabuleiro[i][0] != 0 && _tabuleiro[i][0] == _tabuleiro[i][1] && _tabuleiro[i][1] == _tabuleiro[i][2])
        {
            return true;
        }
    }

    // colunas:
    for (int j = 0; j < _colunas; j++)
    {
        if (_tabuleiro[0][j] != 0 && _tabuleiro[0][j] == _tabuleiro[1][j] && _tabuleiro[1][j] == _tabuleiro[2][j])
        {
            return true;
        }
    }

    // diagonais:
    if (_tabuleiro[0][0] != 0 && _tabuleiro[0][0] == _tabuleiro[1][1] && _tabuleiro[1][1] == _tabuleiro[2][2])
    {
        return true;
    }
    if (_tabuleiro[0][2] != 0 && _tabuleiro[0][2] == _tabuleiro[1][1] && _tabuleiro[1][1] == _tabuleiro[2][0])
    {
        return true;
    }

    return false;
}

bool JogoDaVelha::checar_final()
{
    for (int i = 0; i < _linhas; i++)
    {
        for (int j = 0; j < _colunas; j++)
        {
            if (_tabuleiro[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void JogoDaVelha::partida()
{
    imprimir_tabuleiro();
    while (!checar_vitoria() && !checar_final())
    {
        int x, y;
        std::cout << apelido_atual() << ", faça sua jogada: ";
        std::cin >> x >> y;
        fazer_jogada(x, y);
    }
    if (checar_vitoria())
    {
        alternar_jogador();
        if (_jogador_atual == 1)
        {
            int vitorias = _jogador1.get_vitorias_jdv();
            _jogador1.set_vitorias_jdv(vitorias + 1);
            int derrotas = _jogador2.get_derrotas_jdv();
            _jogador2.set_derrotas_jdv(derrotas + 1);
        } else
        {
            int vitorias = _jogador2.get_vitorias_jdv();
            _jogador2.set_vitorias_jdv(vitorias + 1);
            int derrotas = _jogador1.get_derrotas_jdv();
            _jogador1.set_derrotas_jdv(derrotas + 1);
        }
        
        std::cout << "Parabens " << apelido_atual() << ", voce venceu!" << std::endl;
        _jogador1.imprimir_informacoes_jdv();
        _jogador2.imprimir_informacoes_jdv();
        return;
    }
    if (checar_final())
    {
        std::cout << "Deu velha!" << std::endl;
        _jogador1.imprimir_informacoes_jdv();
        _jogador2.imprimir_informacoes_jdv();
        return;
    }
}