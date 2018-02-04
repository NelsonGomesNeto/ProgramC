#include <bits/stdc++.h>
#define DEBUG if(0)
#define DEBUG2 if(0)
#define uli unsigned long long int
uli all[1000001], sum[1000002];

void printBin(uli n)
{
  if (!n) { printf("0"); return; }
  printBin(n >> 1);
  printf("%llu", (n % 2));
}

uli lfsr(int tap[], int t, int bits, uli at)
{
  uli now = at >> 1;
  bool bit = at & 1;
  DEBUG2 printBin(bit); DEBUG2 printf("\n\n");
  for (int i = 1; i < t; i ++)
  {
    bit ^= (at & (1 << (tap[i]))) >> tap[i];
    DEBUG2 printBin((at & (1 << (tap[i]))) >> tap[i]); DEBUG2 printf("\n");
    DEBUG2 printBin(bit); DEBUG2 printf("\n\n");
  }

  now |= (bit << (bits - 1));
  now &= (1 << (bits)) - 1;
  return(now);
}

int main()
{
  uli a0;
  int n, t, x, y; scanf("%d %d %llu %d %d", &n, &t, &a0, &x, &y);
  int tap[t];
  for (int i = 0; i < t; i ++)
    scanf("%d", &tap[i]);
  DEBUG2 printBin(a0); DEBUG2 printf("\n");

  uli at = a0; all[0] = a0;
  sum[0] = 0; sum[1] = a0;
  for (int i = 1; i <= 1000000; i ++)
  {
    all[i] = lfsr(tap, t, n, all[i - 1]);
    sum[i] = all[i - 1] + sum[i - 1];
  } sum[1000001] = all[1000000] + sum[1000000];

  DEBUG for (int i = 0; i <= 1000; i ++)
  {
    printf("%d %llu ", i, all[i]);
    printBin(all[i]); printf("\n");
  }

  int bi, bj; bi = bj = 1<<20;
  for (int i = 0; i <= bj; i ++)
  {
    if (i == 1500) break;
    for (int j = i + 1; j <= 1000000; j ++)
    {
      if ((j - i) >= y && !((sum[j] - sum[i]) % x))
        if (j < bj || (j == bj && i < bi))
        {
          bi = i; bj = j - 1; break;
        }
    }
  }

  if (bi == 1<<20)
    printf("impossivel\n");
  else
    printf("%d %d\n", bi, bj);

  return(0);
}