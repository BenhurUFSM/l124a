#ifndef _telag_h_  // para evitar problemas com inclusão múltipla deste arquivo
#define _telag_h_

//
// telag.h
// ------
//
// funções de acesso a tela, mouse, relógio
//

#include <stdbool.h>

// tipos de dados
typedef struct {
  int largura;
  int altura;
} tamanho_t;

typedef struct {
  int x;
  int y;
} ponto_t;

typedef struct {
  ponto_t centro;
  int raio;
} circulo_t;

typedef struct {
  ponto_t inicio;
  tamanho_t tamanho;
} retangulo_t;

typedef struct {
  float vermelho;
  float verde;
  float azul;
  float opacidade;
} cor_t;

typedef struct {
  ponto_t posicao;  // onde está o mouse
  bool apertado[3]; // o estado de cada um dos 3 botões
  bool clicado[3];  // se cada botão foi solto desde a última leitura do estado
  int giro;         // quanto a rodela de rolagem girou desda a última leitura
} rato_t;

// inicialização da tela
// cria uma janela com o tamanho dado em pixels
// deve ser executada antes do uso de qualquer outra função da tela
void tela_inicio(tamanho_t tamanho, char nome[]);


// finalização da tela
// deve ser chamada no final da utilização da tela, nenhuma outra função da
// tela deve ser chamada depois desta.
void tela_fim(void);


// atualiza a tela
// faz com o que foi desenhado na tela desde a última atualização
// realmente apareça.
// caso necessário, espera até que a imagem anterior tenha ficado
// na tela pelo tempo adequado.
// antes da chamada a esta função a imagem anterior fica sendo exibida, 
// o conteúdo da nova imagem fica só na memória.
void tela_atualiza(void);

// frequencia de atualizacao da tela
#define QUADROS_POR_SEGUNDO 30.0
#define SEGUNDOS_POR_QUADRO (1/QUADROS_POR_SEGUNDO)

// DESENHO

// desenha um círculo
void tela_circulo(circulo_t circulo, float largura, cor_t cor_linha, cor_t cor_interna);

// desenha uma linha reta
void tela_linha(ponto_t inicio, ponto_t fim, float largura, cor_t cor_linha);

// desenha um retangulo
void tela_retangulo(retangulo_t retangulo, float largura,
                    cor_t cor_linha, cor_t cor_interna);


// desenha texto
void tela_texto(ponto_t posicao, int tamanho, cor_t cor, char texto[]);

// retorna retângulo que contorna o texto
retangulo_t tela_texto_contorno(ponto_t posicao, int tamanho, char texto[]);


// ACESSO AO RATO

// retorna o estado do rato
rato_t tela_rato();


// ACESSO AO TECLADO

// retorna uma tecla digitada ou '\0' se nenhuma tecla for digitada
// se for digitado enter, retorna '\n'
// se for digitado backspace, retorna '\b'
char tela_tecla(void);


// TEMPO

// retorna quantos segundos transcorreram desde algum momento no passado
double tela_relogio(void);

#endif // _telag_h_
