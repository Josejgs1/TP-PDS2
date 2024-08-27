#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "campoMinado.hpp"
#include "jogador.hpp"
#include "jogoDeTabuleiro.hpp"

Jogador jog_teste("jogadorTeste", "teste");
CampoMinado jogo_teste(4, 4, jog_teste, 2);

TEST_CASE("Testar inicializacao campo minado")
{
    SUBCASE("Teste inicializacao valida")
    {
        CHECK_NOTHROW(CampoMinado jogo(6, 6, jog_teste, 10));
    }

    SUBCASE("Teste incializacao linhas invalidas")
    {
        CHECK_THROWS_AS(CampoMinado jogo(3, 5, jog_teste, 10), std::invalid_argument);
        CHECK_THROWS_AS(CampoMinado jogo(31, 5, jog_teste, 10), std::invalid_argument);
    }

    SUBCASE("Teste incializacao colunas invalidas")
    {
        CHECK_THROWS_AS(CampoMinado jogo(4, 3, jog_teste, 10), std::invalid_argument);
        CHECK_THROWS_AS(CampoMinado jogo(30, 31, jog_teste, 10), std::invalid_argument);
    }

    SUBCASE("Teste incializacao bombas invalidas")
    {
        CHECK_THROWS_AS(CampoMinado jogo(4, 4, jog_teste, 20), std::invalid_argument);
        CHECK_THROWS_AS(CampoMinado jogo(31, 5, jog_teste, 0), std::invalid_argument);
    }
}

TEST_CASE("Testar colocar bombas campo minado")
{
    SUBCASE("Teste colocar bombas")
    {
        CampoMinado jogo_teste2(4, 4, jog_teste, 2);
        int bombas_contadas = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (jogo_teste2.get_coordenada(i, j) == 1)
                {
                    ++bombas_contadas;
                }
            }
        }
        CHECK(bombas_contadas == 2);
    }
}

TEST_CASE("Teste fazer jogada campo minado")
{

    SUBCASE("Jogada valida")
    {
        CHECK_NOTHROW(jogo_teste.fazer_jogada(1, 1));
    }

    SUBCASE("Jogada invalida (posicao ocupada)")
    {
        std::ostringstream oss;
        std::streambuf *old_cerr_streambuf = std::cerr.rdbuf(oss.rdbuf());

        jogo_teste.fazer_jogada(1, 1);
        std::string erro_msg = oss.str();
        CHECK(erro_msg.find("Posicao ja ocupada! Tente novamente.") != std::string::npos);

        std::cerr.rdbuf(old_cerr_streambuf);
    }
}

TEST_CASE("Teste marcar bomba campo minado")
{
    SUBCASE("Marcacao valida campo minado")
    {
        CHECK_NOTHROW(jogo_teste.marcar_bomba(1, 1));
    }

    SUBCASE("Marcacao invalida (posicao ocupada)")
    {
        std::ostringstream oss;
        std::streambuf *old_cerr_streambuf = std::cerr.rdbuf(oss.rdbuf());

        jogo_teste.fazer_jogada(1, 1);
        std::string erro_msg = oss.str();
        CHECK(erro_msg.find("Posicao ja ocupada! Tente novamente.") != std::string::npos);

        std::cerr.rdbuf(old_cerr_streambuf);
    }

    SUBCASE("Desmarcacao de bomba valida")
    {
        jogo_teste.marcar_bomba(1, 1);
        CHECK_NOTHROW(jogo_teste.marcar_bomba(1, 1));
    }
}

TEST_CASE("Testar checar vitoria campo minado")
{
    SUBCASE("Teste checar vitoria sem todas as celulas reveladas")
    {
        CHECK(!jogo_teste.checar_vitoria());
    }
    SUBCASE("Teste checar vitoria com todas as celulas reveladas")
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (jogo_teste.get_coordenada(i, j) != 1)
                {
                    jogo_teste.revelar_area(i, j);
                }
            }
        }
        CHECK(jogo_teste.checar_vitoria());
    }
}
