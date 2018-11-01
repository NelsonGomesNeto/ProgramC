#include <bits/stdc++.h>
using namespace std;
const int maxVertices = 1e5;
int source, target, vertices, inf = 1e7;
int cost[maxVertices], prevVertice[maxVertices], prevEdge[maxVertices], minFlow[maxVertices];

struct Edge { int to, back, flow, capacity, cost; };
vector<Edge> graph[maxVertices];
void addEdge(int u, int v, int f, int c)
{
  graph[u].push_back({v, (int) graph[v].size(), f, f, c});
  graph[v].push_back({u, (int) graph[u].size() - 1, 0, 0, -c});
}

int bellmanFord()
{
  for (int i = 0; i < vertices; i ++) cost[i] = minFlow[i] = inf;
  cost[source] = 0;
  for (int i = 0, done = 0; i < vertices - 1; i ++, done = 0)
  {
    for (int u = 0; u < vertices; u ++)
      for (int j = 0; j < graph[u].size(); j ++)
      {
        Edge &e = graph[u][j];
        if (e.flow && cost[u] + e.cost < cost[e.to])
        {
          cost[e.to] = cost[u] + e.cost;
          prevVertice[e.to] = u, prevEdge[e.to] = j;
          minFlow[e.to] = min(minFlow[u], e.flow);
          done = 1;
        }
      }
    if (!done) break;
  }
  return(cost[target] != inf);
}

pair<int, int> minCostFlow()
{
  int minCost = 0, totalFlow = 0;
  while (bellmanFord())
  {
    int flow = minFlow[target];
    totalFlow += flow;
    for (int v = target; v != source; v = prevVertice[v])
    {
      Edge &e = graph[prevVertice[v]][prevEdge[v]];
      e.flow -= flow;
      graph[e.to][e.back].flow += flow;
      minCost += flow * e.cost;
    }
  }
  return(make_pair(minCost, totalFlow));
}

int main()
{
  int n, m; scanf("%d %d", &n, &m); vertices = n;
  source = 0, target = n - 1;

  int u, v, f, c;
  for (int i = 0; i < m; i ++)
  {
    scanf("%d %d %d %d", &u, &v, &f, &c);
    addEdge(u, v, f, c);
  }

  pair<int, int> ans = minCostFlow();
  printf("%d %d\n", ans.first, ans.second);

  return(0);
}
