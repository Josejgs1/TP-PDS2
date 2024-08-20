#include "jogador.hpp"

/**
 * @brief Construtor padrao da classe Jogador.
 * Inicializa o jogador com nome e apelido vazios.
 */
Jogador::Jogador() : Jogador("", "") {}

/**
 * @brief Construtor da classe Jogador com nome e apelido.
 * @param nome Nome do jogador.
 * @param apelido Apelido do jogador.
 */
Jogador::Jogador(std::string nome, std::string apelido)
    : _nome(nome), _apelido(apelido) {}

/**
 * @brief Construtor da classe Jogador com todas as estatisticas.
 * @param nome Nome do jogador.
 * @param apelido Apelido do jogador.
 * @param vitorias_jdv Vitorias no jogo da velha.
 * @param derrotas_jdv Derrotas no jogo da velha.
 * @param vitorias_lig4 Vitorias no Ligue 4.
 * @param derrotas_lig4 Derrotas no Ligue 4.
 * @param vitorias_cm Vitorias no Campo Minado.
 * @param derrotas_cm Derrotas no Campo Minado.
 * @param vitorias_rvs Vitorias no Reversi.
 * @param derrotas_rvs Derrotas no Reversi.
 */
Jogador::Jogador(std::string nome, std::string apelido, int vitorias_jdv, int derrotas_jdv, int vitorias_lig4, int derrotas_lig4, int vitorias_cm, int derrotas_cm, int vitorias_rvs, int derrotas_rvs)
    : _nome(nome), _apelido(apelido), _vitorias_jdv(vitorias_jdv), _derrotas_jdv(derrotas_jdv), _vitorias_lig4(vitorias_lig4), _derrotas_lig4(derrotas_lig4), _vitorias_cm(vitorias_cm), _derrotas_cm(derrotas_cm), _vitorias_rvs(vitorias_rvs), _derrotas_rvs(derrotas_rvs) {}

/**
 * @brief Retorna o apelido do jogador.
 * @return Apelido do jogador.
 */
std::string Jogador::get_apelido() const { return this->_apelido; }

/**
 * @brief Retorna o nome do jogador.
 * @return Nome do jogador.
 */
std::string Jogador::get_nome() const { return this->_nome; }

/**
 * @brief Retorna o numero de vitorias no jogo da velha.
 * @return Numero de vitorias no jogo da velha.
 */
int Jogador::get_vitorias_jdv() const { return this->_vitorias_jdv; }

/**
 * @brief Retorna o numero de derrotas no jogo da velha.
 * @return Numero de derrotas no jogo da velha.
 */
int Jogador::get_derrotas_jdv() const { return this->_derrotas_jdv; }

/**
 * @brief Retorna o numero de vitorias no Ligue 4.
 * @return Numero de vitorias no Ligue 4.
 */
int Jogador::get_vitorias_lig4() const { return this->_vitorias_lig4; }

/**
 * @brief Retorna o numero de derrotas no Ligue 4.
 * @return Numero de derrotas no Ligue 4.
 */
int Jogador::get_derrotas_lig4() const { return this->_derrotas_lig4; }

/**
 * @brief Retorna o numero de vitorias no Campo Minado.
 * @return Numero de vitorias no Campo Minado.
 */
int Jogador::get_vitorias_cm() const { return this->_vitorias_cm; }

/**
 * @brief Retorna o numero de derrotas no Campo Minado.
 * @return Numero de derrotas no Campo Minado.
 */
int Jogador::get_derrotas_cm() const { return this->_derrotas_cm; }

/**
 * @brief Retorna o numero de vitorias no Reversi.
 * @return Numero de vitorias no Reversi.
 */
int Jogador::get_vitorias_rvs() const { return this->_vitorias_rvs; }

/**
 * @brief Retorna o numero de derrotas no Reversi.
 * @return Numero de derrotas no Reversi.
 */
int Jogador::get_derrotas_rvs() const { return this->_derrotas_rvs; }

/**
 * @brief Incrementa o numero de vitorias no jogo da velha.
 */
void Jogador::soma_vitoria_jdv() { this->_vitorias_jdv++; }

/**
 * @brief Incrementa o numero de derrotas no jogo da velha.
 */
void Jogador::soma_derrota_jdv() { this->_derrotas_jdv++; }

/**
 * @brief Incrementa o numero de vitorias no Campo Minado.
 */
void Jogador::soma_vitoria_cm() { this->_vitorias_cm++; }

