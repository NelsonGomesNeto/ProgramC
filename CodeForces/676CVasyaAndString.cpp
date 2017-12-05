#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

void fill(char s[], int a[], int size, char k, int i, int add)
{
  int now = 0;
  for (int j = 0; j < size; j ++)
  {
    if (s[i] == k) now ++;
    else now = 0;
    a[i] = now;
    i += add;
  }
}

void printArray(int a[], int size)
{
  for (int i = 0; i < size; i ++) printf("%d%c", a[i], i < size - 1 ? ' ' : '\n');
}

int main()
{
  int size, k; scanf("%d %d\n", &size, &k);
  char s[size + 1]; scanf("%s", s);

  int a[2][size], b[2][size];
  fill(s, a[0], size, 'a', 0, 1);
  fill(s, a[1], size, 'a', size - 1, -1);
  fill(s, b[0], size, 'b', 0, 1);
  fill(s, b[1], size, 'b', size - 1, -1);

  DEBUG { printArray(a[0], size); printArray(a[1], size);
  printArray(b[0], size); printArray(b[1], size); }

  int best = min(1 + k, size);
  for (int i = 0; i < size; i ++)
  {
    if (i + k + 1 < size && s[i] == s[i + k + 1] && s[i] == 'a')
      best = max(best, a[0][i] + a[1][i + k + 1] + k);
    if (i + k + 1 < size && s[i] == s[i + k + 1] && s[i] == 'b')
      best = max(best, b[0][i] + b[1][i + k + 1] + k);
    best = max(best, min(a[0][i] + k, size)); best = max(best, min(a[1][i] + k , size));
    best = max(best, min(b[0][i] + k, size)); best = max(best, min(b[1][i] + k, size));
  }

  printf("%d\n", best);

  return(0);
}