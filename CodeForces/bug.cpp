#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

void printArray(int a[], int size)
{
  for (int i = 0; i < size; i ++) printf("%d%c", a[i], i < size - 1 ? ' ' : '\n');
}

void printSet(set<int> s)
{
  for (auto i: s) printf("%d ", i);
  printf("\n");
}

int validRange(set<int> range)
{
  if (range.empty()) return(1);
  return((*range.rbegin() - *range.begin()) <= 1);
}

int main()
{
  int n; scanf("%d", &n);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

  int app[100001]; memset(app, 0, sizeof(app));
  int lo = 0, hi = 0, ans = 1; set<int> range;
  while (lo < n && hi < n)
  {
    while (hi < n && validRange(range))
    {
      // printSet(range);
      // printf("%d %d (%d %d) %d\n", lo, hi, *range.end(), *range.begin(), a[hi]);
      app[a[hi]] ++; range.insert(a[hi]);
      if (validRange(range)) ans = max(ans, hi - lo + 1);
      hi ++;
    }
    while (lo < n && hi < n && !validRange(range))
    {
      app[a[lo]] --; if (!app[a[lo]]) range.erase(a[lo]);
      lo ++;
    }
  }

  printf("%d\n", ans);

  return(0);
}