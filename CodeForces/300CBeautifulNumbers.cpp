#include <bits/stdc++.h>
#define DEBUG if(0)
#define lli long long int
lli mod = 1000000007;
int a, b, n;

int valid(int num[])
{
  DEBUG for (int j = 0; j < n; j ++) printf("%d%c", num[j], j < n - 1 ? ' ' : ' ');
  DEBUG printf(" || %d %d\n", a, b);
  lli now = 0;
  for (int i = 0; i < n; i ++)
  {
    if (num[i] != a && num[i] != b) return(0);
    now += num[i];
  }
  // printf("%lld\n", now);
  lli aux = now;
  while (now > 0)
  {
    int remain = now % 10;
    if (remain != a && remain != b) return(0);
    now /= 10;
  }
  // printf("== %lld\n", aux);
  return(1);
}

lli solve(int num[], int i)
{
  lli ans = valid(num);
  // DEBUG for (int j = 0; j < n; j ++) printf("%d%c", num[j], j < n - 1 ? ' ' : '\n');
  if (i == -1) return(ans);

  for (int k = 0; k < 10; k ++)
  {
    num[i] = k;
    ans = (ans + solve(num, i - 1)) % mod;
  }
  return(ans);
}

int main()
{
  scanf("%d %d %d", &a, &b, &n);
  int num[n]; memset(num, 0, sizeof(num));
  lli ans = solve(num, n - 1);
  printf("%lld\n", ans);
  return(0);
}