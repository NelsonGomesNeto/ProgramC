#include <stdio.h>

int divisors(int i, int n)
{
  if (i == 0)
    return(0);
  return((n % i == 0) + divisors(i - 1, n));
}

int moreDivisors(int a, int b, int bestValue, int best)
{
  if (a == b + 1)
    return(0);
}

int main()
{
  int a, b; scanf("%d %d", &a, &b);
  printf("%d\n", moreDivisors(a, b));
  return(0);
}