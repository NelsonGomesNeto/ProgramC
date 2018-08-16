#include <stdio.h>
#define lli long long int

int countPrimes(lli number)
{
  if (!number) return(0);
  int digit = number % 10;
  return((digit == 2 || digit == 3 || digit == 5 || digit == 7) + countPrimes(number / 10));
}

int main()
{
  int n; scanf("%d", &n);
  double mean = 0, lol = n;
  while (n --)
  {
    lli number; scanf("%lld", &number);
    mean += countPrimes(number);
    printf("Prime digits: %d\n", countPrimes(number));
  }
  // printf("Mean: %lf\n", mean / lol);
  return(0);
}