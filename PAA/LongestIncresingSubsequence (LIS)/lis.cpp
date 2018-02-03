#include <bits/stdc++.h>

void printArray(int a[], int size)
{
  for (int i = 0; i < size; i ++)
    printf("%d%c", a[i], i < size - 1 ? ' ' : '\n');
}

int lowerBound(int array[], int tail[], int lo, int hi, int target)
{
  if (lo >= hi) return(lo);
  int mid = (lo + hi) / 2;
  if (target <= array[tail[mid]]) return(lowerBound(array, tail, lo, mid, target));
  else return(lowerBound(array, tail, mid + 1, hi, target));
}

int lis(int ans[], int array[], int n)
{
  int tail[n + 1], prev[n + 1];
  memset(tail, 0, sizeof(tail)); memset(prev, -1, sizeof(prev));

  int size = 0;
  for (int i = 0; i < n; i ++)
  {
    int pos;
    if (array[i] < array[tail[1]]) // Smaller then the smallest
      pos = 1;
    else if (array[i] > array[tail[size]]) // Biggest then the biggest
      pos = size + 1;
    else // Find where it should be
      pos = lowerBound(array, tail, 1, size, array[i]);

    prev[i] = tail[pos - 1]; // Save the prev for this *i*, it will be behind pos - 1, since tail "points" to sorted arrays
    tail[pos] = i; // Make new tail or just increases the sequence

    if (pos > size) size = pos;
  }
  for (int i = tail[size], k = size - 1; k >= 0; k --, i = prev[i])
    ans[k] = array[i];
  return(size);
}

int main()
{
  int n; scanf("%d", &n);
  int array[n];
  for (int i = 0; i < n; i ++)
    scanf("%d", &array[i]);

  int ans[n], size;
  size = lis(ans, array, n);
  printf("%d\n", size);
  //printArray(ans, size);
  return(0);
}