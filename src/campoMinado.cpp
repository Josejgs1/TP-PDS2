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

/**
 * @brief Construtor padrao da classe CampoMinado.
 * Inicializa um jogo de campo minado com um tabuleiro vazio e nenhum jogador e bomba.
 */
CampoMinado::CampoMinado() : JogoDeTabuleiro(0, 0), _jogador(nullptr), _n_bombas(0) {}

/**
 * @brief Construtor da classe CampoMinado com dimensoes de tabuleiro e numero de bombas especificados.
 * @param linhas Numero de linhas do tabuleiro.
 * @param colunas Numero de colunas do tabuleiro.
 * @param jogador Referencia ao jogador.
 * @param n_bombas Numero de bombas a serem colocadas no tabuleiro.
 * Inicializa o tabuleiro e coloca as bombas, validando os parametros fornecidos.
 * @throws std::invalid_argument Se as dimensoes do tabuleiro ou o numero de bombas estiverem fora dos limites validos.
 */
CampoMinado::CampoMinado(int linhas, int colunas, Jogador &jogador, int n_bombas)
    : JogoDeTabuleiro(linhas, colunas), _jogador(&jogador), _n_bombas(n_bombas)
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
        throw std::invalid_argument("Erro ao inicializar o tabuleiro: Numero de bombas deve ser pelo menos 1 e menor que o total de celulas do tabuleiro.");
    }

    srand(time(0));
    colocar_bombas();
}

/**
 * @brief Destruidor da classe CampoMinado.
 * Limpa os recursos alocados pela classe CampoMinado.
 */
CampoMinado::~CampoMinado() {}

/**
 * @brief Imprime o tabuleiro do campo minado no console.
 * Exibe o tabuleiro com as celulas reveladas, marcadas e as bombas.
 */
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

/**
 * @brief Revela a area ao redor de uma celula no tabuleiro.
 * @param x Coordenada da linha da celula a ser revelada.
 * @param y Coordenada da coluna da celula a ser revelada.
 * Revela a celula e, se a celula revelada nao contiver bombas ao redor, revela as celulas adjacentes.
 * @throws std::out_of_range Se as coordenadas estiverem fora dos limites do tabuleiro.
 */
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

/**
 * @brief Realiza uma jogada no tabuleiro, revelando uma celula ou marcando-a como bomba.
 * @param x Coordenada da linha da celula a ser revelada.
 * @param y Coordenada da coluna da celula a ser revelada.
 * Revela a celula ou marca a celula como contendo uma bomba.
 * @throws std::logic_error Se a celula ja estiver ocupada com uma marcacao invalida.
 */
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

/**
 * @brief Marca ou desmarca uma celula como contendo uma bomba.
 * @param x Coordenada da linha da celula a ser marcada.
 * @param y Coordenada da coluna da celula a ser marcada.
 * Marca a celula como bomba, desmarca se ja estiver marcada, ou altera a marcacao se necessario.
 * @throws std::out_of_range Se as coordenadas estiverem fora dos limites do tabuleiro.
 * @throws std::logic_error Se o numero maximo de bombas ja foi atingido ou se a celula ja estiver ocupada com uma marcacao invalida.
 */
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
                throw std::logic_error("Voce ja marcou o numero maximo de bombas (" + std::to_string(_n_bombas) + ").");
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
                throw std::logic_error("Voce ja marcou o numero maximo de bombas (" + std::to_string(_n_bombas) + ").");
                return;
            }
            else
            {
                _tabuleiro[x - 1][y - 1] = 5;
                bombas_marcadas--;
            }
        }
        else
        {
            throw std::logic_error("Posicao ja ocupada com outra marca. Tente novamente.");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao marcar bomba: " << e.what() << '\n';
    }
}

/**
 * @brief Coloca bombas aleatoriamente no tabuleiro.
 * Coloca o numero especificado de bombas em locais aleatorios no tabuleiro.
 */
void CampoMinado::colocar_bombas()
{
    int bombas_colocadas = 0;

    while (bombas_colocadas < _n_bombas)
    {
        int linha = rand() % _linhas;
        int coluna = rand() % _colunas;

        if (_tabuleiro[linha][coluna] == 0)
        {
            _tabuleiro[linha][coluna] = 1;
            bombas_colocadas++;
        }
    }
}

/**
 * @brief Conta o numero de bombas ao redor de uma celula.
 * @param x Coordenada da linha da celula.
 * @param y Coordenada da coluna da celula.
 * @return Numero de bombas ao redor da celula especificada.
 */
int CampoMinado::bombas_em_volta(int x, int y)
{
    int bombas = 0;

    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i < _linhas && j >= 0 && j < _colunas)
            {
                if (_tabuleiro[i][j] == 1)
                {
                    bombas++;
                }
            }
        }
    }

    return bombas;
}

/**
 * @brief Checa se o jogador venceu o jogo.
 * @return True se o jogador venceu, caso contrario false.
 * Verifica se todas as celulas foram reveladas ou marcadas corretamente, indicando a vitoria.
 * @throws std::runtime_error Se ocorrer um erro durante a checagem de vitoria.
 */
bool CampoMinado::checar_vitoria()
{
    try
    {
        for (int i = 0; i < _linhas; i++)
        {
            for (int j = 0; j < _colunas; j++)
            {
                if (_tabuleiro[i][j] == 0)  // Celula nao revelada
                {
                    return false;
                }
                if (_tabuleiro[i][j] == 1 || _tabuleiro[i][j] == 4 || _tabuleiro[i][j] == 5)  // Celulas com bombas ou marcadas
                {
                    if (_tabuleiro[i][j] == 1 || _tabuleiro[i][j] == 5)
                    {
                        continue;  // Continua verificando outras celulas
                    }
                    else
                    {
                        return false;  // Alguma celula ainda nao foi revelada
                    }
                }
            }
        }
        return true;  // Todas as celulas foram reveladas ou marcadas corretamente
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao checar vitoria: " << e.what() << '\n';
        throw;  // Propaga a excecao para que o chamador possa lidar com ela
    }
}

/**
 * @brief Controla o loop principal do jogo, gerenciando a entrada do jogador e atualizando o tabuleiro.
 * Permite ao jogador fazer jogadas e marcar bombas, verificando se houve vitoria ou derrota.
 * @throws std::invalid_argument Se a entrada fornecida pelo jogador for invalida.
 * @throws std::out_of_range Se as coordenadas fornecidas pelo jogador estiverem fora dos limites do tabuleiro.
 */
void CampoMinado::partida()
{
    limpar_terminal();
    std::cout << "Digite duas coordenadas para fazer uma jogada ou adicione 'B' no inicio para marcar uma bomba." << std::endl;
    imprimir_tabuleiro();

    while (!checar_vitoria())
    {
        std::string linha;
        int x, y;
        std::cout << _jogador->get_apelido() << ", faca sua jogada: ";
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
                std::cout << "Voce perdeu!" << std::endl;
                _jogador->soma_derrota_cm();
                _jogador->imprimir_informacoes_cm();
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
        _jogador->soma_vitoria_cm();

        std::cout << "Parabens " << _jogador->get_apelido() << ", voce venceu!" << std::endl;
        _jogador->imprimir_informacoes_cm();
        return;
    }
}
