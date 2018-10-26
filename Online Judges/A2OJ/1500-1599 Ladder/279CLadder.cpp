#include <bits/stdc++.h>
#define DEBUG if(1)
using namespace std;

int main()
{
  int n, m; scanf("%d %d", &n, &m);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  int lol[n], i = 1, now = 0; lol[n - 1] = n + 1;
  while (i < n)
  {
    lol[0] = 0; if (i == 1 && n > 1) now += a[i + 1] < a[i];
    while (i < n && a[i] >= a[i - 1])
    {
      lol[i] = now;
      i ++;
    }
    if (i < n) lol[i] = now;
    now ++;
    while (i < n && a[i] <= a[i - 1])
    {
      lol[i] = now;
      i ++;
    }
    if (i < n) lol[i] = now;
    // now ++;
  } if (lol[n - 1] == n + 1 && n > 1) lol[n - 1] = lol[n - 2];
  DEBUG for (int j = 0; j < n; j ++) printf("%d%c", lol[j], j < n - 1 ? ' ' : '\n');

  int q[m][2];
  for (int j = 0; j < m; j ++)
  {
    scanf("%d %d", &q[j][0], &q[j][1]);
    q[j][0] --; q[j][1] --;
    if (n == 1) printf("Yes\n");
  }

  if (n != 1)
  {
    for (int j = 0; j < m; j ++)
    {
      if (lol[q[j][1]] - lol[q[j][0]] <= 1) printf("Yes\n");
      else printf("No\n");
    }
  }
  return(0);
}
