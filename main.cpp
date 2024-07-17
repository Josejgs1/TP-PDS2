#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"

int main() {
    int a, b;

    // Lig4 john = Lig4(a,b);
    // john.imprimir_tabuleiro();

    JogoDaVelha jogo = JogoDaVelha();
    jogo.imprimir_tabuleiro();
    
    while(true){
        std::cout << "Faça joagada: ";
        std::cin >> a >> b;
        jogo.fazer_jogada(a -1,b -1);
    }

    return 0;
}