# **TRABALHO FINAL - PDSII**
Este projeto implementa quatro jogos de tabuleiro, oferecendo uma oportunidade de reviver a nostalgia de jogos clássicos que, sem dúvida, fazem parte das lembranças de infância de muitas pessoas.

Segue abaixo uma breve explicação sobre cada um dos 4 jogos desenvolvidos: 

- **Jogo da Velha** : Dois jogadores competem para alinhar três símbolos em um tabuleiro 3x3.
  
- **Lig4** : Trata-se de um jogo de estratégia em que dois jogadores disputam na tentativa de alinhar quatro peças consecutivas em um tabuleiro, seja na vertical, horizontal ou diagonal.
  
- **Reversi** : Uma disputa entre dois jogadores, cada um com inicialmente 2 peças. O objetivo aqui é realizar movimentos que capturem as peças dos oponentes, vencendo quem possuir maior quantidade ao final.
  
- **Campo Minado** : Aqui temos um jogo de lógica em que o objetivo é revelar todas as casas de um tabuleiro que não possuem bombas. Apesar do trabalho lógico, em certo ponto, envolve a "sorte" do jogador.

**A partir dessa breve introdução, segue abaixo um sumário dos principais tópicos desenvolvidos ao longo desse arquivo README. Atenção, atente-se aos processos de compilação e execução do projeto!**

---

# Sumário
#### 1. Compreendendo o Trabalho 

#### 2. Processo Criativo

#### 3. Soluções Adotadas

#### 4. Armazenamento de Jogadores

#### 5. Projetos Extras

#### 6. Execução do Código

---

# 1. Compreendendo o Trabalho

#### Podemos então iniciar uma explicação básica e rápida sobre pontos chaves a serem tratados nesse projeto :

Primeiro passo é a formação de um grupo, que por conseguinte ficará responsável por decidir e alocar, por si só, uma estratégia para realização do trabalho final.

Em relação ao trabalho, podemos dividi-lo em 2 partes: requisitos mínimos/obrigatórios e implementações extras.

Como **requisitos mínimos**, devemos implementar os jogos Lig4(Connect 4) e Reversi, cujas introduções foram expostas no início desse documento.

O projeto deverá trabalhar a hierarquia de classes, em especial uma classe tabuleiro geral. 

É necessário construir um "CRUD" para os jogadores, com algumas funções básicas, como cadastro, exclusão e vizualição das informações dos jogadores. Além disso, as informações dos players devem ser salvas, independente do momento da execução, sendo necessário portanto um módulo para armazenamento de dados.

As tarefas extras abrem margem para a criatividade dos envolvidos.

O trabalho deve ser desenvolvido na linguagem C++, aplicando boas práticas de programação, sendo bem estruturado e documentado.

O GitHub é uma ferramenta essencial na realização do mesmo, visto as facilidades em relação ao versionamento dos códigos, sendo necessário a criação de um repositório.

---

# 2. Processo Criativo

A princípio, a primeira estratégia adotada pelo grupo foi desenvolver um jogo simples que pudesse ser utilizado como base para o desenvolvimentos dos demais jogos. Assim, o grupo se reuniu presencialmente e iniciou o desenvolvimento do Jogo Da Velha. 

A partir desse momento, desenvolvemos uma classe JogoDeTabuleiro que simboliza de forma geral algumas funções básicas que são utilizadas em todos os jogos (elas são modificadas para a especificidade de cada código).

Nesse mesmo dia, criamos um repositório no GitHub e começamos a dividir os afazeres. Cada um dos 3 membros do grupo estavam responsáveis por desenvolver um dos jogos de acordo com os atributos e requisitos definidos.

Assim, estavamos prontos para a criação de 3 jogos: finalização do Jogo da Velha, Reversi e Lig4. Definimos que os tabuleiros deveriam ter tamanhos variáveis (exceto Jogo da Velha). Em seguida, um dos membros se propôs a desenvolver o jogo Campo Minado.

De forma generalizada, o nosso processo criativo envolveu tanto a acessibilidade para o usuário (implementando cores no tabuleiro para facilitar a visualização e também barras laterais que contribuem na vizualição de linhas e colunas), quanto na busca por formas mais eficientes de coletar as entradas e realizar o tratamento de erros.

Definimos a nessecidade de algumas funções básicas em todos os códigos, como inicializar_tabuleiro, imprimir_tabuleiro, executar uma partida, limpar_terminal e checar_vitoria, por exemplo. 

Em cada jogo, utilizamos loops que verificam os estados atuais de cada posição no tabuleiro e calculam se um movimento é válido, se após algum movimento temos um vencedor e se ainda existem movimentos válidos.
Dessa forma, conseguimos definir o estado atual do tabuleiro e, por meio de funções que analisam os resultados, checar qual jogador saiu vitorioso.

No arquivo main foi criado um menu para seleção do jogos. Há que se destacar a criração de um outro menu interno que cuida do gerenciamento dos jogadores, além de um arquivo "CSV" para armazenamento de dados. 

Portanto, a main se restringe à seleção do modo de jogo e dos jogadores envolvidos, além de validar alguns inputs, enquanto a execução dos códigos está restrita à implementação individual de cada um.

---

# 3. Soluções Adotadas

Vamos destacar alguns pontos de cada jogo: 

### 1. No **Lig4**, o tabuleiro é representado por um vetor de vetores (_tabuleiro), que cria uma matriz dinâmica. 

O código usa "std::vector<std::vector< int >" para armazenar o estado do tabuleiro.

Na inicialização do construtor "Lig4(int linhas, int colunas, Jogador& jogador1, Jogador& jogador2)", o tabuleiro é redimensionado para o tamanho especificado usando "_tabuleiro.resize(_linhas, std::vector<int>(_colunas, 0));".

