#include <stdio.h>

int main()
{
  int max, min, aux;
  scanf("%d%d", &max, &min);
  if (min > max)
  {
    aux = min;
    min = max;
    max = aux;
  }
  while (min < max - 1)
  {
    min ++;
    printf("%d\n", min);
  }
  return(0);
}
