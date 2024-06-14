## t3 — sudoku

***Esta descrição está incompleta; falta também a nova versão de telag***

Você deve implementar um programa que permita jogar sudoku, conforme descrito a seguir.

O programa deve propor um jogo ao usuário, permitir que ele jogue ou abandone, manter as melhores pontuações, oferecer para jogar novamente.

O jogo proposto deve ser uma das várias combinações de tabuleiro iniciais mantidas em um arquivo.

O programa deve ser implementado usando as funções descritas em telag2.h, que necessitam a biblioteca allegro.

### Como funciona o sudoku

[Sudoku](https://pt.wikipedia.org/wiki/Sudoku) é jogado em um tabuleiro de 3x3 regiões, cada uma dividida em 3x3 casas, totalizando 81 casas dispostas em um quadrado 9x9.
O objetivo é preencher todas as casas com números de 1 a 9, de forma que em cada região, cada linha e cada coluna não tenha número repetido.
No início do jogo, algumas casas já estão preenchidas, e o jogador deve preencher as demais sem violar as regras de não repetição de números.
Só existe uma solução válida.

### Como deve funcionar a interface com o jogador

O tabuleiro deve ser desenhado na tela, e permitir interações pelo jogador como descrito abaixo.

Cada casa do tabuleiro pode conter uma das possibilidades a seguir:
- um número inicial - o valor dessa casa não pode ser alterado
- um número escolhido pelo jogador
- 9 marcadores, cada um podendo estar ligado ou desligado.

No início de uma partida, o tabuleiro é iniciado com um conjunto de casas preenchidas, lidas a partir de um arquivo, em formato descrito adiante.
As demais casas são marcadas como não preenchidas (contendo 9 marcações desligadas).
O jogador pode, a cada jogada, alterar o valor em uma casa das que não tenham sido preenchidas no início:
- uma casa que tenha marcações pode ter uma marcação trocada;
- uma casa que tenha marcações pode ter um número escolhido;
- uma casa que contenha um número pode ter esse número alterado ou apagado (nesse último caso, volta a ser uma casa de marcações).

Só deve ser permitido colocar um número ou alterar um número de uma casa se não for violada a regra de número repetido.

A jogada é realizada com uso do mouse, usando a rodela de rolagem e dois botões de clique:
- tem um valor associado à próxima jogada (1 a 9 ou nulo); esse valor pode ser alterado pela rodela de rolagem do mouse
- se for clicado o primeiro botão, o valor é colocado na casa onde está o mouse, ou retirado o valor dessa casa caso o valor colocado seja nulo
- se for clicado o segundo botão e não tenha valor na casa clicada, a marcação correspondente ao valor é ligada se estiver desligada ou desligada se tiver ligada; se o valor for nulo, todas as marcações da casa são desligadas.

Se a jogada não for possível, deve ser informado o motivo.

Deve existir uma região da tela onde o jogador pode clicar para desistir do jogo.

Caso tenha restrições de hardware, os cliques ou rolagem podem ser diferenciados por teclas modificadoras (shift, control).

O teclado também deve poder ser usado: teclas de 0 a 9 alteram o valor da próxima jogada.

Caso queira, pode ser feita uma interface completa de teclado, com teclas para alterar a casa corrente, para jogar o valor atual e para realizar marcação.

### Final de uma partida

Uma partida termina se for cancelada pelo jogador (após confirmação) ou se o tabuleiro for completamente preenchido.

### Formato do arquivo de tabuleiros

### Formato de arquivo de pontuações 

### Cálculo de pontos
