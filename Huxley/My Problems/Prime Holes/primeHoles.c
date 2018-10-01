#include <stdio.h>
#include <math.h>
int dh[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int holes(long long int n)
{
  if (n <= 9) return(dh[n]);
  return(dh[n % 10] + holes(n / 10));
}

int isPrime(int i, int n)
{
  if (i <= 1) return(n > 1);
  return(!(n % i == 0) * isPrime(i - 1, n));
}

int main()
{
  long long int n; scanf("%lld", &n);
  int h = holes(n);
  printf("%c\n", isPrime(sqrt(h), h) ? 'S' : 'N');
  return(0);
}
// 9223372036854775807