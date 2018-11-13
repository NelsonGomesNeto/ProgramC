#include <bits/stdc++.h>
#define RETRIEVE if(1)
using namespace std;
// left, down, right, up
int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};
// line (1 (horizontal) : 2 (vertical)) flow 2
// corner (3 (left, down), 4 (right, down), 5 (left, up), 6 (right, up)) flow 2
// square (7 (left), 8 (down), 9 (right), 10 (up)) flow 2
// dot (11 (left), 12 (down), 13 (right), 14 (up)) flow 1
int dot[4] = {13, 14, 11, 12};
int square[4] = {9, 10, 7, 8};
int corner[4][2] = {{4, 6}, {5, 6}, {3, 5}, {3, 4}};
int line[4] = {1, 2, 1, 2};

const int maxVertices = 15*20*20 + 2, inf = 1<<20;
// We're gonna map every single cell to every possible piece and configuration
  // So, we will need one vertex to each cell and 14 vertices for the configurations of that pieces
  // (kind of a capacity on vertex)
// First layer: even pieces
// Second layer: odd pieces
// source (15*20*20) -> even pieces -> odd pieces -> target (15*20*20 + 1)
// match will be: n*m - (dots / 2)
int source = 15*20*20, target = 15*20*20 + 1, vertices = maxVertices;
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
  int dots = 0;

  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
    {
      if (puzzle[i][j] == 'o') dots ++;
      if ((i + j) & 1) // odd piece
      {
        addEdge(i*m + j, target, 1 + (puzzle[i][j] != 'o'));
        for (int k = 1; k <= 14; k ++)
          addEdge(k*n*m + i*m + j, i*m + j, 1 + (puzzle[i][j] != 'o'));
      }
      else
      {
        addEdge(source, i*m + j, 1 + (puzzle[i][j] != 'o'));
        for (int k = 1; k <= 14; k ++)
          addEdge(i*m + j, k*n*m + i*m + j, 1 + (puzzle[i][j] != 'o'));

        for (int k = 0; k < 4; k ++)
        {
          int ii = i + dy[k], jj = j + dx[k];
          if (puzzle[i][j] != 'o' && puzzle[ii][jj] != 'o') // square - square
            addEdge((6+k)*n*m + i*m + j, square[k]*n*m + ii*m + jj, 2);

          if (puzzle[i][j] == 'o') // dot
          {
            if (puzzle[ii][jj] == 'o') // dot - dot
              addEdge((10+k)*n*m + i*m + j, dot[k]*n*m + ii*m + jj, 1);
            if (puzzle[ii][jj] != 'o')
            {
              // dot - corner
              addEdge((10+k)*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge((10+k)*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
              // dot - line
              addEdge((10+k)*n*m + i*m + j, line[k]*n*m + ii*m + jj, 1);
            }
          }
          else
          {
            // line
            if (puzzle[ii][jj] == 'o') // line - dot
              addEdge(line[1 - (k % 2)]*n*m + i*m + j, dot[k]*n*m + ii*m + jj, 1);
            else
            {
              // line - line
              addEdge(line[1 - (k % 2)]*n*m + i*m + j, line[k % 2]*n*m + ii*m + jj, 1);
              // line - corner
              addEdge(line[1 - (k % 2)]*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge(line[1 - (k % 2)]*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
            }
            // corner
            if (puzzle[ii][jj] == 'o') // corner - dot
            {
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, dot[k]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, dot[k]*n*m + ii*m + jj, 1);
            }
            else
            {
              // corner - line
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, line[k % 2]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, line[k % 2]*n*m + ii*m + jj, 1);
              // corner - corner
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
            }
          }
        }
        // line (1 (horizontal) : 2 (vertical)) flow 2
        // corner (3 (left, down), 4 (right, down), 5 (left, up), 6 (right, up)) flow 2
        // square (7 (left), 8 (down), 9 (right), 10 (up)) flow 2
        // dot (11 (left), 12 (down), 13 (right), 14 (up)) flow 1
      }
    }

  int ans = dinic();
  // printf("%d\n", ans);
  printf("%s\n", ans == (n*m - (dots / 2)) ? "Y" : "N");
  RETRIEVE
  {
    int puzz[n][m];
    for (Edge &cell: graph[source])
      if (!cell.flow)
      {
        int chosen = -1, i = cell.to / m, j = cell.to % m;
        for (Edge &config: graph[cell.to])
          if (!config.flow)
          {
            printf("%d %d %d\n", config.to, cell.to, n*m);
            chosen = (config.to - cell.to) / (n*m);
          }
        puzz[i][j] = chosen;
      }
    for (Edge &cell: graph[target])
      if (cell.flow)
      {
        int chosen = -1, i = cell.to / m, j = cell.to % m;
        for (Edge &config: graph[cell.to])
          if (config.flow)
            chosen = (config.to - cell.to) / (n*m);
        puzz[i][j] = chosen;
      }
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
        printf("%2d%c", puzz[i][j], j < m - 1 ? ' ' : '\n');
  }
  return(0);
}
