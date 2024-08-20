#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    int _vitorias_rvs = 0;
    int _derrotas_rvs = 0;

public:
    Jogador();
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vitorias_jdv, int derrotas_jdv, int vitorias_lig4, int derrotas_lig4, int vitorias_cm, int derrotas_cm, int vitorias_rvs, int derrotas_rvs);
    
    std::string get_nome() const;
    std::string get_apelido() const;
    int get_vitorias_jdv() const;
    int get_derrotas_jdv() const;
    int get_vitorias_cm() const;
    int get_derrotas_cm() const;
    int get_vitorias_lig4() const;
    int get_derrotas_lig4() const;
    int get_vitorias_rvs() const;
    int get_derrotas_rvs() const;

    void soma_vitoria_jdv();
    void soma_derrota_jdv();
    void soma_vitoria_cm();
    void soma_derrota_cm();
    void soma_derrota_lig4();
    void soma_vitoria_lig4();
    void soma_derrota_rvs();
    void soma_vitoria_rvs();

    void imprimir_informacoes_jdv();
    void imprimir_informacoes_lig4();
    void imprimir_informacoes_rvs();
    void imprimir_informacoes_cm();
    void imprimir_informacoes_geral();
};

std::vector<Jogador> carregar_jogadores();
void salvar_jogadores(std::vector<Jogador> &jogadores);
bool apelido_existe(std::vector<Jogador>& jogadores, std::string& apelido);
Jogador* encontrar_jogador(std::vector<Jogador>& jogadores);
void selecionar_jogadores(Jogador** jogador1, Jogador** jogador2, std::vector<Jogador>& jogadores);
void selecionar_jogador(Jogador** jogador1, std::vector<Jogador>& jogadores);
void ordenar_jogadores(std::vector<Jogador>& jogadores);
void listar_jogadores(std::vector<Jogador>& jogadores);
void remover_jogador(std::vector<Jogador>& jogadores);

#endif