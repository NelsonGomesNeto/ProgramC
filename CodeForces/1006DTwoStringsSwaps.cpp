#include <bits/stdc++.h>

void swap(char *a, char *b)
{
  char aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int n; scanf("%d", &n);
  int mid = n / 2;
  char a[n + 1], b[n + 1];
  scanf("\n%s\n%s", a, b);

  int ans = 0;
  for (int i = 0; i < n; i ++)
  {
    if (i < mid && a[i] != b[i] && b[i] == a[n - i - 1])
      swap(&a[i], &a[n - i - 1]);
    else if (i >= mid && a[i] != b[i]) ans ++;
  }

  printf("%d\n", ans);

  return(0);
}
