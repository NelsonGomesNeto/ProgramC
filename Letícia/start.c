// Comentários são feitos com "//"
#include <stdio.h>
// Aqui você vai declarar as bibliotecas de funções que você vai utilizar
// Por enquanto, "stdio.h" (standart input and output) vai ser suficiente

// Aqui você também vai poder declarar funções, variáveis globais e structs

// Essa é a função principal (sempre chamada de "main")
// É a primeira que vai ser executada
int main()
{
  int variable; // Uma variável do tipo int (Inteiro)

  scanf("%d", &variable); // (ENTRADA) Lê formatadamente (scan formated)
  // '%d' significa que ele vai procurar por uma variável do tipo int na entrada
  // E vai colocar na variável "variable"

  printf("You've typed: %d\n", variable); // (SAIDA) Imprime formatadamente (print formated)
  // Assim como na entrada, o '%d' também significa int
  // Então, ele vai imprimir "You've typed: %d\n", e no lugar do '%d'...
  // ... ele vai colocar o que está dentro da variável depois da vírgula;
  // O '\n' é para quebrar a linha

  return(0); // Aqui encerra a função
}

// Aqui também podem ser declaradas as funções
