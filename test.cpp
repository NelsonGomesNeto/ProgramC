#include <bits/stdc++.h>

void printLine(int start, int size, char separator)
{
  int i = 0;
  while (i ++ < start) printf("%c", separator);
  while (i <= size - start)
  {
    printf("*");
    if (i != size) printf("%c", separator);
    i += 2;
  }
  while (i ++ <= size) printf("%c", separator);
}

int main()
{
  int radious; char separator = '.'; scanf("%d", &radious);
  int size = radious*2 - 1;

  int start = size / 2;
  for (int i = 0; i < size; i ++)
  {
    printLine(start, size, separator); printf("\n");
    if (i < size / 2) start --;
    else start ++;
  }
  return(0);
}