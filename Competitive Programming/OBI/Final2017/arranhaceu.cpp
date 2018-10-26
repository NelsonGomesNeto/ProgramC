#include <bits/stdc++.h>
#define lli long long int

int createSegmentTree(int segmentTree[], int array[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    segmentTree[i] = array[lo];
    return(segmentTree[i]);
  }
  else if (lo > hi) return(0);

  int mid = (lo + hi) / 2;
  segmentTree[i] = createSegmentTree(segmentTree, array, 2*i + 1, lo, mid) + createSegmentTree(segmentTree, array, 2*i + 2, mid + 1, hi);
  return(segmentTree[i]);
}

int gs(int segmentTree[], int i, int lo, int hi, int qlo, int qhi)
{
  if (lo >= qlo && hi <= qhi)
    return(segmentTree[i]);
  else if (hi < qlo || lo > qhi)
    return(0);

  int mid = (lo + hi) / 2;
  return(gs(segmentTree, 2*i + 1, lo, mid, qlo, qhi) + gs(segmentTree, 2*i + 2, mid + 1, hi, qlo, qhi));
}

int getSum(int segmentTree[], int size, int lo, int hi)
{
  if (lo < 0 || hi > size - 1 || lo > hi)
    return(-1);

  return(gs(segmentTree, 0, 0, size - 1, lo, hi));
}

void uv(int segmentTree[], int i, int diff, int lo, int hi, int pos)
{
  if (lo > pos || hi < pos)
    return;

  segmentTree[i] += diff;
  if (lo != hi)
  {
    int mid = (lo + hi) / 2;
    uv(segmentTree, 2*i + 1, diff, lo, mid, pos);
    uv(segmentTree, 2*i + 2, diff, mid + 1, hi, pos);
  }
}

void updateValue(int segmentTree[], int array[], int size, int pos, int value)
{
  if (pos < 0 || pos > size - 1)
    return;

  int diff = value - array[pos];
  array[pos] = value;
  uv(segmentTree, 0, diff, 0, size - 1, pos);
}

int main()
{
  int floors, events; scanf("%d %d", &floors, &events);
  int building[floors], i;
  for (i = 0; i < floors; i ++)
    scanf("%d", &building[i]);

  int segmentTree[2 * (lli) pow(2, (lli) log2(floors) + 1) - 1];
  createSegmentTree(segmentTree, building, 0, 0, floors - 1);

  for (i = 0; i < events; i ++)
  {
    int kind; scanf("%d", &kind);
    if (kind)
    {
      int pos; scanf("%d", &pos);
      printf("%d\n", getSum(segmentTree, floors, 0, pos - 1));
    }
    else
    {
      int pos, people; scanf("%d %d", &pos, &people);
      updateValue(segmentTree, building, floors, pos - 1, people);
    }
  }

  return(0);
}