#include <limits>
#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"
#include "reversi.hpp"
#include "campoMinado.hpp"
#include "jogador.hpp"

void imprimir_menu()
{
    std::cout << "O que você gostaria de fazer?\n1. Jogo da Velha\n2. Lig4\n3. Reversi\n4. Campo Minado\n5. Cadastrar Jogador\n6. Sair\n";
}

int main()
{
    int opcao;
    std::vector<Jogador> jogadores = carregar_jogadores();

    //PARA TESTE
    Jogador jogador3("Jogador 1", "X");
    Jogador jogador4("Jogador 2", "O");

    limpar_terminal();

    while (true)
    {
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
            JogoDaVelha jogo = JogoDaVelha(jogador3, jogador4);
            jogo.partida();

            break;
        }
        case 2:
        {
            Jogador* jogador1 = nullptr;  // Inicialize os ponteiros
            Jogador* jogador2 = nullptr;
            Lig4 jogo;

            std::cout << "Quem irá jogar?" << std::endl;
            while (true)
            {
                std::cout << "Jogador 1: ";
                jogador1 = escolhe_jogador(jogadores);
                std::cout << "Jogador 2: ";
                jogador2 = escolhe_jogador(jogadores);

                if (jogador1->get_apelido() == jogador2->get_apelido())
                {
                    std::cout << "Os jogadores devem ser diferentes." << std::endl; //resolver
                }
                else
                {
                    break;
                }
            }

            int linhas, colunas;
            std::cout << "Insira as dimensoes do tabuleiro de Ligue 4: ";
            std::cin >> linhas >> colunas;

            while (true)
            {
                try
                {
                    jogo = Lig4(linhas, colunas, *jogador1, *jogador2);
                    break;
                }
                catch (const std::invalid_argument &erro) // terminar tratamento de erros
                {
                    std::cout << erro.what() << std::endl;
                    std::cout << "Tente novamente: ";
                    std::cin >> linhas >> colunas;
                }
            }

            limpar_terminal();
            jogo.partida(); // fazer tratamento de exceções
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

            while (true)
            {
                std::cin >> apelido;

                if (!apelido_existe(jogadores, apelido))
                {
                    break;
                }
                else
                {
                    std::cout << "O apelido já existe. Tente novamente: ";
                }
            }

            Jogador novoJogador = Jogador(nome, apelido);
            jogadores.push_back(novoJogador);

            std::cout << "Jogador criado com sucesso!" << std::endl;
            break;
        }
        case 6:
            salvar_jogadores(jogadores);
            exit(0);
        }

        std::cout << std::endl;
    }

    salvar_jogadores(jogadores);
    return 0;
}