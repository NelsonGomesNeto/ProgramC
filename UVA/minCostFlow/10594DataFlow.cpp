#include <bits/stdc++.h>
using namespace std;
#define lli long long int
// source (0) -> nodes (1, n - 2) -> target (n - 1)
const int maxVertices = 101;
lli matrixGraph[maxVertices][maxVertices][2], inf = LLONG_MAX, cost[maxVertices];
int source = 0, target, vertices, previ[maxVertices];

void addEdge(vector<int> graph[], int u, int v, lli f, lli c)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = f, matrixGraph[u][v][1] = c;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = 0, matrixGraph[v][u][1] = -c;
}

int bellmannFord(vector<int> graph[])
{
  for (int i = 0; i < vertices; i ++) cost[i] = LLONG_MAX;
  cost[source] = 0;
  for (int i = 0; i < vertices - 1; i ++)
  {
    int done = 0;
    for (int u = 0; u < vertices; u ++)
      for (auto v: graph[u])
        if (matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
        {
          cost[v] = cost[u] + matrixGraph[u][v][1];
          previ[v] = u, done = 1;
        }
    if (!done) break;
  }
  for (int u = 0; u < vertices; u ++)
    for (auto v: graph[u])
      if (matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
        return(0);
  return(cost[target] != LLONG_MAX);
}

pair<lli, lli> minCostFlow(vector<int> graph[])
{
  lli minCost = 0, maxFlow = 0;
  while (bellmannFord(graph))
  {
    int v = target; lli flow = LLONG_MAX;
    while (v != source)
    {
      printf("%d %d %lld %lld %lld\n", previ[v], v, flow, matrixGraph[previ[v]][v][0], matrixGraph[previ[v]][v][1]);
      flow = min(flow, matrixGraph[previ[v]][v][0]);
      v = previ[v];
    }
    if (!flow) break;
    maxFlow += flow;
    printf("Here %lld %lld %lld\n", maxFlow, minCost, flow);

    v = target;
    while (v != source)
    {
      matrixGraph[previ[v]][v][0] -= flow;
      matrixGraph[v][previ[v]][0] += flow;
      // printf("%d %d %lld\n", previ[v], v, matrixGraph[previ[v]][v][1]);
      minCost += matrixGraph[previ[v]][v][1] * flow;
      v = previ[v];
    }
  }
  return(make_pair(minCost, maxFlow));
}

int main()
{
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF)
  {
    memset(matrixGraph, 0, sizeof(matrixGraph));
    lli edges[m][3]; for (int i = 0; i < m; i ++) scanf("%lld %lld %lld", &edges[i][0], &edges[i][1], &edges[i][2]);
    lli data, capacity; scanf("%lld %lld", &data, &capacity);

    vector<int> graph[n + 1]; target = n, vertices = n + 1;
    for (int i = 0; i < m; i ++)
      addEdge(graph, edges[i][0] - 1, edges[i][1] - 1, capacity, edges[i][2]);
    addEdge(graph, n - 1, target, data, 0);

    pair<lli, lli> ans = minCostFlow(graph);
    if (ans.second < data) printf("Impossible.\n");
    else printf("%lld\n", ans.first);
  }
  return(0);
}