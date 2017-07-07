#include <stdio.h>

int main()
{//FAZER COM %D!!!!!!
  int min = 1, totalmin = 0, lig = 0, limit = 0, totalminlig = 40;
  float preco = 10;
  while (scanf("%i", &min) && min != 0)
  {
    lig ++;
    totalmin += min;
    if ((lig > 10 || totalmin > 40) && min != 0)
    {
      if (totalmin <= 40 && lig == 11)
      {
        totalminlig = totalmin - min;
      }
      limit = totalmin - totalminlig;
    }
  }
  preco += limit * 0.2;
  printf("%.2f\n", preco);
  return(0);
}
