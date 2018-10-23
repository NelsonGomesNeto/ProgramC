#include <bits/stdc++.h>
using namespace std;
const int maxVertices = 100;
vector<int>graph[maxVertices];
int matrixGraph[maxVertices][maxVertices], level[maxVertices], source, target, inf = 1<<20;

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
    if (matrixGraph[u][v] && level[v] == level[u] + 1)
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
}

int main()
{
  memset(matrixGraph, 0, sizeof(matrixGraph));
  int n, m; scanf("%d %d", &n, &m); source = 0, target = n - 1;
  for (int i = 0, u, v; i < m; i ++)
  {
    scanf("%d %d", &u, &v);
    addEdge(u, v, 1);
  }

  int allPaths = dinic();
  printf("%d\n", allPaths);
  return(0);
}