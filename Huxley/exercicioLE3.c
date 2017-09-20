#include <stdio.h>

int main()
{
  float num[10]; int ler;
  for (ler = 0; ler < 10; ler ++)
  {
    scanf("%f", &num[ler]);
  }
  for (ler = 0; ler < 8; ler ++)
  {
    if (ler % 2 == 0)
    {
      printf("%f ", num[ler]);
    }
  }
  printf("%f\n", num[8]);
  return(0);
}
