#include <bits/stdc++.h>

int binSearch(int array[], int lo, int hi, int target)
{
  int mid = (lo + hi) / 2;
  if (lo >= hi)
    return(mid / 2);
  if (array[mid] >= target)
    return(binSearch(array, lo, mid, target));
  return(binSearch(array, mid + 1, hi, target));
}

int main()
{
  int piles; scanf("%d", &piles);
  int pile[piles];
  for (int i = 0; i < piles; i ++)
    scanf("%d", &pile[i]);
  int worms[piles * 2], prev = 0;
  for (int i = 0; i < piles * 2; i += 2)
  {
    worms[i] = prev + 1;
    worms[i + 1] = prev + pile[i / 2];
    prev += pile[i / 2];
    //printf("%d %d\n", worms[i], worms[i + 1]);
  }
  int queries; scanf("%d", &queries);
  while (queries > 0)
  {
    int query; scanf("%d", &query);
    printf("%d\n", binSearch(worms, 0, piles * 2 - 1, query) + 1);
    queries --;
  }
  return(0);
}