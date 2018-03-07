#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n)
{
  for (int i = 0; i < n; i ++)
    printf("%d%c", a[i], i < n - 1 ? ' ' : '\n');
}

int main()
{
  int n, x; scanf("%d %d", &n, &x);
  int array[n], mid = (n + 1) / 2 - 1, pos = -1;
  for (int i = 0; i < n; i ++)
    scanf("%d", &array[i]);
  sort(array, array+n);

  int best = 99999, notIn = 1;
  for (int i = 0; i < n; i ++)
  {
    if (x > array[i])
      pos = i;
    if (x == array[i] && abs(mid - i) < abs(mid - pos))
    {
      best = abs(mid - i);
      pos = i;
      notIn = 0;
    }
  } if (x > array[n - 1]) pos = n;

  //printf("%d %d %d\n", best, mid, pos);

  if (pos < 0 || pos == n)
    printf("%d\n", n + 1);
  else
  {
    if (pos == mid)
      printf("%d\n", notIn);
    else
      printf("%d\n", abs(2*pos - n + 2) + notIn - !(abs(2*pos - n + 2) & 1));
  }

  // (x + n + 1) / 2 - 1 = pos
  // x + n + 1 = 2*pos + 2
  // x = 2*pos - n + 1

  return(0);
}