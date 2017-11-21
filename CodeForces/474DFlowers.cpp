#include <bits/stdc++.h>
#define DEBUG if(1)
#define MOD % ((long long int) 1e9 + 7)
char formed[(int) 1e5 + 1];

long long int fibonacci[(int) 1e5 + 1];

int ways(int i, int now, int size, int k) // HOLLY SHIT, THIS IS FIBONACCI HAHAHAHAHAA
{
  if (i == size)
  {
    formed[i] = '\0';
    //printf("%s\n", formed);
    return(1);
  }

  int ans = 0;
  if (now == k || !now)
  {
    formed[i] = 'R';
    ans = ways(i + 1, 0, size, k);
  }
  if (size - i >= k - now)
  {
    formed[i] = 'W';
    ans += ways(i + 1, (now + 1) % k, size, k);
  }

  return(ans);
}

void fillFib()
{
  long long int a1 = 0, a2 = 1, aux;
  for (int i = 1; i <= 1e5; i ++)
  {
    fibonacci[i] = (a1 + a2) MOD;
    a1 = a2; a2 = fibonacci[i];
  }
}

int main()
{
  fillFib();
  int tests, k; scanf("%d %d", &tests, &k);
  long long int ans[(int) 1e5 + 1], now = 0; ans[0] = 0;
  for (int i = 1; i <= 1e5; i ++)
  {
    if (i < k)
      now = (now + 1);
    else
      now = (now + fibonacci[i - k + 2]);
    ans[i] = now;
    //printf("%d %lld %lld\n", i, now, ans[i]);
  }
  while (tests -- > 0)
  {
    int a, b; scanf("%d %d", &a, &b);
    //DEBUG for (int i = 1; i <= 1e5; i ++) printf("%d -> %d\n", i, ways(0, 0, i, k));
    DEBUG for (int i = 1; i <= 1e5; i ++) printf("%d -> %lld\n", i, fibonacci[i]);

    //printf("%lld %lld\n", ans[b - 1], ans[a - 1]);
    printf("%lld\n", (ans[b] - ans[a - 1]) MOD);
  }
  return(0);
}