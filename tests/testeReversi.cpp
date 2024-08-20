#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogador.hpp"
#include "jogoDeTabuleiro.hpp"
#include "reversi.hpp"

Jogador jogador1("jogadorTeste1", "teste1");
Jogador jogador2("jogadorTeste1", "teste2");
Reversi jogo_teste(6, 6, jogador1, jogador2);

TEST_CASE("Testar inicializacao do reversi")
{
    SUBCASE("Teste inicializacao valida")
    {
        CHECK_NOTHROW(Reversi(6, 6, jogador1, jogador2));
    }
}

TEST_CASE("Testar realização de movimentos") {
    Reversi jogo(6, 6, jogador1, jogador2);

    jogo.inicializarTabuleiro();

    SUBCASE("Realizar movimento válido") {
        CHECK_NOTHROW(jogo.realizarMovimento(2, 4, 1));
    }

    SUBCASE("Realizar movimento inválido") {
        CHECK_THROWS_AS(jogo.realizarMovimento(0, 0, 1), std::invalid_argument);
    }
}

TEST_CASE("Testar se o tabuleiro está cheio") {
    Reversi jogo(6, 6, jogador1, jogador2);

    jogo.inicializarTabuleiro();

    SUBCASE("Tabuleiro não está cheio") {
        CHECK_FALSE(jogo.tabuleiroCheio());
    }

    // SUBCASE("Tabuleiro está cheio") {
    //     // Fill the board and then check
    //     CHECK(jogo.tabuleiroCheio());
    // }
}

TEST_CASE("Testar contagem de peças") {
    Reversi jogo(6, 6, jogador1, jogador2);

    jogo.inicializarTabuleiro();

    SUBCASE("Contar peças do jogador 1") {
        int count = jogo.contarPecas(1);
        CHECK(count >= 0);
    }

    SUBCASE("Contar peças do jogador 2") {
        int count = jogo.contarPecas(2);
        CHECK(count >= 0);
    }
}

TEST_CASE("Testar movimentos válidos") {
    Reversi jogo(6, 6, jogador1, jogador2);

    jogo.inicializarTabuleiro();

    SUBCASE("Movimentos válidos disponíveis") {
        CHECK(jogo.temMovimentosValidos(1));
    }

    // SUBCASE("Movimentos inválidos disponíveis") {
    //     CHECK_FALSE(jogo.temMovimentosValidos(2));
    // }
}