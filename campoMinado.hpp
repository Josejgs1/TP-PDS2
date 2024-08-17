#ifndef CAMPOMINADO_HPP
#define CAMPOMINADO_HPP

#include "jogoDeTabuleiro.hpp"

class CampoMinado : public JogoDeTabuleiro
{
private:
    Jogador _jogador;
    int _n_bombas;
public:
    CampoMinado(int linhas, int colunas, Jogador jogador, int n_bombas);
    ~CampoMinado();

    void imprimir_tabuleiro() override;
    void revelar_area(int x, int y);
    void fazer_jogada(int x, int y);
    void limpar_tela();
    void marcar_bomba(int x, int y);
    void colocar_bombas();
    int bombas_em_volta(int x, int y);
    bool checar_vitoria() override;
    void partida() override;
};

#endif