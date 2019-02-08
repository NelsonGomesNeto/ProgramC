#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
double degToRad(double angle) { return(angle * pi / 180.0); }

struct X { double d, theta, wetted; };

double wettedPerimeter(double d, double theta)
{
  // sin = CO / H
  // H = sin * CO
  // tan = CO / CA
  // CA = CO / tan
  double h = d / sin(theta), ca = d / tan(theta);
  double wetted = 2 * h;
  double smallSide = 50.0 / d - ca / 2.0;
  // printf("%lf %lf %lf %lf %lf\n", d, theta, h, wetted, smallSide);
  if (smallSide < 0) return(1e9);
  return(wetted + smallSide);
  // area = (2*b + d / tan(theta)) * d / 2
  // 2 * area / d = 2*b + d / tan(theta)
  // 2* area / d - d / tan(theta) = 2 * b
  // area / d - d / (2*tan(theta)) =  b
}

int main()
{
  X best; best.wetted = 1e9;
  // wettedPerimeter(4, degToRad(10));
  for (double d = 1; d < 50; d ++)
    for (double theta = 1; theta <= 90; theta ++)
    {
      double ans = wettedPerimeter(d, degToRad(theta));
      if (ans < best.wetted && ans > 0)
      {
        printf("(%3.3lf, %3.3lf) = %lf\n", d, theta, wettedPerimeter(d, degToRad(theta)));
        best = {d, theta, ans};
      }
    }
  return(0);
}
