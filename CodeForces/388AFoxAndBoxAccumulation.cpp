#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; scanf("%d", &n);
  int a[n], small = 1<<20;
  for (int i = 0; i < n; i ++)
  {
    scanf("%d", &a[i]);
    small = min(small, a[i]);
  }
  sort(a, a+n);

  int blocks = 0;
  for (int i = 0; i < n;)
  {
    int now = 0;
    while (i < n && small == a[i])
    {
      i ++;
      now ++;
    }
    blocks = max(blocks, now);
    if (i < n) small = a[i];
  }
  printf("%d\n", blocks);

  return(0);
}