// Programa de exemplo de uso das funções de controle da tela (defindas
// em tela.h e implementadas em tela.c) e de tecla (definidas em tecla.h
// e implementadas em tecla.c)
//
// O programa implementa um jogo simples, em que o jogador deve fugir de
// um fantasma. O jogador pode alterar sua posição usando as teclas wasd,
// o fantasma se move sozinho, pingpongueando na tela.
//
// Sua tarefa é entender como o programa funciona
//
// Esse programa deve ser compilado juntamente com tela.c e tecla.c, que
// contêm as funções de controle de tela e tecla.
// Para isso, use o comando abaixo:
// 
//   gcc -o testa testa.c tela.c tecla.c

// inclui os arquivos que contêm as declarações das funções de controle da
// tela e teclas
#include "tela.h"
#include "tecla.h"

// demais includes para funções padrão usadas pelo programa
#include <stdio.h>
#include <stdlib.h>

// define valores constantes para os limites utilizáveis da tela
// (a janela do terminal deve ter pelo menos esse tamanho)
#define LIN_MAX 24
#define COL_MAX 79

// funções auxiliares

// desenha o contorno da tela
void desenha_contorno(void)
{
  // limpa a tela com a cor default
  tela_cor_normal();
  tela_limpa();
  // seleciona uma cor para a borda
  tela_cor_fundo(30, 70, 22);
  // desenha uma linha no topo da tela
  tela_lincol(1, 1);
  for (int i = 1; i <= COL_MAX; i++) {
    putchar(' ');
  }
  // desenha uma linha embaixo da tela
  tela_lincol(LIN_MAX, 1);
  for (int i = 1; i <= COL_MAX; i++) {
    putchar(' ');
  }
  // desenha uma linha em cada lado da tela
  for (int i = 2; i < LIN_MAX; i++) {
    tela_lincol(i, 1);
    putchar(' ');
    tela_lincol(i, COL_MAX);
    putchar(' ');
  }
  tela_cor_normal();
}

void desenha_jogador(int lin, int col)
{
  tela_cor_fundo(20, 50, 90);
  tela_lincol(lin, col);
  puts("¤");
}

void desenha_fantasma(int lin, int col)
{
  tela_cor_normal();
  tela_lincol(lin, col);
  puts("👻");
}

void anima_final(int pontos)
{
  for (int i = 1; i <= LIN_MAX; i++) {
    desenha_contorno();
    tela_lincol(LIN_MAX / 2 - 2, COL_MAX / 2 - 6);
    printf("PONTOS: %04d", pontos);
    if (tecla_le_char() == '\n') {
      break;
    }
    for (int j = i; j <= LIN_MAX; j++) {
      tela_cor_fundo(200 - 150 * i / LIN_MAX - 50 * j / LIN_MAX, 90, 30);
      tela_lincol(j, 1);
      for (int k = 1; k <= COL_MAX; k++) {
        putchar(' ');
      }
    }
    tela_atualiza();
  }
}

// a função principal

int main()
{
  // variáveis que compõem o estado do jogo
  // posição do jogador
  int lin_jogador = 10;
  int col_jogador = 30;
  // posição e velocidade do fantasma
  int lin_fanta = 2;
  int col_fanta = 2;
  int vel_fanta_x = 2;
  int vel_fanta_y = 1;
  // há quanto "tempo" está jogando
  int tempo_de_jogo = 0;
  // true se o jogo terminou
  bool fim = false;

  // inicializa a tela e as teclas
  tela_ini();
  tecla_ini();
  tela_mostra_cursor(false);

  // laço principal
  while (!fim) {
    // altera o estado do jogo de acordo com a entrada
    char c = tecla_le_char();
    if (c == 's') lin_jogador++;
    if (c == 'w') lin_jogador--;
    if (c == 'a') col_jogador--;
    if (c == 'd') col_jogador++;
    if (c == '\n') fim = true;

    // altera o estado do jogo de forma independente da entrada
    lin_fanta = lin_fanta + vel_fanta_y;
    col_fanta = col_fanta + vel_fanta_x;
    if (lin_fanta >= LIN_MAX - 1 || lin_fanta <= 2) vel_fanta_y = -vel_fanta_y;
    if (col_fanta >= COL_MAX - 1 || col_fanta <= 2) vel_fanta_x = -vel_fanta_x;
    tempo_de_jogo++;

    // verifica de atingiu condição de término do jogo
    if (tempo_de_jogo > 1000) {
      fim = true;
    }
    if((abs(lin_jogador - lin_fanta) + abs(col_jogador - col_fanta)) < 3) {
      fim = true;
    }

    // desenha a tela de acordo com o estado do jogo
    desenha_contorno();
    desenha_jogador(lin_jogador, col_jogador);
    desenha_fantasma(lin_fanta, col_fanta);
    tela_atualiza();
  }

  anima_final(tempo_de_jogo);

  // volta a tela e teclas para o estado normal
  tecla_fim();
  tela_fim();
}
