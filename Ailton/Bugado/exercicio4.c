#include <stdio.h>

int main()
{
  float x, y, z, n, produto;
  scanf("%f\n%f\n%f\n%f", &x, &y, &z, &n);
  produto = x * y * z * n;
  printf("O produto foi: %f\n", produto);
  return(0);
}
