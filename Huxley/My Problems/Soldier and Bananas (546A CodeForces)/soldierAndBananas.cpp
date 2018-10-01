#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli apSum(lli a, lli b, lli q)
{
  return((a + b) / 2.0 * q * (b - a + 1));
}

int main()
{
  lli k, n, w; scanf("%lld %lld %lld", &k, &n, &w);
  lli price = apSum(0, w, k);
  printf("%lld\n", max(0LL, price - n));
  return(0);
}