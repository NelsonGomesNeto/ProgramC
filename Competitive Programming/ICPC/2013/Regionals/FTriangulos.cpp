#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define DEBUG2 if(0)

int main()
{
  int n;
  while (scanf("%d", &n) != EOF)
  {
    int x[n], d[n + 1], size = 0, equi; d[0] = 0;
    for (int i = 0; i < n; i ++)
    {
      scanf("%d", &x[i]);
      size += x[i];
      d[i + 1] = size;
    }

    equi = size / 3;
    DEBUG printf("%d - %d\n", size, equi);
    DEBUG for (int i = 0; i < n; i ++) printf("%d%c", x[i], i < n - 1 ? ' ' : '\n');
    DEBUG for (int i = 0; i < n + 1; i ++) printf("%d%c", d[i], i < n ? ' ' : '\n');

    int has = 0, i, j, k;
    for (i = 0, j = 1, k = 2; i < n; i ++)
    {
      DEBUG2 printf("%d %d %d\n", i, j, k);
      while (j < n && d[j] - d[i] < equi) j ++;
      if (j < n && d[j] - d[i] == equi)
      {
        k = max(k, j + 1);
        DEBUG printf("Foi %d %d %d\n", i, j, k);
        while (k < n && d[k] - d[j] < equi) k ++;
        if (k < n && d[j] - d[i] == equi && d[k] - d[j] == equi && (size - d[k] + d[i] == equi))
        {
          DEBUG printf("Holly %d %d %d\n", i, j, k);
          has ++;
        }
      }
      if (d[j] - d[i] == equi && d[k] - d[j] > equi) k --;
      if (d[j] - d[i] > equi) j --;
    }
    printf("%d\n", has);
  }
  return(0);
}