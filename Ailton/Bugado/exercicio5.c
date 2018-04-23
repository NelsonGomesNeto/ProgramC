#include <stdio.h>

int main()
{
  int x, y, resto;
  float quociente;
  scanf("%i\n%i", &x, &y);
  quociente = x / y;
  resto = x % y;
  printf("O quociente foi: %f; e o resto foi: %i\n", quociente, resto);
  return(0);
}
