#include <limits>
#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"
#include "reversi.hpp"
#include "campoMinado.hpp"

void imprimir_menu()
{
    std::cout << "1. Jogo da Velha\n2. Lig4\n3. Reversi\n4. Campo Minado\n5. Cadastrar Jogador\n6. Sair\n";
}

int main()
{
    int opcao;
    Jogador jogador1("Jogador 1", "X");
    Jogador jogador2("Jogador 2", "O");
    limpar_terminal();

    while (true)
    {   
        std::cout << "O que você gostaria de fazer?" << std::endl;
        imprimir_menu();

        std::cin >> opcao;

        limpar_terminal();

        switch (opcao)
        {
            default:
                std::cout << "Opção inválida. ";
                break;
            case 1:
            {
                JogoDaVelha jogo = JogoDaVelha(jogador1, jogador2);
                jogo.partida();

                break;
            }
            case 2:
            {   
                Lig4 jogo = Lig4(jogador1, jogador2);

                int linhas, colunas;
                std::cout << "Insira as dimensoes do tabuleiro de Ligue 4: ";
                std::cin >> linhas >> colunas;

                while(true)
                {
                    try
                    {
                        jogo = Lig4(linhas, colunas, jogador1, jogador2);
                        break;
                    }
                    catch(const std::invalid_argument &erro) //terminar tratamento de erros
                    {
                        std::cout << erro.what() << std::endl;
                        std::cout << "Tente novamente: ";
                        std::cin >> linhas >> colunas;
                    }
                }

                limpar_terminal();
                jogo.partida(); //fazer tratamento de exceções
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
                int a = 8;
                int b = 8;
                int bombas = 12;

                Jogador jogador3("jogador", "jog");

                CampoMinado jogo = CampoMinado(a, b, jogador3, bombas);
                jogo.partida();
                break;
            }
            case 5:
            {
                std::string nome, apelido; 

                std::cout << "Insira seu nome: ";
                std::cin >> nome;

                std::cout << "Insira seu apelido: ";
                std::cin >> apelido;

                // try
                // {
                // } catch ()
                // {
                //     std::cout << "Tente novamente: ";
                // }

                Jogador novoJogador = Jogador(nome, apelido);
                std::cout << "Jogador criado com sucesso!" << std::endl;
                break;
            }
            case 6:
                exit(0);
        }

        std::cout << std::endl;
    }

    return 0;
}