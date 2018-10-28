#include <bits/stdc++.h>
using namespace std;
// source (0) -> soldiers (1 - n) -> places(n+1 - n+m) - target (n+1+m)
const int maxVertices = 100 + 1 + 100 + 1; int source = 0, target;
int matrixGraph[maxVertices][maxVertices], level[maxVertices], inf = 1<<20;
vector<int> graph[maxVertices];

int bfs()
{
  memset(level, -1, sizeof(level)); level[source] = 0;
  deque<int> q; q.push_back(source);
  while (!q.empty())
  {
    int u = q.front(); q.pop_front();
    for (auto v: graph[u])
      if (matrixGraph[u][v] && level[v] == -1)
        level[v] = level[u] + 1, q.push_back(v);
  }
  return(level[target] != -1);
}

int dfs(int u, int flow)
{
  if (u == target) return(flow);
  int totalDelivered = 0;
  for (auto v: graph[u])
  if (matrixGraph[u][v] && level[u] == level[v] - 1)
  {
    int delivered = dfs(v, min(flow, matrixGraph[u][v]));
    flow -= delivered;
    matrixGraph[u][v] -= delivered;
    matrixGraph[v][u] += delivered;
    totalDelivered += delivered;
  }
  return(totalDelivered);
}

int dinic()
{
  int maxFlow = 0;
  while (bfs()) maxFlow += dfs(source, inf);
  return(maxFlow);
}

void addEdge(int u, int v, int f)
{
  graph[u].push_back(v);
  matrixGraph[u][v] = f;
  graph[v].push_back(u);
  matrixGraph[v][u] = 0;
}

int main()
{
  int t; scanf("%d", &t);
  while (t --)
  {
    memset(matrixGraph, 0, sizeof(matrixGraph));
    int n, m, w; scanf("%d %d %d", &n, &m, &w); target = n+1+m;
    for (int i = 0; i <= target; i ++) graph[i].clear();

    vector<int> preferedPlaces[n];
    for (int i = 0; i < n; i ++)
    {
      int a, b; scanf("%d", &a);
      while (a --)
      {
        scanf("%d", &b); b --;
        preferedPlaces[i].push_back(b);
      }
    }

    vector<int> preferedWeapons[n];
    for (int i = 0; i < n; i ++)
    {
      int a, b; scanf("%d", &a);
      while (a --)
      {
        scanf("%d", &b);
        preferedWeapons[i].push_back(b);
      }
    }

    set<int> placeWeapons[m];
    for (int i = 0; i < m; i ++)
    {
      int a, b; scanf("%d", &a);
      while (a --)
      {
        scanf("%d", &b);
        placeWeapons[i].insert(b);
      }
    }

    for (int i = 0; i < n; i ++) addEdge(0, i + 1, 1);
    for (int i = 0; i < m; i ++) addEdge(n+1+i, target, 1);
    for (int i = 0; i < n; i ++)
      for (auto p: preferedPlaces[i])
        for (auto w: preferedWeapons[i])
          if (placeWeapons[p].count(w))
            addEdge(i + 1, n+1+p, 1);

    int maxFlow = dinic();
    printf("%d\n", maxFlow);
  }
  return(0);
}
