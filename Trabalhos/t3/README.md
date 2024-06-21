## t3 — sudoku

***Esta descrição pode ser complementada conforme surgirem dúvidas. Não chute uma interpretação, se tiver dúvida, pergunte.***

Você deve implementar um programa que permita jogar sudoku, conforme descrito a seguir.

O programa deve propor um jogo ao usuário, permitir que ele jogue ou abandone, manter as melhores pontuações, oferecer para jogar novamente.

O jogo proposto deve ser uma das várias combinações de tabuleiro iniciais mantidas em um arquivo.

O programa deve ser implementado usando as funções descritas em telag2.h (implementadas em telag2.c, exemplificadas em testa_telag2.c), que necessitam a biblioteca allegro.

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

### Início de uma partida

O programa deve sortear um dos tabuleiros do arquivo de tabuleiros para ser preenchido pelo jogador.

### Final de uma partida

Uma partida termina se for cancelada pelo jogador (após confirmação) ou se o tabuleiro for completamente preenchido.

Após o final da partida e apresentação de pontuação (se for o caso, veja abaixo), o programa deve oferecer a opção de jogar nova partida ou encerrar o programa.

### Registro de pontos

Ao final de uma partida não cancelada, os pontos finais dever ser apresentados ao usuário, juntamente com sua classificação no registro geral de pontuações. O programa deve também apresentar, pelo menos, os dados de pontuação imediatamente anterior e posterior (caso houver).

A pontuação deve ser acrescentada ao arquivo de registro de pontuação. A identificação do jogador (uma pequena string sem espaços) deve ser pedida no início da execução do programa. Use uma identificação default caso o usuário forneça uma identificação vazia.

O número de pontuações registradas pode ser qualquer, e as pontuações devem ser mantidas em um vetor de estruturas, cada estrutura contendo os dados de uma pontuação (identificação do jogador, identificação do tabuleiro e número de pontos). Esse vetor deve ser alocado dinamicamente.

A inexistência do arquivo de registro de pontos não deve ser considerada um erro.

Dica: leia o arquivo inteiro para um vetor no início do programa. Use as informações do vetor para apresentar ao usuário no final da partida. Altere o vetor no final da partida para incluir a nova pontuação. Grave o arquivo inteiro após a alteração. Dessa forma, só precisa de 2 funções que acessam o arquivo de pontuação: uma de leitura que só é usada uma vez no início e uma de escrita que é chamada a cada final de partida. A função de leitura, caso o arquivo não exista, deve criar um vetor vazio.

Outra forma de implementação, que não requer a realocação do vetor para incluir a nova pontuação é gravar o arquivo em 3 etapas: todas as pontuações do vetor menores que a da última partida, seguida da pontuação da última partida, seguida das demais pontuações do vetor. Então libera a memória do vetor e chama a função de leitura do arquivo, que irá criar novamente o vetor, com o novo tamanho encontrado no arquivo. Não precisa realocar, mas dá muito mais trabalho para o computador...

### Formato do arquivo de tabuleiros

A primeira linha do arquivo tem o número de tabuleiros que o arquivo contém.

Cada tabuleiro inicia com sua identificação (um número menor que 10000) e sua dificuldade (0-fácil, 1-médio, 2-difícil, 3-osco), seguido por 9 linhas de 9 números com o conteúdo inicial do tabuleiro (0 representa uma casa vazia).

O arquivo `tabuleiros` contém um conjunto de tabuleiros nesse formato.

### Formato de arquivo de pontuações 

A primeira linha contém o número de pontuações no arquivo.

Cada linha subsequente contém a identificação da pessoa, a identificação do tabuleiro e a pontuação. 
As linhas estão em ordem decrescente de pontuação.

O arquivo `recordes` contém um exemplo de um arquivo nesse formato.

### Cálculo de pontos

A pontuação de uma partida é calculada à partir da dificuldade do jogo (0 a 4) e do tempo (em segundos) usado para resolvê-lo, de acordo com a fórmula abaixo:
```
   1285 + 97418 × ( dificuldade + 1 ) ÷ tempo
```
