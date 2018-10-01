#include <bits/stdc++.h>

int read(int n, int *wanted)
{
  if (n == 1000)
  {
    scanf("%d", &(*wanted));
    return(0);
  }
  int number; scanf("%d", &number);
  int count = read(n + 1, &(*wanted));
  if (number == *wanted) count ++;
  return(count);
}

void multiple()
{
  int n; scanf("%d", &n);
  if (n == -1) return;
  int wanted;
  int count = read(1, &wanted);
  if (n == wanted) count ++;
  printf("%d appeared %d times\n", wanted, count);
  multiple();
}

int main()
{
  multiple();
  return(0);
}