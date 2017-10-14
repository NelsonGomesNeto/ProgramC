#include <stdio.h>
#include <math.h>
#define lli long long int
#define DEBUG if(0)

int getSize(lli num)
{
  if (num == 0) return(1);
  int size = 0;
  while (num > 0)
  {
    size ++;
    num /= 10;
  }
  return(size - 1);
}

int isSpecial(lli num)
{
  DEBUG printf("%Ld %d\n", num, getSize(num));
  int size = getSize(num);
  DEBUG if (num >= 0) printf("%Ld %d %Ld\n", num, size, (num / (lli) pow(10, size)) % 10);
  return(num >= 0 && num % 10 == (num / (lli) pow(10, size)) % 10);
}

int createSegmentTree(int segmentTree[], lli array[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    segmentTree[i] = isSpecial(array[lo]);
    return(segmentTree[i]);
  }
  else if (lo > hi) return(0);

  int mid = (lo + hi) / 2;
  segmentTree[i] = createSegmentTree(segmentTree, array, 2*i + 1, lo, mid) + createSegmentTree(segmentTree, array, 2*i + 2, mid + 1, hi);
  return(segmentTree[i]);
}

int gs(int segmentTree[], int i, int lo, int hi, int qlo, int qhi)
{
  if (lo >= qlo && hi <= qhi) return(segmentTree[i]);
  if (lo > qhi || hi < qlo) return(0);

  int mid = (lo + hi) / 2;
  return(gs(segmentTree, 2*i + 1, lo, mid, qlo, qhi) + gs(segmentTree, 2*i + 2, mid + 1, hi, qlo, qhi));
}

int getSum(int segmentTree[], int size, int lo, int hi)
{
  if (lo < 0 || hi > size - 1 || lo > hi) return(-1);
  return(gs(segmentTree, 0, 0, size - 1, lo, hi));
}

void uv(int segmentTree[], int i, int diff, int lo, int hi, int pos)
{
  if (lo > pos || hi < pos) return;

  segmentTree[i] += diff;
  if (lo != hi)
  {
    int mid = (lo + hi) / 2;
    uv(segmentTree, 2*i + 1, diff, lo, mid, pos);
    uv(segmentTree, 2*i + 2, diff, mid + 1, hi, pos);
  }
}

void updateValue(int segmentTree[], lli array[], int size, int pos, lli value)
{
  if (pos < 0 || pos > size - 1) return;

  int diff = isSpecial(value) - isSpecial(array[pos]);
  array[pos] = value;
  uv(segmentTree, 0, diff, 0, size - 1, pos);
}

int main()
{
  int size, queries; scanf("%d %d", &size, &queries);
  lli array[size], i;
  for (i = 0; i < size; i ++) scanf("%Ld", &array[i]);
  DEBUG for (i = 0; i < size; i ++) printf("%Ld %d\n", array[i], isSpecial(array[i]));

  int segmentTree[2 * (lli) pow(2, (lli) log2(size) + 1) - 1];
  createSegmentTree(segmentTree, array, 0, 0, size - 1);

  lli command, lo, hi;
  for (i = 0; i < queries; i ++)
  {
    scanf("%Ld %Ld %Ld", &command, &lo, &hi);
    if (command == 1)
      printf("%d\n", getSum(segmentTree, size, lo - 1, hi - 1));
    else
      updateValue(segmentTree, array, size, lo - 1, hi);
  }
  return(0);
}