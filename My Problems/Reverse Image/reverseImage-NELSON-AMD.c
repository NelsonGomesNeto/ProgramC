#include <stdio.h>

int main()
{
  int n, m; scanf("%d %d", &n, &m);
  char mat[n][m + 1]; int i;
  for (i = 0; i < n; i ++)
    scanf("\n%s", mat[i]);

  int j;
  for (i = n - 1; i >= 0; i --)
    for (j = m - 1; j >= 0; j --)
      printf("%c%c", mat[i][j], j == 0 ? '\n' : '\0');
}