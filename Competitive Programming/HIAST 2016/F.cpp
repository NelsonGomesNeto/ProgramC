#include <bits/stdc++.h>
using namespace std;
int n, v[100];
int dp[100][101], inf = 1<<20;

int solve(int i, int a, int b)
{
  // printf("%d %d\n", abs(currDiff - 100), currDiff);
  if (i == n) return(-1);
  int currA = abs(a + v[i] - b);
  int currB = abs(a - (b + v[i]));
  if (currA <= 100 && dp[i][currA] == -1)
    dp[i][currA] = max(currA, solve(i + 1, a + v[i], b));
  if (currB <= 100 && dp[i][currB] == -1)
    dp[i][currB] = max(currB, solve(i + 1, a, b + v[i]));
  return(min(currA <= 100 ? dp[i][currA] : inf, currB <= 100 ? dp[i][currB] : inf));
}

int main()
{
  int t; scanf("%d", &t);
  while (t --)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &v[i]);
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0, 0);
    printf("%d\n", ans);
  }
  return(0);
}

/*
dp[100][101][210]
int solve(int i, int currDiff, int maxDiff)
{
  // printf("%d %d\n", abs(currDiff - 100), currDiff);
  if (abs(currDiff - 100) > 100) return(inf);
  maxDiff = max(maxDiff, abs(currDiff - 100));
  if (i == n) return(maxDiff);
  if (dp[i][maxDiff][currDiff] == -1)
  {
    int ans = solve(i + 1, currDiff + v[i], maxDiff);
    ans = min(ans, solve(i + 1, currDiff - v[i], maxDiff));
    dp[i][maxDiff][currDiff] = ans;
  }
  // else printf("%d %d %d\n", i, currDiff, dp[i][currDiff]);
  return(dp[i][maxDiff][currDiff]);
}
*/