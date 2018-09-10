#include <stdio.h>

int max(int a, int b)
{
  return(a > b ? a : b);
}

int min(int a, int b)
{
  return(a < b ? a : b);
}

int main()
{
  int n; scanf("%d", &n);
  int height[n], i; for (i = 0; i < n; i ++) scanf("%d", &height[i]);
  int left[n], right[n];
  left[0] = height[0];
  for (i = 1; i < n; i ++) left[i] = max(left[i - 1], height[i]);
  right[n - 1] = height[n - 1];
  for (i = n - 2; i >= 0; i --) right[i] = max(right[i + 1], height[i]);

  int filled = 0;
  for (i = 1; i < n - 1; i ++) filled += (height[i] < min(left[i - 1], right[i + 1]));
  printf("%d\n", filled);

  return(0);
}
