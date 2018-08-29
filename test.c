#include <stdio.h>
#include <math.h>

double series(int i, int end, int oddNum, int oddDivi, int evenNum, int evenDivi)
{
  if (i == end) return(0);
  if (i & 1)
    return((double) evenNum / evenDivi + series(i + 1, end, oddNum, oddDivi, evenNum * 4, evenDivi + 3));
  else
    return((double) oddNum / oddDivi + series(i + 1, end, oddNum + 2, oddDivi * 4, evenNum, evenDivi));
}

int main()
{
  int s; scanf("%d", &s);
  printf("S: %.2lf\n", series(0, s, 1, 1, 2, 3));
  return(0);
}