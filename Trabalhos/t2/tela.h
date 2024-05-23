// tela.h
// ------
// funções para controlar a impressão no terminal
//

#ifndef TELA_H
#define TELA_H

#include <stdbool.h>

// inicializa a tela
void tela_ini(void);

// volta a tela ao normal
void tela_fim(void);

// limpa a tela
void tela_limpa(void);

// posiciona o cursor (0,0 é o canto superior esquerdo)
void tela_lincol(int lin, int col);

// cor normal para as próximas impressões
void tela_cor_normal(void);

// seleciona a cor das letras nas próximas impressões
// os componentes da cor são valores entre 0 e 255
void tela_cor_letra(int vermelho, int verde, int azul);

// seleciona a cor do fundo nas próximas impressões
// os componentes da cor são valores entre 0 e 255
void tela_cor_fundo(int vermelho, int verde, int azul);

// seleciona se o cursor aparece ou não
void tela_mostra_cursor(bool mostra);

// para melhorar a apresentação na tela, os dados impressos são
// mantidos em memória para serem enviados agrupados ao sistema.
// Esta função deve ser chamada quando for necessário que os dados
// sejam enviados e efetivamente apareçam
void tela_atualiza(void);

#endif // TELA_H
