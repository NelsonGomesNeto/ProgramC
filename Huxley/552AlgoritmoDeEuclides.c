#include <stdio.h>

int mdc(int a, int d)
{
  if (a % d == 0)
    return(d);
  return(mdc(d, a % d));
}

void read(int n)
{
  if (n == 0)
    return;
  int a, d;
  scanf("%d %d", &a, &d);
  printf("MDC(%d,%d) = %d\n", a, d, mdc(a, d));
  read(n - 1);
}

int main()
{
  int n;
  scanf("%d", &n);
  read(n);
  return(0);
}