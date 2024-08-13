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
    try
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
                else if (_tabuleiro[i][j] == 4 || _tabuleiro[i][j] == 5)
                {
                    std::cout << " B ";
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

void CampoMinado::limpar_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CampoMinado::fazer_jogada(int x, int y)
{
    try
    {
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
            limpar_tela();
            throw std::logic_error("Posicao ja ocupada! Tente novamente.");
            imprimir_tabuleiro();
            return;
        }
        limpar_tela();
        imprimir_tabuleiro();
    }
    catch (const std::exception &e)
    {
        limpar_tela();
        std::cerr << "Erro ao fazer jogada: " << e.what() << '\n';
        imprimir_tabuleiro();
    }
}

void CampoMinado::marcar_bomba(int x, int y)
{
    try
    {
        static int bombas_marcadas = 0;

        if (x < 1 || x > _linhas || y < 1 || y > _colunas)
        {
            limpar_tela();
            throw std::out_of_range("Jogada invalida! Por favor, insira dois numeros de 1 a " + std::to_string(_colunas) + ".");
            imprimir_tabuleiro();
            return;
        }

        if (_tabuleiro[x - 1][y - 1] == 0)
        {
            if (bombas_marcadas >= _n_bombas)
            {
                limpar_tela();
                throw std::logic_error("Você já marcou o número máximo de bombas (" + std::to_string(_n_bombas) + ").");
                imprimir_tabuleiro();
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
                limpar_tela();
                throw std::logic_error("Você já marcou o número máximo de bombas (" + std::to_string(_n_bombas) + ").");
                imprimir_tabuleiro();
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
            limpar_tela();
            throw std::logic_error("Posicao ja ocupada! Tente novamente.");
            imprimir_tabuleiro();
            return;
        }
        limpar_tela();
        imprimir_tabuleiro();
    }
    catch (const std::exception &e)
    {
        limpar_tela();
        std::cerr << "Erro ao marcar bomba: " << e.what() << '\n';
        imprimir_tabuleiro();
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
                if ((_tabuleiro[i][j] == 0) || (_tabuleiro[i][j] == 1 && _tabuleiro[i][j] != 4 && _tabuleiro[i][j] != 5))
                {
                    return false;
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
    try
    {
        limpar_tela();
        std::cout << "Digite duas coordenadas para fazer uma jogada ou adicione 'B' no inicio para marcar uma bomba." << std::endl;
        imprimir_tabuleiro();
        while (!checar_vitoria())
        {
            std::string jogada;
            int x, y;
            std::cout << _jogador.get_apelido() << ", faca sua jogada: ";
            std::cin >> jogada;

            try
            {
                if (jogada == "B")
                {
                    std::cin >> x >> y;
                    if (x < 1 || x > _linhas || y < 1 || y > _colunas)
                    {
                        throw std::out_of_range("Erro ao marcar bombas: Jogada fora dos limites! Tente novamente.");
                    }
                    marcar_bomba(x, y);
                }
                else
                {
                    x = stoi(jogada);
                    std::cin >> y;
                    if (x < 1 || x > _linhas || y < 1 || y > _colunas)
                    {
                        throw std::out_of_range("Erro ao fazer jogada: Jogada fora dos limites! Tente novamente.");
                    }
                    fazer_jogada(x, y);
                }
                if (_tabuleiro[x - 1][y - 1] == 3)
                {
                    std::cout << "Voce perdeu!" << std::endl;
                    int vitorias = _jogador.get_derrotas_cm();
                    _jogador.set_derrotas_cm(vitorias + 1);
                    _jogador.imprimir_informacoes();
                    return;
                }
            }
            catch (const std::invalid_argument &)
            {
                limpar_tela();
                std::cerr << "Entrada inválida! Digite duas coordenadas para fazer uma jogada ou adicione 'B' no inicio para marcar uma bomba." << '\n';
                imprimir_tabuleiro();
                continue;
            }
            catch (const std::exception &e)
            {
                limpar_tela();
                std::cerr << e.what() << '\n';
                imprimir_tabuleiro();
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
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}