#include <bits/stdc++.h>

int main()
{
  int liters; scanf("%d", &liters);
  int cost[9];
  for (int i = 0; i < 9; i ++)
    scanf("%d", &cost[i]);

  int toPrint = -1, best;
  for (int j = 0; j < 2; j ++)
  {
    best = 0;
    for (int i = 9 - 1; i >= 0; i --)
      if (liters / cost[i] > best)
      {
        best = liters / cost[i];
        toPrint = i + 1;
      }

    for (int i = 0; i < best; i ++)
      printf("%d", toPrint);

    if (toPrint != -1)
      liters -= best * cost[toPrint - 1];
  }

  if (toPrint == -1) printf("-1");

  printf("\n");

  return(0);
}