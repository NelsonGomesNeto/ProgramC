#include <bits/stdc++.h>
#define DEBUG if(0)

void printArray(int array[], int n)
{
  for (int i = 0; i < n; i ++)
    printf("%d%c", array[i], i < n - 1 ? ' ' : '\n');
}

int lowerBound(int array[], int tail[], int lo, int hi, int target)
{
  if (lo >= hi) return(lo);
  int mid = (lo + hi) / 2;
  if (target <= array[tail[mid]]) return(lowerBound(array, tail, lo, mid, target));
  else return(lowerBound(array, tail, mid + 1, hi, target));
}

int lis(int array[], int ans[], int n)
{
  int tail[n + 1], prev[n + 1];
  memset(tail, 0, sizeof(tail)); memset(prev, -1, sizeof(prev));

  int size = 0;
  for (int i = 0; i < n; i ++)
  {
    int pos;
    if (array[tail[size]] < array[i]) // The last of the actual sequence is smaller, so array[i] should be the end of the sequence
      pos = size + 1;
    else
      pos = lowerBound(array, tail, 1, size, array[i]); // Where should array[i] substitute
    DEBUG printf("i: %d, lo: %d, hi: %d, pos: %d\n", i, 1, size, pos);
    int newSize = pos;
    prev[i] = tail[newSize - 1];
    tail[newSize] = i;

    if (newSize > size) size = newSize;
    DEBUG printf("Size: %d\n", size); DEBUG printArray(tail, n + 1); DEBUG printArray(prev, n + 1); DEBUG printf("\n");
  }
  for (int i = tail[size], k = size - 1; k >= 0; i = prev[i])
    ans[k --] = array[i];
  return(size);
}

int main()
{
  int n; scanf("%d", &n);
  int array[n], ans[n];
  for (int i = 0; i < n; i ++)
    scanf("%d", &array[i]);
  DEBUG printArray(array, n);

  int size = lis(array, ans, n);
  printf("%d\n", size);
  printArray(ans, size);
  return(0);
}