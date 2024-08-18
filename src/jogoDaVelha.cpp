#include "jogoDaVelha.hpp"
#include <limits>

JogoDaVelha::JogoDaVelha(Jogador jogador1, Jogador jogador2)
    : JogoDeTabuleiro(3, 3), _jogador1(jogador1), _jogador2(jogador2), _jogador_atual(1) {}

void JogoDaVelha::imprimir_tabuleiro()
{
    try
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
                    std::cout << "\033[34m X \033[0m";
                }
                else if (_tabuleiro[i][j] == 2)
                {
                    std::cout << "\033[32m O \033[0m";
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
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao imprimir o tabuleiro: " << e.what() << '\n';
    }
}

void JogoDaVelha::fazer_jogada(int x, int y)
{
    try
    {
        if (_tabuleiro[x - 1][y - 1] == 0)
        {
            _tabuleiro[x - 1][y - 1] = _jogador_atual;
            alternar_jogador();
        }
        else
        {
            throw std::logic_error("Posicao ja ocupada! Tente novamente.");
        }
        limpar_terminal();
        imprimir_tabuleiro();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao fazer jogada: " << e.what() << '\n';
    }
}

void JogoDaVelha::alternar_jogador()
{
    try
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
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao alternar jogador: " << e.what() << '\n';
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
    try
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
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao checar vitoria" << e.what() << '\n';
    }
}

bool JogoDaVelha::checar_final()
{
    try
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
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao checar final" << e.what() << '\n';
    }
}

void JogoDaVelha::partida()
{
    limpar_terminal();
    imprimir_tabuleiro();
    while (!checar_vitoria() && !checar_final())
    {
        int x, y;
        std::cout << apelido_atual() << ", faça sua jogada: ";
        std::cin >> x >> y;
        try
        {
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Entrada invalida! Por favor, insira dois numeros de 1 a 3.");
            }
            if (x < 1 || x > _linhas || y < 1 || y > _colunas)
            {
                throw std::out_of_range("Jogada invalida! Por favor, insira dois numeros de 1 a 3.");
                return;
            }
            else
            {
                fazer_jogada(x, y);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Erro na partida: " << e.what() << '\n';
            continue;
        }
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
        }
        else
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