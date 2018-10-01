#include <stdio.h>

int divisors(int i, int n)
{
  if (i == 0)
    return(0);
  return((n % i == 0) + divisors(i - 1, n));
}

int candySharing(int a, int b, int qbest, int best)
{
  if (a >= b + 1)
    return(best);

  int divi = divisors(a, a);

  if (divi > qbest)
    return(candySharing(a + 1, b, divi, a));
  else
    return(candySharing(a + 1, b, qbest, best));
}

int main()
{
  int a, b; scanf("%d %d", &a, &b);
  int best = candySharing(a + 1, b, divisors(a, a), a);
  printf("%d %d\n", best, divisors(best, best));
  return(0);
}
