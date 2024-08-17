#include "jogador.hpp"

Jogador::Jogador(std::string nome, std::string apelido)
: _nome(nome), _apelido(apelido) {}

std::string Jogador::get_apelido()
{
    return this->_apelido;
}

int Jogador::get_vitorias_jdv() {
    return this->_vitorias_jdv;
}

int Jogador::get_derrotas_jdv() {
    return this->_derrotas_jdv;
}

int Jogador::get_vitorias_cm() {
    return this->_vitorias_cm;
}

int Jogador::get_derrotas_cm() {
    return this->_derrotas_cm;
}

void Jogador::set_apelido(std::string apelido)
{
    this->_apelido = apelido;
}

void Jogador::set_vitorias_jdv(int vitorias) {
    this->_vitorias_jdv = vitorias;
}

void Jogador::set_derrotas_jdv(int derrotas) {
    this->_derrotas_jdv = derrotas;
}

void Jogador::set_vitorias_cm(int vitorias) {
    this->_vitorias_cm = vitorias;
}

void Jogador::set_derrotas_cm(int derrotas) {
    this->_derrotas_cm = derrotas;
}

void Jogador::imprimir_informacoes() {
    std::cout << "Jogador: " << this->_nome << std::endl;
    std::cout << "Apelido: " << this->_apelido << std::endl;
    std::cout << "Vitorias no jogo da velha: " << this->_vitorias_jdv << "      Derrotas no jogo da velha: " << this->_derrotas_jdv << std::endl;
    std::cout << "Vitorias no campo minado: " << this->_vitorias_cm << "      Derrotas no campo minado: " << this->_derrotas_cm << std::endl;
    std::cout << std::endl;
}