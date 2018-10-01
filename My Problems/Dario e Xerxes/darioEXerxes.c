#include <stdio.h>

int main()
{
  int rounds; scanf("%d", &rounds);
  int dario = 0, xerxes = 0, d, x;

  while (rounds > 0)
  {
    scanf("%d %d", &d, &x);
    if ((d + 1) % 5 == x || (d + 2) % 5 == x)
      dario ++;
    else
      xerxes ++;
    rounds --;
  }

  if (dario > xerxes)
    printf("dario\n");
  else
    printf("xerxes\n");

  return(0);
}