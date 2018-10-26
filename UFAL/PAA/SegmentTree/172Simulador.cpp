#include <bits/stdc++.h>
using namespace std;

int createSegmentTree(int segmentTree[], int array[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    segmentTree[i] = array[lo];
    return(segmentTree[i]);
  }
  int mid = (lo + hi) / 2;
  segmentTree[i] = createSegmentTree(segmentTree, array, 2*i + 1, lo, mid) + createSegmentTree(segmentTree, array, 2*i + 2, mid + 1, hi);
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

void uv(int segmentTree[], int i, int lo, int hi, int diff, int pos)
{
  if (lo > pos || hi < pos) return;
  segmentTree[i] += diff;
  if (lo != hi)
  {
    int mid = (lo + hi) / 2;
    uv(segmentTree, 2*i + 1, lo, mid, diff, pos);
    uv(segmentTree, 2*i + 2, mid + 1, hi, diff, pos);
  }
}

void updateValue(int segmentTree[], int array[], int size, int value, int pos)
{
  if (pos < 0 || pos > size - 1) return;
  int diff = value - array[pos];
  array[pos] = value;
  uv(segmentTree, 0, 0, size - 1, diff, pos);
}

void invert(int segmentTree[], int array[], int size, int left, int right)
{
  int i, j;
  for (i = left, j = right; i < j; i ++, j --)
  {
    int a = array[j], b = array[i];
    updateValue(segmentTree, array, size, a, i);
    updateValue(segmentTree, array, size, b, j);
    //printf("%d %d\n", array[i], array[j]);
  }
}

int main()
{
  int numbers, instructions; scanf("%d %d", &numbers, &instructions);
  int array[numbers], i;
  for (i = 0; i < numbers; i ++) array[i] = i + 1;
  int *segmentTree = (int*) malloc((2*pow(2, log2(numbers) + 1) - 1) * sizeof(int));
  int *lazy = (int*) malloc((2*pow(2, log2(numbers) + 1) - 1) * sizeof(int));
  memset(lazy, 0, sizeof(lazy));
  createSegmentTree(segmentTree, array, 0, 0, numbers - 1);

  char command; int left, right;
  for (i = 0; i < instructions; i ++)
  {
    getchar();
    scanf("%c %d %d", &command, &left, &right); left --; right --;
    if (command == 'S') printf("%d\n", getSum(segmentTree, numbers, left, right));
    else invert(segmentTree, array, numbers, left, right);
    // int k;
    // for (k = 0; k < numbers; k ++) printf("%d%c", array[k], k < numbers - 1 ? ' ' : '\n');
  }

  return(0);
}