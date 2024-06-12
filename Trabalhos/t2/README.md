## Trabalho 2 - Jogo da velha

### Parte I

Os arquivos tela.h e tela.c contêm funções para controle da tela.
Os arquivos tecla.h e tecla.c contêm funções para o controle do teclado.

O arquivo testa.c contém um programa para demonstrar o uso das funções definidas nesses arquivos. No início desse arquivo tem instruções de como compilá-lo.

Sua tarefa é entender o programa em testa.c, e entender o que fazem as funções de tela e de tecla. Não precisa entender como funcionam as funções de tela e tecla, somente o que elas fazem. Nem precisa olhar os arquivos tela.c e tecla.c (mas precisa olhar tela.h e tecla.h (e certamente testa.c)).

Essa parte não tem muito a ver com o jogo da velha.

### Parte II

A estrutura geral do programa será semelhante à do programa exemplo, e **deve conter**:
- inicialização de variáveis que representam o estado do jogo
- inicialização do programa
- laço principal, onde uma partida é jogada
- finalização do programa

Entre as variáveis que representam o estado, deve estar alguma que indica que a partida terminou, e que o laço deve encerrar. Essa variável controla a repetição do laço.

A forma de jogar vai ser assim:
- o jogo é realizado entre 2 jogadores que se alternam nas jogadas. O programa não joga, só permite que os usuários joguem.
- tem o jogador corrente, aquele que irá realizar a próxima jogada. Esse jogador muda após cada jogada.
- tem uma posição selecionada no tabuleiro. O jogador pode alterar essa posição usando o teclado, e pode realizar sua jogada nessa posição.
- o programa identifica quando tem um vencedor, ou quando não se pode mais jogar por estar cheio o tabuleiro.

No caso do jogo da velha, o estado é composto por, pelo menos,
- o tabuleiro, uma matriz com o valor de cada posição que pode receber uma "peça". Esses valores podem ser `X`, `O` ou espaço, para representar a peça de cada jogador ou um espaço ainda não ocupado.
- a identificação do próximo jogador.
- a posição da jogada.
- informação se a partida terminou e quem ganhou.
  
O laço principal **deve conter**:
- alterações do estado à partir de entradas
- alterações do estado independentes das entradas
- desenho da tela à partir do estado

Para facilitar a implementação e modularizar melhor o programa, toda a saída deve ser concentrada na parte de desenho, e essa parte não deve alterar nenhuma das variáveis que representam o estado do jogo.

As entradas possíveis são:
- 4 teclas para alterar a posição atual, uma para cada direção
- uma tecla para dizer que o jogador deseja jogar na posição atual

O processamento da entrada consiste, dependendo da tecla lida, em:
- alterar a posição corrente, se possível, na direção correspondente à tecla
- colocar a identificação do jogador atual na posição corrente, se possível, para a tecla de jogada. Caso seja realizada a jogada, alterar o jogador corrente.

As alterações independentes da entrada consiste em alterar o estado de término à partir da análise do tabuleiro.

O desenho da tela deve colocar na tela, pelo menos, a identificação do jogador corrente e o desenho do conteúdo do tabuleiro, com a posição corrente em destaque.

Deve haver no programa um comentário indicando o início de cada uma das 4 seções da estrutura geral e das 3 seções do laço principal (marcados com **deve conter** no texto acima).

O programa deve usar as funções de tela.h+tecla.h ou de telag.h. O programa testa.c contém um programa simples para exemplificar o uso das funções em tela.h+tecla.h, com um comentário no início de como compilar. Idem para o programa testag.c em relação à telag.h.
