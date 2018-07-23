#include <bits/stdc++.h>
#define DEBUG if(0)
#define lli long long int
lli grid[20][20], n, m, k, lol[20][20], dp[20][20], dpRes;

lli allPaths(int i, int j, lli prev, int depth)
{
  if (i >= n || j >= m) return(0);
  DEBUG for (int k = 0; k < depth; k ++) printf("\t"); DEBUG printf("(%d, %d [%lld][%lld])\n", i, j, grid[i][j], prev ^ grid[i][j]);
  if (i == n - 1 && j == m - 1) return((prev ^ grid[i][j]) == k);

  if (lol[i][j] && prev == dp[i][j])
  {
    dpRes += lol[i][j] + 1;
    lol[i][j] ++;
    return(1);
  }

  if (allPaths(i + 1, j, prev ^ grid[i][j], depth + 1))
  {
    dp[i][j] = prev;
    lol[i][j] ++;
  }
  if (allPaths(i, j + 1, prev ^ grid[i][j], depth + 1))
  {
    dp[i][j] = prev;
    lol[i][j] ++;
  }
  return(lol[i][j] > 0);
}

int main()
{
  scanf("%lld %lld %lld", &n, &m, &k);
   for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) scanf("%lld", &grid[i][j]);

  memset(lol, 0, sizeof(lol)); dpRes = 0;
  allPaths(0, 0, 0, 0);
  DEBUG for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) printf("%lld%c", lol[i][j], j < m - 1 ? ' ' : '\n');
  printf("%lld\n", lol[n - 2][m - 1] + lol[n - 1][m - 2] + dpRes);

  return(0);
}