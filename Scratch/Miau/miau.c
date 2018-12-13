#include <stdio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  if (a > b) swap(&a, &b);
  if (a > c) swap(&a, &c);
  if (b > c) swap(&b, &c);
  int h, l; scanf("%d %d", &h, &l);
  if (h > l) swap(&h, &l);

  printf("%c\n", (a <= h && b <= l) ? 'S' : 'N');

  return(0);
}