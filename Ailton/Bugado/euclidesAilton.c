#include <stdio.h>

int MDC(int n1, int n2)
{
  if (n1 % n2 == 0)
  {
    return(n2);
  }
  MDC(n2, n1 % n2);
}

int ler(int *a, int *b)
{
    printf("Digite os dois números: ");
    scanf("%d %d", &*a, &*b);
    return(1);
}

int main()
{
  int num1, num2;
  printf("Esse programa vai calcular o MDC de dois números através do Algoritmo de Euclides. Para fechar o programa, basta digitar '0 0'.\n");
  while (ler(&num1, &num2) && !(num1 == 0 && num2 == 0))
  {
    printf("MDC(%d,%d) = %d\n", num1, num2, MDC(num1,num2));
  }
  return(0);
}
