#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000], n, m;

int topDown(int i, int j, char a[], char b[])
{
  if (i == n || j == m) return(0);
  if (dp[i][j] == -1)
  {
    if (a[i] == b[j])
      dp[i][j] = 1 + topDown(i + 1, j + 1, a, b);
    else
      dp[i][j] = max(topDown(i + 1, j, a, b), topDown(i, j + 1, a, b));
  }
  return(dp[i][j]);
}

int bottomUp(char a[], char b[])
{
  for (int i = n; i >= 0; i --)
    for (int j = m; j >= 0; j --)
    {
      if (!a[i] || !b[j]) dp[i][j] = 0;
      else if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
      else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  return(dp[0][0]);
}

int main()
{
  memset(dp, -1, sizeof(dp));

  char a[(int) 1e6], b[(int) 1e6]; scanf("\n%s\n%s", a, b);
  n = strlen(a); m = strlen(b);

  int lcs = topDown(0, 0, a, b);
  printf("Longest Common Subsequence = %d\n", lcs);

  return(0);
}