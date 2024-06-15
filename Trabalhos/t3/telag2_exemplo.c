// Programa de exemplo de uso de telag.h e telag.c
//
// Necessita os arquivos telag_exemplo.c (este), telag.h, telag.c e DejaVuSans.ttf
// Necessita ter instalado a biblioteca allegro5
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o exemplo telag_exemplo.c telag.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
//

#include "telag.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// cria algumas cores globais
cor_t fucsia = { 1, 0.2, 0.8, 1 };
cor_t transparente = { 0, 0, 0, 0 };
cor_t branco = { 1, 1, 1, 1 };
cor_t vermelho = { 1, 0, 0, 1 };
cor_t amarelo = { 0.1, 0.6, 0.6, 1 };

// alguns valores constantes globais
tamanho_t tam_tela = { 500, 500 };
retangulo_t contorno_tela = {{ 30, 30 }, { 440, 440 }};

// funções auxiliares
float tira_sinal(float x) { return x < 0 ? -x : x; }

int aleatorio_entre(int minimo, int maximo)
{
  return minimo + rand() % (maximo - minimo); 

}

float zeroaum(float v)
{
  v = tira_sinal(v);
  return v - (int)v;
}

ponto_t pos_aleatoria()
{
  ponto_t pos;
  pos.x = aleatorio_entre(50, 450);
  pos.y = aleatorio_entre(50, 450);
  return pos;
}

// o estado do jogo
typedef struct {
  char tecla;
  int pontos;
  ponto_t alvo;
  double data_inicio;
  double tempo_de_jogo;
  enum { nada, rainho, raiao } raio;
  rato_t rato;
  bool terminou;
} jogo_t;

// funções que processam entradas
void processa_tempo(jogo_t *j)
{
  // termina depois de alguns segundos
  j->tempo_de_jogo = tela_relogio() - j->data_inicio;
  if (j->tempo_de_jogo >= 30) j->terminou = true;
}

void processa_teclado(jogo_t *j)
{
  // altera tec caso tenha sido digitado algo
  char c = tela_tecla();
  if (c != 0) j->tecla = c;
}

void processa_mouse(jogo_t *j)
{
  // obtem estado do rato
  j->rato = tela_rato();
  if (j->rato.clicado[0]) {
    j->raio = raiao;
    // vê se a linha do mouse passa perto do alvo
    float dx = ((float)j->rato.posicao.x - contorno_tela.inicio.x)
             / ((float)j->alvo.x - contorno_tela.inicio.x);
    float dy = ((float)j->rato.posicao.y - contorno_tela.inicio.y)
             / ((float)j->alvo.y - contorno_tela.inicio.y);
    if (dx >= 1 && dy >= 1 && tira_sinal(dx / dy - 1) < 0.01) {
      // acertou! calcula quantidade de pontos e muda alvo de lugar
      j->pontos += aleatorio_entre(1, 5);
      j->alvo = pos_aleatoria();
    }
  } else if (j->rato.apertado[0]) {
    j->raio = rainho;
  } else {
    j->raio = nada;
  }

}


void desenha_tela(jogo_t *j)
{
  // desenha um contorno
  tela_retangulo(contorno_tela, 5, fucsia, transparente);

  // desenha um cursor na posição do mouse
  circulo_t cursor = { j->rato.posicao, 5 };
  cor_t cor_cursor = {
    zeroaum(j->tempo_de_jogo * 5),
    zeroaum(j->tempo_de_jogo * 3),
    zeroaum(j->tempo_de_jogo),
    1
  };
  tela_circulo(cursor, 3, cor_cursor, branco);

  // desenha um raio se for o caso
  switch (j->raio) {
    case nada:
      break;
    case rainho:
      tela_linha(contorno_tela.inicio, j->rato.posicao, 1, branco);
      break;
    case raiao:
      tela_linha(contorno_tela.inicio, j->rato.posicao, 5, vermelho);
      break;
  }

  // desenha o alvo
  char txt[100];
  sprintf(txt, "%c%c%c", j->tecla, j->tecla, j->tecla);
  retangulo_t ret_txt = tela_texto_contorno(j->alvo, 20, txt);
  ponto_t pos_txt = j->alvo;
  // ajusta para o texto ficar no centro do alvo
  pos_txt.x -= ret_txt.tamanho.largura / 2;
  pos_txt.y += 5;
  ret_txt.inicio.x -= ret_txt.tamanho.largura / 2;
  ret_txt.inicio.y += 5;
  tela_retangulo(ret_txt, 1, vermelho, transparente);
  tela_texto(pos_txt, 20, amarelo, txt);
  // desenha linhas cruzando o alvo
  ponto_t l1p1 = { 0, j->alvo.y };
  ponto_t l1p2 = { 499, j->alvo.y };
  ponto_t l2p1 = { j->alvo.x, 0 };
  ponto_t l2p2 = { j->alvo.x, 499 };
  tela_linha(l1p1, l1p2, 1, fucsia);
  tela_linha(l2p1, l2p2, 1, fucsia);
  sprintf(txt, "%d", j->pontos);
  ponto_t pos_pontos = { 50, 430 };
  tela_texto(pos_pontos, 20, branco, txt);

  // faz aparecer na tela o que foi desenhado
  tela_atualiza();
}


// A função principal
int main(void)
{
  // inicializa gerador de números aleatórios
  srand(time(NULL));

  // inicializa a tela gráfica
  tela_inicio(tam_tela, "exemplo");

  // cria e inicializa o descritor do jogo
  jogo_t jogo;

  jogo.tecla = 'x';
  jogo.pontos = 0;
  jogo.alvo = pos_aleatoria();
  jogo.data_inicio = tela_relogio();
  jogo.terminou = false;

  // laço principal
  while (!jogo.terminou) {
    processa_tempo(&jogo);
    processa_teclado(&jogo);
    processa_mouse(&jogo);
    desenha_tela(&jogo);
  }

  // encerra a tela gráfica
  tela_fim();
}
