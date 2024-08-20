#ifndef JOGODETABULEIRO_HPP
#define JOGODETABULEIRO_HPP

#include <string>
#include <iostream>
#include <vector>
#include "jogador.hpp"
#include <iomanip>

/**
 * @class JogoDeTabuleiro
 * @brief Classe base abstrata para jogos de tabuleiro.
 * Define a estrutura e as operacoes basicas para um jogo de tabuleiro.
 */
class JogoDeTabuleiro
{
protected:
    int _linhas; ///< Numero de linhas do tabuleiro.
    int _colunas; ///< Numero de colunas do tabuleiro.
    std::vector<std::vector<int>> _tabuleiro; ///< Matriz que representa o tabuleiro.

public:
    /**
     * @brief Construtor padrao da classe JogoDeTabuleiro.
     * Inicializa o tabuleiro com 0 linhas e 0 colunas.
     */
    JogoDeTabuleiro();

    /**
     * @brief Construtor da classe JogoDeTabuleiro com dimensoes especificas.
     * @param linhas Numero de linhas do tabuleiro.
     * @param colunas Numero de colunas do tabuleiro.
     */
    JogoDeTabuleiro(int linhas, int colunas);

    /**
     * @brief Retorna o valor na coordenada (x, y) do tabuleiro.
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @return Valor na coordenada especificada.
     */
    int get_coordenada(int x, int y) const;
    
    /**
     * @brief Inicializa o tabuleiro com valores padrao.
     */
    void inicializar_tabuleiro();

    /**
     * @brief Imprime o tabuleiro no console.
     * Funcao virtual que pode ser sobrescrita por classes derivadas.
     */
    virtual void imprimir_tabuleiro();

    /**
     * @brief Checa se houve vitoria no jogo.
     * Funcao virtual pura que deve ser implementada por classes derivadas.
     * @return True se houver vitoria, False caso contrario.
     */
    virtual bool checar_vitoria() = 0;

    /**
     * @brief Inicia uma partida do jogo.
     * Funcao virtual pura que deve ser implementada por classes derivadas.
     */
    virtual void partida() = 0;
};

/**
 * @brief Limpa o terminal.
 * Funcao auxiliar para limpar a tela do console.
 */
void limpar_terminal();

#endif
