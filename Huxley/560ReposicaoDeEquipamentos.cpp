#include <bits/stdc++.h>
using namespace std;
int inf = 1<<20;
int dp[5003][5003];
char path[5003];

int solve(int i, int period, int age, int price, int maintence[], int salePrice[], int scrapPrice[])
{
  if (i == period)
  {
    //dp[i][age] = scrapPrice[age];
    return(-scrapPrice[age]);
  }

  if (dp[i][age] == -1)
  {
    int keep = solve(i + 1, period, 1, price, maintence, salePrice, scrapPrice) - salePrice[age] + price + maintence[0];
    int sell = (age + 1 < period + 5000) ? (solve(i + 1, period, age + 1, price, maintence, salePrice, scrapPrice) + maintence[age]) : inf;
    dp[i][age] = min(keep, sell);
  }

  return(dp[i][age]);
}

void findPath(int i, int age, int period)
{
  if (i == period) return;

  if (dp[i + 1][1] < dp[i + 1][age + 1])
  {
    path[i] = 'B';
    findPath(i + 1, 1, period);
  }
  else
  {
    path[i] = 'M';
    findPath(i + 1, age + 1, period);
  }
}

int main()
{
  memset(dp, -1, sizeof(dp));
  int age, period, price; scanf("%d %d %d", &age, &period, &price);
  int maintence[period + 5000], salePrice[period + 5000], scrapPrice[period + 5000]; memset(maintence, 0, sizeof(maintence)); memset(salePrice, 0, sizeof(salePrice)); memset(scrapPrice, 0, sizeof(scrapPrice));
  for (int i = 0; i < period + 2; i ++) scanf("%d", &maintence[i]);
  for (int i = 0; i < period + 1; i ++) scanf("%d", &salePrice[i + 1]);
  for (int i = 0; i < period + 1; i ++) scanf("%d", &scrapPrice[i + 1]);

  int ans = solve(0, period, age, price, maintence, salePrice, scrapPrice);
  findPath(0, age, period);
  // for (int i = 0; i < period + 2; i ++)
  // {
  //   for (int j = 0; j < period + 2; j ++)
  //     printf("%3d ", dp[i][j]);
  //   printf("\n");
  // }

  path[period] = '\0';
  printf("%d\n%s\n", ans, path);

  return(0);
}