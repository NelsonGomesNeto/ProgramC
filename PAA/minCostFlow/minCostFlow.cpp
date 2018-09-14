#include <bits/stdc++.h>
#define VERBOSE if(1)
using namespace std;
int matrixGraph[1000][1000][2], n, m, inf = 1<<20;

void addEdge(vector<int> graph[], int u, int v, int f, int c)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = f, matrixGraph[u][v][1] = c;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = 0, matrixGraph[v][u][1] = -c;
}

int bellmannFord(vector<int> graph[], int prev[], int source, int target)
{
  int cost[n]; for (int i = 0; i < n; i ++) cost[i] = inf;
  cost[source] = 0;
  for (int i = 0; i < n - 1; i ++)
    for (int u = 0; u < n; u ++)
      for (auto v: graph[u])
        if (matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
        {
          cost[v] = cost[u] + matrixGraph[u][v][1];
          prev[v] = u;
        }
  return(cost[target] != inf);
}

void printGraph(vector<int> graph[])
{
  for (int u = 0; u < n; u ++)
  {
    printf("%d: ", u);
    for (auto v: graph[u])
      printf("(%d, %d, %d) -> ", v, matrixGraph[u][v][0], matrixGraph[u][v][1]);
    printf("¬\n");
  }
}

void printPath(int prev[], int u, int source)
{
  if (prev[u] == source)
  {
    printf("(u: %d, f: %d, c: %d)", u, matrixGraph[prev[u]][u][0], matrixGraph[prev[u]][u][1]);
    return;
  }
  printPath(prev, prev[u], source);
  printf(" -> (u: %d, f: %d, c: %d)", u, matrixGraph[prev[u]][u][0], matrixGraph[prev[u]][u][1]);
}

pair<int, int> minCostFlow(vector<int> graph[], int source, int target)
{
  int prev[n], minCost = 0, maxFlow = 0;
  while (bellmannFord(graph, prev, source, target))
  {
    VERBOSE { printPath(prev, target, source); printf("\n"); }
    int v = target, flow = inf;
    while (v != source)
    {
      flow = min(flow, matrixGraph[prev[v]][v][0]);
      v = prev[v];
    }
    maxFlow += flow;

    v = target;
    while (v != source)
    {
      matrixGraph[prev[v]][v][0] -= flow;
      matrixGraph[v][prev[v]][0] += flow;
      minCost += matrixGraph[prev[v]][v][1] * flow;
      v = prev[v];
    }
  }
  pair<int, int> ans = {minCost, maxFlow};
  return(ans);
}

int main()
{
  memset(matrixGraph, 0, sizeof(matrixGraph));
  scanf("%d %d", &n, &m);
  vector<int> graph[n]; int u, v, f, c;
  for (int i = 0; i < m; i ++)
  {
    scanf("%d %d %d %d", &u, &v, &f, &c);
    addEdge(graph, u, v, f, c);
  }
  VERBOSE
  {
    printf("\tGraph:\n");
    printGraph(graph);
    printf("\n");
  }
  int minCost = 0, maxFlow = 0;
  pair<int, int> ans = minCostFlow(graph, 0, n - 1);
  minCost = ans.first, maxFlow = ans.second;
  printf("Min Cost: %d, Max Flow: %d\n", minCost, maxFlow);

  return(0);
}