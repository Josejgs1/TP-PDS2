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
    int _vitorias_jdv = 0;
    int _derrotas_jdv = 0;
    int _vitorias_cm = 0;
    int _derrotas_cm = 0;
public:
    Jogador(std::string nome, std::string apelido);

    std::string get_apelido();
    int get_vitorias_jdv();
    int get_derrotas_jdv();
    int get_vitorias_cm();
    int get_derrotas_cm();

    void set_apelido(std::string apelido);
    void set_vitorias_jdv(int vitorias);
    void set_derrotas_jdv(int derrotas);
    void set_vitorias_cm(int vitorias);
    void set_derrotas_cm(int derrotas);

    void imprimir_informacoes();
};

#endif