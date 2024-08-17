#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

class JogoDaVelha : public JogoDeTabuleiro
{
private:
    Jogador _jogador1;
    Jogador _jogador2;
    int _jogador_atual;

public:
    JogoDaVelha(Jogador jogador1, Jogador jogador2);

    void imprimir_tabuleiro() override;
    void fazer_jogada(int x, int y);
    void alternar_jogador();
    std::string apelido_atual();
    bool checar_vitoria() override;
    bool checar_final();
    void partida() override;
};

#endif