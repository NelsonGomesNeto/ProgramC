#include <bits/stdc++.h>

int main()
{
  int sieve[(int) 1e5]; memset(sieve, 0, sizeof(sieve));
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i < 1e5; i ++)
    for (int j = 2; i * j < 1e5; j ++)
      sieve[i * j] = 1;

  for (int i = 0; i < 1e2; i ++)
    printf("%d: %s\n", i, sieve[i] ? "Not prime" : "Prime");
  return(0);
}