/**
 * @brief Incrementa o numero de derrotas no Campo Minado.
 */
void Jogador::soma_derrota_cm() { this->_derrotas_cm++; }

/**
 * @brief Incrementa o numero de derrotas no Ligue 4.
 */
void Jogador::soma_derrota_lig4() { this->_derrotas_lig4++; }

/**
 * @brief Incrementa o numero de vitorias no Ligue 4.
 */
void Jogador::soma_vitoria_lig4() { this->_vitorias_lig4++; }

/**
 * @brief Incrementa o numero de derrotas no Reversi.
 */
void Jogador::soma_derrota_rvs() { this->_derrotas_rvs++; }

/**
 * @brief Incrementa o numero de vitorias no Reversi.
 */
void Jogador::soma_vitoria_rvs() { this->_vitorias_rvs++; }

/**
 * @brief Imprime as informacoes do jogador relacionadas ao jogo da velha.
 */
void Jogador::imprimir_informacoes_jdv()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no jogo da velha: " << this->_vitorias_jdv << "      Derrotas no jogo da velha: " << this->_derrotas_jdv << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Imprime as informacoes do jogador relacionadas ao Ligue 4.
 */
void Jogador::imprimir_informacoes_lig4()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Ligue 4: " << this->_vitorias_lig4 << "      Derrotas no Ligue 4: " << this->_derrotas_lig4 << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Imprime as informacoes do jogador relacionadas ao Reversi.
 */
void Jogador::imprimir_informacoes_rvs()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Reversi: " << this->_vitorias_rvs << "      Derrotas no Reversi: " << this->_derrotas_rvs << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Imprime as informacoes do jogador relacionadas ao Campo Minado.
 */
void Jogador::imprimir_informacoes_cm()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Campo Minado: " << this->_vitorias_cm << "      Derrotas no campo minado: " << this->_derrotas_cm << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Imprime todas as informacoes gerais do jogador.
 */
void Jogador::imprimir_informacoes_geral()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Jogo da Velha: "  <<  this->_vitorias_jdv << "      Derrotas no jogo da velha: " << this->_derrotas_jdv << std::endl;
    std::cout << "Vitorias no Campo Minado: "   <<  this->_vitorias_cm  << "       Derrotas no campo minado: " << this->_derrotas_cm << std::endl;
    std::cout << "Vitorias no Reversi: "        << this->_vitorias_rvs  << "            Derrotas no Reversi: " << this->_derrotas_rvs << std::endl;
    std::cout << "Vitorias no Ligue 4: "        << this->_vitorias_lig4 << "            Derrotas no Ligue 4: " << this->_derrotas_lig4 << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Salva a lista de jogadores em um arquivo CSV.
 * @param jogadores Vetor de jogadores a ser salvo.
 */
void salvar_jogadores(std::vector<Jogador> &jogadores)
{
    std::ofstream ofs("files/jogadores.csv");
    if (!ofs)
    {
        std::cerr << "Erro ao abrir o arquivo para escrita\n";
        return;
    }

    ordenar_jogadores(jogadores);

    for (const auto &jogador : jogadores)
    {
        ofs << jogador.get_nome() << ',' << jogador.get_apelido() << ','
            << jogador.get_vitorias_jdv() << ',' << jogador.get_derrotas_jdv() << ','
            << jogador.get_vitorias_lig4() << ',' << jogador.get_derrotas_lig4() << ','
            << jogador.get_vitorias_cm() << ',' << jogador.get_derrotas_cm() << ','
            << jogador.get_vitorias_rvs() << ',' << jogador.get_derrotas_rvs() << '\n';
    }
}

/**
 * @brief Carrega a lista de jogadores de um arquivo CSV.
 * @return Vetor de jogadores carregados.
 */
std::vector<Jogador> carregar_jogadores()
{
    std::ifstream ifs("files/jogadores.csv");
    std::vector<Jogador> jogadores;
    if (!ifs)
    {
        std::cerr << "Erro ao abrir o arquivo para leitura\n"; // fazer tratamento
        return jogadores;
    }

    std::string linha;
    while (std::getline(ifs, linha))
    {
        std::istringstream iss(linha);
        std::string nome, apelido;
        int vjdv, djdv, vlig4, dlig4, vcm, dcm, vrvs, drvs;

        std::getline(iss, nome, ',');
        std::getline(iss, apelido, ',');
        iss >> vjdv;
        iss.ignore();
        iss >> djdv;
        iss.ignore();
        iss >> vlig4;
        iss.ignore();
        iss >> dlig4;
        iss.ignore();
        iss >> vcm;
        iss.ignore();
        iss >> dcm;
        iss.ignore();
        iss >> vrvs;
        iss.ignore();
        iss >> drvs;

        jogadores.emplace_back(nome, apelido, vjdv, djdv, vlig4, dlig4, vcm, dcm, vrvs, drvs);
    }

    return jogadores;
}

