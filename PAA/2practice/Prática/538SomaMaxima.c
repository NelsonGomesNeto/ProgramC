#include <stdio.h>
int inf = 1000000;

int max(int a, int b)
{
  return(a > b ? a : b);
}

int main()
{
  int dim; scanf("%d", &dim);
  int mat[dim][dim], spreadSum[dim][dim], i, j;
  for (i = 0; i < dim; i ++)
    for (j = 0; j < dim; j ++)
    {
      scanf("%d", &mat[i][j]);
      spreadSum[i][j] = mat[i][j];
      if (i)
        spreadSum[i][j] += spreadSum[i - 1][j];
      if (j)
        spreadSum[i][j] += spreadSum[i][j - 1];
      if (i && j)
        spreadSum[i][j] -= spreadSum[i - 1][j - 1];
    }

  int best = -inf;
  int iLo, jLo, iHi, jHi;
  for (iLo = 0; iLo < dim; iLo ++)
    for (jLo = 0; jLo < dim; jLo ++)
      for (iHi = iLo; iHi < dim; iHi ++)
        for(jHi = jLo; jHi < dim; jHi ++)
        {
          int newBest = spreadSum[iHi][jHi];
          if (iLo)
            newBest -= spreadSum[iLo - 1][jHi];
          if (jLo)
            newBest -= spreadSum[iHi][jLo - 1];
          if (iLo && jLo)
            newBest += spreadSum[iLo - 1][jLo - 1];
          best = max(best, newBest);
        }

  printf("%d\n", best);
  return(0);
}