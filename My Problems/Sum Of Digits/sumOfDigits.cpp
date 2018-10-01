#include <bits/stdc++.h>

int sumDigits(int n)
{
  if (!n) return(0);
  return(n % 10 + sumDigits(n / 10));
}

int main()
{
  int n, k, saved = 0; scanf("%d %d", &n, &k);
  int t = 0;
  while (t <= n)
  {
    if (sumDigits(t) == k)
    {
      printf("%d\n", t);
      saved ++;
    }
    t ++;
  }
  printf("Numbers: %d\n", saved);

  return(0);
}