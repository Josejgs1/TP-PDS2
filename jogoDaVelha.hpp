#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

class JogoDaVelha : public JogoDeTabuleiro {
private:

public:
    JogoDaVelha();
    void imprimir_tabuleiro() override;
    void fazer_jogada(int x, int y);
};

#endif