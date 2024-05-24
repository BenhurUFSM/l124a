#include "tela.h"

// A maior parte das funções é implementada enviando sequências especiais
// de caracteres para controlar o funcionamento do terminal.
// Essas sequências são conhecidas como sequências de escape ANSI. Pode
// encontrar uma descrição delas (e de uma enormidade de outras) em
//   https://en.wikipedia.org/wiki/ANSI_escape_code


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// alguns includes incomuns, para acesso a funções incomuns de controle
// de baixo nível de terminal
#include <sys/ioctl.h>
#include <fcntl.h>

// o "static" na declaração de uma função faz com que ela seja invisível
// a código que esteja em outros arquivos
static void tela_altera_modo_saida(void)
{
  // faz com que os caracteres impressos sejam enviados para uma
  // região de memória antes de serem enviados à tela. Isso melhora
  // a qualidade de apresentação na tela
  setbuf(stdout, malloc(BUFSIZ));
}

void tela_mostra_cursor(bool mostra)
{
  if (mostra) {
    printf("%c[?25h", 27);
  } else {
    printf("%c[?25l", 27);
  }
}

static void tela_seleciona_tela_alternativa(bool alt)
{
  if (alt) {
    printf("%c[?1049h", 27);
  } else {
    printf("%c[?1049l", 27);
  }
}

void tela_ini(void)
{
  tela_altera_modo_saida();
  tela_seleciona_tela_alternativa(true);
  tela_limpa();
  //tela_mostra_cursor(false);
}

void tela_fim(void)
{
  tela_limpa();
  tela_seleciona_tela_alternativa(false);
  tela_mostra_cursor(true);
}

void tela_atualiza(void)
{
  // envia os dados de saída memorizados para a tela
  fflush(stdout);
}

void tela_limpa(void)
{
  printf("%c[2J", 27);
  tela_lincol(1, 1);
}

void tela_lincol(int lin, int col)
{
  printf("%c[%d;%dH", 27, lin, col);
}

void tela_cor_normal(void)
{
  printf("%c[m", 27);
}

void tela_cor_letra(int vermelho, int verde, int azul)
{
  printf("%c[38;2;%d;%d;%dm", 27, vermelho, verde, azul);
}

void tela_cor_fundo(int vermelho, int verde, int azul)
{
  printf("%c[48;2;%d;%d;%dm", 27, vermelho, verde, azul);
}
