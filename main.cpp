#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"

void imprimir_menu(){
    std::cout << "O que você gostaria de fazer?\n1. Jogo da Velha\n2. Lig4\n3. Sair\n";
}

int main()
{
    int opcao;

    while (true)
    {
        imprimir_menu();
        std::cin >> opcao;

        switch (opcao)
        {
            case 1:
            {
                // Jogador jogador1("Jogador 1", "X");
                // Jogador jogador2("Jogador 2", "O");

                // JogoDaVelha jogo = JogoDaVelha(jogador1, jogador2);
                // jogo.partida();
                // break;
            }
            case 2:
            {
                int a, b, x;

                std::cout << "Insira as dimensões do tabuleiro: ";
                std::cin >> a >> b;

                if(a <= 0 || b <= 0){
                    std::cout << "Dimensões inválidas\n";
                    break;
                }

                Lig4 john = Lig4(a,b);
                john.imprimir_tabuleiro();

                while(true){
                    std::cout << "Faça jogada: ";
                    std::cin >> x;
                    john.fazer_jogada(x);
                break;
                }
            }
            case 3:
                exit(0);
        }
    }
    return 0;
}