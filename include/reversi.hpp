#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"
#include "jogador.hpp"

class Reversi : public JogoDeTabuleiro
{
private:
    Jogador _jogador1;
    Jogador _jogador2;
    int _jogador_atual;

public:
    Reversi(int linhas, int colunas, Jogador jogador1, Jogador jogador2);
    virtual ~Reversi();
    void imprimir_tabuleiro(int jogadorAtual);
    bool checar_vitoria() override;
    void partida();
    void inicializarTabuleiro();
    bool movimentoValido(int linha, int coluna, int jogador);
    void realizarMovimento(int linha, int coluna, int jogador);
    bool tabuleiroCheio();
    int contarPecas(int jogador);
    bool temMovimentosValidos(int jogador);
};

#endif


