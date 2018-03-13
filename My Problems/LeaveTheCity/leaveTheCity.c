#include <stdio.h>

int furthestTravel(int x, int v, int a, int g)
{
  if (g <= 0)
    return(x);
  return(furthestTravel(x + v, v + a, a, g - v));
}

int main()
{
  int a, g, place; scanf("%d %d %d", &a, &g, &place);
  int wentTo = furthestTravel(0, 0, a, g);
  printf("%d\n", wentTo);
  printf("%s\n", place <= wentTo ? "S" : "N");
  return(0);
}