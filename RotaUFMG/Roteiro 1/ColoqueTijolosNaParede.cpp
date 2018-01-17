#include <bits/stdc++.h>

int main()
{
  int n, prev[5][5], res[9][9]; memset(res, 0, sizeof(res));
  scanf("%d", &n);
  while (n -- > 0)
  {
    for (int i = 0; i < 5; i ++)
      for (int j = 0; j <= i; j ++)
      {
        scanf("%d", &prev[i][j]);
        res[2*i][2*j] = prev[i][j];
      }

    for (int i = 0; i < 9; i ++)
      for (int j = 0; j <= i; j ++)
        printf("%d%c", res[i][j], j < i ? ' ' : '\n');
  }
  return(0);
}