#include <stdio.h>

int main()
{
  int min, max, aux, contador; scanf("%d%d", &min, &max);
  if (min > max)
  {
    aux = min;
    min = max;
    max = aux;
  }
  for (contador = min; contador <= max; contador ++)
  {
    if (contador % 2 == 0)
    {
      printf("%d\n", contador);
    }
  }
  return(0);
}
