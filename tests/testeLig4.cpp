#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lig4.hpp"
#include "jogador.hpp"
#include "jogoDeTabuleiro.hpp"

Jogador jogador1("jogadorTeste1", "teste1");
Jogador jogador2("jogadorTeste2", "teste2");

TEST_CASE("Testar inicializacao Lig4")
{
    SUBCASE("Teste inicializacao valida")
    {
        CHECK_NOTHROW(Lig4(6, 6, jogador1, jogador2));
    }

    SUBCASE("Teste inicializacao invalida (tamanho minimo)")
    {
        CHECK_THROWS_AS(Lig4(3, 7, jogador1, jogador2), std::invalid_argument);
    }

    SUBCASE("Teste inicializacao invalida (tamanho maximo)")
    {
        CHECK_THROWS_AS(Lig4(21, 7, jogador1, jogador2), std::invalid_argument);
        CHECK_THROWS_AS(Lig4(6, 21, jogador1, jogador2), std::invalid_argument);
    }
}

TEST_CASE("Testar fazer jogada")
{
    Lig4 jogo_teste(6, 7, jogador1, jogador2);

    SUBCASE("Teste jogada valida")
    {
        CHECK_NOTHROW(jogo_teste.fazer_jogada(1));
    }
    SUBCASE("Teste jogada invalida (coluna cheia)")
    {
        for (int i = 0; i < 6; ++i)
        {
            jogo_teste.fazer_jogada(1);
        }
        std::ostringstream oss;
        std::streambuf* old_cout_streambuf = std::cout.rdbuf(oss.rdbuf());

        jogo_teste.fazer_jogada(1);

        std::cout.rdbuf(old_cout_streambuf);

        std::string erro_msg = oss.str();
        CHECK(erro_msg.find("Coluna cheia! Por favor, escolha outra coluna.") != std::string::npos);
    }
    SUBCASE("Teste jogada invalida (coluna fora do intervalo)")
    {
        std::ostringstream oss;
        std::streambuf* old_cout_streambuf = std::cout.rdbuf(oss.rdbuf());

        jogo_teste.fazer_jogada(8);
        std::string erro_msg = oss.str();
        CHECK(erro_msg.find("Jogada invalida! Por favor, escolha uma coluna entre 1 e 7.") != std::string::npos);

        std::cout.rdbuf(old_cout_streambuf);
    }
}

TEST_CASE("Testar alternar jogador Lig4")
{
    Lig4 jogo_teste2(6, 7, jogador1, jogador2);

    SUBCASE("Teste alternar jogadores")
    {
        jogo_teste2.fazer_jogada(1);
        CHECK(jogo_teste2.apelido_atual() == "teste2");

        jogo_teste2.fazer_jogada(2);
        CHECK(jogo_teste2.apelido_atual() == "teste1");
    }
}

TEST_CASE("Testar vitoria Lig4")
{
    SUBCASE("Teste checar vitoria sem vitoria")
    {
        Lig4 jogo_teste7(6, 7, jogador1, jogador2);
        CHECK(jogo_teste7.checar_vitoria() == false);
    }
    SUBCASE("Teste checar vitoria horizontal")
    {
        Lig4 jogo_teste3(6, 7, jogador1, jogador2);
        jogo_teste3.fazer_jogada(1);
        jogo_teste3.fazer_jogada(2);
        jogo_teste3.fazer_jogada(1);
        jogo_teste3.fazer_jogada(2);
        jogo_teste3.fazer_jogada(1);
        jogo_teste3.fazer_jogada(2);
        jogo_teste3.fazer_jogada(1);
        CHECK(jogo_teste3.checar_vitoria() == true);
    }
    SUBCASE("Teste checar vitoria vertical")
    {
        Lig4 jogo_teste4(6, 7, jogador1, jogador2);
        jogo_teste4.fazer_jogada(1);
        jogo_teste4.fazer_jogada(1);
        jogo_teste4.fazer_jogada(2);
        jogo_teste4.fazer_jogada(2);
        jogo_teste4.fazer_jogada(3);
        jogo_teste4.fazer_jogada(3);
        jogo_teste4.fazer_jogada(4);
        CHECK(jogo_teste4.checar_vitoria() == true);
    }
    SUBCASE("Teste checar vitoria diagonal descendente")
    {
        Lig4 jogo_teste5(6, 7, jogador1, jogador2);
        jogo_teste5.fazer_jogada(1);
        jogo_teste5.fazer_jogada(2);
        jogo_teste5.fazer_jogada(2);
        jogo_teste5.fazer_jogada(3);
        jogo_teste5.fazer_jogada(4);
        jogo_teste5.fazer_jogada(3);
        jogo_teste5.fazer_jogada(3);
        jogo_teste5.fazer_jogada(4);
        jogo_teste5.fazer_jogada(4);
        jogo_teste5.fazer_jogada(5);
        jogo_teste5.fazer_jogada(4);
        CHECK(jogo_teste5.checar_vitoria() == true);
    }
    SUBCASE("Teste checar vitoria diagonal ascendente")
    {
        Lig4 jogo_teste6(6, 7, jogador1, jogador2);
        jogo_teste6.fazer_jogada(5);
        jogo_teste6.fazer_jogada(4);
        jogo_teste6.fazer_jogada(2);
        jogo_teste6.fazer_jogada(3);
        jogo_teste6.fazer_jogada(4);
        jogo_teste6.fazer_jogada(3);
        jogo_teste6.fazer_jogada(3);
        jogo_teste6.fazer_jogada(2);
        jogo_teste6.fazer_jogada(2);
        jogo_teste6.fazer_jogada(1);
        jogo_teste6.fazer_jogada(2);
        CHECK(jogo_teste6.checar_vitoria() == true);
    }
}