/**
 * @brief Verifica se um apelido ja existe na lista de jogadores.
 * @param jogadores Vetor de jogadores.
 * @param apelido Apelido a ser verificado.
 * @return True se o apelido existir, False caso contrario.
 */
bool apelido_existe(std::vector<Jogador> &jogadores, std::string &apelido)
{
    for (const auto &jogador : jogadores)
    {
        if (jogador.get_apelido() == apelido)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Encontra um jogador pelo apelido.
 * @param jogadores Vetor de jogadores.
 * @return Ponteiro para o jogador com o apelido correspondente.
 */
Jogador *encontrar_jogador(std::vector<Jogador> &jogadores)
{
    std::string apelidoJogador;

    while (true)
    {
        std::cin >> apelidoJogador;

        if (!apelido_existe(jogadores, apelidoJogador))
        {
            std::cout << "O apelido nao foi encontrado. Tente novamente: ";
        }
        else
        {
            for (auto &jogador : jogadores)
            {
                if (jogador.get_apelido() == apelidoJogador)
                {
                    return &jogador; // Retorna o endereco do jogador com o apelido correspondente
                }
            }
        }
    }
}

/**
 * @brief Seleciona dois jogadores da lista para uma partida.
 * @param jogador1 Ponteiro para o primeiro jogador.
 * @param jogador2 Ponteiro para o segundo jogador.
 * @param jogadores Vetor de jogadores.
 */
void selecionar_jogadores(Jogador** jogador1, Jogador** jogador2, std::vector<Jogador>& jogadores) {
    std::cout << "Quem ira jogar?" << std::endl;

    while (true) {
        std::cout << "Informe o apelido do jogador 1: ";
        *jogador1 = encontrar_jogador(jogadores);
        std::cout << "Informe o apelido do jogador 2: ";
        *jogador2 = encontrar_jogador(jogadores);

        if ((*jogador1)->get_apelido() == (*jogador2)->get_apelido()) {
            std::cout << "Os jogadores devem ser diferentes." << std::endl;
        } else {
            break;
        }
    }
}

/**
 * @brief Seleciona um jogador da lista para uma partida.
 * @param jogador1 Ponteiro para o jogador.
 * @param jogadores Vetor de jogadores.
 */
void selecionar_jogador(Jogador** jogador1, std::vector<Jogador>& jogadores) {
    std::cout << "Quem ira jogar?" << std::endl;
    std::cout << "Informe o apelido do jogador: ";
    *jogador1 = encontrar_jogador(jogadores); 
}

/**
 * @brief Ordena a lista de jogadores pelo nome em ordem alfabetica.
 * @param jogadores Vetor de jogadores a ser ordenado.
 */
void ordenar_jogadores(std::vector<Jogador>& jogadores)
{
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b)
    {
        return a.get_nome() < b.get_nome();
    });
}

/**
 * @brief Lista todos os jogadores ordenados por nome.
 * @param jogadores Vetor de jogadores a ser listado.
 */
void listar_jogadores(std::vector<Jogador>& jogadores){
    ordenar_jogadores(jogadores);
    std::cout << "Lista de Jogadores:\n" << std::endl;
    for (const auto& jogador : jogadores)
    {
        std::cout << jogador.get_nome() << " (" << jogador.get_apelido() << ")" << std::endl;
    }
}

/**
 * @brief Remove um jogador da lista pelo apelido.
 * @param jogadores Vetor de jogadores.
 */
void remover_jogador(std::vector<Jogador>& jogadores) {
    std::string apelido;
    std::cout << "Informe o apelido do jogador a ser removido: ";
    Jogador* jogador = encontrar_jogador(jogadores);

     if (jogador != nullptr) {
        auto it = std::find_if(jogadores.begin(), jogadores.end(), [&jogador](const Jogador& j) {
                                   return &j == jogador;
                               });

        if (it != jogadores.end()) {
            jogadores.erase(it);
            std::cout << "Jogador removido com sucesso!" << std::endl;
        }
    }
}