#include <stdio.h>

int main()
{
  int n, jumps; scanf("%d %d", &n, &jumps);
  int array[n], i, biggest = 0; for (i = 0; i < n; i ++) scanf("%d", &array[i]);

  int bestLaps = 0, bestTotal = 0, bestStart = 0, j;
  for (i = 0; i < n; i ++)
  {
    if (array[i] > biggest) biggest = array[i];
    int at = i, laps = 0, total = 0;
    for (j = 0; j < jumps; j ++)
    {
      total += array[at];
      at += array[at];
      if (at / n >= 1)
      {
        laps += at / n;
        at %= n;
      }
    }
    if (total > bestTotal)
    {
      bestTotal = total;
      bestStart = i;
    }
    //printf("%d %d\n", i, total);
  }

  printf("%d %d\n", bestStart, bestTotal);
  return(0);
}