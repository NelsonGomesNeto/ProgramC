#include <bits/stdc++.h>
using namespace std;
int matrixGraph[1000][1000], inf = 1<<20, size;

int findPath(vector<int> graph[], int visited[], int source, int target, int flow)
{
  if (source == target) return(flow);
  visited[source] = 1;
  for (int v = 0; v < size; v ++)
  {
    if (!visited[v] && matrixGraph[source][v] > 0)
    {
      int pathFlow = findPath(graph, visited, v, target, min(flow, matrixGraph[source][v]));
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

int fordFulkerson(vector<int> graph[], int source, int target)
{
  int maxFlow = 0;
  while (1)
  {
    int visited[size]; memset(visited, 0, sizeof(visited));
    int pathFlow = findPath(graph, visited, source, target, inf);
    if (!pathFlow)
      return(maxFlow);
    maxFlow += pathFlow;
  }
}

int main()
{
  memset(matrixGraph, 0, sizeof(matrixGraph));
  int edges, source, target; scanf("%d %d %d %d", &size, &edges, &source, &target);
  vector<int> graph[size];
  int u, v, c;
  for (int i = 0; i < edges; i ++)
  {
    scanf("%d %d %d", &u, &v, &c);
    graph[u].push_back(v);
    graph[v].push_back(u);
    matrixGraph[u][v] = c;
  }
  // for (int i = 0; i < size; i ++)
  // {
  //   printf("%d", i);
  //   for (int j = 0; j < size; j ++)
  //     printf(" -> (%d, %d)", j, matrixGraph[i][j]);
  //   printf("\n");
  // }

  int maxFlow = fordFulkerson(graph, source, target);

  printf("%d\n", maxFlow);

  return(0);
}