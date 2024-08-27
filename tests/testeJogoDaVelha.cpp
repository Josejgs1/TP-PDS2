#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogoDaVelha.hpp"
#include "jogador.hpp"
#include "jogoDeTabuleiro.hpp"

Jogador jogador1("jogadorTeste1", "teste1");
Jogador jogador2("jogadorTeste1", "teste2");
JogoDaVelha jogo_teste(jogador1, jogador2);

TEST_CASE("Testar inicializacao jogo da velha")
{
    SUBCASE("Teste inicializacao valida")
    {
        CHECK_NOTHROW(JogoDaVelha(jogador1, jogador2));
    }
}

TEST_CASE("Testar fazer jogada jogo da velha")
{
    SUBCASE("Teste jogada valida")
    {
        CHECK_NOTHROW(jogo_teste.fazer_jogada(1, 1));
    }
    SUBCASE("Teste jogada invalida (posicao ocupada)")
    {
        std::ostringstream oss;
        std::streambuf *old_cerr_streambuf = std::cerr.rdbuf(oss.rdbuf());

        jogo_teste.fazer_jogada(1, 1);
        std::string erro_msg = oss.str();
        CHECK(erro_msg.find("Posicao ja ocupada! Tente novamente.") != std::string::npos);

        std::cerr.rdbuf(old_cerr_streambuf);
    }
}

TEST_CASE("Teste alternar jogador jogo da velha")
{
    SUBCASE("Teste alternar jogadores")
    {
        jogo_teste.fazer_jogada(1, 1);
        CHECK(jogo_teste.apelido_atual() == "teste2");

        jogo_teste.fazer_jogada(2, 2);
        CHECK(jogo_teste.apelido_atual() == "teste1");
    }
}

TEST_CASE("Testar checar vitoria")
{
    SUBCASE("Teste checar vitoria sem vitória")
    {
        CHECK(jogo_teste.checar_vitoria() == false);
    }
    SUBCASE("Teste checar vitoria horizontal")
    {
        JogoDaVelha jogo_teste2(jogador1, jogador2);
        jogo_teste2.fazer_jogada(1, 1);
        jogo_teste2.fazer_jogada(2, 1);
        jogo_teste2.fazer_jogada(1, 2);
        jogo_teste2.fazer_jogada(3, 1);
        jogo_teste2.fazer_jogada(1, 3);
        CHECK(jogo_teste2.checar_vitoria() == true);
    }

    SUBCASE("Teste checar vitoria vertical")
    {
        JogoDaVelha jogo_teste3(jogador1, jogador2);
        jogo_teste3.fazer_jogada(1, 1);
        jogo_teste3.fazer_jogada(1, 2);
        jogo_teste3.fazer_jogada(2, 1);
        jogo_teste3.fazer_jogada(1, 3);
        jogo_teste3.fazer_jogada(3, 1);
        CHECK(jogo_teste3.checar_vitoria() == true);
    }

    SUBCASE("Teste checar vitoria diagonal")
    {
        JogoDaVelha jogo_teste4(jogador1, jogador2);
        jogo_teste4.fazer_jogada(1, 1);
        jogo_teste4.fazer_jogada(1, 2);
        jogo_teste4.fazer_jogada(2, 2);
        jogo_teste4.fazer_jogada(1, 3);
        jogo_teste4.fazer_jogada(3, 3);
        CHECK(jogo_teste4.checar_vitoria() == true);
    }
}

TEST_CASE("Testar checar final jogo da velha")
{
    JogoDaVelha jogo_teste4(jogador1, jogador2);

    SUBCASE("Teste checar final quando ainda ha jogadas")
    {
        jogo_teste4.fazer_jogada(1, 1);
        CHECK(jogo_teste4.checar_final() == false);
    }

    SUBCASE("Teste checar final quando o tabuleiro esta cheio")
    {
        for (int i = 1; i <= 3; ++i)
        {
            for (int j = 1; j <= 3; ++j)
            {
                jogo_teste4.fazer_jogada(i, j);
            }
        }
        CHECK(jogo_teste4.checar_final() == true);
    }
}