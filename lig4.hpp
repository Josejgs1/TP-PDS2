#ifndef LIG4_HPP
#define LIG4_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

class Lig4 : public JogoDeTabuleiro {
private:
    Jogador _jogador1;
    Jogador _jogador2;
    int _jogador_atual;

public:
    Lig4(int linhas, int colunas, Jogador jogador1, Jogador jogador2);
    
    void fazer_jogada(int x);
    void alternar_jogador();
    std::string apelido_atual();
    bool checar_vitoria() override;
    bool checar_final();
    void partida() override;
};

bool validar_tabuleiro_lig4(int linhas, int colunas);

#endif