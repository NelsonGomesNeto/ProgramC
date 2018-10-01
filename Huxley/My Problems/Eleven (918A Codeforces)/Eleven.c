#include <stdio.h>

void fillWithFib(int a, int b, int n, char name[])
{
  if (a > n) return;
  name[a - 1] = 'O';
  fillWithFib(b, a + b, n, name);
}

int main()
{
  int n; scanf("%d", &n);
  char name[n + 1]; for (int i = 0; i < n; i ++) name[i] = 'o'; name[n] = '\0';
  fillWithFib(1, 1, n, name);
  printf("%s\n", name);
  return(0);
}
