#include <bits/stdc++.h>
using namespace std;
int matrixGraph[1000][1000], level[1000], work[1000], vertices, inf = 1<<20;

int bfs(vector<int> graph[], int source, int target)
{
  memset(level, -1, sizeof(level));
  level[source] = 0;
  deque<int> queue;
  queue.push_back(source);
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop_front();
    for (auto v: graph[u])
      if (level[v] < 0 && matrixGraph[u][v] > 0)
      {
        level[v] = level[u] + 1;
        queue.push_back(v);
      }
  }
  return(level[target] > 0);
}

int dfs(vector<int> graph[], int source, int target, int flow)
{
  if (source == target) return(flow);
  int totalFlow = 0;
  for (auto v: graph[source])
    if (level[v] == level[source] + 1 && matrixGraph[source][v] > 0)
    {
      int pathFlow = dfs(graph, v, target, min(flow, matrixGraph[source][v]));
      //flow -= pathFlow;
      matrixGraph[source][v] -= pathFlow;
      matrixGraph[v][source] += pathFlow;
      totalFlow += pathFlow;
    }
  return(totalFlow);
}

int dinic(vector<int> graph[], int source, int target)
{
  int maxFlow = 0, pathFlow = 0;
  while (bfs(graph, source, target))
  {
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