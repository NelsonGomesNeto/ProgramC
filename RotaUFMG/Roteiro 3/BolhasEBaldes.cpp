#include <bits/stdc++.h>

int merge(int array[], int lo, int mid, int hi)
{
  int copy[hi - lo + 1], i = lo, j = mid + 1, at = 0, changes = 0;
  while (i <= mid || j <= hi)
  {
    if (i == mid + 1) copy[at ++] = array[j ++];
    else if (j == hi + 1) copy[at ++] = array[i ++];
    else if (array[i] > array[j])
    {
      copy[at ++] = array[j ++]; changes += (mid - i + 1);
    }
    else copy[at ++] = array[i ++];
  }
  for (i = 0; i <= hi - lo; i ++)
    array[lo + i] = copy[i];
  return(changes);
}

int mergeSort(int array[], int lo, int hi)
{
  if (lo >= hi) return(0);
  int changes = 0, mid = (lo + hi) / 2;
  changes += mergeSort(array, lo, mid);
  changes += mergeSort(array, mid + 1, hi);
  changes += merge(array, lo, mid, hi);
  return(changes);
}

int main()
{
  int n;
  while (scanf("%d", &n) && n)
  {
    int array[n];
    for (int i = 0; i < n; i ++)
      scanf("%d", &array[i]);

    int changes = mergeSort(array, 0, n - 1);
    printf("%s\n", (changes & 1) ? "Marcelo" : "Carlos");
  }
  return(0);
}