#include <stdio.h>

int main()
{
  float x, y, soma, z, sub;
  scanf("%f\n%f", &x, &y);
  soma = x + y;
  scanf("%f", &z);
  sub = soma - z;
  printf("Resultado: %f\n", sub);
  return(0);
}
