#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "campoMinado.hpp"
#include "jogador.hpp"
#include "jogoDeTabuleiro.hpp"

Jogador jog_teste("jogadorTeste", "teste");
CampoMinado jogo_teste(4, 4, jog_teste, 2);

TEST_CASE("Testar inicializacao")
{
    SUBCASE("Teste inicializacao valida campo minado")
    {
        CHECK_NOTHROW(CampoMinado jogo(6, 6, jog_teste, 10));
    }

    SUBCASE("Teste incializacao linhas invalidas campo minado")
    {
        CHECK_THROWS_AS(CampoMinado jogo(3, 5, jog_teste, 10), std::invalid_argument);
        CHECK_THROWS_AS(CampoMinado jogo(31, 5, jog_teste, 10), std::invalid_argument);
    }

    SUBCASE("Teste incializacao colunas invalidas campo minado")
    {
        CHECK_THROWS_AS(CampoMinado jogo(4, 3, jog_teste, 10), std::invalid_argument);
        CHECK_THROWS_AS(CampoMinado jogo(30, 31, jog_teste, 10), std::invalid_argument);
    }

    SUBCASE("Teste incializacao bombas invalidas campo minado")
    {
        CHECK_THROWS_AS(CampoMinado jogo(4, 4, jog_teste, 20), std::invalid_argument);
        CHECK_THROWS_AS(CampoMinado jogo(31, 5, jog_teste, 0), std::invalid_argument);
    }
}

TEST_CASE("Teste fazer jogada")
{

    SUBCASE("Jogada valida campo minado")
    {
        CHECK_NOTHROW(jogo_teste.fazer_jogada(1, 1));
    }

    SUBCASE("Jogada invalida campo minado")
    {
        std::ostringstream oss;
        std::streambuf *old_cerr_streambuf = std::cerr.rdbuf(oss.rdbuf());

        jogo_teste.fazer_jogada(1, 1);
        std::string erro_msg = oss.str();
        CHECK(erro_msg.find("Posicao ja ocupada! Tente novamente.") != std::string::npos);

        // Restaura o fluxo original de std::cerr
        std::cerr.rdbuf(old_cerr_streambuf);
    }
}
