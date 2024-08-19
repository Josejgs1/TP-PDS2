#include "campoMinado.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <iomanip>

const int MIN_LINHAS = 4;
const int MAX_LINHAS = 30;
const int MIN_COLUNAS = 4;
const int MAX_COLUNAS = 30;

CampoMinado::CampoMinado(int linhas, int colunas, Jogador jogador, int n_bombas)
    : JogoDeTabuleiro(linhas, colunas), _jogador(jogador), _n_bombas(n_bombas)
{
    if (linhas < MIN_LINHAS || linhas > MAX_LINHAS)
    {
        throw std::invalid_argument("Erro ao inicializar o tabuleiro: Numero de linhas deve estar entre " + std::to_string(MIN_LINHAS) + " e " + std::to_string(MAX_LINHAS) + ".");
    }
    if (colunas < MIN_COLUNAS || colunas > MAX_COLUNAS)
    {
        throw std::invalid_argument("Erro ao inicializar o tabuleiro: Numero de colunas deve estar entre " + std::to_string(MIN_COLUNAS) + " e " + std::to_string(MAX_COLUNAS) + ".");
    }
    if (n_bombas < 1 || n_bombas >= (linhas * colunas))
    {
        throw std::invalid_argument("Erro ao inicializar o tabuleiro: Numero de bombas deve ser pelo menos 1 e menor que o total de células do tabuleiro.");
    }

    srand(time(0));
    colocar_bombas();
}

CampoMinado::~CampoMinado() {}

/*  0- sem marcação e sem bomba
    1- sem marcação e com bomba
    2- marcado e sem bombas em volta
    3- marcado e com bombas em volta
    4- bomba marcada e tem bomba de verdade
    5- bomba marcada e não tem bomba de verdade*/

void CampoMinado::imprimir_tabuleiro()
{
    try
    {
        std::cout << "   ";
        for (int j = 0; j < _colunas; ++j)
        {
            std::cout << std::setw(3) << (j + 1) << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < _linhas; i++)
        {
            std::cout << std::setw(2) << (i + 1) << " |";
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
                        std::cout << "\033[32m " << bombas_em_volta(i, j) << " \033[0m";
                    }
                }
                else if (_tabuleiro[i][j] == 3)
                {
                    std::cout << "\033[1;31m * \033[0m";
                }
                else if (_tabuleiro[i][j] == 4 || _tabuleiro[i][j] == 5)
                {
                    std::cout << "\033[1;31m B \033[0m";
                }

                std::cout << "|";
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

void CampoMinado::revelar_area(int x, int y)
{
    try
    {
        if (x < 0 || x >= _linhas || y < 0 || y >= _colunas)
        {
            return;
        }
        if (_tabuleiro[x][y] == 2)
        {
            return;
        }

        _tabuleiro[x][y] = 2;

        if (bombas_em_volta(x, y) > 0)
        {
            return;
        }

        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i == x && j == y)
                {
                    continue;
                }
                revelar_area(i, j);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao revelar area: " << e.what() << '\n';
    }
}

void CampoMinado::fazer_jogada(int x, int y)
{
    try
    {
        if (_tabuleiro[x - 1][y - 1] == 0)
        {
            revelar_area(x - 1, y - 1);
        }
        else if (_tabuleiro[x - 1][y - 1] == 1)
        {
            _tabuleiro[x - 1][y - 1] = 3;
        }
        else
        {
            throw std::logic_error("Posicao ja ocupada! Tente novamente.");
            return;
        }
        limpar_terminal();
        imprimir_tabuleiro();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao fazer jogada: " << e.what() << '\n';
    }
}

