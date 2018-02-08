#include <bits/stdc++.h>
int k, l, n;

int winner(int coins, int player, int dp[])
{
  if (coins <= 0) return(1 - player);

  if (1)
  {
    if (winner(coins - l, 1 - player, dp)) return(1);
    if (winner(coins - k, 1 - player, dp)) return(1);
    if (winner(coins - 1, 1 - player, dp)) return(1);
    dp[coins] = 0;
  }
  return(0);
}

int main()
{
  scanf("%d %d %d", &k, &l, &n);
  while (n --)
  {
    int coins; scanf("%d", &coins);
    int dp[coins]; memset(dp, -1, sizeof(dp));
    printf("%c", winner(coins, 0, dp) ? 'B' : 'A');
  } printf("\n");
  return(0);
}