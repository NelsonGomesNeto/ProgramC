#include <stdio.h>

int main()
{
  int n, m, a; scanf("%d %d %d", &n, &m, &a);
  printf("%d\n", ((n % a > 0) + (n / a)) * ((m % a > 0) + m / a));
  return(0);
}