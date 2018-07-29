#include <bits/stdc++.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int a = 0, b = 1;
  swap(&a, &b);
  printf("%d %d\n", a, b);
  return(0);
}