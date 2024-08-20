#ifndef JOGODETABULEIRO_HPP
#define JOGODETABULEIRO_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogador.hpp"
#include <iomanip>

class JogoDeTabuleiro
{
protected:
    int _linhas;
    int _colunas;
    std::vector<std::vector<int>> _tabuleiro;

public:
    JogoDeTabuleiro();
    JogoDeTabuleiro(int linhas, int colunas);

    int get_coordenada(int x, int y) const;
    
    void inicializar_tabuleiro();
    virtual void imprimir_tabuleiro();
    virtual bool checar_vitoria() = 0;
    virtual void partida() = 0;
};

void limpar_terminal();

#endif