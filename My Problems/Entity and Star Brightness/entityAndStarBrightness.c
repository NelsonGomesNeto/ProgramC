#include <stdio.h>
#define lli long long int

int amount(lli path, int target)
{
  if (path == 0) return(0);
  return((path % 10 == target) + amount(path / 10, target));
}

int forAmount(lli path, int target)
{
  int now = 0; lli i;
  for (i = path; i; i /= 10)
    now += (i % 10 == target);
  return(now);
}

int main()
{
  int n; scanf("%d", &n);
  int t = 1;
  while (t <= n)
  {
    lli path; scanf("%lld", &path);
    printf("Path %d:\n", t); int k;
    for (k = 1; k <= 9; k ++)
      printf("    Brightness %d: %d\n", k, amount(path, k));
    t ++;
  }
  return(0);
}