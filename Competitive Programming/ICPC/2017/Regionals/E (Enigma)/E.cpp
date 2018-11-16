#include <bits/stdc++.h>
char s[(int) 1e3 + 1]; int n, sz;
int dp[1000][1001];

int solve(int i)
{
  if (i == sz - 1) return(s[i] == '?' || (s[i] - '0') % n == 0):
  if (dp[i][n] == -1)
  {
    dp[i][n] = solve(i + 1);
  }
  return(dp[i][n]);
}

int main()
{
  scanf("%s %d", s, &n); sz = strlen(s);
  memset(dp, -1, sizeof(dp));
  int ans = solve(0);
  return(0);
}
