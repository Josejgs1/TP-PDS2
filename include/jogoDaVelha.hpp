#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

/**
 * @class JogoDaVelha
 * @brief Classe que representa o jogo da velha.
 * Herda de JogoDeTabuleiro e implementa funcionalidades especificas do Jogo da Velha.
 */
class JogoDaVelha : public JogoDeTabuleiro
{
private:
    Jogador* _jogador1; ///< Ponteiro para o jogador 1.
    Jogador* _jogador2; ///< Ponteiro para o jogador 2.
    int _jogador_atual; ///< Indice do jogador atual (1 ou 2).

public:
    /**
     * @brief Construtor padrao da classe JogoDaVelha.
     * Inicializa o jogo com dois jogadores nulos e o jogador atual como 1.
     */
    JogoDaVelha();

    /**
     * @brief Construtor da classe JogoDaVelha com dois jogadores especificos.
     * @param jogador1 Referencia para o jogador 1.
     * @param jogador2 Referencia para o jogador 2.
     */
    JogoDaVelha(Jogador& jogador1, Jogador& jogador2);

    /**
     * @brief Destruidor da classe JogoDaVelha.
     */
    virtual ~JogoDaVelha();

    /**
     * @brief Imprime o tabuleiro do jogo da velha.
     * Sobrescreve a funcao virtual pura da classe base JogoDeTabuleiro.
     */
    void imprimir_tabuleiro() override;

    /**
     * @brief Faz uma jogada no tabuleiro na coordenada (x, y).
     * @param x Coordenada x.
     * @param y Coordenada y.
     */
    void fazer_jogada(int x, int y);

    /**
     * @brief Alterna o jogador atual.
     */
    void alternar_jogador();

    /**
     * @brief Retorna o apelido do jogador atual.
     * @return Apelido do jogador atual.
     */
    std::string apelido_atual();

    /**
     * @brief Checa se o jogador venceu a partida.
     * Sobrescreve a funcao virtual pura da classe base JogoDeTabuleiro.
     * @return True se o jogador venceu, False caso contrario.
     */
    bool checar_vitoria() override;

    /**
     * @brief Checa se o jogo chegou ao fim.
     * @return True se o jogo terminou, False caso contrario.
     */
    bool checar_final();

    /**
     * @brief Inicia uma partida de Jogo da Velha.
     * Sobrescreve a funcao virtual pura da classe base JogoDeTabuleiro.
     */
    void partida() override;
};

#endif
