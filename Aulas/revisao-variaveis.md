### Resumo - variáveis

Variáveis são usadas para representar dados armazenados em memória, que podem ser manipulados diretamente pelos comandos em um programa C.

Uma variável tem um *tipo*, que indica que valores essa variável irá representar, quanto de memória é necessário para um desses valores, como os bits armazenados nessa memória devem ser interpretados.

Uma variável tem um *valor*, que corresponde a interpretação dos valores dos bits atualmente em sua memória, de acordo com as regras de seu tipo.

Uma variável tem um *endereço*, que é a posição da memória onde o valor da variável é colocado.

Os tipos em C podem ser básicos ou compostos.
Os tipos básicos são definidos diretamente pela linguagem e correspondem a dados que geralmente podem ser manipulados diretamente pelo hardware (bool, char, int, float, etc.).
Os tipos compostos (vetor, matriz, registro) são definidos pelo programado, formados por conjuntos de valores de tipos básicos ou compostos (pode-se definir um registro composto por um vetor de registros com um int e um vetor de doubles, por exemplo).

Pode-se definir novos nomes para qualquer desses tipos, usando `typedef`. Isso é mais comum com registros, que são definidos de forma "verbosa".

Para qualquer dos tipos, existe um tipo `ponteiro` correspondente. Uma variável do tipo ponteiro tem um valor que é o endereço de uma região de memória que contém um dado de determinado tipo. Por exemplo, uma variável do tipo 'ponteiro para int' (escrito como `int *`) pode apontar para (ou referenciar) uma outra variável que contém um valor do tipo int.
Um uso comum para ponteiros é passar referências para uma função, para que a função possa alterar variáveis de outra função (o que não é normalmente permitido).

### Tipos básicos

```c
  // como declarar
  int var;

  // como inicializar na declaração
  int var = 17;

  // como alterar o valor
  var = 83;

  // como alterar o valor com o retorno de uma função
  var = f();

  // como passar o valor para uma função
  f(var);

  // como passar uma referência para uma função poder alterar o valor
  f(&var);

  // como uma função pode retornar um valor
  int f() {
    int a;
    a = ...
    return a;
  }

  // como uma função pode receber um valor
  int f(int x) {
    int y = x * x;
    return y;
  }

  // como uma função pode alterar um valor por referência
  void f(int *p) {
    int y = ...
    *p = y;
  }
```

### Vetores

```c
  // como declarar
  int var[10];

  // como inicializar na declaração
  int var[10] = { 17, 28, 23, 1 }; // os demais são inicializados com 0
  int var[10] = { [3] = 17, [7] = 28 }; // os demais são inicializados com 0
  int var[] = { 17, 28, 23, 1 }; // vetor de 4 elementos

  // como alterar o valor
  // não tem atribuição de vetor só de elementos
  var[0] = 83;

  // como alterar o valor com o retorno de uma função
  // não tem atribuição de vetor

  // como passar o valor para uma função
  // não tem como passar o vetor, seria uma atribuição de vetor a um argumento

  // como passar uma referência para uma função poder alterar o valor
  f(var); // a função não tem acesso ao tamanho do vetor
  f(10, var); // uma forma comum de dar acesso ao tamanho do vetor

  // como uma função pode retornar um valor
  // não pode

  // como uma função pode receber um valor
  // não pode

  // como uma função pode alterar um valor por referência
  void f(int p[]) {
    int y = ...
    p[0] = y;
  }
  // para que a função tenha acesso ao tamanho:
  void f(int n, int p[n]) {...}
```
Com alocação dinâmica:
```c
  // como declarar
  int *var;

  // como alocar memória
  var = malloc(10 * sizeof(int));
  if (var == NULL) { /* erro de alocação ... */ }

  // como inicializar na declaração
  // não dá

  // como alterar o valor
  // não tem atribuição de vetor só de elementos
  var[0] = 83;

  // como alterar o valor com o retorno de uma função
  // não tem atribuição de vetor.
  // Dá para a função alocar o vetor e retornar o ponteiro
  var = f(); // perde o valor anterior de var

  // como passar o valor para uma função
  // não tem como passar o vetor, só o ponteiro (uma referência)

  // como passar uma referência para uma função poder alterar o valor
  f(var); // a função não tem acesso ao tamanho do vetor
  f(10, var); // uma forma comum de dar acesso ao tamanho do vetor

  // como uma função pode retornar um valor
  // não pode retornar como vetor, mas como ponteiro
  int *f() {
    int *v = malloc(3 * sizeof(int));
    if (v != NULL) {
      v[0] = 1;
      v[1] = 25;
      v[2] = 8;
    }
    return v;
  }

  // como uma função pode receber um valor
  // não pode receber como vetor, mas como ponteiro (uma referência)

  // como uma função pode alterar um valor por referência
  void f(int p[]) {
    int y = ...
    p[0] = y;
  }
  // para que a função tenha acesso ao tamanho:
  void f(int n, int p[n]) {...}
```

### Registros

```c
  // como declarar
  struct {
    int a;
    float b;
  } var;
  // mais comumente, de declara um tipo:
  typedef struct {
    int a;
    float b;
  } t;
  t var;

  // como inicializar na declaração
  t var = { 5, 3.2 };
  t v2 = { .b = 5.5 }; // .a é inicializado com 0

  // como alterar o valor
  var.a = 12;
  var.b = 2.5;
  var = (t){ .a = 83, .b = 2 };
  var = v2;

  // como alterar o valor com o retorno de uma função
  var = f();

  // como passar o valor para uma função
  f(var);

  // como passar uma referência para uma função poder alterar o valor
  f(&var);

  // como uma função pode retornar um valor
  t f() {
    t a;
    a = ...
    return a;
  }

  // como uma função pode receber um valor
  int f(t x) {
    int y = x.a * x.b;
    return y;
  }

  // como uma função pode alterar um valor por referência
  void f(t *p) {
    t y = ...
    *p = y;
  }
  void f(t *p) {
    p->a = 12;
    p->b = sqrt(p->a);
  }
```
Vetor de registros com alocação dinâmica:
```c
  // como declarar
  t *var;

  // como alocar memória
  var = malloc(10 * sizeof(t));
  if (var == NULL) { /* erro de alocação ... */ }

  // como inicializar na declaração
  // não dá

  // como alterar o valor de um elemento
  var[0].a = 12;
  var[i].b = 2.5;
  var[5] = (t){ .a = 83, .b = 2 };
  var[j] = v2;

  // como alterar o valor com o retorno de uma função
  var[2] = f();
  // se for alteração do vetor inteiro, a função aloca e retorna o ponteiro
  var = f();

  // como passar o valor para uma função
  // não dá para passar o vetor, só o ponteiro (ver abaixo)

  // como passar uma referência para uma função poder alterar o valor
  f(var);

  // como uma função pode retornar um valor
  // retorno de um elemento
  t f() {
    t a;
    a = ...
    return a;
  }
  // alocação de um vetor e retorno do ponteiro
  t *f() {
    t a = malloc ...
    a[0].a = 5; ...
    return a;
  }

  // como uma função pode receber um valor
  // por referência

  // como uma função pode alterar um valor por referência
  void f(t *p) {
    t y = ...
    p[2] = y;
  }
  void f(t *p) {
    p[2].a = 12;
    p[2].b = sqrt(p[2].a);
  }
```
