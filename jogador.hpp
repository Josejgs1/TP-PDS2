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

    int _vitorias_lig4 = 0;
    int _derrotas_lig4 = 0;

public:
    Jogador(std::string nome, std::string apelido);

    std::string get_apelido();
    int get_vitorias_jdv();
    int get_derrotas_jdv();

    void set_apelido(std::string apelido);
    void set_vitorias_jdv(int vitorias);
    void set_derrotas_jdv(int derrotas);

    void soma_derrota_lig4();
    void soma_vitoria_lig4();

    void imprimir_informacoes_jdv();
    void imprimir_informacoes_lig4();
};

#endif