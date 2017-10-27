#include <stdio.h>
#include <string.h>

int main()
{
  int i, j, k;
  char let[5] = {'s', 'p', 'd', 'f'};
  int letInt[5] = {2, 6, 10, 14};
  int intTable[7][7], numTable[7][7];
  memset(intTable, -1, sizeof(intTable));
  char charTable[7][7];
  for (i = 0, k = 1; i < 7; i ++)
  {
    for (j = 0; j < k; j ++)
    {
      intTable[i][j] = i + 1; numTable[i][j] = letInt[j];
      charTable[i][j] = let[j];
    }
    if (i < 3) k ++;
    else if (i > 3) k --;
  }

  for (i = 0, k = 1; i < 7; i ++)
  {
    for (j = 0; j < k; j ++)
      printf("%d%c(%d)%c", intTable[i][j], charTable[i][j], numTable[i][j], j < k - 1 ? ' ' : '\n');
    if (i < 3) k ++;
    else if (i > 3) k --;
  }

  char element[10]; int atomicNumber; scanf("%s %d", element, &atomicNumber);
  printf("Element: %s, Atomic number: %d\n", element, atomicNumber);
  int now = 0; i = 0;
  while (now < atomicNumber)
  {
    for (j = i; j >= 0; j --)
    {
      if ((i - j) >= 0 && j >= 0 && j < 7 && (i - j) < 7 && intTable[(i - j)][j] != -1)
      {
        if (now + numTable[(i - j)][j] >= atomicNumber)
          numTable[(i - j)][j] = atomicNumber - now;
        now += numTable[(i - j)][j];
        printf("%d%c(%d)%c", intTable[(i - j)][j], charTable[(i - j)][j], numTable[(i - j)][j], now >= atomicNumber ? '\n' : ' ');
      }
      if (now >= atomicNumber) break;
    }
    i ++;
  }

  return(0);
}