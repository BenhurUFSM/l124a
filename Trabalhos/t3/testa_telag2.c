// Programa de exemplo de uso de telag2.h e telag2.c
//
// Necessita os arquivos testa_telag2.c (este), telag2.h, telag2.c e DejaVuSans.ttf
// Necessita ter instalado a biblioteca allegro5
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o teste testa_telag2.c telag2.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
// para executar:
// ./teste
//

#include "telag2.h"

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

ponto_t posicao_aleatoria()
{
  ponto_t pos;
  pos.x = aleatorio_entre(50, 450);
  pos.y = aleatorio_entre(50, 450);
  return pos;
}

// o estado do jogo
typedef struct {
  // constantes, devem ser inicializadas antes da tela
  tamanho_t tamanho_tela;
  retangulo_t contorno_tela;
  // necessários no início de cada partida
  char tecla;
  int pontos;
  ponto_t alvo;
  double data_inicio;
  bool terminou;
  // não precisam de estado inicial
  double tempo_de_jogo;
  enum { nada, rainho, raiao } raio;
  rato_t rato;
  cor_t cor_contorno;
} jogo_t;

// inicializa estado do jogo
void inicializa_jogo(jogo_t *j)
{
  j->tecla = 'x';
  j->pontos = 0;
  j->alvo = posicao_aleatoria();
  j->data_inicio = tela_relogio();
  j->terminou = false;
}

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

  j->cor_contorno = fucsia;
  if (tela_shift()) { j->cor_contorno.verde = 0.8; }
  if (tela_control()) { j->cor_contorno.azul = 0.4; }
}

void processa_mouse(jogo_t *j)
{
  // obtem estado do rato
  j->rato = tela_rato();
  if (j->rato.clicado[0]) {
    j->raio = raiao;
    // vê se a linha do mouse passa perto do alvo
    float dx = ((float)j->rato.posicao.x - j->contorno_tela.inicio.x)
             / ((float)j->alvo.x - j->contorno_tela.inicio.x);
    float dy = ((float)j->rato.posicao.y - j->contorno_tela.inicio.y)
             / ((float)j->alvo.y - j->contorno_tela.inicio.y);
    if (dx >= 1 && dy >= 1 && tira_sinal(dx / dy - 1) < 0.01) {
      // acertou! calcula quantidade de pontos e muda alvo de lugar
      j->pontos += aleatorio_entre(1, 5);
      j->alvo = posicao_aleatoria();
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
  tela_retangulo(j->contorno_tela, 5, j->cor_contorno, transparente);

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
      tela_linha(j->contorno_tela.inicio, j->rato.posicao, 1, branco);
      break;
    case raiao:
      tela_linha(j->contorno_tela.inicio, j->rato.posicao, 5, vermelho);
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

void desenha_tela_final(jogo_t *j)
{
  char txt[100];
  sprintf(txt, "pts: %d", j->pontos);
  ponto_t pos_pontos, pos_enter;
  double t_pos = 0;
  do {
    if (tela_relogio() - t_pos > 1) {
      pos_pontos = posicao_aleatoria();
      pos_enter = posicao_aleatoria();
      t_pos = tela_relogio();
    }
    tela_texto(pos_pontos, 40, branco, txt);
    tela_texto(pos_enter, 15, amarelo, "tecle «enter»");
    tela_atualiza();
  } while (tela_tecla() != '\n');
}

// A função principal
int main(void)
{
  // inicializa gerador de números aleatórios
  srand(time(NULL));

  // cria e inicializa o descritor do jogo
  jogo_t jogo;

  jogo.tamanho_tela = (tamanho_t){ 500, 500 };
  jogo.contorno_tela = (retangulo_t){{ 30, 30 }, { 440, 440 }};

  // inicializa a tela gráfica
  tela_inicio(jogo.tamanho_tela, "exemplo");

  inicializa_jogo(&jogo);

  // laço principal
  while (!jogo.terminou) {
    processa_tempo(&jogo);
    processa_teclado(&jogo);
    processa_mouse(&jogo);
    desenha_tela(&jogo);
  }

  desenha_tela_final(&jogo);

  // encerra a tela gráfica
  tela_fim();
}
