#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
const int maxN = 100, maxM = 100, inf = 1e9; int an, am, bn, bm;
double A[maxN][maxM], inverse[maxN][maxM], B[maxN][maxM];

void printMatrix(double a[maxN][maxM], int n, int m)
{
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      printf("%8.5lf%c", a[i][j], j < m - 1 ? ' ' : '\n');
}

void switchLines(double a[maxN][maxM], int i, int j, int m)
{
  for (int k = 0; k < m; k ++)
    swap(a[i][k], a[j][k]);
}

void sumLine(double a[maxN][maxM], int i, int j, double c, int m)
{
  for (int k = 0; k < m; k ++)
    a[j][k] += c * a[i][k];
}

bool gaussElimination(double a[maxN][maxM], double inv[maxN][maxM], double b[maxN][maxM])
{
  for (int i = 0, l; i < min(an, am); i ++)
  {
    for (l = i; l < an && abs(a[l][i]) < eps; l ++);
    if (l == an) return(false);
    switchLines(a, i, l, am), switchLines(inv, i, l, am), switchLines(b, i, l, bm);
    for (int j = 0; j < an; j ++)
    {
      if (i == j) continue;
      double c = -a[j][i] / a[i][i];
      sumLine(a, i, j, c, am), sumLine(inv, i, j, c, am), sumLine(b, i, j, c, bm);
    }
  }
  for (int i = 0; i < an; i ++)
  {
    for (int j = 0; j < am; j ++)
      inv[i][j] /= a[i][i];
    for (int j = 0; j < bm; j ++)
      b[i][j] /= a[i][i];
  }
  return(true);
}

int main()
{
  scanf("%d %d", &an, &am);
  for (int i = 0; i < an; i ++)
  {
    inverse[i][i] = 1;
    for (int j = 0; j < am; j ++)
      scanf("%lf", &A[i][j]);
  }
  scanf("%d %d", &bn, &bm);
  for (int i = 0; i < bn; i ++)
    for (int j = 0; j < bm; j ++)
      scanf("%lf", &B[i][j]);

  printf("Solutions: %d\n", gaussElimination(A, inverse, B));
  printf("A:\n");
  printMatrix(A, an, am);
  printf("B:\n");
  printMatrix(B, bn, bm);
  printf("inverse:\n");
  printMatrix(inverse, am, an);

  return(0);
}