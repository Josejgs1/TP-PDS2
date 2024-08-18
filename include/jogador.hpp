#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Jogador
{
private:
    std::string _nome;
    std::string _apelido;
    int _vitorias_jdv = 0;
    int _derrotas_jdv = 0;
    int _vitorias_lig4 = 0;
    int _derrotas_lig4 = 0;
    int _vitorias_cm = 0;
    int _derrotas_cm = 0;

public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vitorias_jdv, int derrotas_jdv, int vitorias_lig4, int derrotas_lig4, int vitorias_cm, int derrotas_cm);
    
    std::string get_nome() const;
    std::string get_apelido() const;
    int get_vitorias_jdv() const;
    int get_derrotas_jdv() const;
    int get_vitorias_cm() const;
    int get_derrotas_cm() const;
    int get_vitorias_lig4() const;
    int get_derrotas_lig4() const;

    // alterar depois
    void set_vitorias_jdv(int vitorias);
    void set_derrotas_jdv(int derrotas);
    void set_vitorias_cm(int vitorias);
    void set_derrotas_cm(int derrotas);

    void soma_derrota_lig4();
    void soma_vitoria_lig4();

    void imprimir_informacoes_jdv();
    void imprimir_informacoes_lig4();
    void imprimir_informacoes();
};

std::vector<Jogador> carregar_jogadores();
void salvar_jogadores(const std::vector<Jogador> &jogadores);
bool apelido_existe(const std::vector<Jogador>& jogadores, const std::string& apelido);
Jogador escolhe_jogador(const std::vector<Jogador>& jogadores);

#endif