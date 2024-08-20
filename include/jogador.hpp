#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

/**
 * @class Jogador
 * @brief Classe que representa um jogador, com informacoes sobre vitorias e derrotas em diferentes jogos.
 */
class Jogador
{
private:
    std::string _nome; ///< Nome do jogador.
    std::string _apelido; ///< Apelido do jogador.
    int _vitorias_jdv = 0; ///< Numero de vitorias no Jogo da Velha.
    int _derrotas_jdv = 0; ///< Numero de derrotas no Jogo da Velha.
    int _vitorias_lig4 = 0; ///< Numero de vitorias no Ligue 4.
    int _derrotas_lig4 = 0; ///< Numero de derrotas no Ligue 4.
    int _vitorias_cm = 0; ///< Numero de vitorias no Campo Minado.
    int _derrotas_cm = 0; ///< Numero de derrotas no Campo Minado.
    int _vitorias_rvs = 0; ///< Numero de vitorias no Reversi.
    int _derrotas_rvs = 0; ///< Numero de derrotas no Reversi.

public:
    /**
     * @brief Construtor padrao da classe Jogador.
     * Inicializa o jogador com nome e apelido vazios e todas as estatisticas zeradas.
     */
    Jogador();

    /**
     * @brief Construtor da classe Jogador com nome e apelido especificos.
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     */
    Jogador(std::string nome, std::string apelido);

    /**
     * @brief Construtor da classe Jogador com nome, apelido e estatisticas especificas.
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     * @param vitorias_jdv Numero de vitorias no Jogo da Velha.
     * @param derrotas_jdv Numero de derrotas no Jogo da Velha.
     * @param vitorias_lig4 Numero de vitorias no Ligue 4.
     * @param derrotas_lig4 Numero de derrotas no Ligue 4.
     * @param vitorias_cm Numero de vitorias no Campo Minado.
     * @param derrotas_cm Numero de derrotas no Campo Minado.
     * @param vitorias_rvs Numero de vitorias no Reversi.
     * @param derrotas_rvs Numero de derrotas no Reversi.
     */
    Jogador(std::string nome, std::string apelido, int vitorias_jdv, int derrotas_jdv, int vitorias_lig4, int derrotas_lig4, int vitorias_cm, int derrotas_cm, int vitorias_rvs, int derrotas_rvs);
    
    /**
     * @brief Retorna o nome do jogador.
     * @return Nome do jogador.
     */
    std::string get_nome() const;

    /**
     * @brief Retorna o apelido do jogador.
     * @return Apelido do jogador.
     */
    std::string get_apelido() const;

    /**
     * @brief Retorna o numero de vitorias no Jogo da Velha.
     * @return Numero de vitorias no Jogo da Velha.
     */
    int get_vitorias_jdv() const;

    /**
     * @brief Retorna o numero de derrotas no Jogo da Velha.
     * @return Numero de derrotas no Jogo da Velha.
     */
    int get_derrotas_jdv() const;

    /**
     * @brief Retorna o numero de vitorias no Campo Minado.
     * @return Numero de vitorias no Campo Minado.
     */
    int get_vitorias_cm() const;

    /**
     * @brief Retorna o numero de derrotas no Campo Minado.
     * @return Numero de derrotas no Campo Minado.
     */
    int get_derrotas_cm() const;

    /**
     * @brief Retorna o numero de vitorias no Ligue 4.
     * @return Numero de vitorias no Ligue 4.
     */
    int get_vitorias_lig4() const;

    /**
     * @brief Retorna o numero de derrotas no Ligue 4.
     * @return Numero de derrotas no Ligue 4.
     */
    int get_derrotas_lig4() const;

    /**
     * @brief Retorna o numero de vitorias no Reversi.
     * @return Numero de vitorias no Reversi.
     */
    int get_vitorias_rvs() const;

    /**
     * @brief Retorna o numero de derrotas no Reversi.
     * @return Numero de derrotas no Reversi.
     */
    int get_derrotas_rvs() const;

