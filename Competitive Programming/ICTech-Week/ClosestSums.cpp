#include <bits/stdc++.h>
using namespace std;

int findClosestSum(int a[], int n, int s)
{
  int best = 1e9;
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++)
      if (i != j && abs(a[i] + a[j] - s) < abs(best - s))
        best = a[i] + a[j];
  return(best);
}

int main()
{
  int n, t = 1;
  while (scanf("%d", &n) != EOF)
  {
    int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    int m; scanf("%d", &m);
    printf("Case %d:\n", t ++);
    for (int i = 0, s; i < m; i ++)
    {
      scanf("%d", &s);
      int sum = findClosestSum(a, n, s);
      printf("Closest sum to %d is %d.\n", s, sum);
    }
  }
  return(0);
}