void CampoMinado::marcar_bomba(int x, int y)
{
    try
    {
        static int bombas_marcadas = 0;

        if (x < 1 || x > _linhas || y < 1 || y > _colunas)
        {
            throw std::out_of_range("Jogada invalida! Por favor, insira dois numeros de 1 a " + std::to_string(_colunas) + ".");
            return;
        }

        if (_tabuleiro[x - 1][y - 1] == 0)
        {
            if (bombas_marcadas >= _n_bombas)
            {
                throw std::logic_error("Voce já marcou o número máximo de bombas (" + std::to_string(_n_bombas) + ").");
                return;
            }
            else
            {
                _tabuleiro[x - 1][y - 1] = 4;
                bombas_marcadas++;
            }
        }
        else if (_tabuleiro[x - 1][y - 1] == 1)
        {
            if (bombas_marcadas >= _n_bombas)
            {
                throw std::logic_error("Voce já marcou o número máximo de bombas (" + std::to_string(_n_bombas) + ").");
                return;
            }
            else
            {
                _tabuleiro[x - 1][y - 1] = 5;
                bombas_marcadas++;
            }
        }
        else if (_tabuleiro[x - 1][y - 1] == 4)
        {
            _tabuleiro[x - 1][y - 1] = 0;
            bombas_marcadas--;
        }
        else if (_tabuleiro[x - 1][y - 1] == 5)
        {
            _tabuleiro[x - 1][y - 1] = 1;
            bombas_marcadas--;
        }
        else
        {
            throw std::logic_error("Posicao ja ocupada! Tente novamente.");
            return;
        }
        limpar_terminal();
        imprimir_tabuleiro();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao marcar bomba: " << e.what() << '\n';
    }
}

void CampoMinado::colocar_bombas()
{
    try
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
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao colocar bombas: " << e.what() << '\n';
    }
}

int CampoMinado::bombas_em_volta(int x, int y)
{
    try
    {
        int bombas_adjacentes = 0;
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i >= 0 && i < _linhas && j >= 0 && j < _colunas && (i != x || j != y))
                {
                    if (_tabuleiro[i][j] == 1 || _tabuleiro[i][j] == 3 || _tabuleiro[i][j] == 5)
                    {
                        bombas_adjacentes++;
                    }
                }
            }
        }
        return bombas_adjacentes;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao contar bombas em volta" << e.what() << '\n';
    }
}

bool CampoMinado::checar_vitoria()
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
                if (_tabuleiro[i][j] == 1 || _tabuleiro[i][j] == 4 || _tabuleiro[i][j] == 5)
                {
                    if (_tabuleiro[i][j] == 1 || _tabuleiro[i][j] == 5)
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao checar vitoria" << e.what() << '\n';
    }
}

void CampoMinado::partida()
{
    limpar_terminal();
    std::cout << "Digite duas coordenadas para fazer uma jogada ou adicione 'B' no inicio para marcar uma bomba." << std::endl;
    imprimir_tabuleiro();
    while (!checar_vitoria())
    {
        std::string linha;
        int x, y;
        std::cout << _jogador.get_apelido() << ", faca sua jogada: ";
        std::getline(std::cin, linha);

        if (linha.empty())
        {
            limpar_terminal();
            imprimir_tabuleiro();
            continue;
        }

        try
        {
            std::istringstream iss(linha);
            char opcao;
            if (iss >> opcao)
            {
                if (opcao == 'B')
                {
                    if (!(iss >> x >> y) || !iss.eof())
                    {
                        throw std::invalid_argument("Erro ao marcar bomba: Entrada invalida! Digite 'B' seguido de duas coordenadas.");
                    }

                    if (x < 1 || x > _linhas || y < 1 || y > _colunas)
                    {
                        throw std::out_of_range("Erro ao marcar bombas: Jogada fora dos limites! Tente novamente.");
                    }
                    marcar_bomba(x, y);
                }
                else
                {
                    iss.clear();
                    iss.str(linha);
                    iss >> x >> y;
                    if (iss.fail() || !iss.eof())
                    {
                        throw std::invalid_argument("Erro ao fazer jogada: Entrada invalida! Digite duas coordenadas inteiras.");
                    }

                    if (x < 1 || x > _linhas || y < 1 || y > _colunas)
                    {
                        throw std::out_of_range("Erro ao fazer jogada: Jogada fora dos limites! Tente novamente.");
                    }
                    fazer_jogada(x, y);
                }
            }
            else
            {
                throw std::invalid_argument("Erro ao processar a entrada: Entrada invalida!");
            }

            if (_tabuleiro[x - 1][y - 1] == 3)
            {
                std::cout << "Você perdeu!" << std::endl;
                int vitorias = _jogador.get_derrotas_cm();
                _jogador.set_derrotas_cm(vitorias + 1);
                _jogador.imprimir_informacoes();
                return;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
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