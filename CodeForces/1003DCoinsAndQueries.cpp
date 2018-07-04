#include <bits/stdc++.h>
using namespace std;
#define lli long long int
unordered_map<lli, lli> dp;

int main()
{
  int n, q; scanf("%d %d", &n, &q);
  lli a[n]; for (int i = 0; i < n; i ++) scanf("%lld", &a[i]);
  sort(a, a+n);

  while (q --)
  {
    lli query; scanf("%lld", &query);
    if (query & 1)
      printf("-1\n");
    else
    {
      if (!dp.count(query))
      {
        int amount = 0, now = n;
        do
        {
          int pos = lower_bound(a, a+now, query) - a;
          pos = min(pos, now - 1);
          // printf("%d %lld %lld\n", pos, a[pos], query);
          now = pos; amount ++;
          if (a[pos] == query) break;
          query -= a[pos];
        } while(1);
        dp[query] = amount;
      }
      printf("%lld\n", dp[query]);
    }
  }
  return(0);
}