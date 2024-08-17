#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "campoMinado.hpp"

int main() {
    // int a, b;

    // Jogador jogador1("Jogador 1", "X");
    // Jogador jogador2("Jogador 2", "O");

    // // Lig4 john = Lig4(a,b);
    // // john.imprimir_tabuleiro();

    // JogoDaVelha jogo = JogoDaVelha(jogador1, jogador2);
    
    // jogo.partida();

    int a = 8;
    int b = 8;
    int bombas = 12;

    Jogador jogador1("jogador", "jog");

    CampoMinado jogo = CampoMinado(a, b, jogador1, bombas);
    jogo.partida();

    return 0;
}