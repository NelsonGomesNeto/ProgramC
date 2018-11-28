#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int maxN = 1e5, maxLog = ceil(log2(1e5)); int n, logn;
vector<pair<int, lli>> tree[maxN];
int level[maxN], ancestor[maxN][maxLog], in[maxN], t; lli dist[maxN];
set<pair<int, int>> nowTree; lli total = 0;
void dfs(int u, int prev)
{
  in[u] = ++ t;
  for (auto v: tree[u])
    if (v.first != prev)
    {
      level[v.first] = level[u] + 1, ancestor[v.first][0] = u, dist[v.first] = dist[u] + v.second;
      dfs(v.first, u);
    }
}
void build()
{
  level[0] = ancestor[0][0] = dist[0] = t = 0; dfs(0, -1);
  for (int i = 1; i < logn; i ++)
    for (int u = 0; u < n; u ++)
      ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
}
int LCA(int u, int v)
{
  if (level[v] > level[u]) swap(u, v);
  for (int diff = level[u] - level[v], i = 0; diff; diff >>= 1, i ++)
    if (diff & 1) u = ancestor[u][i];
  if (u == v) return(u);
  for (int i = logn - 1; i >= 0; i --)
    if (ancestor[u][i] != ancestor[v][i])
      u = ancestor[u][i], v = ancestor[v][i];
  return(ancestor[u][0]);
}
int distance(int u, int v)
{
  int lca = LCA(u, v);
  return(dist[u] + dist[v] - 2*dist[lca]);
}

void rem(int u)
{
  if (nowTree.size() < 4)
  {
    if (nowTree.count({in[u], u})) nowTree.erase({in[u], u});
    total = 0;
    if (nowTree.size() <= 1) return;
    else
    {
      total += distance(nowTree.begin()->second, prev(nowTree.end(), 1)->second);
      if (nowTree.size() == 3) total += (dist[next(nowTree.begin(),1)->second] - dist[LCA(next(nowTree.begin(),1)->second, nowTree.begin()->second)]);
      return;
    }
  }
  else
  {
    set<pair<int, int>>::iterator it = nowTree.find({in[u], u});
    if (it == nowTree.begin()) total -= (dist[it->second] - dist[LCA(it->second, next(it,1)->second)]);
    else if (it == prev(nowTree.end(), 1)) total -= (dist[it->second] - dist[LCA(it->second, prev(it,1)->second)]);
    else total -= (distance(it->second, prev(it,1)->second) + (dist[next(it,1)->second] - dist[LCA(it->second, next(it,1)->second)]) - distance(prev(it,1)->second, next(it,1)->second));
    nowTree.erase(it);
  }
}

void add(int u)
{
  nowTree.insert({in[u], u});
  if (nowTree.size() < 4)
  {
    total = 0;
    if (nowTree.size() <= 1) return;
    else
    {
      total += distance(nowTree.begin()->second, prev(nowTree.end(), 1)->second);
      if (nowTree.size() == 3) total += (dist[next(nowTree.begin(),1)->second] - dist[LCA(next(nowTree.begin(),1)->second, nowTree.begin()->second)]);
      return;
    }
  }
  else
  {
    set<pair<int, int>>::iterator it = nowTree.find({in[u], u});
    if (it == nowTree.begin()) total += dist[it->second] - dist[LCA(it->second, next(it,1)->second)];
    else if (it == prev(nowTree.end(), 1)) total += dist[it->second] - dist[LCA(it->second, prev(it,1)->second)];
    else
    {
      // printf("%d %d %d\n", it->second + 1, prev(it,1)->second + 1, next(it,1)->second + 1);
      total += distance(it->second, prev(it,1)->second) + (dist[next(it,1)->second] - dist[LCA(it->second, next(it,1)->second)]) - distance(prev(it,1)->second, next(it,1)->second);
    }
  }
}

int main()
{
  scanf("%d", &n); logn = ceil(log2(n));
  int u, v; lli c;
  for (int i = 0; i < n - 1; i ++)
  {
    scanf("%d %d %lld", &u, &v, &c); u --, v --;
    tree[u].push_back({v, c}); tree[v].push_back({u, c});
  }
  build();

  int q; scanf("%d", &q);
  while (q --)
  {
    char op; scanf("\n%c", &op);
    if (op == '?') printf("%lld\n", total);
    else
    {
      scanf("%d", &u); u --;
      if (op == '+') add(u); else rem(u);
    }
  }

  return(0);
}
