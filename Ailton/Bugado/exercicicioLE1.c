#include <stdio.h>

int main()
{
  int num[10], ler;
  for (ler = 0; ler < 10; ler ++)
  {
    scanf("%d", &num[ler]);
  }
  while (ler > 0)
  {
    ler --;
    if (num[ler] % 2 == 0)
    {
      printf("%d ", num[ler]);
    }
  }
  printf("%d\n", num[0]);
  return(0);
}
