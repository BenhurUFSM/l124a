# l124a

Disciplina de Laboratório de Programação I, 1° semestre de 2024
ELC1065 DLSC/CT/UFSM\
professor: Benhur Stein ([benhur+l124a@inf.ufsm.br](mailto:benhur%2bl124a@inf.ufsm.br))\
monitor: Leandro Nascimento [lonascimento@inf.ufsm.br](mailto:lonascimento@inf.ufsm.br))\
terças e quintas, 14h30\
sala 334, prédio 7 (principal do CT)\

## Exame: 20 de agosto de 2024, 14h30min, sala 376, anexo B do CT

Alunos em exame:
| Nome | Média |
| :--- | ---: |
| Anthony Colombelli Pereira | 5 |
| Leandro Ribeiro Pereira | 5 |

## Desenvolvimento da disciplina

Os canais de comunicação entre o professor e os alunos são:
- as aulas presenciais,
- esta página (<https://github.com/BenhurUFSM/l124a>),
- e-mail (ver endereço acima),
- conversa individual, manda um mail que marcamos.

O e-mail pode ser usado para o envio de perguntas, exercícios, reclamações, sugestões, críticas e o que mais for, durante todo o período em que durar a disciplina.

Esta página concentrará os assuntos vistos em aula, a descrição de exercícios e trabalhos, avaliações, etc. Ela será atualizada durante todo o semestre. Ela é o canal oficial de informações sobre a disciplina. Todos os alunos devem olhar o que está aqui periodicamente (recomendo habilitar notificações no github).

O objetivo da disciplina, aprender a programar computadores, envolve conceitos que podem levar um tempo razoável para serem adquiridos.
A disciplina é bastante prática, e exige que os alunos se dediquem bastante e desenvolvam trabalhos práticos.
É necessário dedicar um bom tempo à disciplina, além do tempo em aula. 
Use os canais de comunicação com o professor para sanar dúvidas.
Compartilhe dúvidas e dicas com os colegas (mas não copie trabalhos).

**Não deixe as dúvidas acumularem**.

Para realizar as práticas, é necessário acesso a um computador e a um ambiente de desenvolvimento de programas, com (pelo menos) um editor de textos e um compilador da linguagem 'C'.
A universidade dispõe de laboratórios com computadores para acesso aos alunos, com todo o software necessário instalado; consulte o [NCC](http://ncc.inf.ufsm.br/).

Existem ambientes de programação gratuitos online, como replit e onlineGDB. Os exercícios e trabalhos iniciais da disciplina podem ser desenvolvidos nesses ambientes, mas geralmente é menos confortável que usar ferramentas instaladas localmente.

Os trabalhos serão avaliados em um ambiente linux, usando o compilador `gcc`. Os programas entregues pelos alunos devem compilar e executar corretamente nesse ambiente.

A principal forma de avaliação dos alunos será através do desenvolvimento de pequenos programas de computador, a serem enviados para o professor. O trabalho final do semestre será um pouco mais complexo.
A descrição desses trabalhos, bem como a forma e data de entrega dos mesmos será disponibilizada nesta página.

Os trabalhos entregues não serão imediatamente pontuados, mas comentados de forma individual ou coletiva.
Espera-se que esses comentários sejam aproveitados para gerar novas e melhores versões dos programas, como forma de aprendizagem. 
Os programas podem ser alterados e reenviados ao professor, caso restem dúvidas.

A avaliação será realizada no final do semestre. Para isso, cada aluno deverá entregar a versão final de um subconjunto dos trabalhos (a ser definido), juntamente com uma auto-avaliação descrevendo o seu desenvolvimento durante o semestre, contendo uma sugestão de nota.
Cada aluno será entrevistado individualmente pelo professor. A nota final será então calculada, considerando:
- o estado de cada trabalho na data definida de entrega
- a versão final dos trabalhos
- a auto-avaliação
- a entrevista.

Para quem não alcançar a nota suficiente (7), haverá uma prova escrita de recuperação (chamada exame).

##  Aulas 

Os assuntos vistos em aula serão listados aqui.

|    N |   data | assunto
| ---: | -----: | :--------
|    1 |  12mar | apresentação, [introdução](Aulas/01.md)
|    2 |  14mar | [meu primeiro programa C](Aulas/02.md)
|    3 |  19mar | [meu primeiro programa C, cont.](Aulas/03.md)
|    4 |  21mar | [não aguento mais o meu primeiro programa C!](Aulas/04.md)
|    5 |  26mar | [saída de dados com printf](Aulas/05.md)
|    6 |  28mar | [entrada de dados com scanf](Aulas/06.md)
|    7 |   2abr | [comandos de seleção](Aulas/07.md)
|    8 |   4abr | [comandos de repetição](Aulas/08.md)
|    9 |   9abr | [como é o *for* mesmo?](Aulas/09.md)
|   10 |  11abr | [exercícios de repetição](Aulas/10.md)
|   11 |  16abr | mais exercícios de repetição
|   12 |  18abr | [vetores](Aulas/12.md)
|   13 |  23abr | [vetores como argumentos](Aulas/13.md)
|   14 |  25abr | [strings](Aulas/14.md)
|   15 |  30abr | Exercícios. Mais exercícios em [15](Aulas/15.md)
|   16 |  21mai | [matrizes](Aulas/16.md)
|   17 |  23mai | conversa sobre o t2 (ver abaixo)
|   18 |  28mai | conversa sobre o t2
|   19 |   4jun | [referências (ponteiros)](Aulas/19.md), tela gráfica no t2
|   20 |   6jun | [registros (*struct*)](Aulas/20.md)
|   21 |  11jun | [arquivos](Aulas/21.md)
|   22 |  13jun | [alocação dinâmica](Aulas/22.md)
|   23 |  18jun | conversa sobre o t3
|   24 |  20jun | conversa sobre dúvidas
|   25 |  25jun | conversa sobre dúvidas
|   26 |  27jun | conversa sobre dúvidas

Os principais conceitos que serão tratados na disciplina são:
- tipos básicos de dados (char, int, bool, float, etc)
- variáveis
- entrada e saída no terminal (scanf, printf)
- seleção (if, switch)
- laços (for, while, do-while)
- funções (modularização, passagem de parâmetros por valor e referência)
- vetores, strings, matrizes
- registros
- arquivos
- alocação dinâmica de memória


## Exercícios, trabalhos

A descrição dos trabalhos a entregar será colocada abaixo.

|     N |     prazo | descrição
| ----: | --------: | :-----------
|     1 | 4abr, <12h | [t1](Trabalhos/t1.md)
|     2 | 18jun, <12h | [jogo da velha](Trabalhos/t2)
|     3 |           | [sudoku](Trabalhos/t3)
| final | 9jul a 7ago | [entrega final](final.md)

## Notas

As avaliações e outras anotações individuais serão colocadas na [planilha](https://docs.google.com/spreadsheets/d/1rBIFTQvJx1bCjZ6LBQj0zh5WYruM7zAq6GmSyVYW_zI/edit?usp=sharing).

## Ementa

Ver no [ementário](https://www.ufsm.br/ementario/disciplinas/ELC1065/).


## Material Auxiliar

[Apostila de C da UFPR](http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula.pdf)

[Apostila de programação da UFPR](https://www.inf.ufpr.br/marcos/livro_alg1/livro_alg1.pdf)

Capítulos iniciais do livro "Introdução a Estruturas de Dados - Com Técnicas de Programação em C - Waldemar Celes".
Esse livro está disponível no [minha biblioteca](https://www.ufsm.br/orgaos-suplementares/biblioteca/e-books-2/), acessível aos alunos da UFSM.

Ajude o robozinho a iluminar o mundo (ajuda no desenvolvimento de lógica de programação, fundamental para o conteúdo da disciplina) [lightbot](http://lightbot.com).

Ajude o passarinho a detonar o porco (semelhante ao anterior) [code.org](http://studio.code.org/hoc/1)

Os grupos PET geralmente oferecem tópicos de apoio a disciplinas iniciais.

