#include <bits/stdc++.h>
int segtree[(int) 4e6], lazy[(int) 4e6];

void printSpacing(int depth)
{
  for (int i = 0; i < depth; i ++) printf("   ");
}

void printSegTree(int lo, int hi, int i, int depth)
{
  printSpacing(depth);
  if (lo >= hi)
  {
    printf("[%d,%d] = %d\n", lo, hi, segtree[i]);
    return;
  }
  int mid = (lo + hi) / 2;
  printf("[%d,%d] = %d\n", lo, hi, segtree[i]);
  printSegTree(lo, mid, 2*i, depth + 1);
  printSegTree(mid + 1, hi, 2*i + 1, depth + 1);
}

void build(int array[], int lo, int hi, int i)
{
  if (lo >= hi)
  {
    segtree[i] = array[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  build(array, lo, mid, 2*i);
  build(array, mid + 1, hi, 2*i + 1);
  segtree[i] = segtree[2*i] + segtree[2*i + 1];
}

int query(int qlo, int qhi, int lo, int hi, int i)
{
  if (lo > qhi || hi < qlo) return(0);
  if (lazy[i] != 0)
  {
    segtree[i] = (hi - lo + 1) * lazy[i];
    if (lo != hi) lazy[2*i] += lazy[i], lazy[2*i + 1] += lazy[i];
    lazy[i] = 0;
  }
  if (lo >= qlo && hi <= qhi) return(segtree[i]);
  int mid = (lo + hi) / 2;
  return(query(qlo, qhi, lo, mid, 2*i) + query(qlo, qhi, mid + 1, hi, 2*i + 1));
}

void updateRange(int array[], int qlo, int qhi, int value, int lo, int hi, int i, int kind)
{
  if (lazy[i] != 0)
  {
    segtree[i] += (hi - lo + 1) * lazy[i];
    if (lo != hi) lazy[2*i] += lazy[i], lazy[2*i + 1] += lazy[i];
    lazy[i] = 0;
  }
  if (lo > qhi || hi < qlo) return;
  if (lo >= qlo && hi <= qhi)
  {
    segtree[i] = (hi - lo + 1) * value + (kind ? segtree[i] : 0);
    if (lo != hi) lazy[2*i] += value, lazy[2*i + 1] += value;
    return;
  }
  int mid = (lo + hi) / 2;
  updateRange(array, qlo, qhi, value, lo, mid, 2*i, kind);
  updateRange(array, qlo, qhi, value, mid + 1, hi, 2*i + 1, kind);
  segtree[i] = segtree[2*i] + segtree[2*i + 1];
}

int main()
{
  int n; scanf("%d", &n);
  int array[n]; for (int i = 0; i < n; i ++) scanf("%d", &array[i]);
  build(array, 0, n - 1, 1);
  printSegTree(0, n - 1, 1, 0);

  char kind;
  while (scanf("%c", &kind) != EOF)
  {
    if (kind == 'Q')
    {
      int lo, hi; scanf("%d %d", &lo, &hi);
      printf("Sum(%d, %d) = %d\n", lo, hi, query(lo, hi, 0, n - 1, 1));
    }
    else if (kind == 'U')
    {
      int lo, hi, add; scanf("%d %d %d", &lo, &hi, &add); updateRange(array, lo, hi, add, 0, n - 1, 1, 1);
      printf("UpdateRange((%d, %d) with %d)\n", lo, hi, add);
      printSegTree(0, n - 1, 1, 0);
    }
    else if (kind == 'S')
    {
      int lo, hi, add; scanf("%d %d %d", &lo, &hi, &add); updateRange(array, lo, hi, add, 0, n - 1, 1, 0);
      printf("SetRange((%d, %d) with %d)\n", lo, hi, add);
      printSegTree(0, n - 1, 1, 0);
    }
  }
  return(0);
}