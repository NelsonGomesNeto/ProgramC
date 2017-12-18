#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli mod = (1e9 + 7);

int main()
{
  lli a, k;
  scanf("%lld\n%lld", &a, &k);

  int at[10], size = 0; memset(at, 0, sizeof(at));
  while (a > 0)
  {
    if (a % 5 == 0) at[size] = 1;
    a /= 10;
    size ++;
  }
  reverse(at, at+size);
  for (int i = 0; i < size; i ++) printf("%d\n", at[i]);

  lli total = 0;
  for (int i = 0; i < size; i ++)
  {
    total = (total + pow(2, i)) % mod ;
  }

  return(0);
}