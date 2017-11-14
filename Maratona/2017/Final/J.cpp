#include <bits/stdc++.h>
using namespace std;
char lake[100000];

int test(int start, int k, int size)
{
  if (lake[start] == 'P') return(0);
  int now = (start + k) % size;
  while (now != start)
  {
    if (lake[now] == 'P') return(0);
    now = (now + k) % size;
  }
  return(1);
}

int main()
{
  int i, j, size = 100000, root = sqrt(100000);
  int sieve[size];
  memset(sieve, 1, sizeof(sieve));
  sieve[0] = sieve[1] = 0;
  set<int> primes;
  for (i = 2; i <= root; i ++)
    if (sieve[i])
    {
      primes.insert(i);
      for (j = 2; i*j <= size; j ++)
        sieve[i*j] = 0;
    }

  for (i = root; i <= size; i ++) if (sieve[i]) primes.insert(i);
  primes.insert(1);

  scanf("%s", lake);

  size = strlen(lake);
  int can[size]; memset(can, 1, sizeof(can)); can[0] = 0;
  for (auto k: primes)
  {
    for (i = 0; i < k; i ++)
    {
      if (test(i, k, size))
      {
        for (j = 1; k*j < size; j ++) can[k*j] = 1;
        break;
      }
    }
  }

  int total = 0;
  for (i = 0; i < size; i ++)
  {
    printf("%d - %d\n", i, can[i]);
    total += can[i];
  }

  printf("%d\n", total);

  return(0);
}