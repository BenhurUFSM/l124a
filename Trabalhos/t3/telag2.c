// inclui as definicoes
#include "telag2.h"
#include <stdio.h>
#include <assert.h>

// Os includes do allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

static void cai_fora(char *msg)
{
  int cai = 42;
  int fora = 42;
  fprintf(stderr, "\n\nERRO\n%s\n\n", msg);
  assert(cai-fora);
}

static void tela_inicializa_janela(tamanho_t tamanho, char nome[])
{
  // pede para tentar linhas mais suaves (multisampling)
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  // cria uma janela
  ALLEGRO_DISPLAY *janela = al_create_display(tamanho.largura, tamanho.altura);
  if (janela == NULL) {
    cai_fora("problema na criação de janela do allegro");
  }
  // esconde o cursor do mouse
  al_hide_mouse_cursor(janela);
  al_set_window_title(janela, nome);
}

static ALLEGRO_COLOR conv_cor(cor_t cor)
{
  return (ALLEGRO_COLOR){cor.vermelho, cor.verde, cor.azul, cor.opacidade};
}

// fila para receber os eventos do teclado
static ALLEGRO_EVENT_QUEUE *tela_eventos_teclado;
static void tela_inicializa_teclado(void)
{
  if (!al_install_keyboard()) {
    cai_fora("problema na inicialização do teclado do allegro");
  }
  // cria e inicializa a fila de eventos do teclado
  tela_eventos_teclado = al_create_event_queue();
  if (tela_eventos_teclado == NULL) {
    cai_fora("problema na criação da fila de eventos do teclado do allegro");
  }
  al_register_event_source(tela_eventos_teclado,
                           al_get_keyboard_event_source());
}

void tela_inicio(tamanho_t tamanho, char nome[])
{
  // inicializa os subsistemas do allegro
  if (!al_init()) cai_fora("problema na inicialização do allegro");
  if (!al_install_mouse()) cai_fora("problema na inicialização do mouse do allegro");
  if (!al_init_primitives_addon()) cai_fora("problema na inicialização de addons do allegro");
  al_init_font_addon();
  if (!al_init_ttf_addon()) cai_fora("problema na inicialização do addon de fontes ttf");

  // inicializa a tela
  tela_inicializa_janela(tamanho, nome);
  tela_inicializa_teclado();
}


void tela_fim(void)
{
  // badabum!
  al_uninstall_system();
}

void tela_atualiza(void)
{
  static double tempo_ultima_tela = 0;
  double agora = tela_relogio();
  double quando_mostrar = tempo_ultima_tela + SEGUNDOS_POR_QUADRO;
  double tempo_ate_mostrar = quando_mostrar - agora;
  if (tempo_ate_mostrar > 0) {
    // é muito cedo, dá uma cochilada
    al_rest(tempo_ate_mostrar);
  }
  // troca a tela mostrada pela que foi desenhada em memória
  al_flip_display();
  tempo_ultima_tela = tela_relogio();

  // limpa todo o canvas em memória, para desenhar a próxima tela
  cor_t preto = { 0, 0, 0, 1 };
  al_clear_to_color(conv_cor(preto));
}


void tela_circulo(circulo_t circulo, float largura, cor_t cor_linha, cor_t cor_interna)
{
  // preenche
  al_draw_filled_circle(circulo.centro.x, circulo.centro.y, circulo.raio,
                        conv_cor(cor_interna));
  // faz o contorno
  al_draw_circle(circulo.centro.x, circulo.centro.y, circulo.raio,
                 conv_cor(cor_linha), largura);
}

void tela_linha(ponto_t inicio, ponto_t fim, float largura, cor_t cor_linha)
{
  al_draw_line(inicio.x, inicio.y, fim.x, fim.y, conv_cor(cor_linha), largura);
}

void tela_retangulo(retangulo_t retangulo, float largura,
                    cor_t cor_linha, cor_t cor_interna)
{
  int x1 = retangulo.inicio.x;
  int y1 = retangulo.inicio.y;
  int x2 = retangulo.inicio.x + retangulo.tamanho.largura;
  int y2 = retangulo.inicio.y + retangulo.tamanho.altura;
  al_draw_filled_rectangle(x1, y1, x2, y2, conv_cor(cor_interna));
  al_draw_rectangle(x1, y1, x2, y2, conv_cor(cor_linha), largura);
}

