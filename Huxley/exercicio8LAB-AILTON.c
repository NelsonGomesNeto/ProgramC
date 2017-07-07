#include <stdio.h>

int main()
{
  int saque, nota1 = 0, nota5 = 0, nota10 = 0, nota50 = 0, nota100 = 0;
  printf("Insira o valor do saque: ");
  scanf("%d", &saque);
  if (saque  >= 10 && saque <= 600)
  {
    if (saque % 100 > 0)
    {
      nota100 = saque / 100;
      saque %= 100;
    }
    if (saque % 50 > 0)
    {
      nota50 = saque / 50;
      saque %= 50;
    }
    if (saque % 10 > 0)
    {
      nota10 = saque / 10;
      saque %= 10;
    }
    if (saque % 5 > 0)
    {
      nota5 = saque / 5;
      saque %= 5;
    }
    nota1 = saque;
    printf("Nota(s) de R$100: %d\n", nota100);
    printf("Nota(s) de R$50: %d\n", nota50);
    printf("Nota(s) de R$10: %d\n", nota10);
    printf("Nota(s) de R$5: %d\n", nota5);
    printf("Nota(s) de R$1: %d\n", nota1);
  }
  else
  {
    printf("Saque inválido!\n");
  }
  return(0);
}
