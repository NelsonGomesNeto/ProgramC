#include <stdio.h>

void functionWithoutReference(int a)
{
  a = 1;
}

void functionWithReference(int *a)
{
  *a = 1;
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int a, b; scanf("%d %d", &a, &b);
  printf("Before: %d %d\n", a, b);
  swap(&a, &b);
  printf("After: %d %d\n", a, b);
}
