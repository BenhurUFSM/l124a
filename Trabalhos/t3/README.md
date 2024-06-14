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

### Como deve funcionar o programa

Cada casa do tabuleiro pode conter uma das possibilidades a seguir:
- um número inicial - o valor dessa casa não pode ser alterado
- um número escolhido pelo jogador
- entre 0 e 9 marcações.

No início de uma partida, o tabuleiro é iniciado com um conjunto de casas preenchidas, lidas a partir de um arquivo, em formato descrito adiante.
As demais casas são marcadas como não preenchidas (contendo 0 marcações).
O jogador pode, a cada jogada, alterar o valor em uma casa que não tenha sido previamente preenchida:
- uma casa que tenha marcações pode ter uma marcação trocada;
- uma casa que tenha marcações pode ter um número escolhido;
- uma casa que contenha um número pode ter esse número alterado ou apagado.

Só deve ser permitido colocar um número ou alterar um número de uma casa se não for violada a regra de número repetido.
