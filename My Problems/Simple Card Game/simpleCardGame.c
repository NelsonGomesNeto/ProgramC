#include <stdio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void sort(int *a, int *b, int *c)
{
  if ((*a) > (*b))
    swap(&(*a), &(*b));
  if ((*b) > (*c))
    swap(&(*b), &(*c));
  if ((*a) > (*b))
    swap(&(*a), &(*b));
}

int score(int a, int b, int c)
{
  int s = 0;
  if (a == b - 1 && b == c - 1) s += a;
  if (a == b && b == c) s += a;
  if (a == b && b != c) s += a / 2;
  if (a != b && b == c) s += b / 2;
  if (a + b + c == 8) s += 8;
  return(s);
}

int main()
{
  int p1, p2, p3, w1, w2, w3;
  scanf("%d %d %d\n%d %d %d", &p1, &p2, &p3, &w1, &w2, &w3);
  sort(&p1, &p2, &p3); sort(&w1, &w2, &w3);

  int paes = score(p1, p2, p3), willy = score(w1, w2, w3);
  //printf("%s\n", paes == willy ? "empate" : paes > willy ? "paes" : "willy");
  printf("%d\n", paes == willy ? 0 : paes > willy ? 1 : 2);

  return(0);
}