    /**
     * @brief Incrementa o numero de vitorias no Jogo da Velha.
     */
    void soma_vitoria_jdv();

    /**
     * @brief Incrementa o numero de derrotas no Jogo da Velha.
     */
    void soma_derrota_jdv();

    /**
     * @brief Incrementa o numero de vitorias no Campo Minado.
     */
    void soma_vitoria_cm();

    /**
     * @brief Incrementa o numero de derrotas no Campo Minado.
     */
    void soma_derrota_cm();

    /**
     * @brief Incrementa o numero de derrotas no Ligue 4.
     */
    void soma_derrota_lig4();

    /**
     * @brief Incrementa o numero de vitorias no Ligue 4.
     */
    void soma_vitoria_lig4();

    /**
     * @brief Incrementa o numero de derrotas no Reversi.
     */
    void soma_derrota_rvs();

    /**
     * @brief Incrementa o numero de vitorias no Reversi.
     */
    void soma_vitoria_rvs();

    /**
     * @brief Imprime informacoes do jogador relacionadas ao Jogo da Velha.
     */
    void imprimir_informacoes_jdv();

    /**
     * @brief Imprime informacoes do jogador relacionadas ao Ligue 4.
     */
    void imprimir_informacoes_lig4();

    /**
     * @brief Imprime informacoes do jogador relacionadas ao Reversi.
     */
    void imprimir_informacoes_rvs();

    /**
     * @brief Imprime informacoes do jogador relacionadas ao Campo Minado.
     */
    void imprimir_informacoes_cm();

    /**
     * @brief Imprime informacoes gerais do jogador, incluindo todas as estatisticas.
     */
    void imprimir_informacoes_geral();
};

/**
 * @brief Carrega a lista de jogadores a partir de um arquivo CSV.
 * @return Vetor de jogadores carregados do arquivo.
 */
std::vector<Jogador> carregar_jogadores();

/**
 * @brief Salva a lista de jogadores em um arquivo CSV.
 * @param jogadores Vetor de jogadores a serem salvos.
 */
void salvar_jogadores(std::vector<Jogador> &jogadores);

/**
 * @brief Checa se um apelido ja existe na lista de jogadores.
 * @param jogadores Vetor de jogadores.
 * @param apelido Apelido a ser verificado.
 * @return True se o apelido existir, False caso contrario.
 */
bool apelido_existe(std::vector<Jogador>& jogadores, std::string& apelido);

/**
 * @brief Encontra um jogador pelo apelido na lista de jogadores.
 * @param jogadores Vetor de jogadores.
 * @return Ponteiro para o jogador encontrado ou nullptr se nao encontrado.
 */
Jogador* encontrar_jogador(std::vector<Jogador>& jogadores);

/**
 * @brief Seleciona dois jogadores da lista.
 * @param jogador1 Ponteiro para o primeiro jogador.
 * @param jogador2 Ponteiro para o segundo jogador.
 * @param jogadores Vetor de jogadores.
 */
void selecionar_jogadores(Jogador** jogador1, Jogador** jogador2, std::vector<Jogador>& jogadores);

/**
 * @brief Seleciona um jogador da lista.
 * @param jogador1 Ponteiro para o jogador.
 * @param jogadores Vetor de jogadores.
 */
void selecionar_jogador(Jogador** jogador1, std::vector<Jogador>& jogadores);

/**
 * @brief Ordena a lista de jogadores por nome em ordem alfabetica.
 * @param jogadores Vetor de jogadores a ser ordenado.
 */
void ordenar_jogadores(std::vector<Jogador>& jogadores);

/**
 * @brief Lista todos os jogadores no console.
 * @param jogadores Vetor de jogadores a ser listado.
 */
void listar_jogadores(std::vector<Jogador>& jogadores);

/**
 * @brief Remove um jogador da lista.
 * @param jogadores Vetor de jogadores.
 */
void remover_jogador(std::vector<Jogador>& jogadores);

#endif
