#include <stdio.h>
#include <string.h>

int main()
{
  int y, x; scanf("%d %d", &y, &x);
  int i, j;

  int intTable[y][x], numTable[y][x];
  memset(intTable, -1, sizeof(intTable));
  char charTable[y][x];
  for (i = 0; i < y; i ++)
  {
    int quant; scanf("%d", &quant);
    for (j = 0; j < quant; j ++)
      scanf("%d%c(%d)", &intTable[i][j], &charTable[i][j], &numTable[i][j]);
  }

  for (i = 0; i < y; i ++)
    for (j = 0; j < x; j ++)
      if (intTable[i][j] != -1)
        printf("%d%c(%d)%c", intTable[i][j], charTable[i][j], numTable[i][j], (j < x - 1 && intTable[i][j + 1] != -1) ? ' ' : '\n');

  char element[10]; int atomicNumber; scanf("%s %d", element, &atomicNumber);
  printf("Atom: %s, Atomic number: %d\n", element, atomicNumber);
  int now = 0; i = 0;
  while (now < atomicNumber)
  {
    for (j = i; j >= 0; j --)
    {
      if ((i - j) >= 0 && j >= 0 && j < x && (i - j) < y && intTable[(i - j)][j] != -1)
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

// for (i = 0, k = 1; i < 7; i ++)
// {
//   for (j = 0; j < k; j ++)
//   {
//     intTable[i][j] = i + 1; numTable[i][j] = letInt[j];
//     charTable[i][j] = let[j];
//   }
//   if (i < 3) k ++;
//   else if (i > 3) k --;
// }