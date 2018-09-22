#include <bits/stdc++.h>

void printSpacing(int depth)
{
  for (int i = 0; i < depth; i ++) printf("   ");
}

void printSegTree(int segtree[], int lo, int hi, int i, int depth)
{
  printSpacing(depth);
  if (lo >= hi)
  {
    printf("[%d,%d] = %d\n", lo, hi, segtree[i]);
    return;
  }
  int mid = (lo + hi) / 2;
  printf("[%d,%d] = %d\n", lo, hi, segtree[i]);
  printSegTree(segtree, lo, mid, 2*i, depth + 1);
  printSegTree(segtree, mid + 1, hi, 2*i + 1, depth + 1);
}

void build(int segtree[], int array[], int lo, int hi, int i)
{
  if (lo >= hi)
  {
    segtree[i] = array[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  build(segtree, array, lo, mid, 2*i);
  build(segtree, array, mid + 1, hi, 2*i + 1);
  segtree[i] = segtree[2*i] + segtree[2*i + 1];
}

int query(int segtree[], int qlo, int qhi, int lo, int hi, int i)
{
  if (lo > qhi || hi < qlo) return(0);
  if (lo >= qlo && hi <= qhi) return(segtree[i]);
  int mid = (lo + hi) / 2;
  return(query(segtree, qlo, qhi, lo, mid, 2*i) + query(segtree, qlo, qhi, mid + 1, hi, 2*i + 1));
}

void update(int segtree[], int array[], int pos, int value, int lo, int hi, int i)
{
  if (lo > pos || hi < pos || lo > hi) return;
  if (lo == pos && hi == pos)
  {
    segtree[i] += value - array[lo];
    array[lo] = value;
  }
  int mid = (lo + hi) / 2;
  update(segtree, array, pos, value, lo, mid, 2*i);
  update(segtree, array, pos, value, mid + 1, hi, 2*i + 1);
}

int main()
{
  int n; scanf("%d", &n);
  int array[n]; for (int i = 0; i < n; i ++) scanf("%d", &array[i]);
  int segtree[4 * n]; build(segtree, array, 0, n - 1, 1);
  printSegTree(segtree, 0, n - 1, 1, 0);

  char kind;
  while (scanf("%c", &kind) != EOF)
  {
    if (kind == 'Q')
    {
      int lo, hi; scanf("%d %d", &lo, &hi);
      printf("Sum(%d, %d) = %d\n", lo, hi, query(segtree, lo, hi, 0, n - 1, 1));
    }
    else if (kind == 'U')
    {
      int pos, value; scanf("%d %d", &pos, &value); update(segtree, array, pos, value, 0, n - 1, 1);
      printSegTree(segtree, 0, n - 1, 1, 0);
    }
  }
  return(0);
}