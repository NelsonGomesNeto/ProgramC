// Comentários são feitos com "//"
#include <stdio.h>
// Aqui você vai declarar as bibliotecas de funções que você vai utilizar; por enquanto, "stdio.h" vai ser suficiente

// Aqui você também vai poder declarar funções, variáveis globais e structs

// Essa é a função principal, a primeira que vai ser rodada quando você executar o programa
int main()
{
  int variable; // Uma variável do tipo int (Inteiro)

  scanf("%d", &variable); // (ENTRADA) Lê formatadamente, no caso, o '%d' significa que ele vai procurar por uma variável do tipo int na entrada, e vai colocar na variável "variable"

  printf("You've typed: %d\n", variable); // (SAIDA) Imprime formatadamente, no caso, assim como na entrada, o '%d' também significa int, então, ele vai imprimir "You've typed: %d\n", e no lugar do '%d', ele vai colocar o que está dentro da variável depois da vírgula; O '\n' é para quebrar a linha

  return(0);
}

// Aqui também podem ser declaradas as funções