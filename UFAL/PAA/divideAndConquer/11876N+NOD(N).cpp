#include <bits/stdc++.h>
#define DEBUG if(0)
int seq[(int) 1e6];

int binSearch(int lo, int hi, int target, int lower)
{
  int mid = (lo + hi) / 2;
  if (lo >= hi)
    if (lower) return(seq[lo] >= target ? lo : lo + 1);
    else return(seq[lo] <= target ? lo : lo - 1);
  if (target <= seq[mid]) return(binSearch(lo, mid, target, lower));
  else return(binSearch(mid + 1, hi, target, lower));
}

int nod(int n)
{
  int d = 0;
  for (int i = 1; i <= sqrt(n); i ++)
  {
    d += !(n % i);
    if ((n / i) != i) d += !(n % (n / i));
  }
  return(d);
}

int main()
{
  int n = 1, at = 0; seq[0] = 1;
  while (at <= 1e6)
  {
    seq[n] = seq[n - 1] + nod(seq[n - 1]);
    at = seq[n ++];
  }
  DEBUG for (int i = 0; i < 1000; i ++) printf("%d%c", seq[i], i < 1000 - 1 ? ' ' : '\n');

  int tests, run = 0; scanf("%d", &tests);
  while (run ++ < tests)
  {
    int a, b; scanf("%d %d", &a, &b);
    printf("Case %d: %d\n", run, binSearch(0, n - 1, b, 0) - binSearch(0, n - 1, a, 1) + 1);
    DEBUG printf("%d %d\n", binSearch(0, n - 1, b, 0), binSearch(0, n - 1, a, 1));
  }
  return(0);
}