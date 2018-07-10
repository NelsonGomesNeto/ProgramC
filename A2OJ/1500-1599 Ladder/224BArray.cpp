#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

int main()
{
  int n, k; scanf("%d %d", &n, &k);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  int diff[n + 1]; diff[0] = 0; set<int> now;
  for (int i = 0; i < n; i ++)
  {
    now.insert(a[i]);
    diff[i + 1] = now.size();
  }
  DEBUG for (int i = 0; i <= n; i ++)
    printf("%d %d\n", i, diff[i]);

  if (diff[n] < k) printf("-1 -1\n");
  else
  {
    int l = -1, r = -1, minSize = n + 1;
    for (int i = 1; i <= n; i ++)
    {
      while (i + 1 <= n && diff[i] == diff[i + 1]) i ++;
      int end = lower_bound(diff, diff+n+1, k + diff[i] - (i > 0)) - diff;
      DEBUG if (end <= n) printf("%d %d %d %d\n", i, end, diff[i], diff[end]);
      if (end >= i && end <= n && diff[end] - diff[i] + (i > 0) == k && end - i + 1 < minSize)
      {
        l = i;
        r = end;
        minSize = end - i + 1;
      }
    }
    printf("%d %d\n", l, r);
  }

  return(0);
}
