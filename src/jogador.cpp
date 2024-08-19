#include "jogador.hpp"
Jogador::Jogador() : Jogador("", "") {}

Jogador::Jogador(std::string nome, std::string apelido)
    : _nome(nome), _apelido(apelido) {}

Jogador::Jogador(std::string nome, std::string apelido, int vitorias_jdv, int derrotas_jdv, int vitorias_lig4, int derrotas_lig4, int vitorias_cm, int derrotas_cm, int vitorias_rvs, int derrotas_rvs)
    : _nome(nome), _apelido(apelido), _vitorias_jdv(vitorias_jdv), _derrotas_jdv(derrotas_jdv), _vitorias_lig4(vitorias_lig4), _derrotas_lig4(derrotas_lig4), _vitorias_cm(vitorias_cm), _derrotas_cm(derrotas_cm), _vitorias_rvs(vitorias_rvs), _derrotas_rvs(derrotas_rvs) {}

std::string Jogador::get_apelido() const { return this->_apelido; }
std::string Jogador::get_nome() const { return this->_nome; }

int Jogador::get_vitorias_jdv() const { return this->_vitorias_jdv; }
int Jogador::get_derrotas_jdv() const { return this->_derrotas_jdv; }
int Jogador::get_vitorias_lig4() const { return this->_vitorias_lig4; }
int Jogador::get_derrotas_lig4() const { return this->_derrotas_lig4; }
int Jogador::get_vitorias_cm() const { return this->_vitorias_cm; }
int Jogador::get_derrotas_cm() const { return this->_derrotas_cm; }
int Jogador::get_vitorias_rvs() const { return this->_vitorias_rvs; }
int Jogador::get_derrotas_rvs() const { return this->_derrotas_rvs; }

void Jogador::set_vitorias_jdv(int vitorias)
{
    this->_vitorias_jdv = vitorias;
}

void Jogador::set_derrotas_jdv(int derrotas)
{
    this->_derrotas_jdv = derrotas;
}

void Jogador::set_vitorias_cm(int vitorias)
{
    this->_vitorias_cm = vitorias;
}

void Jogador::set_derrotas_cm(int derrotas)
{
    this->_derrotas_cm = derrotas;
}

void Jogador::soma_derrota_lig4() { this->_derrotas_lig4 = _derrotas_lig4 + 1; }
void Jogador::soma_vitoria_lig4() { this->_vitorias_lig4++; }
void Jogador::soma_derrota_rvs() { this->_derrotas_rvs++; }
void Jogador::soma_vitoria_rvs() { this->_vitorias_rvs++; }

void Jogador::imprimir_informacoes_jdv()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no jogo da velha: " << this->_vitorias_jdv << "      Derrotas no jogo da velha: " << this->_derrotas_jdv << std::endl;
    std::cout << std::endl;
}

void Jogador::imprimir_informacoes_lig4()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Ligue 4: " << this->_vitorias_lig4 << "      Derrotas no Ligue 4: " << this->_derrotas_lig4 << std::endl;
    std::cout << std::endl;
}

void Jogador::imprimir_informacoes_rvs()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Reversi: " << this->_vitorias_rvs << "      Derrotas no Reversi: " << this->_derrotas_rvs << std::endl;
    std::cout << std::endl;
}

void Jogador::imprimir_informacoes_cm()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no Campo Minado: " << this->_vitorias_cm << "      Derrotas no campo minado: " << this->_derrotas_cm << std::endl;
    std::cout << std::endl;
}

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

Jogador *encontrar_jogador(std::vector<Jogador> &jogadores)
{
    std::string apelidoJogador;

    while (true)
    {
        std::cin >> apelidoJogador;

        if (!apelido_existe(jogadores, apelidoJogador))
        {
            std::cout << "O apelido não foi encontrado. Tente novamente: ";
        }
        else
        {
            for (auto &jogador : jogadores)
            {
                if (jogador.get_apelido() == apelidoJogador)
                {
                    return &jogador; // Retorna o endereço do jogador com o apelido correspondente
                }
            }
        }
    }
}

void selecionar_jogadores(Jogador** jogador1, Jogador** jogador2, std::vector<Jogador>& jogadores) {
    std::cout << "Quem irá jogar?" << std::endl;

    while (true) {
        std::cout << "Informe o apelido do jogador 1: ";
        *jogador1 = encontrar_jogador(jogadores);  // Atribuir o endereço retornado por encontrar_jogador
        std::cout << "Informe o apelido do jogador 2: ";
        *jogador2 = encontrar_jogador(jogadores);  // Atribuir o endereço retornado por encontrar_jogador

        if ((*jogador1)->get_apelido() == (*jogador2)->get_apelido()) {
            std::cout << "Os jogadores devem ser diferentes." << std::endl;
        } else {
            break;
        }
    }
}

void selecionar_jogador(Jogador** jogador1, std::vector<Jogador>& jogadores) {
    std::cout << "Quem irá jogar?" << std::endl;
    std::cout << "Informe o apelido do jogador: ";
    *jogador1 = encontrar_jogador(jogadores);  // Atribuir o endereço retornado por encontrar_jogador
}

void ordenar_jogadores(std::vector<Jogador>& jogadores)
{
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b)
    {
        return a.get_nome() < b.get_nome();
    });
}

void listar_jogadores(std::vector<Jogador>& jogadores){
    ordenar_jogadores(jogadores);
    std::cout << "Lista de Jogadores:\n" << std::endl;
    for (const auto& jogador : jogadores)
    {
        std::cout << jogador.get_nome() << " (" << jogador.get_apelido() << ")" << std::endl;
    }
}

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
