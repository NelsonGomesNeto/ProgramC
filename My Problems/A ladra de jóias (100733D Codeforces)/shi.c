#include <stdio.h>
#include <string.h>
int n, v[(int) 1e6], dp[(int) 1e6];

int max(int a, int b)
{
  return(a > b ? a : b);
}

int solve(int i)
{
  if (i >= n) return(0);
  if (dp[i] == -1) dp[i] = max(solve(i + 1), v[i] + solve(i + 3));
  return(dp[i]);
}

int bottomUp()
{
  if (n < 3)
  {
    int best = 0; for (int i = 0; i < n; i ++) best = max(best, v[i]);
    return(best);
  }
  dp[0] = v[0]; dp[1] = max(dp[0], v[1]); dp[2] = max(dp[1], v[2]);
  for (int i = 3;  i < n; i ++) dp[i] = max(dp[i - 1], dp[i - 3] + v[i]);
  return(dp[n - 1]);
}

int main()
{
  // memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) scanf("%d", &v[i]);
  // int ans = solve(0);
  int ans = bottomUp();
  printf("%d\n", ans);
  return(0);
}