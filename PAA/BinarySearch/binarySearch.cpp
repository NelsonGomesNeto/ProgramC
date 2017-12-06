#include <bits/stdc++.h>
using namespace std;

int getMid(int lo, int hi)
{
  return((lo + hi) / 2);
  //return(lo + (hi - lo) / 2);
}

int binSearch(int array[], int lo, int hi, int target)
{
  int mid = getMid(lo, hi); // Try other calc
  if (lo >= hi) return(array[mid] == target ? mid : -1);
  if (target <= array[mid])
    return(binSearch(array, lo, mid, target));
  else
    return(binSearch(array, mid + 1, hi, target));
}

int lowerBound(int array[], int lo, int hi, int target)
{
  int mid = getMid(lo, hi);
  if (lo >= hi) return(array[mid] == target ? mid : -1);
  if (target <= array[mid])
    return(lowerBound(array, lo, mid, target));
  else
    return(lowerBound(array, mid + 1, hi, target));
}

int upperBound(int array[], int lo, int hi, int target)
{
  int mid = getMid(lo, hi);
  if (lo >= hi - 1) return(array[hi] == target ? hi : array[lo] == target ? lo : -1);
  if (target < array[mid])
    return(upperBound(array, lo, mid - 1, target));
  else
    return(upperBound(array, mid, hi, target));
}

void printArray(int array[], int size, int pos)
{
  for (int i = 0; i < size; i ++)
    printf("%d%c", array[i], i < size - 1 ? ' ' : '\n');
  for (int i = 0; i < pos; i ++)
    printf("  ");
  printf("^\n");
}

int main()
{
  int size = 10; //scanf("%d", &size);
  int array[size] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2};
  //{0, 1, 1, 1, 1, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 6};
  //for (int i = 0; i < size; i ++)
    //array[i] = array[i] * (-1);
  sort(array, array+size);
  //for (int i = 0; i < size; i ++)
    //scanf("%d", &array[i]);

  int query, ans;
  while (scanf("%d", &query) != EOF)
  {
    ans = binSearch(array, 0, size - 1, query);
    printf("Pure Binary Search: %d; found at: %d\n", query, ans);
    if (ans != -1) printArray(array, size, ans);

    ans = lowerBound(array, 0, size - 1, query);
    printf("Lower Bound:        %d, found at: %d\n", query, ans);
    if (ans != -1) printArray(array, size, ans);

    ans = upperBound(array, 0, size - 1, query);
    printf("Upper Bound:        %d, found at: %d\n", query, ans);
    if (ans != -1) printArray(array, size, ans);
    printf("\n");
  }

  return(0);
}

