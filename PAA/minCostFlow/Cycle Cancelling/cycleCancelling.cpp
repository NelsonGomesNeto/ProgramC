#include <bits/stdc++.h>
using namespace std;

int vertice, matrixGraph[2][1000][1000], residualGraph[2][1000][1000], costNetWork[1000][1000], level[1000], inf = 1<<20; // 0 capacity, 1 cost

int bfs(vector<int> graph[], int source, int target)
{
  memset(level, -1, sizeof(level));
  level[source] = 0;
  deque<int> queue; queue.push_back(source);
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop_front();
    for (auto v: graph[u])
      if (level[v] < 0 && residualGraph[0][u][v] > 0)
      {
        level[v] = level[u] + 1;
        queue.push_back(v);
      }
  }
  return(level[target] > 0);
}

int dfs(vector<int> graph[], int u, int target, int flow)
{
  if (u == target) return(flow);
  int actualFlow = 0;
  for (auto v: graph[u])
    if (level[u] == level[v] + 1 && residualGraph[0][u][v] > 0)
    {
      int pathFlow = dfs(graph, v, target, min(flow, residualGraph[0][u][v]));
      flow -= pathFlow;
      residualGraph[0][u][v] -= pathFlow;
      residualGraph[0][v][u] += pathFlow;
      actualFlow += pathFlow;
    }
  return(actualFlow);
}

int dinic(vector<int> graph[], int source, int target)
{
  int maxFlow = 0, pathFlow;
  while (bfs(graph, source, target))
    do
    {
      pathFlow = dfs(graph, source, target, inf);
      maxFlow += pathFlow;
    }
    while (pathFlow);
  return(maxFlow);
}

void costNetWork(vector<int> graph[])
{
  for (int i = 0; i < vertice; i ++)
    for (auto j: graph[i])
      if (matrixGraph[0][i][j] != 0)
        costNetWork[i][j] = matrixGraph[1][i][j];
      else if (residualGraph[0][i][j] != 0)
        costNetWork[i][j] = residualGraph[1][i][j].
}

int minCost(vector<int> graph[], int source, int target))
{
  int minCost = 0;
  memcpy(residualGraph, matrixGraph, sizeof(matrixGraph));
  dinic(graph, source, target);
  costNetWork(graph);
  while (negativeCycle())
  {
    // get minimum capacity, increase the flow along the edges in cycle C
    // update residual graph
    costNetWork(graph);
  }
  // Calculate min cost
  return(minCost);
}

void addEdge(vector<int> graph[], int u, int v, int cap, int cost)
{
  graph[u].push_back(v);
  matrixGraph[0][u][v] = cap;
  matrixGraph[1][u][v] = cost;
  graph[v].push_back(u);
  matrixGraph[0][v][u] = 0;
  matrixGraph[1][v][u] = 0;
}

int main()
{
  memset(matrixGraph, 0, sizeof(matrixGraph));
  int edge, source, target;
  scanf("%d %d %d %d", &vertice, &edge, &source, &target);

  vector<int> graph[vertice]; int u, v, cap, cost;
  for (int i = 0; i < edge; i ++)
  {
    scanf("%d %d %d %d", &u, &v, &cap, &cost);
    addEdge(graph, u, v, cap, cost);
  }

  int minCost = minCost(graph);

  return(0);
}