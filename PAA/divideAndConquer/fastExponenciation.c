#include <stdio.h>
#include <math.h>

long double pot(long double x, long long int n)
{
  if (n == 0)
    return(1);
  if (n == 1)
    return(x);

  if (n & 1) // (n & 1) means odd, same as (n % 2) != 0
  {
    long double half = pot(x, (n - 1) / 2);
    return(half * half * x);
  }
  else
  {
    long double half = pot(x, n / 2);
    return(half * half);
  }
}

long double naivePot(long double x, long long int n)
{
  long double aux = x; long long int i;
  for (i = 0; i < n; i ++)
    x *= aux;

  return(x);
}

int main()
{
  long double x; long long int n;
  int mode; scanf("%d", &mode);

  if (mode == 0) // fast
    while (scanf("%Lf %Ld", &x, &n) != EOF)
      printf("%Lg\n", pot(x, n));
  else if (mode == 1) // math.h
    while (scanf("%Lf %Ld", &x, &n) != EOF)
      printf("%lg\n", pow(x, n));
  else // naive
    while (scanf("%Lf %Ld", &x, &n) != EOF)
      printf("%Lg\n", naivePot(x, n));

  return(0);
}