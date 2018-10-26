#include <bits/stdc++.h>
char mat[500][501];
int n, m, k, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0}, da[5] = {0, 1, 2, 3, 4};

int around(int i, int j)
{
  int count = 0;
  for (int kk = 0; kk < 4; kk ++)
  {
    int y = i + dy[kk], x = j + dx[kk];
    if (y < 0 || y >= n || x < 0 || x >= m || mat[y][x] != '.') continue;
    else count ++;
  }
  return(count);
}

void go(int i, int j)
{
  if (!k || i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != '.' || around(i, j) > 2) return;
  mat[i][j] = 'X', k --;
  for (int kk = 0; kk < 4; kk ++)
    go(i + dy[kk], j + dx[kk]);

}

int main()
{
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i ++) scanf("\n%s", mat[i]);

  while (k)
  {
    for (int a = 1; a <= 4; a ++)
    {
      int done = 0;
      for (int i = 0; i < n && k && !done; i ++)
        for (int j = 0; j < m && k && !done; j ++)
          if (mat[i][j] == '.' && around(i, j) <= a)
            go(i, j), done = 1;
    }

  }
  for (int i = 0; i < n; i ++)
    printf("%s\n", mat[i]);
  return(0);
}
