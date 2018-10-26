#include <bits/stdc++.h>

int m, n;

void binDFSkk(int im, int in, int lom, int lon, int him, int hin, char path[], int i)
{
  path[i] = '\0';
  if (im == m && in == n) return;
  if ((double) im / in > (double) m / n)
  {
    path[i] = 'L';
    binDFSkk(im + lom, in + lon, lom, lon, im, in, path, i + 1);
  }
  else
  {
    path[i] = 'R';
    binDFSkk(im + him, in + hin, im, in, him, hin, path, i + 1);
  }
}

int main()
{
  char path[(int) 1e6];
  while (scanf("%d %d", &m, &n) && !(m == 1 && n == 1))
  {
    binDFSkk(1, 1, 0, 1, 1, 0, path, 0);
    printf("%s\n", path);
  }
  return(0);
}