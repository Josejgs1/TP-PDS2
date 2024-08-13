#include <limits>
#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"
#include "reversi.hpp"

void imprimir_menu()
{
    std::cout << "O que você gostaria de fazer?\n1. Jogo da Velha\n2. Lig4\n3. Reversi\n4. Sair\n";
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
                while (!validar_tabuleiro_lig4(linhas, colunas))
                {
                    std::cout << "Dimensões inválidas. Tente novamente: ";
                    std::cin >> linhas >> colunas;
                }
                Lig4 jogo = Lig4(linhas, colunas, jogador1, jogador2);
                jogo.partida();

                break;
            }
            case 3:
            {
                int tamanho;
                while (true)
                {
                    std::cout << "O tabuleiro deve ser quadrado, no mínimo 6x6, no máximo 10x10, e com dimensões pares: ";
                    std::cin >> tamanho;

                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Entrada inválida. Tente novamente." << std::endl;
                    }
                    else if (tamanho < 6 || tamanho > 10 || tamanho % 2 != 0)
                    {
                        std::cout << "O valor deve ser entre 6 e 10 e deve ser par. Tente novamente." << std::endl;
                    }
                    else
                    {
                        break;
                    }
                }

                try
                {
                    Reversi jogo(tamanho, tamanho);
                    jogo.jogar();
                }
                catch (const std::invalid_argument &erro)
                {
                    std::cout << erro.what() << std::endl;
                }
                break;
            }
            case 4:
                exit(0);
        }
    }
    
    return 0;
}