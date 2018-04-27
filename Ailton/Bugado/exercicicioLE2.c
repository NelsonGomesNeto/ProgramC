#include <stdio.h>

int main()
{
  int num[10], ler;
  for (ler = 0; ler < 10; ler ++)
  {
    scanf("%d", &num[ler]);
  }
  for (ler = 0; ler < 9; ler ++)
  {
    if (num[ler] % 2 == 0)
    {
      num[ler] = 1;
    }
    else
    {
      num[ler] = -1;
    }
    printf("%d ", num[ler]);
  }
  printf("%d\n", num[9]);
  return(0);
}
