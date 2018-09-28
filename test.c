#include <stdio.h>

struct type
{
  int value, color;
};

void swap(struct type *a, struct type *b)
{
  struct type aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  struct type miau[3];
  for (int i = 0; i < 3; i ++)
    miau[i].value = 3 - i, miau[i].color = i + 1;

  for (int i = 0; i < 3; i ++)
    for (int j = i + 1; j < 3; j ++)
      if (miau[i].value > miau[j].value)
        swap(&miau[i], &miau[j]);

  for (int i = 0; i < 3; i ++)
    printf("(%d, %d)%c", miau[i].value, miau[i].color, i < 3 - 1 ? ' ' : '\n');
  return(0);
}
