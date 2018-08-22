#include <stdio.h>
#include <math.h>
double pi;

void sort(int *a, int *b)
{
  if (*a > *b)
  {
    int aux = *a;
    *a = *b;
    *b = aux;
  }
}

// pi - 180
// x - y
// y*pi = x*180
// y = x*180/pi
double radToDeg(double angle)
{
  return(angle * 180 / pi);
}

// sin = co / h
// angle = asin(co / h)
double calculateInclination(int lo, int hi, int dist)
{
  // sort(&lo, &hi);
  double co = (hi - lo);
  double h = dist * dist + co * co;
  double ca = dist;
  return((acos(ca / h)));
}

double findSteepestInclination(int heights[], int size, int *lo, int *hi)
{
  int i, j; double best = 0;
  for (i = 0; i < size; i ++)
    for (j = 0; j < size; j ++)
    {
      double inclination = calculateInclination(heights[i], heights[j], j - i);
      if (inclination > best)
      {
        best = inclination;
        *lo = i; *hi = j;
      }
    }
  sort(lo, hi);
  return(best);
}

int main()
{
  pi = acos(-1);
  int size; scanf("%d", &size);
  int heights[size], i; for (i = 0; i < size; i ++) scanf("%d", &heights[i]);

  int j;
  double steepest = findSteepestInclination(heights, size, &i, &j);
  printf("%d -> %d: %lf degrees\n", i, j, steepest);
  return(0);
}