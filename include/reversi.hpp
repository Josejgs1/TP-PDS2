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
    void inicializarTabuleiro();
    bool movimentoValido(int linha, int coluna, int jogador);
    void realizarMovimento(int linha, int coluna, int jogador);
    bool tabuleiroCheio();
    int contarPecas(int jogador);
    bool temMovimentosValidos(int jogador);

public:
    Reversi(int linhas, int colunas);
    void imprimir_tabuleiro(int jogadorAtual);
    void jogar();
    bool checar_vitoria() override;
    void partida() override;
};

#endif

