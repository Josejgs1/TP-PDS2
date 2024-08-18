#include <limits>
#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"
#include "reversi.hpp"
#include "campoMinado.hpp"

void imprimir_menu()
{
    std::cout << "O que você gostaria de fazer?\n1. Jogo da Velha\n2. Lig4\n3. Reversi\n4. Campo Minado\n5. Sair\n";
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
            std::cout << "Insira as dimensoes do tabuleiro: ";
            std::cin >> linhas >> colunas;
            while (!validar_tabuleiro_lig4(linhas, colunas))
            {
                std::cout << "Dimensoes inválidas. Tente novamente: ";
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
                std::cout << "O tabuleiro deve ser quadrado, no mínimo 6x6, no máximo 10x10, e com dimensoes pares: ";
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
        {
            Jogador jogador3("jogador", "jog");
            std::cout << "Escolha uma opção de tamanho do tabuleiro:" << std::endl;
            std::cout << "1. Facil (6 x 6 e 10 bombas)" << std::endl;
            std::cout << "2. Medio (15 x 15 e 50 bombas)" << std::endl;
            std::cout << "3. Dificil (24 x 24 e 95 bombas)" << std::endl;
            std::cout << "4. Extremo (30 x 30 e 150 bombas)" << std::endl;
            std::cout << "5. Personalizado" << std::endl;
            int opcao;
            std::cin >> opcao;

            CampoMinado *jogo = nullptr;

            switch (opcao)
            {
            case 1:
                jogo = new CampoMinado(6, 6, jogador3, 10);
                break;
            case 2:
                jogo = new CampoMinado(15, 15, jogador3, 50);
                break;
            case 3:
                jogo = new CampoMinado(24, 24, jogador3, 95);
                break;
            case 4:
                jogo = new CampoMinado(30, 30, jogador3, 150);
                break;
            case 5:
                int a, b, c;
                std::cout << "O tamanho minimo do tabuleiro e 4 x 4 e maximo 30 x 30" << std::endl;
                std::cout << "Digite as dimensoes e o numero de bombas desejadas: ";
                std::cin >> a >> b >> c;
                jogo = new CampoMinado(a, b, jogador3, c);
                break;
            default:
                break;
            }
            jogo->partida();
            break;
        }
        case 5:
            exit(0);
        }
    }
    return 0;
}