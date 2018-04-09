#include <bits/stdc++.h>
#define lli long long int

int main()
{
  lli a = 0, b = 1, c = 1, d = 2;
  for (int i = 0; i < 100; i ++)
  {
    lli ad = d, ac = c, ab = b;
    d = c + d;
    c = ad; b = ac; a = ab;
    lli lol = (d * a) - (b * c);
    printf("%Ld %Ld %Ld %Ld %Ld\n", lol, a, b, c, d);
  }
  return(0);
}
