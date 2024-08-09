#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"

int main()
{
    int opcao;

    while (true)
    {
        std::cin >> opcao;
        switch (opcao)
        {
            case 1:
            {
                int a, b; // boa prática?
                std::cin >> a >> b;

                Jogador jogador1("Jogador 1", "X");
                Jogador jogador2("Jogador 2", "O");

                JogoDaVelha jogo = JogoDaVelha(jogador1, jogador2);
                jogo.partida();
                break;
            }
            case 2:
            {
                // int a, b, x;

                // Lig4 john = Lig4(a,b);
                // john.imprimir_tabuleiro();

                // while(true){
                //     std::cout << "Faça jogada: ";
                //     std::cin >> x;
                //     john.fazer_jogada(x);
                break;
            }
        }
    }
    return 0;
}