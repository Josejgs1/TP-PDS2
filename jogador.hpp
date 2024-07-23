#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <iostream>
#include <vector>

class Jogador
{
private:
    std::string _nome;
    std::string _apelido;
public:
    Jogador(std::string nome, std::string apelido);

    std::string get_nome();
    std::string get_apelido();

    void set_nome(std::string nome);
    void set_apelido(std::string apelido);
};

#endif