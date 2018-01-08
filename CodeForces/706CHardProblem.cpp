#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli dp[(int) 1e5][4];

lli solve(lli cost[], string toSort[], int i, int s, int done)
{
  if (i == s - 1) return(0);
  if (dp[i][done] == -1)
  {
    lli ans = 1e12, atLeastOne = 0; string auxb = toSort[i], auxa = toSort[i + 1];
    if (auxb <= auxa)
    {
      ans = min(ans, solve(cost, toSort, i + 1, s, 0));
      atLeastOne ++;
    }
    reverse(auxb.begin(), auxb.end());
    if (auxb <= auxa && (done != 2 && done != 3))
    {
      ans = min(ans, cost[i] + solve(cost, toSort, i + 1, s, 1));
      atLeastOne ++;
    }
    reverse(auxa.begin(), auxa.end());
    if (auxb <= auxa && (done != 2 && done != 3))
    {
      lli aux = cost[i + 1]; cost[i + 1] = 1e9;
      ans = min(ans, cost[i] + aux + solve(cost, toSort, i + 1, s, 2));
      cost[i + 1] = aux;
      atLeastOne ++;
    }
    reverse(auxb.begin(), auxb.end());
    if (auxb <= auxa)
    {
      lli aux = cost[i + 1]; cost[i + 1] = 1e9;
      ans = min(ans, aux + solve(cost, toSort, i + 1, s, 3));
      cost[i + 1] = aux;
      atLeastOne ++;
    }
    dp[i][done] = atLeastOne ? ans : 1e12;
  }
  return(dp[i][done]);
}

int main()
{
  memset(dp, -1, sizeof(dp));
  int s; scanf("%d", &s);
  lli cost[s]; string toSort[s];
  for (int i = 0; i < s; i ++)
    scanf("%lld", &cost[i]);
  for (int i = 0; i < s; i ++)
  {
    getchar();
    cin >> toSort[i];
  }

  lli best = solve(cost, toSort, 0, s, 0);

  printf("%lld\n", best >= 1e9 ? -1 : best);

  return(0);
}