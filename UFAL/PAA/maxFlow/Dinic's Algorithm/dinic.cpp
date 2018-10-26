#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
int vertices, edges, source, sink, inf = 1<<20;
int matrixGraph[1000][1000], level[1000];

void printGraph(vector<int> graph[])
{
  for (int i = 0; i < vertices; i ++)
  {
    printf("%d", i);
    for (auto u: graph[i])
      if (matrixGraph[i][u])
        printf(" -> (%d, %d)", u, matrixGraph[i][u]);
    printf("\n");
  }
}

int bfs(vector<int> graph[], int source, int target)
{
  memset(level, -1, sizeof(level));
  level[source] = 0;
  deque<int> queue; queue.push_back(source);
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
  DEBUG {printf("Level: "); for (int i = 0; i < vertices; i ++) printf("%d%c", level[i], i < vertices - 1 ? ' ' : '\n');}
  return(level[target] > 0);
}

int dfs(vector<int> graph[], int u, int target, int flow)
{
  DEBUG printf("At: %d %d\n", u, flow);
  if (u == target) return(flow);
  int totalDelivered = 0;
  for (auto v: graph[u])
    if (level[u] == level[v] - 1 && matrixGraph[u][v] > 0)
    {
      int delivered = dfs(graph, v, target, min(flow, matrixGraph[u][v]));
      DEBUG printf("totalDelivered: %d %d %d\n", u, totalDelivered + delivered, matrixGraph[u][v]);
      flow -= delivered;
      matrixGraph[u][v] -= delivered;
      matrixGraph[v][u] += delivered;
      totalDelivered += delivered;
      DEBUG printGraph(graph);
    }
  return(totalDelivered);
}

int dinic(vector<int> graph[], int source, int target)
{
  int maxFlow = 0, pathFlow;
  while (bfs(graph, source, target))
  {
    pathFlow = dfs(graph, source, target, inf);
    DEBUG printf("%d\n", pathFlow);
    maxFlow += pathFlow;
  }
  return(maxFlow);
}

int main()
{
  while (scanf("%d %d %d %d", &vertices, &edges, &source, &sink) != EOF)
  {
    memset(matrixGraph, 0, sizeof(matrixGraph));
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
  }

  return(0);
}
