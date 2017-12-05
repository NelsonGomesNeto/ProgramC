#include <bits/stdc++.h>
using namespace std;
const int maxVertices = 1000 + 2;
int matrixGraph[maxVertices][maxVertices][2], inf = 1<<20, friends, capacity, vertices;

void printGraph(vector<int> graph[])
{
  for (int i = 0; i < vertices; i ++)
  {
    printf("%d", i);
    for (auto j: graph[i])
      printf(" -> (%d, %d, %d)", j, matrixGraph[i][j][0], matrixGraph[i][j][1]);
    printf("\n");
  }
}

int bellmanFord(vector<int> graph[], int source, int target, int parent[])
{
  int cost[vertices];
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  cost[source] = 0;

  for (int i = 0; i < vertices - 1; i ++)
    for (int u = 0; u < vertices; u ++)
      for (auto v: graph[u])
        if (cost[u] + matrixGraph[u][v][0] < cost[v] && matrixGraph[u][v][1] > 0)
        {
          cost[v] = cost[u] + matrixGraph[u][v][0];
          parent[v] = u;
        }

  for (int u = 0; u < vertices; u ++)
    for (auto v: graph[u])
      if (cost[u] + matrixGraph[u][v][0] < cost[v] && matrixGraph[u][v][1] > 0)
        return(0);

  //printf("cost: %d\n", cost[target]);
  return(cost[target] != inf);
}

int minMax(vector<int> graph[], int source, int target)
{
  int maxFlow = 0, cost = 0, parent[maxVertices]; memset(parent, -1, sizeof(parent));
  // printGraph(graph);
  while (bellmanFord(graph, source, target, parent))
  {
    int pathFlow = inf, v = target, u;
    while (v != source)
    {
      //printf("%d ", v + 1);
      u = parent[v];
      pathFlow = min(pathFlow, matrixGraph[u][v][1]);
      v = parent[v];
    }
    //printf("\npathFlow: %d\n", pathFlow);
    pathFlow = capacity;
    v = target;
    while (v != source)
    {
      u = parent[v];
      matrixGraph[u][v][1] -= pathFlow;
      matrixGraph[v][u][1] += pathFlow;
      matrixGraph[v][u][0] = matrixGraph[u][v][0] * -1;
      cost += matrixGraph[u][v][0] * min(pathFlow, friends);
      v = parent[v];
    }
    maxFlow += min(pathFlow, friends);
    //if (maxFlow == friends) break;
    //printf("maxFlow: %d\n", maxFlow);
  }
  if (maxFlow != friends) cost = inf;
  return(cost);
}

void addEdge(vector<int> graph[], int u, int v, int dist, int cap)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = dist;
  matrixGraph[u][v][1] = cap;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = dist;
  matrixGraph[v][u][1] = cap;
}

int main()
{
  int cities, flights, run = 1;
  while (scanf("%d %d", &cities, &flights) != EOF)
  {
    vertices = cities; memset(matrixGraph, 0, sizeof(matrixGraph));
    vector<int> graph[maxVertices];
    int u, v, c, input[flights][3];
    for (int i = 0; i < flights; i ++)
    {
      scanf("%d %d %d", &u, &v, &c); u --; v --;
      input[i][0] = u; input[i][1] = v; input[i][2] = c;
    }
    scanf("%d %d", &friends, &capacity);
    for (int i = 0; i < flights; i ++)
      addEdge(graph, input[i][0], input[i][1], input[i][2], capacity);

    int maxFlow = minMax(graph, 0, cities - 1);
    if (run > 1) printf("\n");
    printf("Instancia %d\n", run ++);
    if (maxFlow == inf) printf("impossivel\n");
    else printf("%d\n", maxFlow);
  }


  return(0);
}