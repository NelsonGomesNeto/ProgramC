#include <stdio.h>

int mult(int a, int b)
{
  if (!b) return(0);
  int res = mult(a, b / 2);
  if (b & 1)
    return(res + res + a);
  else
    return(res + res);
}

int main()
{
  //int a, b; scanf("%d %d", &a, &b);
  int i, j;
  for (i = 0; i <= 100; i ++)
    for (j = 0; j <= 100; j ++)
      if (mult(i, j) != i * j)
        printf("Not\n");
}