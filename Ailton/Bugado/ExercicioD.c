#include <stdio.h>

int main()
{
  int contador = 1;
  while (contador <= 20)
  {
    if (contador % 2 != 0)
    {
      printf("%d\n", contador);
    }
    contador ++;
  }
  return(0);
}
