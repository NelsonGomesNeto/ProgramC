#include <stdio.h>

int min(int a, int b)
{
  return(a < b ? a : b);
}

int main()
{
  int size, i; scanf("%d\n", &size);
  char command[size]; scanf("%s", command);

  int l = 0, r = 0, u = 0, d = 0;
  for (i = 0; command[i]; i ++)
  {
    if (command[i] == 'L') l ++;
    if (command[i] == 'R') r ++;
    if (command[i] == 'U') u ++;
    if (command[i] == 'D') d ++;
  }

  int total = (min(l, r)*2) + (min(d,u)*2);

  printf("%d\n", total);

  return(0);
}