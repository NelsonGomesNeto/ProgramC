#include <bits/stdc++.h>

void printRes(int res[9][9])
{
  for (int i = 0; i < 9; i ++)
    for (int j = 0; j <= i; j ++)
      printf("%d%c", res[i][j], j < i ? ' ' : '\n');
}

int main()
{
  int n, prev[5][5], res[9][9]; memset(res, -1, sizeof(res));
  scanf("%d", &n);
  while (n -- > 0)
  {
    for (int i = 0; i < 5; i ++)
      for (int j = 0; j <= i; j ++)
      {
        scanf("%d", &prev[i][j]);
        res[2*i][2*j] = prev[i][j];
      }

    printRes(res);

    int missing = 31;
    while (missing > 30)
    {
      for (int i = 5 - 1; i >= 0 + 1; i --)
        for (int j = 0; j <= i - 1; j ++)
          if (prev[i][j] + prev[i][j + 1] == prev[i - 1][j])
          {
            res[2*i][2*j] = prev[i][j];
            res[2*i][2*j + 1] = 0;
            res[2*i][2*j + 2] = prev[i][j];
          }

      missing --;
      printRes(res);
    }
  }
  return(0);
}