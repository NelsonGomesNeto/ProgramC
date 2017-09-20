#include <stdio.h>

int main()
{
  int testes; scanf("%d", &testes);
  int tamanho, tempo, drawX, drawY, meio;
  scanf("%d\n%d", &tamanho, &tempo);
  meio = 2;
  for (drawY = 0; drawY < tamanho * 4; drawY ++)
  {
    if (drawY % 2 == 0)
    {
      printf("*");
      if (drawY == 0 || drawY == (tamanho * 4) - 2)
      {
        printf("* * * * *");
      }
      while (meio < tamanho * 2)
      {
        if (meio == drawY + 1)
        {
          printf("*");
        }
        else
        {
          printf(" ");
        }
        meio ++;
      }
    }
    else
    {
      printf("\n");
    }
  }
  return(0);
}
