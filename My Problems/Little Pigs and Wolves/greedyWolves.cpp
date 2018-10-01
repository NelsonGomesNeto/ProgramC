#include <bits/stdc++.h>
int n, m;
char f[10][10 + 1];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int valid(int i, int limit)
{
  return(!(i < 0 || i >= limit));
}

int adjacentPig(int i, int j)
{
  for (int k = 0; k < 4; k ++)
    if (valid(i + dy[k], n) && valid(j + dx[k], m) && f[i + dy[k]][j + dx[k]] == 'P')
      return(1);
  return(0);
}

int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i ++) scanf("\n%s", f[i]);

  int total = 0;
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      if (f[i][j] == 'W' && adjacentPig(i, j))
        total ++;
  printf("%d\n", total);

  return(0);
}
