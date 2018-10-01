#include <stdio.h>

int min(int a, int b)
{
  return(a < b ? a : b);
}

int abs(int a)
{
  return(a < 0 ? a*-1 : a);
}

int bruteForce(int pizza[], int slices)
{
  int i, j, all, best = 360, now;
  for (i = 0; i < slices; i ++)
  {
    now = 0;
    for (all = 0, j = i; all < slices; all ++, j ++)
    {
      j %= slices;
      now += pizza[j];
      best = min(best, abs((360 - now) - now));
    }
  }
  return(best);
}

int main()
{
  int slices; scanf("%d", &slices);
  int pizza[slices], i;
  for (i = 0; i < slices; i ++)
    scanf("%d", &pizza[i]);

  int diff = bruteForce(pizza, slices);

  printf("%d\n", diff);

  return(0);
}