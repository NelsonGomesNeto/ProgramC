#include <bits/stdc++.h>
using namespace std;
#define lli long long int
pair<lli, lli> boxes[(int) 1e3];

bool comp(pair<lli, lli> i, pair<lli, lli> j) { return(i.first + i.second < j.first + j.second); }

int main()
{
  int n; scanf("%d", &n);
  for (int i = 0; i < n; i ++) scanf("%lld %lld", &boxes[i].first, &boxes[i].second);
  sort(boxes, boxes+n, comp);

  lli best[n + 1]; for (int i = 0; i <= n; i ++) best[i] = 1000000047;
  best[0] = 0; int maxCount = 0;
  for (int i = 0; i < n; i ++)
    for (int j = maxCount + 1; j > 0; j --)
      if (boxes[i].second >= best[j - 1] && best[j - 1] + boxes[i].first < best[j])
        best[j] = best[j - 1] + boxes[i].first, maxCount = max(maxCount, j);

  printf("%d\n", maxCount);
  return(0);
}
