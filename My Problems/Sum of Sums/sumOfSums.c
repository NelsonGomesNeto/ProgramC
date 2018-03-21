#include <stdio.h>
#include <math.h>

double sumBug(int i, int j, int n, int m)
{
  if (i >= n + 1) return(0);
  if (j >= m + 1) return(sumBug(i + 1, i + 1, n, m));
  return(sin(j) + cos(j) + sumBug(i, j + 1, n, m));
}

int main()
{
  int n, m; scanf("%d %d", &n, &m);
  int i, j; double sum;
  for (i = 0; i <= n; i ++)
    for (j = i; j <= m; j ++)
      sum += sin(j) + cos(j);

  printf("%lf\n", sum);
  //printf("%lf\n", sumBug(0, 0, n, m));

  return(0);
}