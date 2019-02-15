#include <bits/stdc++.h>

int n, m;

void func(int mat[][])
{
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      printf("%d%c", mat[i][j], j < 10 - 1 ? ' ' : '\n');
}

int main()
{
  scanf("%d %d", &n, &m);
  int mat[n][m];
  for (int i = 0, s = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      mat[i][j] = s ++;
  func(&mat[0][0]);
  return(0);
}