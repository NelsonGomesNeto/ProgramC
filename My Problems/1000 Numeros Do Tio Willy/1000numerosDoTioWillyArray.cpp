#include <bits/stdc++.h>

int main()
{
  int n, ar[1000];
  while (scanf("%d", &n) && n != -1)
  {
    memset(ar, 0, sizeof(ar));
    ar[n] ++;
    for (int i = 0; i < 999; i ++)
    {
      scanf("%d", &n);
      ar[n] ++;
    }
    int wanted; scanf("%d", &wanted);
    printf("%d appeared %d times\n", wanted, ar[wanted]);
  }
  return(0);
}