#include <bits/stdc++.h>

int main()
{ // 10 ^ 18
  int num, f; scanf("%d %d", &num, &f);

  int can = 0;
  if (num % 1000 == f) can = 1;
  num /= 10;
  if (num % 1000 == f) can = 1;
  num /= 10;
  if (num % 1000 == f) can = 1;
  num /= 10;
  if (num % 1000 == f) can = 1;
  num /= 10;
  if (num % 1000 == f) can = 1;
  num /= 10;
  if (num % 1000 == f) can = 1;
  num /= 10;
  if (num % 1000 == f) can = 1;

  printf("%s\n", can ? "YES" : "NO");

  return(0);
}
