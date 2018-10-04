#include <bits/stdc++.h>
using namespace std;
#define lli long long int
// source (0) -> nodes (1, n - 2) -> target (n - 1)
const int maxVertices = 101;
lli matrixGraph[maxVertices][maxVertices][2], inf = 1e18, cost[maxVertices];
int source = 0, target, vertices, previ[maxVertices];

void addEdge(vector<int> graph[], int u, int v, lli f, lli c)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = f, matrixGraph[u][v][1] = c;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = f, matrixGraph[v][u][1] = c;
}

int bellmannFord(vector<int> graph[])
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
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
  return(cost[target] != inf);
}

pair<lli, lli> minCostFlow(vector<int> graph[], lli data)
{
  lli minCost = 0, maxFlow = 0;
  while (bellmannFord(graph))
  {
    lli flow = LLONG_MAX;
    for (int v = target; v != source; v = previ[v]) flow = min(flow, matrixGraph[previ[v]][v][0]);
    maxFlow += flow; data -= flow;
    // printf("Here %lld %lld %lld\n", maxFlow, minCost, flow);

    for (int v = target; v != source; v = previ[v])
    {
      matrixGraph[previ[v]][v][0] -= flow;
      matrixGraph[v][previ[v]][0] += flow;
      minCost += matrixGraph[previ[v]][v][1] * flow;
      matrixGraph[previ[v]][v][1] *= -1; // because it can go both ways
      matrixGraph[v][previ[v]][1] *= -1; // so back-edge must be both ways
    }
    if (!data) return(make_pair(minCost, maxFlow));
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
    addEdge(graph, 0, 1, data, 0);
    for (int i = 0; i < m; i ++)
      addEdge(graph, edges[i][0], edges[i][1], capacity, edges[i][2]);
    // addEdge(graph, n - 1, target, data, 0);

    pair<lli, lli> ans = minCostFlow(graph, data);
    if (ans.second < data) printf("Impossible.\n");
    else printf("%lld\n", ans.first);
  }
  return(0);
}