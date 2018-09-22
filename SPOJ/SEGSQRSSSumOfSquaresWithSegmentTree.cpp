#include <bits/stdc++.h>
#define lli long long int
lli segtree[2][(int) 4e6], lazy[2][(int) 4e6];

void build(lli array[], int lo, int hi, int i, int kind)
{
  if (lo >= hi)
  {
    segtree[kind][i] = array[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  build(array, lo, mid, 2*i, kind);
  build(array, mid + 1, hi, 2*i + 1, kind);
  segtree[kind][i] = segtree[kind][2*i] + segtree[kind][2*i + 1];
}

lli query(int qlo, int qhi, int lo, int hi, int i, int kind)
{
  if (lazy[kind][i] != 0)
  {
    segtree[kind][i] += (hi - lo + 1) * lazy[kind][i];
    if (lo != hi) lazy[kind][2*i] += lazy[kind][i], lazy[kind][2*i + 1] += lazy[kind][i];
    lazy[kind][i] = 0;
  }
  if (lo > qhi || hi < qlo) return(0);
  if (lo >= qlo && hi <= qhi) return(segtree[kind][i]);
  int mid = (lo + hi) / 2;
  return(query(qlo, qhi, lo, mid, 2*i, kind) + query(qlo, qhi, mid + 1, hi, 2*i + 1, kind));
}

void updateRange(int qlo, int qhi, lli x, int lo, int hi, int i, int seg, int kind)
{
  if (lazy[seg][i] != 0)
  {
    segtree[seg][i] = (hi - lo + 1) * lazy[seg][i];
    if (lo != hi) lazy[seg][2*i] += lazy[seg][i], lazy[seg][2*i + 1] += lazy[seg][i];
    lazy[seg][i] = 0;
  }
  if (lo > qhi || hi < qlo) return;
  if (lo >= qlo && hi <= qhi)
  {
    segtree[seg][i] = (hi - lo + 1) * x + (kind ? segtree[seg][i] : 0);
    if (lo != hi) lazy[seg][2*i] += x, lazy[seg][2*i + 1] += x;
    return;
  }
  int mid = (lo + hi) / 2;
  updateRange(qlo, qhi, x, lo, mid, 2*i, seg, kind);
  updateRange(qlo, qhi, x, mid + 1, hi, 2*i + 1, seg, kind);
  segtree[seg][i] = segtree[seg][2*i] + segtree[seg][2*i + 1];
}

int main()
{
  int t; scanf("%d", &t);
  for (int r = 1; r <= t; r ++)
  {
    int n, q; scanf("%d %d", &n, &q);
    lli a[n]; for (int i = 0; i < n; i ++) scanf("%lld", &a[i]);
    lli sq[n]; for (int i = 0; i < n; i ++) sq[i] = a[i] * a[i];
    build(a, 0, n - 1, 1, 0), build(sq, 0, n - 1, 1, 1);

    printf("Case %d:\n", r);
    while (q --)
    {
      int kind, st, nd, x; scanf("%d", &kind);
      if (kind < 2)
      {
        scanf("%d %d %d", &st, &nd, &x); // set range
        updateRange(st - 1, nd - 1, x, 0, n - 1, 1, 0, kind), updateRange(st - 1, nd - 1, x * x, 0, n - 1, 1, 1, kind);
      }
      else if (kind == 2)
      {
        scanf("%d %d", &st, &nd);
        printf("%lld\n", query(st - 1, nd - 1, 0, n - 1, 1, 1));
      }
    }
  }
  return(0);
}