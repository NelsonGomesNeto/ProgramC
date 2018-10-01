#include <stdio.h>

int factsum(int n, int d)
{
  if (n <= 0)
    return(0);
  return(n + factsum(n - d, d));
}

int main()
{
  int n, d; scanf("%d %d", &n, &d);
  printf("%d\n", factsum(n, d));
  return(0);
}