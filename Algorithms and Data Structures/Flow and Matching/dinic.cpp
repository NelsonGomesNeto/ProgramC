#include <bits/stdc++.h>
using namespace std;
const int maxVertices = 1e5;
int source, target, inf = 1e8, vertices;
int level[maxVertices];

struct Edge
{
  int to, back, flow, capacity;
};
vector<Edge> graph[maxVertices];

void addEdge(int u, int v, int f)
{
  graph[u].push_back({v, (int) graph[v].size(), f, f});
  graph[v].push_back({u, (int) graph[u].size() - 1, 0, 0});
}

int bfs()
{
  memset(level, -1, sizeof(level)); level[source] = 0;
  deque<int> q; q.push_back(source);
  while (!q.empty())
  {
    int u = q.front(); q.pop_front();
    for (auto e: graph[u])
      if (e.flow && level[e.to] == -1)
        q.push_back(e.to), level[e.to] = level[u] + 1;
  }
  return(level[target] != -1);
}

int dfs(int u, int flow)
{
  if (u == target) return(flow);
  int totalDelivered = 0;
  for (auto &e: graph[u])
  {
    if (e.flow && level[u] == level[e.to] - 1)
    {
      int delivered = dfs(e.to, min(flow, e.flow));
      flow -= delivered;
      e.flow -= delivered;
      graph[e.to][e.back].flow += delivered;
      totalDelivered += delivered;
    }
  }
  return(totalDelivered);
}

int dinic()
{
  int maxFlow = 0, flow;
  while (bfs()) while (flow = dfs(source, inf)) maxFlow += flow;
  return(maxFlow);
}

int main()
{
  int n, m; scanf("%d %d", &n, &m); vertices = n;
  source = 0, target = n - 1;

  int u, v, f;
  for (int i = 0; i < m; i ++)
  {
    scanf("%d %d %d", &u, &v, &f);
    addEdge(u, v, f);
  }

  int maxFlow = dinic();
  printf("%d\n", maxFlow);

  return(0);
}
