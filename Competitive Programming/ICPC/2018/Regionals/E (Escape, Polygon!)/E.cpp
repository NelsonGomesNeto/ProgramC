#include <bits/stdc++.h>
#define lli long long int
using namespace std;

/*
i < j < k
a[j] > a[k] > a[i] | (a[j] and a[k] left to right) (a[i] right to left, smallest)
a[k] > a[i] > a[j] | (a[k] right to left, biggest) (a[i] and a[j] left to right)
a[i] > a[j] > a[k] | (a[i], a[j] and a[k] left to right)
*/

void printArray(int a[], int n)
{
  for (int i = 0; i < n; i ++)
    printf("%3d%c", a[i], i < n - 1 ? ' ' : '\n');
}

int findPos(vector<int> &a, int target)
{
  int lo = 0, hi = a.size() - 1, mid;
  while (lo < hi)
  {
    // printf("\t%d %d %d", lo, hi, target);
    mid = (lo + hi) >> 1;
    if (a[mid] >= target) hi = mid;
    else lo = mid + 1;
  }
  return(lo);
}

vector<int> right, left;
lli solve(int a[], int n)
{
  lli ans = 0;
  for (int i = 0; i < n - 2; i ++)
    for (int j = i + 1; j < n - 1; j ++)
      for (int k = j + 1; k < n; k ++)
        ans += (1*(a[j] > a[k] && a[k] > a[i])) || (1*(a[k] > a[i] && a[i] > a[j])) || (1*(a[i] > a[j] && a[j] > a[k]));
  return(ans);
}

int main()
{
  int n; scanf("%d", &n);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  int memoRight[n], memoLeft[n]; memo[n - 1] = 0;
  right.push_back(a[n - 1]);
  for (int i = n - 2; i >= 0; i --)
  {
    int pos = findPos(right, a[i]);
    printf("%d %d %d\n", pos, right[pos], a[i]);
    memo[i] = pos + (right[pos] < a[i] ? 1 : 0);
    right.push_back(a[i]); sort(right.begin(), right.end());
  }

  printArray(a, n);
  printArray(memo, n);
  lli ans = solve(a, n);
  printf("%lld\n", ans);
  return(0);
}