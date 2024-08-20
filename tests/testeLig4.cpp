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