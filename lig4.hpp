#ifndef LIG4_HPP
#define LIG4_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

class Lig4 : public JogoDeTabuleiro {
private:
    int _linha;
    int _coluna;
public:
    Lig4(int linhas, int colunas);
};

#endif