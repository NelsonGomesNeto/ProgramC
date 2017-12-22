#include <bits/stdc++.h>
using namespace std;
int inf = 1<<20;

typedef struct Point
{
  double x, y;
} Point;

double dist(Point p1, Point p2)
{
  return(sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2)));
}

typedef struct vec
{
  double x, y;
} vec;

Point translate(Point p, vec v)
{
  Point a = {p.x + v.x, p.y + v.y};
  return(a);
}

vec toVec(Point a, Point b)
{
  vec v = {b.x - a.x, b.y - a.y};
  return(v);
}

vec scale(vec v, double s)
{
  vec r = {v.x * s, v.y * s};
  return(r);
}

double dot(vec a, vec b)
{
  return(a.x * b.x + a.y * b.y);
}

double normSq(vec v)
{
  return(v.x * v.x + v.y * v.y);
}

typedef struct Particle
{
  Point position;
  double angle;
} Partile;

typedef struct Segment
{
  Point a, b;
} Segment;

bool onSegment(Point p, Point q, Point r)
{
  return(q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orientation(Point p, Point q, Point r)
{
  double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return(0);
  return(val > 0 ? 1 : 2);
}

bool doIntersect(Segment s1, Segment s2)
{
  Point p1 = s1.a, q1 = s1.b, p2 = s2.a, q2 = s2.b;
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  if (o1 != o2 && o3 != o4) return(true);
  if (!o1 && onSegment(p1, p2, q1)) return(true);
  if (!o2 && onSegment(p1, q2, p1)) return(true);
  if (!o3 && onSegment(p2, p1, q2)) return(true);
  if (!o4 && onSegment(p2, q1, q2)) return(true);
  return(false);
}

double distToLine(Point p, Point a, Point b, Point& c)
{
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / normSq(ab);
  c = translate(a, scale(ab, u));
  return(dist(p, c));
}

double distToSegment(Point p, Point a, Point b, Point& c)
{
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / normSq(ab);
  if (u < 0.0)
  {
    c = {a.x, a.y};
    return(dist(p, a));
  }
  if (u > 1.0)
  {
    c = {b.x, b.y};
    return(dist(p, b));
  }
  return(distToLine(p, a, b, c));
}

Point closestIntersection(Particle p, Segment fs, vector<Segment> s)
{
  Point aux, m = {-inf*1.0, -inf*1.0}; double distance = inf;
  for (int i = 0; i < s.size(); i ++)
    if (doIntersect(fs, s[i]))
    {
      double d = distToSegment(p.position, s[i].a, s[i].b, aux);
      if (d < distance)
      {
        distance = d;
        m = aux;
      }
    }
  return(m);
}

double degToRad(double angle)
{
  return(angle * M_PI / 180.0);
}

int main()
{
  int segments; scanf("%d", &segments);
  vector<Segment> s;
  for (int i = 0;  i < segments; i ++)
  {
    double x1, y1, x2, y2; scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    Point p1 = {x1, y1}, p2 = {x2, y2};
    s.push_back({p1, p2});
  }

  printf("Segments (%d):\n", segments);
  for (int i = 0; i < segments; i ++)
    printf("\tSegment %d: A(%lg, %lg) <-> B(%lg, %lg)\n", i + 1, s[i].a.x, s[i].a.y, s[i].b.x, s[i].b.y);

  Particle p; double x, y, angle;
  while (scanf("%lf %lf %lf\n", &x, &y, &angle) != EOF)
  {
    printf("\n");
    p = {x, y, angle};
    printf("Particle: (%lg, %lg) %lg°\n", p.position.x, p.position.y, p.angle);
    Segment fakeSegment = {{x, y}, {x+inf*cos(degToRad(p.angle)), y+inf*sin(degToRad(p.angle))}};
    printf("Fake Segment: A(%lg, %lg) <-> B(%lg, %lg)\n", fakeSegment.a.x, fakeSegment.a.y, fakeSegment.b.x, fakeSegment.b.y);

    Point m = closestIntersection(p, fakeSegment, s);
    printf("Closest Intersection: (%lg, %lg) dist = %lg\n", m.x, m.y, dist(p.position, m));
  }

  return(0);
}