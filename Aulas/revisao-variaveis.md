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
