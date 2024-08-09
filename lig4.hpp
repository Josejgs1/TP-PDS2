#ifndef LIG4_HPP
#define LIG4_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

class Lig4 : public JogoDeTabuleiro {
private:

public:
    Lig4(int linhas, int colunas);
    void fazer_jogada(int x);

};

#endif