Ao adicionar uma peça ao tabuleiro, a posição é atualizada usando a notação de índice em vetores, como "_tabuleiro[_linhas - 1 - i][x - 1]".

O código analisa separadamente cada uma dás posições de vitória: vertical, horizontal, diagonal descendente e diagonal ascendente.

Para facilitar na execução da partida, o código a divide em várias partes, como apresentado acima, dando uma boa ideia da divisão de métodos usada.

### 2. No **Reversi**, podemos destacar alguns métodos que validam cada movimento: 

temMovimentosValidos(int jogador) verifica por meio de um loop se há ao menos uma casa no tabuleiro em que o movimento é valido. Caso exista, a função retorna True. Em caso negativo, retorna False, o jogador é alternado e novamente se verifica se há uma jogada válida para o novo player. Se houver, se alterna novamente o jogador, e a verificação continua até que não haja mais jogadas válidas para nenhum dos players.

No método Imprimir_Tabuleiro, é utilizado a biblioteca iomanip (setw) para garantir alinhamento e espaçamento consistentes entre linhas e colunas, foram utilizadas cores no tabuleiro para melhorar a visualização.
Há uma estrutura de repetição para percorrer e imprimir o conteúdo do tabuleiro, com lógica para diferenciar os tipos de movimentos e suas representações visuais.

Assim como no Lig4, temos no Reversi a separação de alguns métodos que são utilizados ao longo da execução do jogo e, por sua vez, acabam facilitando a modularização do código

### 3. No **CampoMinado**, podemos destacar a principio o método usado para a marcação de bombas: 

_tabuleiro[x - 1][y - 1] == 0: Se a posição está vazia (0), marca-se a posição com uma bomba (4), e incrementa-se o contador de bombas marcadas.

_tabuleiro[x - 1][y - 1] == 1: Se a posição contém um número (1), muda-se o valor para uma bomba alternativa (5), e incrementa-se o contador de bombas marcadas.

_tabuleiro[x - 1][y - 1] == 4: Se a posição já tem uma bomba marcada (4), remove-se a bomba (0), e decrementa-se o contador de bombas marcadas.

_tabuleiro[x - 1][y - 1] == 5: Se a posição contém uma bomba alternativa (5), muda-se o valor para o número (1), e decrementa-se o contador de bombas marcadas.

No método colocar_bomba, é utilizado um loop para verificar a quantidade de bombas colocadas e, por meio de duas funções rand(), são geradas coordenadas aleatórias em que as bombas são colocadas.

Já para o método bombas_em_volta, a solução consiste em utilizar dois loops aninhados para percorrer todas as casas adjacentes à posição alvo (x, y), verificando se cada casa está dentro dos limites do tabuleiro e se contém uma bomba. Se esses critérios forem atendidos, o contador de bombas adjacentes é incrementado. 

### Não foram gerados grandes problemas no JogoDaVelha, mas vale destacar a clareza do código. Foi um espelho para os demais que, obviamente, apresentam um nível de complexidade maior. 

---

# 4. Armazenamento de Jogadores

Utilizamos o arquivo de texto CSV para conseguir armazenar as informações dos jogadores. Utilizar o CSV frente a arquivos TXT é uma facilidade muito grande em relação à leitura e passagem de informações, visto que o arquivo é construído a partir de campos (que representam informações distintas) separado por linhas.

As alterações no CSV estão sendo implementadas dentro da classe Jogador.

As funções get e set são métodos que permitem acessar e modificar os atributos privados da classe Jogador. Esses métodos são importantes para encapsular os dados, garantindo que eles sejam manipulados de forma controlada.

---

A função get, por exemplo, é usada para recuperar alguns atributos privados, como: 

std::string Jogador::get_apelido() const - Retorna o apelido do jogador.

std::string Jogador::get_nome() const - Retorna o nome do jogador.

int Jogador::get_vitorias_jdv() const - Retorna o número de vitórias no Jogo da Velha.

int Jogador::get_derrotas_jdv() const - Retorna o número de derrotas no Jogo da Velha.

E assim por diante.

---

O set, por sua vez, é usada para manipular a contagem de vitorias e derrotas de cada player em cada jogo, como por exemplo:

void Jogador::soma_vitoria_jdv() - Incrementa o número de vitórias no Jogo da Velha.

void Jogador::soma_derrota_jdv() - Incrementa o número de derrotas no Jogo da Velha.

---

### Além disso, podemos destacar que dentro do classe jogador, são desenvolvidas funções que criam, removem, listam e vizualiam jogadores e sua informações, que também são atualizadas através dessa classe.

# 5. Projetos Extras

Como extras, podemos destacar as seguintes funcionalidades:

1.  Cores que facilitam a visualização do tabuleiro
   
2.  Orientação via numeração de linhas e colunas
   
3.  Tamanho de Tabuleiros variáveis, de acordo com a dinâmica de jogo desejada
   
4.  Criação dos jogos CampoMinado e JogoDaVelha
   
5.  Uso do CSV para manipulação dos dados

# 6. Execução do Código

# Instruções para Compilar e Executar o Programa

1. **Abra o Terminal**:
   - No Linux ou macOS, abra o Terminal.
   - No Windows, abra o Prompt de Comando ou o PowerShell. Se estiver usando o WSL, abra um terminal Linux.

2. **Navegue para o Diretório do Projeto**:
   ```bash
   cd /caminho/para/seu/projeto

3. **Comando "make"**

4. **Comando "./bin/main"**

5. **Seu código já deve estar em execução**

Observações:

Certifique-se de que o Makefile está corretamente configurado para gerar o executável no diretório ./bin.

Se você encontrar problemas, verifique as mensagens de erro no terminal e ajuste seu Makefile ou código conforme necessário.






