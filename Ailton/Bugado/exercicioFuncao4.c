#include <stdio.h>

#define Q '*'

void parede(int altura)
{
  int i;
  for (i = 0; i < altura; i ++)
  {
    printf("%c", Q);
  }
  printf("\n");
}

void casa(int h)
{
  parede(h - 1);
  parede(h - 1);
  parede(h - 1);
  parede(h);
  parede(h);
  parede(h - 1);
  parede(h - 1);
  parede(h - 1);
}

int main()
{
  int alta;
  scanf("%d", &alta);
  casa(alta);
  return(0);
}
