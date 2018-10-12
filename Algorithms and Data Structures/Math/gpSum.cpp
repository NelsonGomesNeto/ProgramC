#include <bits/stdc++.h>
#define lli long long int

double apSum(lli a1, double r, lli n)
{
  return(a1 * (1 - pow(r, n)) / (1 - r));
}

int main()
{
  lli a1, n; double r;
  while (scanf("%lld %lf %lld", &a1, &r, &n) != EOF)
    printf("[%lld, %.3lf, %lld] = %.6lf\n", a1, r, n, apSum(a1, r, n));
  return(0);
}