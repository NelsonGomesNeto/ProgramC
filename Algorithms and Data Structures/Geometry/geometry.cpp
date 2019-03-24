/*
triangle area given points a, b and c
1/2 * det({a.x, b.x, c.x},
          {a.y, b.y, c.y},
          {  1,   1,   1})
*/
/*
point inside a non convex polygon: pnpoly
bool insidePolygon(int x, int y)
{
  bool c = false;
  for (int i = 0; i < n; i ++)
  {
    int x1 = points[i].x, x2 = points[i + 1].x, y1 = points[i].y, y2 = points[i + 1].y;

    // iff you can guarantee that there will be only right angled line
    // if (y1 == y2 && y == y1 && x >= min(x1, x2) && x <= max(x1, x2)) return(true);
    // if (x1 == x2 && x == x1 && y >= min(y1, y2) && y <= max(y1, y2)) return(true);

    double h = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)), a = sqrt(pow(x - x1, 2) + pow(y - y1, 2)), b = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    if (a + b - h <= 1e-6) return(true);
    if ((y1 > y) != (y2 > y) && (x < (x2 - x1) * (double) (y - y1) / (y2 - y1) + x1))
      c = !c;
  }
  return(c);
}
*/
/*
struct Point
{
  double x, y, d; int id;
  double dist(const Point &a) { return(sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y))); }
  bool collinear(const Point &a, const Point &b) { return((x - a.x)*(a.y - b.y) - (a.x - b.x)*(y - a.y) == 0); }
};
*/