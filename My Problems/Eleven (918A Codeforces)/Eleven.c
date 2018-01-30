#include <stdio.h>
int isFib[2000];

int fib(int n)
{
  if (n <= 1) return(1);
  int ans = fib(n - 1) + fib(n - 2);
  isFib[ans] = 1;
  return(ans);
}

void print(int i, int n)
{
  if (i > n) return;
  printf("%c%s", isFib[i] ? 'O' : 'o', i == n ? "\n" : "\0");
  print(i + 1, n);
}

int main()
{
  int n; scanf("%d", &n);
  fib(16); isFib[1] = isFib[2] = 1;
  print(1, n);
  return(0);
}