#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

class Reversi : public JogoDeTabuleiro {
private:

public:
    Reversi::Reversi(int linhas, int colunas);
};

#endif