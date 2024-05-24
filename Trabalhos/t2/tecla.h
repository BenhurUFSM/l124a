// tecla.h
// contém declarações de funções para permitir o acesso ao teclado
// sem bufferização, dando acesso às teclas digitadas ao programa tão
// logo elas tenham sido digitadas, sem esperar por «enter»
//
// a bufferização é desligada por tecla_ini (que deve ser chamada no início
// do programa), e religada por tecla_fim (que deve ser chamada no final).
// A função tecla_le_char permite a leitura de um caractere.
// As funções habituais de leitura (getchar, scanf, etc) não funcionam muito
// bem quando a bufferização está desabilitada, e não devem ser usadas.

#ifndef TECLA_H
#define TECLA_H

// muda o processamento de caracteres de entrada pelo terminal
//   para que a leitura seja feita em caracteres individuais, sem esperar
//   digitar enter
// esta função deve ser chamada no início do programa
void tecla_ini(void);

// configura o teclado para o modo que estava quando tecla_ini foi chamada
// esta função deve ser chamada no final da execução do programa
void tecla_fim(void);

// retorna o próximo caractere lido do teclado, ou 0 se não tiver nenhum
//   caractere a ser lido
char tecla_le_char(void);

#endif // TECLA_H
