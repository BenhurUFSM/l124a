// tela.h
// ------
// Este arquivo contém as declarações de funções para controlar a impressão
// no terminal.
// As funções estão implementadas no arquivo tela.c.
// Para poder ter acesso a estas funções, o programa deve incluir este arquivo,
// com o comando
//    #include "tela.h"
//
// Para poder usar as funções de controle, primeiro deve ser chamada a função
// tela_ini.
// Quando o programa não for mais usar o terminal dessa forma, deve chamar a
// função tela_fim.

// esses dois comandos (em comjunto com o #endif no final do arquivo) servem
// para evitar redefinições caso este arquivo seja incluído mais de uma vez
#ifndef TELA_H
#define TELA_H

#include <stdbool.h>

// inicializa a tela
void tela_ini(void);

// volta a tela ao normal
void tela_fim(void);

// limpa a tela
void tela_limpa(void);

// posiciona o cursor (1,1 é o canto superior esquerdo)
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
