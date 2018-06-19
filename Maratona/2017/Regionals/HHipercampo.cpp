#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
double pi = acos(-1);

typedef struct point
{
  int x, y;
  double angleA, angleB;
} point;

bool sortByY(const point a, const point b)
{
  return(a.y < b.y);
}

double module(point a)
{
  return(sqrt(a.x*a.x + a.y*a.y));
}

double angle(point a, point o, point b)
{ // theta = acos(<pa, pb>/(||a||*||b||))
  point va = {o.x - a.x, o.y - a.y}, vb = {o.x - b.x, o.y - b.y};
  double internProduct = (va.x*vb.x + va.y*vb.y);
  return(acos(internProduct / (module(va)*module(vb))));
}

double radToDeg(double angle)
{
  // pi - 180
  // angle - x
  // x = (180 * angle) / pi
  return(180 * angle / pi);
}

void printPoints(point p[], int size)
{
  for (int i = 0; i < size; i ++)
    printf("%d %d %lf %lf\n", p[i].x, p[i].y, p[i].angleA, p[i].angleB);
  printf("\n");
}

int dfs(vector<int> graph[], int u, int visited[])
{
  if (visited[u]) return(0);
  visited[u] = 1;
  int maxLevel = 0;
  for (auto v: graph[u])
    maxLevel = max(maxLevel, 1 + dfs(graph, v, visited));
  return(maxLevel);
}

int main()
{
  int n, xa, xb; scanf("%d %d %d", &n, &xa, &xb);
  point p[n];
  for (int i = 0; i < n; i ++)
  {
    scanf("%d %d", &p[i].x, &p[i].y);
    p[i].angleA = angle(p[i], {xa, 0}, {xb, 0}); // radToDeg
    p[i].angleB = angle(p[i], {xb, 0}, {xa, 0}); // radToDeg
  }

  sort(p, p+n, sortByY);
  DEBUG printPoints(p, n);

  vector<int> canPair[n], canPair2[n];

  for (int i = 0; i < n; i ++)
    for (int j = i + 1; j < n; j ++)
      if (p[i].y < p[j].y && p[i].angleA < p[j].angleA && p[i].angleB < p[j].angleB)
        canPair[i].push_back(j);

  for (int i = n - 1; i >= 0; i --)
    for (int j = i - 1; j >= 0; j --)
      if (p[i].y > p[j].y && p[i].angleA > p[j].angleA && p[i].angleB > p[j].angleB)
        canPair2[i].push_back(j);

  DEBUG for (int i = 0; i < n; i ++)
  {
    printf("%d:", i);
    for (auto u: canPair[i])
      printf(" %d ->", u);
    printf(" ¬\n");
  }

  int visited[n], ans = 0;
  for (int i = 0; i < n; i ++)
  {
    memset(visited, 0, sizeof(visited));
    ans = max(ans, 1 + dfs(canPair, i, visited));
    memset(visited, 0, sizeof(visited));
    ans = max(ans, 1 + dfs(canPair2, i, visited));
  }

  printf("%d\n", ans);

  return(0);
}

// sin = CO/H || H = CO / sin
// if (H > module(p1, p2))

