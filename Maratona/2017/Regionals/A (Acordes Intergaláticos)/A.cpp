#include <bits/stdc++.h>
int segTree[9][(int) 4e5], lazy[9][(int) 4e5];
int notes[(int) 1e5];
int n, q;

void build(int lo, int hi, int i, int note)
{
  if (lo >= hi)
  {
    segTree[note][i] = notes[lo] == note;
    return;
  }

  int mid = (lo + hi) / 2;
  build(lo, mid, 2*i, note);
  build(mid + 1, hi, 2*i + 1, note);
  segTree[note][i] = segTree[note][2*i] + segTree[note][2*i + 1];
}

int getSum(int qlo, int qhi, int lo, int hi, int i, int note)
{
  if (lo > qhi || hi < qlo) return(0);
  if (lo >= qlo && hi <= qhi) return(segTree[note][i]);

  int mid = (lo + hi) / 2;
  return(getSum(qlo, qhi, lo, mid, 2*i, note) + getSum(qlo, qhi, mid + 1, hi, 2*i + 1, note));
}

void updateRange(int qlo, int qhi, int lo, int hi, int i, int note, int value)
{
  if (lazy[note][i] != 0)
  {
    segTree[note][i] += (hi - lo + 1) * lazy[note][i];
    if (lo != hi) lazy[note][2*i] += lazy[note][i], lazy[note][2*i + 1] += lazy[note][i];
    lazy[note][i] = 0;
  }
  if (lo > qhi || hi < qlo) return;

  if (lo == hi)
  {
    int prev = notes[note];
    notes[note] = (notes[note] + value) % 9;
    segTree[note][i] = (notes[note] != prev && prev == note) ? -1 : (notes[note] == note);
  }
  else
  {
    segTree[note][i] += (end - start + 1) * value;
    int mid = (lo + hi) / 2;
    updateRange(qlo, qhi, lo, mid, 2*i, note, value);
    updateRange(qlo, qhi, mid + 1, hi, 2*i + 1, note, value);
    segTree[note][i] = segTree[note][2*i] + segTree[note][2*i + 1];
  }
}

int mostFrequentNote(int lo, int hi)
{
  int mf = -1, app = -1;
  for (int i = 0; i < 9; i ++)
  {
    int freq = getSum(lo, hi, 0, n - 1, 0, i);
    if (freq >= app)
      app = freq, mf = i;
  }
  return(mf);
}

int main()
{
  scanf("%d", &n, &q);

  for (int i = 0; i < n; i ++) notes[i] = 1;
  for (int i = 0; i < 9; i ++) build(0, n - 1, 0, i);
  while (q --)
  {
    int a, b; scanf("%d %d", &a, &b);
    int f = mostFrequentNote(a, b);
    for (int i = 0; i < 9; i ++) updateRange(a, b, 0, n - 1, 0, i, f);
  }
  for (int i = 0; i < n; i ++) printf("%d\n", mostFrequentNote(i, i));

  return(0);
}
// 1 1 1 1 1
// 1 2 2 1 1
// 2 3 3 2 2
// 5 6 6 2 2
