#include <stdio.h>
#include <math.h>

double calc(int i, int j, int m)
{
  if (i == -1) return(0);
  if (j == i - 1) return(calc(i - 1, m, m));
  return(sin(j) + cos(j) + calc(i, j - 1, m));
}

int main()
{
  int n, m; scanf("%d %d", &n, &m);
  int i, j; double sum = 0;
  for (i = n; i >= 0; i --)
    for (j = m; j >= i; j --)
      sum += sin(j) + cos(j);

  printf("%lf %lf\n", sum, calc(n, m, m));
}