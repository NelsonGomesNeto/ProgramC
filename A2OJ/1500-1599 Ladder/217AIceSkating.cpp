#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; scanf("%d", &n);
  int mins = 1<<20, sn, x[n], y[n];
  for (int i = 0; i < n; i ++) scanf("%d %d", &x[i], &y[i]);

  for (int j = 0; j < n; j ++)
  {
    int xx[1001], yy[1001]; memset(xx, 0, sizeof(xx)); memset(yy, 0, sizeof(yy));
    sn = -1;
    for (int i = j, k = 0; k < n; i ++, k ++)
    {
      i %= n;
      if (!xx[x[i]] && !yy[y[i]]) sn ++;
      xx[x[i]] = 1; yy[y[i]] = 1;
    }
    mins = min(mins, sn);
  }
  printf("%d\n", mins);

  return(0);
}