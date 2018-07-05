#include <bits/stdc++.h>

int main()
{
  int n; scanf("%d", &n);
  int numbers[n + 1], x; memset(numbers, 0, sizeof(numbers));
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i ++)
  {
    x = a[i]; if (x < 0) x = 0;
    int prev = x;
    while (x) { prev = x; x = a[x] - 1; }
    numbers[prev] = 1;
  }
  int ans = 0; for (int i = 0; i < n; i ++) ans += numbers[i];
  printf("%d\n", ans + 1);

  return(0);
}