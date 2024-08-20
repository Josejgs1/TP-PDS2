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
    SUBCASE("Teste alternar jogadores") {
        jogo_teste.fazer_jogada(1, 1); 
        CHECK(jogo_teste.apelido_atual() == "teste2"); 

        jogo_teste.fazer_jogada(2, 2); 
        CHECK(jogo_teste.apelido_atual() == "teste1");
    }
}
