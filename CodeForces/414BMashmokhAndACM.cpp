#include <bits/stdc++.h>
#define lli long long int

lli dp[2001][2001], mod = (lli) 1e9 + 7;

lli solve(int n, int k, int prev)
{
  if (k == 0) return(1);

  if (dp[k][prev] == -1)
  {
    lli ans = 0;
    for (int i = prev; i <= n; i ++)
      if (!(i % prev))
        ans = (ans + solve(n, k - 1, i)) % mod;
    dp[k][prev] = ans;
  }

  return(dp[k][prev]);
}

int main()
{
  memset(dp, -1, sizeof(dp));
  int n, k; scanf("%d %d", &n, &k);

  lli ans = solve(n, k, 1);
  for (int i = 1; i <= k; i ++)
    for (int j = 1; j <= n; j ++)
      printf("%lld%c", dp[i][j], j < n ? ' ' : '\n');

  printf("%lld\n", ans);

  return(0);
}