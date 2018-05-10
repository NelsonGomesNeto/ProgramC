#include <stdio.h>

int main()
{
  int n; scanf("%d", &n);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n-1-i; j++)
      if (a[j+1] < a[j]) {  /* compare the two neighbors */
        int tmp = a[j];         /* swap a[j] and a[j+1]      */
        a[j] = a[j+1];
        a[j+1] = tmp;
    }
  }
  for (int i = 0; i < n; i ++)
    printf("%d%c", a[i], i < n - 1 ? ' ' : '\n');
  return(0);
}