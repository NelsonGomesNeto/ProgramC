#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

const int maxVertices = 1 + 2 * 20 * 20 + 1, inf = 1<<20;
int source = 0, target, vertices;
int level[maxVertices], ptr[maxVertices];
struct Edge { int to, back, flow, capacity; };
vector<Edge> graph[maxVertices];
deque<int> q;
void addEdge(int u, int v, int f)
{
  graph[u].push_back({v, (int) graph[v].size(), f, f});
  graph[v].push_back({u, (int) graph[u].size() - 1, 0, 0});
}

bool bfs()
{
  memset(level, -1, sizeof(level));
  level[source] = 0; q.push_back(source);
  while (!q.empty())
  {
    int u = q.front(); q.pop_front();
    for (Edge &e: graph[u])
      if (e.flow && level[e.to] == -1)
        q.push_back(e.to), level[e.to] = level[u] + 1;
  }
  return(level[target] != -1);
}

int dfs(int u, int flow)
{
  if (u == target || !flow) return(flow);
  for (int &p = ptr[u]; p < graph[u].size(); p ++)
  {
    Edge &e = graph[u][p];
    if (e.flow && level[e.to] == level[u] + 1)
    {
      int delivered = dfs(e.to, min(flow, e.flow));
      e.flow -= delivered;
      graph[e.to][e.back].flow += delivered;
      if (delivered) return(delivered);
    }
  }
  return(0);
}

int dinic()
{
  int maxFlow = 0, flow;
  while (bfs())
  {
    memset(ptr, 0, sizeof(ptr));
    while (flow = dfs(source, inf)) maxFlow += flow;
  }
  return(maxFlow);
}

int main()
{
  int n, m; scanf("%d %d", &n, &m);
  char puzzle[n][m + 1]; for (int i = 0; i < n; i ++) scanf("\n%s", puzzle[i]);

  target = 2*n*m + 1; vertices = target + 1;
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
    {
      if ((i + j) & 1) // odd
      {
        addEdge(1 + i*m + j, target, 1);
        // if (puzzle[i][j] != 'o') addEdge(1 + n*m + i*m + j, target, 1);
      }
      else
      {
        addEdge(source, 1 + i*m + j, 1);
        if (puzzle[i][j] != 'o') addEdge(source, 1 + n*m + i*m + j, 1);
        for (int k = 0; k < 4; k ++)
        {
          int ii = i + dy[k], jj = j + dx[k];
          if (ii >= 0 && ii < n && jj >= 0 && jj < m)
          {
            addEdge(1 + i*m + j, 1 + ii*m + jj, 1);
            if (puzzle[ii][jj] != 'o') addEdge(1 + i*m + j, 1 + n*m + ii*m + jj, 1);
            if (puzzle[i][j] != 'o')
            {
              addEdge(1 + n*m + i*m + j, 1 + ii*m + jj, 1);
              if (puzzle[ii][jj] != 'o') addEdge(1 + n*m + i*m + j, 1 + n*m + ii*m + jj, 1);
            }
          }
        }
      }
    }

  int ans = dinic();
  printf("%d\n", ans);
  return(0);
}
