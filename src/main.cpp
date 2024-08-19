#include <limits>
#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"
#include "jogoDaVelha.hpp"
#include "reversi.hpp"
#include "campoMinado.hpp"
#include "jogador.hpp"

#define DIMENSAO_JOGO_RAPIDO 6
#define DIMENSAO_JOGO_CLASSICO 8
#define DIMENSAO_JOGO_EXTREMO 10

void imprimir_menu()
{
    std::cout << "O que você gostaria de fazer?\n1. Jogo da Velha\n2. Lig4\n3. Reversi\n4. Campo Minado\n5. Cadastrar Jogador\n6. Sair\n";
}

char validar_entrada()
{
    char modo_de_jogo;
    std::cin >> modo_de_jogo;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("\033[31mErro: Não foi possível ler um caractere.\033[0m");
    }

    if (std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("\033[31mErro: Entrada deve ser um único caractere.\033[0m");
    }

    if (modo_de_jogo != 'R' && modo_de_jogo != 'r' && modo_de_jogo != 'E' && modo_de_jogo != 'e' && modo_de_jogo != 'C' && modo_de_jogo != 'c')
    {
        throw std::runtime_error("\033[31mErro: Caractere inválido. Use R, r, E, e, C ou c.\033[0m");
    }

    return modo_de_jogo;
}

int main()
{
    int opcao;
    std::vector<Jogador> jogadores = carregar_jogadores();

    //PARA TESTE
    Jogador jogador1("Jogador 1", "X");
    Jogador jogador2("Jogador 2", "O");

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
            JogoDaVelha jogo = JogoDaVelha(jogador1, jogador2);
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
            limpar_terminal();
            while (true)
            {
                std::cout << "- Escolha a dimensão do tabuleiro -" << std::endl;
                std::cout << "Digite R para Jogo Rápido   (Tabuleiro 6x6) " << std::endl
                          << "Digite C para Jogo Clássico (Tabuleiro 8x8) " << std::endl
                          << "Digite E para Jogo Extremo  (Tabuleiro 10x10) " << std::endl;
                std::cout << std::endl;

                try
                {
                    char modo_de_jogo = validar_entrada();

                    if (modo_de_jogo == 'R' || modo_de_jogo == 'r')
                    {
                        std::cout << "Você escolheu Jogo Rápido (Tabuleiro 6x6)." << std::endl;
                        limpar_terminal();
                        Reversi jogo(DIMENSAO_JOGO_RAPIDO, DIMENSAO_JOGO_RAPIDO, jogador1, jogador2);
                        jogo.partida();
                        break;
                    }
                    else if (modo_de_jogo == 'C' || modo_de_jogo == 'c')
                    {
                        std::cout << "Você escolheu Jogo Clássico (Tabuleiro 8x8)." << std::endl;
                        limpar_terminal();
                        Reversi jogo(DIMENSAO_JOGO_CLASSICO, DIMENSAO_JOGO_CLASSICO, jogador1, jogador2);
                        jogo.partida();
                        break;
                    }
                    else if (modo_de_jogo == 'E' || modo_de_jogo == 'e')
                    {
                        std::cout << "Você escolheu Jogo Extremo (Tabuleiro 10x10)." << std::endl;
                        limpar_terminal();
                        Reversi jogo(DIMENSAO_JOGO_EXTREMO, DIMENSAO_JOGO_EXTREMO, jogador1, jogador2);
                        jogo.partida();
                        break;
                    }
                    else
                    {
                        std::cout << "Opção inválida. Tente novamente." << std::endl;
                    }
                }
                catch (const std::runtime_error &e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
            break;
        }

        case 4:
        {
            limpar_terminal();
            int opcao;
            Jogador jogador3("jogador", "jog");

            std::cout << "Escolha uma opção de tamanho do tabuleiro:" << std::endl;
            std::cout << "1. Facil (6 x 6 e 10 bombas)" << std::endl;
            std::cout << "2. Medio (15 x 15 e 50 bombas)" << std::endl;
            std::cout << "3. Dificil (24 x 24 e 95 bombas)" << std::endl;
            std::cout << "4. Extremo (30 x 30 e 150 bombas)" << std::endl;
            std::cout << "5. Personalizado" << std::endl;
            start_case_4:
            std::cin >> opcao;

            CampoMinado *jogo = nullptr;

            try
            {
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Entrada invalida. Escolha uma opcao de 1 a 5.");
                }
                else
                {
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
                        int linhas, colunas, bombas;
                        limpar_terminal();
                        std::cout << "O tamanho minimo do tabuleiro e 4 x 4 e maximo 30 x 30" << std::endl;
                        start_personalizado:
                        std::cout << "Digite as dimensoes e o numero de bombas desejadas: ";
                        std::cin >> linhas >> colunas >> bombas;
                        try
                        {
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw std::invalid_argument("Entrada invalida. Digite tres numeros inteiros.");
                            }
                            else
                            {
                                jogo = new CampoMinado(linhas, colunas, jogador3, bombas);
                                break;
                            }
                        }
                        catch (const std::exception &e)
                        {
                            std::cerr << e.what() << '\n';
                            goto start_personalizado;
                        }

                    default:
                        throw std::invalid_argument("Opção invalida. Escolha uma opcao de 1 a 5.");
                    }

                    jogo->partida();
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                goto start_case_4;
            }
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


