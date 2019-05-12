#include <bits/stdc++.h>
#define lli long long int
using namespace std;

/* Tutorial:
  Divide and Conquer FOR THE WIN
  You have two options:
    Horizontal:
      Fill the whole fence from left to right
      At first, that will be done min(a1, a2, ..., an) times
      This will split a segment into many others
    Vertical:
      Fill each plank, so: right - left + 1 times
      This will end a segment

  You start by the whole fence: lo = 0, hi = n - 1, currentHeight = 0
    vertical choice will always be: hi - lo + 1
    horizontal choice will be: min(a1, a2, ..., an) - currentHeight
      But you will end up splitting this segment into others, since you
      can no longer fill the next heights with a single stroke
      For each new segment: horizontal += recursiveCall(newLo, newHi, min(a1, a2, ..., an))
    return(min(vertical, horizontal))
*/

const int maxN = 5e3; int n;
lli a[maxN];

lli minimumHeight(int lo, int hi)
{
  lli h = 1e9 + 1;
  for (int i = lo; i <= hi; i ++) h = min(h, a[i]);
  return(h);
}

lli solve(int lo = 0, int hi = n - 1, lli h = 0)
{
  lli newHeight = minimumHeight(lo, hi), horizontal = 0, vertical = hi - lo + 1;
  horizontal += newHeight - h;
  for (int i = lo; i <= hi; i ++)
  {
    if (a[i] <= newHeight) continue;
    int end = i + 1; while (end <= hi && newHeight < a[end]) end ++;
    horizontal += solve(i, end - 1, newHeight);
    i = end - 1;
  }
  return(min(horizontal, vertical));
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i ++)
    scanf("%lld", &a[i]);

  lli ans = solve();
  printf("%lld\n", ans);

  return(0);
}