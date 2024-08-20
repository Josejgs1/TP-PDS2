#ifndef LIG4_HPP
#define LIG4_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"

/**
 * @class Lig4
 * @brief Classe que representa o jogo Lig4, derivada da classe JogoDeTabuleiro.
 * Implementa as operacoes e regras especificas do jogo Lig4.
 */
class Lig4 : public JogoDeTabuleiro {
private:
    Jogador* _jogador1; ///< Ponteiro para o primeiro jogador.
    Jogador* _jogador2; ///< Ponteiro para o segundo jogador.
    int _jogador_atual; ///< Indica o jogador atual.

public:
    /**
     * @brief Construtor padrao da classe Lig4.
     * Inicializa o jogo com dimensoes padrao e jogadores nao definidos.
     */
    Lig4();

    /**
     * @brief Construtor da classe Lig4 com dimensoes e jogadores especificos.
     * @param linhas Numero de linhas do tabuleiro.
     * @param colunas Numero de colunas do tabuleiro.
     * @param jogador1 Referencia para o primeiro jogador.
     * @param jogador2 Referencia para o segundo jogador.
     */
    Lig4(int linhas, int colunas, Jogador& jogador1, Jogador& jogador2);

    /**
     * @brief Destrutor da classe Lig4.
     * Libera recursos utilizados pela instancia da classe.
     */
    ~Lig4();
    
    /**
     * @brief Faz uma jogada no jogo.
     * @param x Coordenada da coluna onde a jogada sera feita.
     */
    void fazer_jogada(int x);

    /**
     * @brief Alterna entre os jogadores.
     */
    void alternar_jogador();

    /**
     * @brief Retorna o apelido do jogador atual.
     * @return Apelido do jogador atual.
     */
    std::string apelido_atual();

    /**
     * @brief Checa se houve vitoria no jogo.
     * @return True se houver vitoria, False caso contrario.
     */
    bool checar_vitoria() override;

    /**
     * @brief Checa se o jogo chegou ao fim.
     * @return True se o jogo esta terminado, False caso contrario.
     */
    bool checar_final();

    /**
     * @brief Inicia uma partida do jogo.
     */
    void partida() override;
};

#endif
