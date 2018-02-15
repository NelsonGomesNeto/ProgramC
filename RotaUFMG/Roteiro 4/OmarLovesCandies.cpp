#include <bits/stdc++.h>
#define DEBUG if(0)
int mat[1000][1000], sum[1000][1000];

void printMat(int a[][1000], int n, int m)
{
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      printf("%d%c", a[i][j], j < m - 1 ? ' ' : '\n');
}

int main()
{
  int t; scanf("%d", &t);
  while (t --)
  {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
        scanf("%d", &mat[i][j]);

    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
      {
        sum[i][j] = mat[i][j];
        if (i) sum[i][j] += sum[i - 1][j];
        if (j) sum[i][j] += sum[i][j - 1];
        if (i && j) sum[i][j] -= sum[i - 1][j - 1];
      }

    DEBUG printMat(sum, n, m);

    int bestSum = sum[0][0];
    for (int li = 0; li < n; li ++)
      for (int lj = 0; lj < m; lj ++)
        for (int hi = li; hi < n; hi ++)
          for (int hj = lj; hj < m; hj ++)
          {
            int now = sum[hi][hj];
            if (li) now -= sum[li - 1][hj];
            if (lj) now -= sum[hi][lj - 1];
            if (li && lj) now += sum[li - 1][lj - 1];
            DEBUG printf("%d %d %d %d %d\n", li, lj, hi, hj, now);
            if (now > bestSum) bestSum = now;
          }

    printf("%d\n", bestSum);
  }
  return(0);
}