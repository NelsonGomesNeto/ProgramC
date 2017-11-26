#include <bits/stdc++.h>
using namespace std;
int matrixGraph[1000][1000], dist[1000], level[1000], work[1000], vertices, inf = 1<<20;

int bfs(vector<int> graph[], int source, int target)
{
  fill(dist, dist + vertices, -1);
  dist[source] = 0;
  int nowLevel = 0;
  level[nowLevel ++] = source;
  for (int i = 0; i < nowLevel; i ++)
  {
    int u = level[i];
    for (auto v: graph[u])
    {
      if (dist[v] < 0 && matrixGraph[u][v] > 0)
      {
        dist[v] = dist[u] + 1;
        level[nowLevel ++] = v;
      }
    }
  }
  return(dist[target] >= 0);
}

int dfs(vector<int> graph[], int source, int target, int flow)
{
  if (source == target) return(flow);
  for (auto v: graph[source])
  {
    if (matrixGraph[source][v] <= 0) continue;
    if (dist[v] == dist[source] + 1)
    {
      int pathFlow = dfs(graph, v, target, min(flow, matrixGraph[source][v]));
      if (pathFlow > 0)
      {
        matrixGraph[source][v] -= pathFlow;
        matrixGraph[v][source] += pathFlow;
        return(pathFlow);
      }
    }
  }
  return(0);
}

int dinic(vector<int> graph[], int source, int target)
{
  int maxFlow = 0, pathFlow = 0;
  while (bfs(graph, source, target))
  {
    fill(work, work + vertices, 0);
    do
    {
      pathFlow = dfs(graph, source, target, inf);
      printf("%d\n", pathFlow);
      maxFlow += pathFlow;
    } while(pathFlow);
  }
  return(maxFlow);
}

int main()
{
  memset(matrixGraph, 0, sizeof(matrixGraph));
  int edges, source, sink; scanf("%d %d %d %d", &vertices, &edges, &source, &sink);

  vector<int> graph[vertices];
  int u, v, c;
  for (int i = 0; i < edges; i ++)
  {
    scanf("%d %d %d", &u, &v, &c);
    graph[u].push_back(v);
    graph[v].push_back(u);
    matrixGraph[u][v] = c;
  }

  int maxFlow = dinic(graph, source, sink);

  printf("%d\n", maxFlow);

  return(0);
}