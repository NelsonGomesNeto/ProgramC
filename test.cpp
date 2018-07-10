#include <bits/stdc++.h>

void printArray(int a[], int size)
{
  for (int i = 0; i < size; i ++) printf("%d%c", a[i], i < size - 1 ? ' ' : '\n');
}

void shellSort(int a[], int size, int verbose)
{
  int h = size / 3;
  int pass = 1;
  while (h > 0)
  {
    for (int i = h; i < size; i ++)
    {
      int temp = a[i], j;
      for (j = i; j >= h && a[j - h] > temp; j -= h)
        a[j] = a[j - h];
      a[j] = temp;
      if (verbose) { printf("Pass: %d || ", pass); printArray(a, size); }
    }
    pass ++;
    h /= 2;
  }
}

int main()
{
  int n; scanf("%d", &n);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  printf("Before: "); printArray(a, n);
  shellSort(a, n, 0);
  printf("After: "); printArray(a, n);

  return(0);
}