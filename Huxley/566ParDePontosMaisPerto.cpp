#include <bits/stdc++.h>
using namespace std;
pair<double, double> points[(int) 1e4];
int n;

double dist(pair<double, double> a, pair<double, double> b)
{
  return(sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)));
}

double bruteForce(int lo, int hi)
{
  double minDist = 1e6;
  for (int i = lo; i <= hi; i ++)
    for (int j = i + 1; j <= hi; j ++)
      minDist = min(minDist, dist(points[i], points[j]));
  return(minDist);
}

double minMid(double d, int lo, int hi)
{
  int mid = (lo + hi) >> 1;
  int begin = mid - 1, end = mid + 1;
  while (begin > lo && points[mid].first - points[begin].first < d) begin --;
  while (end < hi && points[end].first - points[mid].first < d) end ++;
  return(bruteForce(begin, end));
}

double dq(int lo, int hi)
{
  if (hi - lo + 1 <= 3) return(bruteForce(lo, hi));

  int mid = (lo + hi) >> 1;
  double dlo = dq(lo, mid), dhi = dq(mid, hi);
  double d = min(dlo, dhi);
  return(min(d, minMid(d, lo, hi)));
}

int main()
{
  while (scanf("%d", &n) && n)
  {
    for (int i = 0; i < n; i ++)
    {
      double x, y; scanf("%lf %lf", &x, &y);
      points[i] = {x, y};
    }

    sort(points, points+n);
    double minDist = dq(0, n - 1);
    if (minDist < 1e4) printf("%.4lf\n", minDist);
    else printf("INFINITY\n");
  }
  return(0);
}