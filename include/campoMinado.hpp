#ifndef CAMPOMINADO_HPP
#define CAMPOMINADO_HPP

#include "jogoDeTabuleiro.hpp"

/**
 * @class CampoMinado
 * @brief Classe que representa o jogo Campo Minado.
 * Herda de JogoDeTabuleiro e implementa funcionalidades específicas do Campo Minado.
 */
class CampoMinado : public JogoDeTabuleiro
{
private:
    Jogador* _jogador; ///< Ponteiro para o jogador atual.
    int _n_bombas; ///< Numero de bombas no tabuleiro.

public:
    /**
     * @brief Construtor padrao da classe CampoMinado.
     * Inicializa um tabuleiro vazio com zero bombas.
     */
    CampoMinado();

    /**
     * @brief Construtor da classe CampoMinado com dimensoes e bombas especificas.
     * @param linhas Numero de linhas do tabuleiro.
     * @param colunas Numero de colunas do tabuleiro.
     * @param jogador Referencia ao jogador atual.
     * @param n_bombas Numero de bombas no tabuleiro.
     */
    CampoMinado(int linhas, int colunas, Jogador &jogador, int n_bombas);

    /**
     * @brief Destruidor da classe CampoMinado.
     */
    ~CampoMinado();

    /**
     * @brief Imprime o tabuleiro do Campo Minado.
     * Sobrescreve a funcao virtual pura da classe base JogoDeTabuleiro.
     */
    void imprimir_tabuleiro() override;

    /**
     * @brief Revela a area ao redor de uma coordenada (x, y).
     * @param x Coordenada x.
     * @param y Coordenada y.
     */
    void revelar_area(int x, int y);

    /**
     * @brief Faz uma jogada no tabuleiro, revelando ou marcando uma bomba.
     * @param x Coordenada x.
     * @param y Coordenada y.
     */
    void fazer_jogada(int x, int y);

    /**
     * @brief Marca uma coordenada (x, y) como contendo uma bomba.
     * @param x Coordenada x.
     * @param y Coordenada y.
     */
    void marcar_bomba(int x, int y);

    /**
     * @brief Coloca as bombas no tabuleiro em posicoes aleatorias.
     */
    void colocar_bombas();

    /**
     * @brief Conta o numero de bombas ao redor de uma coordenada (x, y).
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @return Numero de bombas ao redor.
     */
    int bombas_em_volta(int x, int y);

    /**
     * @brief Checa se o jogador venceu a partida.
     * Sobrescreve a funcao virtual pura da classe base JogoDeTabuleiro.
     * @return True se o jogador venceu, False caso contrario.
     */
    bool checar_vitoria() override;

    /**
     * @brief Inicia uma partida de Campo Minado.
     * Sobrescreve a funcao virtual pura da classe base JogoDeTabuleiro.
     */
    void partida() override;
};

#endif
