#include <bits/stdc++.h>

void printDiamond(int size)
{
  if (size == -1) return;
  printf("%c", size & 1 ? '.' : '*');
  printDiamond(size - 1);
}

void printUntilBorder(int size)
{
  if (size == -1) return;
  printf(".");
  printUntilBorder(size - 1);
}

void printLine(int i, int size)
{
  if (i == size) return;
  //printf("%d\n", abs((size / 2) - i));
  printUntilBorder(abs((size / 2) - i) - 1);
  //printf("%d\n", size - 2 * (abs((size / 2) - i)));
  printDiamond(size - 2 * abs((size / 2) - i) - 1);
  printUntilBorder(abs((size / 2) - i) - 1);
  printf("\n");
  printLine(i + 1, size);
}

int main()
{
  int radious; scanf("%d", &radious);
  printLine(0, 2 * radious - 1);
  return(0);
}