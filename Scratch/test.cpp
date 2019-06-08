#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5; int n;
int a[maxN];
int lowerBound(int target, int lo = 0, int hi = n - 1)
{
  if (lo >= hi) return(lo);
  int mid = (lo + hi) >> 1;
  if (target <= a[mid]) return(lowerBound(target, lo, mid));
  return(lowerBound(target, mid + 1, hi));
}
int upperBound(int target, int lo = 0, int hi = n - 1)
{
  if (lo >= hi) return(lo);
  int mid = ((lo + hi) >> 1) + ((lo + hi) & 1);
  if (target >= a[mid]) return(upperBound(target, mid, hi));
  return(upperBound(target, lo, mid - 1));
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i ++) printf("%d%c", a[i], i < n - 1 ? ' ' : '\n');

  int target;
  while (scanf("%d", &target) != EOF)
  {
    int lo = lowerBound(target), hi = upperBound(target);
    printf("target: %d || lowerBound: %d -- %d || upperBound: %d -- %d\n", target, lo, a[lo], hi, a[hi]);
  }

  return(0);
}