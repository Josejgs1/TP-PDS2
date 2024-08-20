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

// TEST_CASE("Testar fazer jogada jogo da velha")
// {
//     SUBCASE("Teste jogada valida")
//     {
//         CHECK_NOTHROW(jogo_teste.fazer_jogada(1, 1));
//     }
//     SUBCASE("Teste jogada invalida (posicao ocupada)")
//     {
//         std::ostringstream oss;
//         std::streambuf *old_cerr_streambuf = std::cerr.rdbuf(oss.rdbuf());

//         jogo_teste.fazer_jogada(1, 1);
//         std::string erro_msg = oss.str();
//         CHECK(erro_msg.find("Posicao ja ocupada! Tente novamente.") != std::string::npos);

//         std::cerr.rdbuf(old_cerr_streambuf);
//     }
// }

// TEST_CASE("Teste alternar jogador jogo da velha")
// {
//     SUBCASE("Teste alternar jogadores")
//     {
//         jogo_teste.fazer_jogada(1, 1);
//         CHECK(jogo_teste.apelido_atual() == "teste2");

//         jogo_teste.fazer_jogada(2, 2);
//         CHECK(jogo_teste.apelido_atual() == "teste1");
//     }
// }

// TEST_CASE("Testar checar vitoria")
// {
//     SUBCASE("Teste checar vitoria sem vitória")
//     {
//         CHECK(jogo_teste.checar_vitoria() == false);
//     }
//     SUBCASE("Teste checar vitoria horizontal")
//     {
//         JogoDaVelha jogo_teste2(jogador1, jogador2);
//         jogo_teste2.fazer_jogada(1, 1);
//         jogo_teste2.fazer_jogada(2, 1);
//         jogo_teste2.fazer_jogada(1, 2);
//         jogo_teste2.fazer_jogada(3, 1);
//         jogo_teste2.fazer_jogada(1, 3);
//         CHECK(jogo_teste2.checar_vitoria() == true);
//     }

//     SUBCASE("Teste checar vitoria vertical")
//     {
//         JogoDaVelha jogo_teste3(jogador1, jogador2);
//         jogo_teste3.fazer_jogada(1, 1);
//         jogo_teste3.fazer_jogada(1, 2);
//         jogo_teste3.fazer_jogada(2, 1);
//         jogo_teste3.fazer_jogada(1, 3);
//         jogo_teste3.fazer_jogada(3, 1);
//         CHECK(jogo_teste3.checar_vitoria() == true);
//     }

//     SUBCASE("Teste checar vitoria diagonal")
//     {
//         JogoDaVelha jogo_teste4(jogador1, jogador2);
//         jogo_teste4.fazer_jogada(1, 1);
//         jogo_teste4.fazer_jogada(1, 2);
//         jogo_teste4.fazer_jogada(2, 2);
//         jogo_teste4.fazer_jogada(1, 3);
//         jogo_teste4.fazer_jogada(3, 3);
//         CHECK(jogo_teste4.checar_vitoria() == true);
//     }
// }

TEST_CASE("Testar se o tabuleiro está cheio") {
    Reversi jogo(8, 8, jogador1, jogador2);

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
    Reversi jogo(8, 8, jogador1, jogador2);

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

// TEST_CASE("Testar movimentos válidos") {
//     Reversi jogo(8, 8, jogador1, jogador2);

//     jogo.inicializarTabuleiro();

//     SUBCASE("Movimentos válidos disponíveis") {
//         CHECK(jogo.temMovimentosValidos(1));
//     }

//     SUBCASE("Movimentos inválidos disponíveis") {
//         CHECK_FALSE(jogo.temMovimentosValidos(2));
//     }
// }