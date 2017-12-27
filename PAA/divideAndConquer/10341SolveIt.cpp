#include <bits/stdc++.h>
#define DEBUG if(0)
int p, q, r, s, t, u;

double func(double x)
{
  return(p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int valid(double x)
{
  return(-1e-5 <= x && x <= 1e-5);
}

double binSearch(double lo, double hi, double target)
{
  double mid = (lo + hi) / 2.0;
  if (lo >= hi - 1e-10) return(valid(func(lo)) ? lo : -1);
  DEBUG printf("%lg %lg %lg %lg\n", lo, hi, mid, func(mid));
  if (target >= func(mid)) return(binSearch(lo, mid, target));
  else return(binSearch(mid, hi, target));
}

int main()
{
  while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
  {
    double x = binSearch(0, 1, 0);

    if (x == -1) printf("No solution\n");
    else printf("%.4lf\n", x);
  }
  return(0);
}