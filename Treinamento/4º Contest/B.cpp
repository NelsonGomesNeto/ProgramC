#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
multiset<int> nullSet;

multiset<int> createSegmentTree(multiset<int> segmentTree[], int array[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    segmentTree[i] = {array[lo]};
    return(segmentTree[i]);
  }
  else if (lo > hi) return(nullSet);
  int mid = (lo + hi) / 2;
  multiset<int> left = createSegmentTree(segmentTree, array, 2*i + 1, lo, mid);
  multiset<int> right = createSegmentTree(segmentTree, array, 2*i + 2, mid + 1, hi);

  segmentTree[i].insert(left.begin(), left.end()); segmentTree[i].insert(right.begin(), right.end());
  return(segmentTree[i]);
}

multiset<int> gs(multiset<int> segmentTree[], int i, int lo, int hi, int qlo, int qhi)
{
  if (lo >= qlo && hi <= qhi) return(segmentTree[i]);
  else if (lo > qhi || hi < qlo) return(nullSet);

  int mid = (lo + hi) / 2;
  multiset<int> left = gs(segmentTree, 2*i + 1, lo, mid, qlo, qhi);
  multiset<int> right = gs(segmentTree, 2*i + 2, mid + 1, hi, qlo, qhi);
  multiset<int> ans; ans.insert(left.begin(), left.end()); ans.insert(right.begin(), right.end());
  return(ans);
}

multiset<int> getSum(multiset<int> segmentTree[], int size, int lo, int hi)
{
  if (lo < 0 || hi > size - 1 || lo > hi) return(nullSet);
  return(gs(segmentTree, 0, 0, size - 1, lo, hi));
}

int main()
{
  int n; scanf("%d", &n);
  int array[n];
  for (int i = 0; i < n; i ++)
    scanf("%d", &array[i]);

  multiset<int> segmentTree[(int) 1e5];
  createSegmentTree(segmentTree, array, 0, 0, n - 1);

  int q; scanf("%d", &q);
  while (q -- > 0)
  {
    int lo, hi, k; scanf("%d %d %d", &lo, &hi, &k);
    multiset<int> lolSum = getSum(segmentTree, n, lo - 1, hi - 1);
    DEBUG for (auto i: lolSum)
      printf("%d ", i);
    DEBUG printf("\n");
    multiset<int>::iterator pos = lolSum.upper_bound(k);
    multiset<int> qqq; qqq.insert(pos, lolSum.end());
    printf("%d\n", (int) qqq.size());
  }
  return(0);
}