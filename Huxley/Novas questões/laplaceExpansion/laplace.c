#include <stdio.h>
#define lli long long int
int DEBUG = 0;
int WOLFRAM = 0;

void printMatrix(int dim, lli matrix[][dim], int wolfram)
{
  int i, j;
  if (wolfram) printf("{");
  for (i = 0; i < dim; i ++)
  {
    if (wolfram && i) printf(", {");
    else if (wolfram) printf("{");
    for (j = 0; j < dim; j ++)
    {
      printf("%Ld", matrix[i][j]);
      if (wolfram && j < dim - 1) printf(",");
      else printf(" ");
    }
    if (wolfram) printf("}");
    else printf("\n");
  }
  if (wolfram) printf("}\n");
}

lli mult(int i, int j)
{
  return((i + j) & 1 ? -1 : 1);
}

lli base(lli matrix[][2])
{
  return((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}

lli laplace(int dim, lli matrix[][dim])
{
  if (DEBUG) printf("dim: %d\n", dim);
  if (dim == 1) return(matrix[0][0]);
  //if (dim == 2) return(base(matrix));

  int k; lli determinant = 0;
  for (k = 0; k < dim; k ++)
  {
    int newI, newJ, movJ;
    lli newMatrix[dim - 1][dim - 1];
    for (newI = 0; newI < dim - 1; newI ++)
    {
      for (newJ = 0, movJ = 0; newJ < dim - 1; movJ ++)
      {
        if (movJ == k) { continue; }
        newMatrix[newI][newJ] = matrix[newI + 1][movJ];
        newJ ++;
      }
    }
    if (DEBUG)
    {
      printf("New Matrix:\n");
      printMatrix(dim - 1, newMatrix, 0);
      printf("\n");
      printf("(%d, %d), %Ld * %Ld\n", 0, k, mult(0, k), matrix[0][k]); printMatrix(dim - 1, newMatrix, 0);
    }
    determinant += mult(0, k) * matrix[0][k] * laplace(dim - 1, newMatrix);
  }
  return(determinant);
}

int main()
{
  int dim; scanf("%d", &dim);
  lli matrix[dim][dim], i, j;
  for (i = 0; i < dim; i ++)
    for (j = 0; j < dim; j ++)
      scanf("%Ld", &matrix[i][j]);
  if (DEBUG) { printMatrix(dim, matrix, 0); printf("\n"); }

  lli determinant = laplace(dim, matrix);
  printf("%Ld\n", determinant);

  if (WOLFRAM)
    printMatrix(dim, matrix, 1);

  return(0);
}