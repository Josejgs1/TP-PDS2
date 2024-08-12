#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"

void imprimir_menu()
{
    std::cout << "O que você gostaria de fazer?\n1. Jogo da Velha\n2. Lig4\n3. Sair\n";
}

int main()
{
    int opcao;
    Jogador jogador1("Jogador 1", "X");
    Jogador jogador2("Jogador 2", "O");

    while (true)
    {
        imprimir_menu();
        std::cin >> opcao;

        switch (opcao)
        {
            case 1:
            {
                JogoDaVelha jogo = JogoDaVelha(jogador1, jogador2);
                jogo.partida();

                break;
            }
            case 2:
            {
                int linhas, colunas;
                std::cout << "Insira as dimensões do tabuleiro: ";
                std::cin >> linhas >> colunas;
                while(!validar_tabuleiro_lig4(linhas, colunas))
                {
                    std::cout << "Dimensões inválidas. Tente novamente: ";
                    std::cin >> linhas >> colunas;
                }
                Lig4 jogo = Lig4(linhas, colunas, jogador1, jogador2);
                jogo.partida();
                break;
            }
            case 3:
                exit(0);
        }
    }
    return 0;
}