// retorna uma fonte com o tamanho pedido
#define N_FONTES 5  // número de fontes a guardar
static int soma_indice(int indice, int soma)
{
  return (indice + soma + N_FONTES) % N_FONTES;
}
static ALLEGRO_FONT *tela_fonte(int tam)
{
  static struct {
    int tamanho;
    ALLEGRO_FONT *fonte;
  } fontes[N_FONTES];
  static int prox_indice = 0;
  static int n_indices = 0;

  for (int i = 0; i < n_indices; i++) {
    int indice = soma_indice(prox_indice, -(i+1));
    if (fontes[indice].tamanho == tam) return fontes[i].fonte;
  } 

  // carrega uma fonte, para poder escrever na tela
  ALLEGRO_FONT *fonte = al_load_font("DejaVuSans.ttf", tam, 0);
  fonte = al_load_font("DejaVuSans.ttf", tam, 0);
  if (fonte == NULL) {
    al_uninstall_system();
    fprintf(stderr,
            "\n\nERRO FATAL\n"
            "O ARQUIVO COM O DESENHO DAS LETRAS (DejaVuSans.ttf) NAO FOI ENCONTRADO.\n"
            "COPIE ESSE ARQUIVO, OU MUDE telag2.c PARA USAR UM QUE EXISTA.\n"
            " (pode ser tambem que tela_inicio() nao tenha sido chamada)\n");
    exit(1);
  }

  // se ja tinha uma fonte carregada, livra-se dela antes de carregar outra
  if (n_indices == N_FONTES && fontes[prox_indice].fonte != NULL) {
    al_destroy_font(fontes[prox_indice].fonte);
  } else {
    n_indices++;
  }
  fontes[prox_indice].fonte = fonte;
  fontes[prox_indice].tamanho = tam;
  prox_indice = soma_indice(prox_indice, 1);

  return fonte;
}

void tela_texto(ponto_t posicao, int tamanho, cor_t cor, char texto[])
{
  ALLEGRO_FONT *fonte = tela_fonte(tamanho);
  posicao.y -= al_get_font_ascent(fonte);
  al_draw_text(fonte, conv_cor(cor), posicao.x, posicao.y, ALLEGRO_ALIGN_LEFT, texto);
}

retangulo_t tela_texto_contorno(ponto_t posicao, int tamanho, char texto[])
{
  ALLEGRO_FONT *fonte = tela_fonte(tamanho);
  retangulo_t ret;
  int rx, ry, rw, rh;
  al_get_text_dimensions(fonte, texto, &rx, &ry, &rw, &rh);
  ret.inicio.x = posicao.x + rx;
  ret.inicio.y = posicao.y + ry - al_get_font_ascent(fonte);
  ret.tamanho.largura = rw;
  ret.tamanho.altura = rh;
  return ret;
}

rato_t tela_rato()
{
  ALLEGRO_MOUSE_STATE mouse;
  rato_t rato;
  al_get_mouse_state(&mouse);
  rato.posicao.x = al_get_mouse_state_axis(&mouse, 0);
  rato.posicao.y = al_get_mouse_state_axis(&mouse, 1);

  static int ultimo_giro = INT_MAX;
  int giro = al_get_mouse_state_axis(&mouse, 2);
  if (ultimo_giro == INT_MAX) ultimo_giro = giro;
  rato.giro = ultimo_giro - giro;
  ultimo_giro = giro;
  
  static bool ultimo_apertado[3] = { false, false, false };
  for (int b = 0; b < 3; b++) {
    rato.apertado[b] = al_mouse_button_down(&mouse, b + 1);
    rato.clicado[b] = ultimo_apertado[b] && !rato.apertado[b];
    ultimo_apertado[b] = rato.apertado[b];
  }

  return rato;
}

static bool t_shift, t_control;

bool tela_shift() { return t_shift; }
bool tela_control() { return t_control; }

char tela_tecla(void)
{
  ALLEGRO_EVENT ev;

  while (al_get_next_event(tela_eventos_teclado, &ev)) {
    t_shift = ev.keyboard.modifiers & ALLEGRO_KEYMOD_SHIFT;
    t_control = ev.keyboard.modifiers & ALLEGRO_KEYMOD_CTRL;
    if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
      int k = ev.keyboard.keycode;
      switch (k) {
        case ALLEGRO_KEY_ENTER:     return '\n';
        case ALLEGRO_KEY_BACKSPACE: return '\b';
      }
      int c = ev.keyboard.unichar;
      return c;
    }
  }
  // nada foi pressionado (ou foi pressionado algo não imprimível)
  return '\0';
}


double tela_relogio(void)
{
  return al_get_time();
}
