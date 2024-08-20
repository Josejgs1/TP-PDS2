#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogoDeTabuleiro.hpp"
#include "jogador.hpp"

/**
 * @class Reversi
 * @brief Classe que representa o jogo Reversi, derivada da classe JogoDeTabuleiro.
 * Implementa as operacoes e regras especificas do jogo Reversi.
 */
class Reversi : public JogoDeTabuleiro
{
private:
    Jogador* _jogador1; ///< Ponteiro para o primeiro jogador.
    Jogador* _jogador2; ///< Ponteiro para o segundo jogador.
    int _jogador_atual; ///< Indica o jogador atual.

public:
    /**
     * @brief Construtor padrao da classe Reversi.
     * Inicializa o jogo com dimensoes padrao e jogadores nao definidos.
     */
    Reversi();

    /**
     * @brief Construtor da classe Reversi com dimensoes e jogadores especificos.
     * @param linhas Numero de linhas do tabuleiro.
     * @param colunas Numero de colunas do tabuleiro.
     * @param jogador1 Referencia para o primeiro jogador.
     * @param jogador2 Referencia para o segundo jogador.
     */
    Reversi(int linhas, int colunas, Jogador& jogador1, Jogador& jogador2);
    
    /**
     * @brief Destrutor da classe Reversi.
     * Libera recursos utilizados pela instancia da classe.
     */
    virtual ~Reversi();

    /**
     * @brief Imprime o tabuleiro do jogo.
     * @param jogadorAtual Indica o jogador atual para o qual o tabuleiro sera impresso.
     */
    void imprimir_tabuleiro(int jogadorAtual);

    /**
     * @brief Checa se houve vitoria no jogo.
     * @return True se houver vitoria, False caso contrario.
     */
    bool checar_vitoria() override;

    /**
     * @brief Inicia uma partida do jogo.
     */
    void partida();

    /**
     * @brief Inicializa o tabuleiro do jogo Reversi.
     */
    void inicializarTabuleiro();

    /**
     * @brief Checa se um movimento e valido.
     * @param linha Linha do movimento.
     * @param coluna Coluna do movimento.
     * @param jogador Indica o jogador que esta fazendo o movimento.
     * @return True se o movimento for valido, False caso contrario.
     */
    bool movimentoValido(int linha, int coluna, int jogador);

    /**
     * @brief Realiza um movimento no tabuleiro.
     * @param linha Linha onde o movimento sera feito.
     * @param coluna Coluna onde o movimento sera feito.
     * @param jogador Indica o jogador que esta realizando o movimento.
     */
    void realizarMovimento(int linha, int coluna, int jogador);

    /**
     * @brief Checa se o tabuleiro esta cheio.
     * @return True se o tabuleiro estiver cheio, False caso contrario.
     */
    bool tabuleiroCheio();

    /**
     * @brief Conta o numero de pecas de um jogador no tabuleiro.
     * @param jogador Indica o jogador para contar as pecas.
     * @return Numero de pecas do jogador.
     */
    int contarPecas(int jogador);

    /**
     * @brief Checa se existem movimentos validos para um jogador.
     * @param jogador Indica o jogador para verificar os movimentos validos.
     * @return True se o jogador tem movimentos validos, False caso contrario.
     */
    bool temMovimentosValidos(int jogador);
};

#endif
