#include <stdio.h>

int main()
{
  float num[10], aux; int ler, ordem;
  for (ler = 0; ler < 10; ler ++)
  {
    scanf("%f", &num[ler]);
  }
  for (ler = 0; ler < 10; ler ++)
  {
    for (ordem = ler; ordem < 10; ordem ++)
    {
      if (num[ler] > num[ordem])
      {
        aux = num[ler];
        num[ler] = num[ordem];
        num[ordem] = aux;
      }
    }
  }
  for (ler = 0; ler < 9; ler ++)
  {
    printf("%f ", num[ler]);
  }
  printf("%f\n", num[9]);
  return(0);
}
