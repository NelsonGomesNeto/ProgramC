#include <bits/stdc++.h>
#define DEBUG if(0)
#define lli long long int
using namespace std;

const int maxB = 10, maxZ = 100; int b, z;
const lli inf = LLONG_MAX;
int monsters[maxB][maxZ + 1];
vector<int> cycles[maxB];
vector<int> intersections;

lli gcdExtended(lli a, lli b, lli *x, lli *y)
{
  if (!a)
  {
    *x = 0, *y = 1;
    return(b);
  }
  lli x1, y1;
  lli g = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1, *y = x1;
  return(g);
}
lli lcm(lli a, lli b) { return(a*b / __gcd(a, b)); }

lli modMult(lli a, lli b, lli m)
{
  if (!b) return(0);
  lli r = modMult(a, b >> 1, m);
  r = (r + r) % m;
  if (b & 1) r = (r + a) % m;
  return(r);
}

bool monstersInSamePlace(int m[maxB][maxZ + 1])
{
  for (int i = 1; i < b; i ++)
    if (m[0][0] != m[i][0])
      return(false);
  return(true);
}

bool canEmulating()
{
  int t;
  for (t = 0; t < 1e5; t ++)
  {
    if (monstersInSamePlace(monsters))
    {
      printf("%d %d\n", monsters[0][0], t);
      break;
    }
    for (int i = 0; i < b; i ++) monsters[i][0] = monsters[i][monsters[i][0]];
  }
  if (t == 1e5) return(false);
  else return(true);
}

int main()
{
  scanf("%d %d", &b, &z);
  for (int i = 0; i < b; i ++)
    for (int j = 0; j <= z; j ++)
      scanf("%d", &monsters[i][j]);

  if (canEmulating()) return(0);

  lli t = inf; int zoo;
  for (int i = 0; i < b; i ++)
  {
    cycles[i].push_back(monsters[i][0]);
    for (int j = monsters[i][monsters[i][0]]; j != cycles[i][0]; j = monsters[i][j])
      cycles[i].push_back(j);
  }

  for (int target: cycles[0])
  {
    bool hasInAll = true;
    for (int i = 0; i < b; i ++)
    {
      if (i == 0) continue;
      bool has = false;
      for (int j: cycles[i])
        if (j == target)
          has = true;
      if (!has) hasInAll = false;
    }
    if (hasInAll) intersections.push_back(target);
  }

  DEBUG for (int i = 0; i < b; i ++)
    printf("Cycle[%d].size() = %d\n", i, (int) cycles[i].size());

  int first = 0;
  for (int z: intersections)
  {
    DEBUG printf("Intersection: %d\n", z);
    int meetsIn[b]; lli eqa = 0, eqb = -1, meets = 0;
    for (int i = 0, j, k; i < b; i ++)
    {
      for (j = cycles[i][0], k = 0; j != z; j = cycles[i][++ k]);
      meetsIn[i] = k;
      DEBUG printf("meetsIn[%d] = %d, cyclesSize[%d] = %d\n", i, k, i, (int) cycles[i].size());
      if (i == first) continue;
      eqb = eqb == -1 ? cycles[i].size() : lcm(eqb, cycles[i].size());
    }
    for (int i = 0; i < b; i ++)
    {
      if (i == first) continue;
      eqa += cycles[first].size() * (eqb / cycles[i].size());
      meets += (meetsIn[first] - meetsIn[i]) * (eqb / cycles[i].size());
    }

    lli x, y;
    lli g = gcdExtended(eqa, eqb, &x, &y);
    lli dx = eqb / g;
    lli x0 = modMult((x < 0 ? -1 : 1) * -meets / g, x < 0 ? -x : x, dx);
    DEBUG printf("Hollly: %lld %lld %lld %lld\n", meets, g, x, x0);
    DEBUG printf("gcd(%lld, %lld) = %lld || %lld || %lld %lld || %lld + %lld*t\n", eqa, eqb, g, meets, x, y, x0, dx);
    for (int j = 0; j < 1e5; j ++)
    {
      lli tt = x0 + dx*j;
      lli timeToReach = (lli) cycles[first].size() * tt + meetsIn[first];
      bool valid = true;
      for (int i = 0; i < b; i ++)
      {
        if (i == first) continue;
        if ((timeToReach - meetsIn[i]) % cycles[i].size() != 0)
          valid = false;
      }
      if (valid)
      {
        DEBUG printf("%lld %lld\n", timeToReach, t);
        if (timeToReach + 100000 < t || (timeToReach == t && z < zoo))
          t = timeToReach + 100000, zoo = z;
        break;
      }
    }
  }
  if (t == inf) printf("*\n");
  else printf("%d %lld\n", zoo, t);
  return(0);
}