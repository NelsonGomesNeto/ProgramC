#include <bits/stdc++.h>

typedef struct point
{
  int x, y;
} point;

double norm(point p)
{
  return(sqrt(p.x * p.x + p.y * p.y));
}

double internProduct(point a, point b)
{
  return(a.x * b.x + a.y * b.y);
}

double angle(point a, point o, point b)
{
  point v1 = {b.x - o.x, b.y - o.y}, v2 = {a.x - o.x, a.y - o.y};
  return(acos(internProduct(v1, v2)/(norm(v1)*norm(v2))));
}

int main()
{
  int t; scanf("%d", &t);
  int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
  point p1 = {a, b}, p2 = {c, d};

  double cossine = cos()
  return(0);
}