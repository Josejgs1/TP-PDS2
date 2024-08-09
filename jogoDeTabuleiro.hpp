#ifndef JOGODETABULEIRO_HPP
#define JOGODETABULEIRO_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogador.hpp"

class JogoDeTabuleiro
{
protected:
    int _linhas;
    int _colunas;
    std::vector<std::vector<int>> _tabuleiro;

public:
    JogoDeTabuleiro(int linhas, int colunas);
    virtual void imprimir_tabuleiro();
    void inicializar_tabuleiro();
};

#endif