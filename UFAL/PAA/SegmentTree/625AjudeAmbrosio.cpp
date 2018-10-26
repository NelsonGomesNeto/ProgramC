#include <stdio.h>
#include <math.h>
#define lli long long int
#define DEBUG if(0)

int createSegmentTree(int odd, int segmentTree[], int array[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    segmentTree[i] = array[lo] & 1;
    if (!odd)
      segmentTree[i] = 1 - segmentTree[i];
    return(segmentTree[i]);
  }
  else if (lo > hi) return(0);

  int mid = (lo + hi) / 2;
  segmentTree[i] = createSegmentTree(odd, segmentTree, array, 2*i + 1, lo, mid) + createSegmentTree(odd, segmentTree, array, 2*i + 2, mid + 1, hi);
  return(segmentTree[i]);
}

int gs(int segmentTree[], int i, int lo, int hi, int qlo, int qhi)
{
  if (lo >= qlo && hi <= qhi) return(segmentTree[i]);
  else if (lo > qhi || hi < qlo) return(0);

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

void updateValue(int odd, int segmentTree[], int array[], int size, int pos, int value)
{
  if (pos < 0 || pos > size - 1) return;

  int diff = (value & 1) - (array[pos] & 1);
  if (!odd)
    diff *= -1;

  if (odd)
    array[pos] = value;
  uv(segmentTree, 0, diff, 0, size - 1, pos);
}

int main()
{
  int numbers; scanf("%d", &numbers);
  int array[numbers], i;
  for (i = 0; i < numbers; i ++)
    scanf("%d", &array[i]);

  int segmentTree[2][2 * (lli) pow(2, (lli) log2(numbers) + 1) - 1];
  // segmentTree[0] = (int*) malloc((2 * (lli) pow(2, (lli) log2(numbers) + 1) - 1) * sizeof(int));
  // segmentTree[1] = (int*) malloc((2 * (lli) pow(2, (lli) log2(numbers) + 1) - 1) * sizeof(int));
  createSegmentTree(0, segmentTree[0], array, 0, 0, numbers - 1);
  createSegmentTree(1, segmentTree[1], array, 0, 0, numbers - 1);
  DEBUG {
    for (i = 0; i < 2 * (lli) pow(2, (lli) log2(numbers) + 1) - 1; i ++)
      printf("%d ", segmentTree[0][i]);
    printf("\n");
    for (i = 0; i < 2 * (lli) pow(2, (lli) log2(numbers) + 1) - 1; i ++)
      printf("%d ", segmentTree[1][i]);
    printf("\n");
  }

  int queries; scanf("%d", &queries);
  int operation, lo, hi;
  while (queries -- > 0)
  {
    scanf("%d %d %d", &operation, &lo, &hi);
    if (operation == 0)
    {
      updateValue(0, segmentTree[0], array, numbers, lo - 1, hi);
      updateValue(1, segmentTree[1], array, numbers, lo - 1, hi);
    }
    else if (operation == 1)
      printf("%d\n", getSum(segmentTree[0], numbers, lo - 1, hi - 1));
    else
      printf("%d\n", getSum(segmentTree[1], numbers, lo - 1, hi - 1));
  }
  return(0);
}