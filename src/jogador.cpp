#include "jogador.hpp"

Jogador::Jogador(std::string nome, std::string apelido)
    : _nome(nome), _apelido(apelido) {}

Jogador::Jogador(std::string nome, std::string apelido, int vitorias_jdv, int derrotas_jdv, int vitorias_lig4, int derrotas_lig4, int vitorias_cm, int derrotas_cm)
    : _nome(nome), _apelido(apelido), _vitorias_jdv(vitorias_jdv), _derrotas_jdv(derrotas_jdv), _vitorias_lig4(vitorias_lig4), _derrotas_lig4(derrotas_lig4), _vitorias_cm(vitorias_cm), _derrotas_cm(derrotas_cm) {}

std::string Jogador::get_apelido()
{
    return this->_apelido;
}

void Jogador::set_apelido(std::string apelido)
{
    this->_apelido = apelido;
}

int Jogador::get_vitorias_jdv()
{
    return this->_vitorias_jdv;
}

int Jogador::get_derrotas_jdv()
{
    return this->_derrotas_jdv;
}

int Jogador::get_vitorias_cm()
{
    return this->_vitorias_cm;
}

int Jogador::get_derrotas_cm()
{
    return this->_derrotas_cm;
}

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

void Jogador::soma_derrota_lig4()
{
    this->_derrotas_lig4 = _derrotas_lig4 + 1;
}

void Jogador::soma_vitoria_lig4()
{
    this->_vitorias_lig4++;
}

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

void Jogador::imprimir_informacoes()
{
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no jogo da velha: " << this->_vitorias_jdv << "      Derrotas no jogo da velha: " << this->_derrotas_jdv << std::endl;
    std::cout << "Vitorias no campo minado: " << this->_vitorias_cm << "      Derrotas no campo minado: " << this->_derrotas_cm << std::endl;
    std::cout << std::endl;
}

//REFAZER
void Jogador::salvar_jogador() {
    std::string caminho_arquivo = "files/jogadores.csv";

    std::ofstream arquivo(caminho_arquivo, std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << caminho_arquivo << std::endl;
        return;
    }

    // Escrever os dados do jogador no arquivo
    arquivo << _nome << ","
            << _apelido << ","
            << _vitorias_jdv << ","
            << _derrotas_jdv << ","
            << _vitorias_lig4 << ","
            << _derrotas_lig4 << ","
            << _vitorias_cm << ","
            << _derrotas_cm << "\n";

    arquivo.close();
}

void Jogador::ler_jogadores_de_csv(std::vector<Jogador>& jogadores) {
    std::string nome_arquivo = "files/jogadores.csv";

    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nome_arquivo << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nome, apelido;
        int vitorias_jdv = 0, derrotas_jdv = 0, vitorias_lig4 = 0, derrotas_lig4 = 0, vitorias_cm = 0, derrotas_cm = 0;

        std::getline(ss, nome, ',');
        std::getline(ss, apelido, ',');
        ss >> vitorias_jdv;
        ss.ignore();
        ss >> derrotas_jdv;
        ss.ignore();
        ss >> vitorias_lig4;
        ss.ignore();
        ss >> derrotas_lig4;
        ss.ignore();
        ss >> vitorias_cm;
        ss.ignore();
        ss >> derrotas_cm;

        jogadores.emplace_back(nome, apelido, vitorias_jdv, derrotas_jdv, vitorias_lig4, derrotas_lig4, vitorias_cm, derrotas_cm);
    }

    arquivo.close();
}