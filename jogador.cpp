#include "jogador.hpp"

Jogador::Jogador(std::string nome, std::string apelido)
: _nome(nome), _apelido(apelido) {}

std::string Jogador::get_nome()
{
    return this->_nome;
}

std::string Jogador::get_apelido()
{
    return this->_apelido;
}

void Jogador::set_nome(std::string nome)
{
    this->_nome = nome;
}

void Jogador::set_apelido(std::string apelido)
{
    this->_apelido = apelido;
}