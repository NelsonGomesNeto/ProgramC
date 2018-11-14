#include <bits/stdc++.h>
#define RETRIEVE if(1)
using namespace std;
// left, down, right, up
int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};
// line (1 (horizontal) : 2 (vertical)) flow 2
// corner (3 (left, down), 4 (right, down), 5 (right, up), 6 (left, up)) flow 2
// square (7 (left), 8 (down), 9 (right), 10 (up)) flow 2
// dot (11 (left), 12 (down), 13 (right), 14 (up)) flow 1
int dot[4] = {13, 14, 11, 12};
int square[4] = {9, 10, 7, 8};
int corner[4][2] = {{4, 5}, {6, 5}, {3, 6}, {3, 4}};
int line[4] = {1, 2, 1, 2};
int n, m;
int puzz[20][20];

int restriction(int i, int j, int k)
{
  if (!i && (k == 2 || k == 6 || k == 5 || k == 10 || k == 14)) return(1);
  if (i == n - 1 && (k == 2 || k == 3 || k == 4 || k == 8 || k == 12)) return(1);
  if (!j && (k == 1 || k == 3 || k == 6 || k == 7 || k == 11)) return(1);
  if (j == m - 1 && (k == 1 || k == 4 || k == 5 || k == 9 || k == 13)) return(1);
  return(0);
}

bool hasNegative()
{
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      if (puzz[i][j] == -1)
        return(true);
  return(false);
}

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
  scanf("%d %d", &n, &m);
  char puzzle[n][m + 1]; for (int i = 0; i < n; i ++) scanf("\n%s", puzzle[i]);
  int dots = 0;

  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
    {
      if (puzzle[i][j] == 'o') dots ++;
      if ((i + j) & 1) // odd piece
      {
        addEdge(i*m + j, target, 1 + (puzzle[i][j] != 'o'));
        if (puzzle[i][j] == 'o')
        {
          for (int k = 11; k <= 14; k ++)
            if (!restriction(i, j, k))
              addEdge(k*n*m + i*m + j, i*m + j, 1);
        }
        else
          for (int k = 1; k < 11; k ++)
            if (!restriction(i, j, k))
              addEdge(k*n*m + i*m + j, i*m + j, 1 + (puzzle[i][j] != 'o'));
      }
      else
      {
        addEdge(source, i*m + j, 1 + (puzzle[i][j] != 'o'));
        if (puzzle[i][j] == 'o')
        {
          for (int k = 11; k <= 14; k ++)
            if (!restriction(i, j, k))
              addEdge(i*m + j, k*n*m + i*m + j, 1);
        }
        else
          for (int k = 1; k < 11; k ++)
            if (!restriction(i, j, k))
              addEdge(i*m + j, k*n*m + i*m + j, 1 + (puzzle[i][j] != 'o'));

        for (int k = 0; k < 4; k ++)
        {
          int ii = i + dy[k], jj = j + dx[k];
          if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
          // if (puzzle[i][j] != 'o' && puzzle[ii][jj] != 'o') // square - square
          //   addEdge((7+k)*n*m + i*m + j, square[k]*n*m + ii*m + jj, 2);

          if (puzzle[i][j] == 'o') // dot
          {
            if (puzzle[ii][jj] == 'o') // dot - dot
              addEdge((11+k)*n*m + i*m + j, dot[k]*n*m + ii*m + jj, 1);
            if (puzzle[ii][jj] != 'o')
            {
              // dot - corner
              addEdge((11+k)*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge((11+k)*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
              // dot - line
              addEdge((11+k)*n*m + i*m + j, line[k]*n*m + ii*m + jj, 1);
            }
          }
          else
          {
            // line
            if (puzzle[ii][jj] == 'o') // line - dot
              addEdge(line[k]*n*m + i*m + j, dot[k]*n*m + ii*m + jj, 1);
            else
            {
              // line - line
              addEdge(line[k]*n*m + i*m + j, line[k]*n*m + ii*m + jj, 1);
              // line - corner
              addEdge(line[k]*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge(line[k]*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
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
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, line[k]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, line[k]*n*m + ii*m + jj, 1);
              // corner - corner
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][0]*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, corner[k][0]*n*m + ii*m + jj, 1);
              addEdge(corner[(k + 2) % 4][1]*n*m + i*m + j, corner[k][1]*n*m + ii*m + jj, 1);
            }
          }
        }
        // line (1 (horizontal) : 2 (vertical)) flow 2
        // corner (3 (left, down), 4 (right, down), 5 (right, up), 6 (left, up)) flow 2
        // square (7 (left), 8 (down), 9 (right), 10 (up)) flow 2
        // dot (11 (left), 12 (down), 13 (right), 14 (up)) flow 1
      }
    }

  int ans = dinic();
  // printf("%d\n", ans);
  printf("%s\n", ans == (n*m - (dots / 2)) ? "Y" : "N");
  RETRIEVE
  {
    for (Edge &cell: graph[source])
      if (!cell.flow)
      {
        int chosen = -1, i = cell.to / m, j = cell.to % m;
        for (Edge &config: graph[cell.to])
          if (!config.flow)
            chosen = (config.to - cell.to) / (n*m);
        puzz[i][j] = chosen;
      }
    for (Edge &cell: graph[target])
      if (!graph[cell.to][cell.back].flow)
      {
        int chosen = -1, i = cell.to / m, j = cell.to % m;
        for (Edge &config: graph[cell.to])
          if (!graph[config.to][config.back].flow)
            chosen = (config.to - cell.to) / (n*m);
        puzz[i][j] = chosen;
      }
    while (hasNegative() && 0)
      for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
          if (puzz[i][j] == -1)
          {
            if (i > 0 && (puzz[i - 1][j] == 2 || puzz[i - 1][j] == 3 || puzz[i - 1][j] == 4 || puzz[i - 1][j] == 12))
            {
              if (j > 0 && (puzz[i][j - 1] == 1 || puzz[i][j - 1] == 4 || puzz[i][j - 1] == 5 || puzz[i][j - 1] == 13))
                puzz[i][j] = 6;
              else
                puzz[i][j] = 5;
            }
            else if (i > 0 && j < m - 1 && (puzz[i - 1][j] == 1 || puzz[i - 1][j] == 5 || puzz[i - 1][j] == 6 || (puzz[i - 1][j] >= 11 && puzz[i - 1][j] != 12)))
              puzz[i][j] = 1;
            else
            {
              if (j > 0 && (puzz[i][j - 1] == 1 || puzz[i][j - 1] == 4 || puzz[i][j - 1] == 5 || puzz[i][j - 1] == 13))
                puzz[i][j] = 3;
              else
                puzz[i][j] = 4;
            }
          }
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
        printf("%d%c", puzz[i][j], j < m - 1 ? ' ' : '\n');

    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
        if (puzzle[i][j] == 'o')
        {
          printf("[%d, %d] %d\n", i, j, (i + j) & 1);
          for (Edge &e: graph[i*m + j])
          {
            if (e.to != source && e.to != target) printf("\t%d %d %d\n", e.to / (n*m), e.to, e.flow);
            if ((((i + j) & 1) && !graph[e.to][e.back].flow) || (!((i + j) & 1) && !e.flow))
              for (Edge &ee: graph[e.to])
              {
                printf("\t\t%d %d\n", ee.to, ee.flow);
                if ((((i + j) & 1) && !graph[ee.to][ee.back].flow) || (!((i + j) & 1) && !ee.flow))
                  for (Edge &eee: graph[ee.to])
                  {
                    if ((i + j) & 1 && eee.capacity)
                      printf("\t\t\t%d [%d, %d] %d\n", (ee.to - eee.to) / (n*m), ee.to / m, ee.to % m, ee.to, eee.flow);
                    else if (eee.capacity)
                      printf("\t\t\t%d [%d, %d] %d\n", (ee.to - eee.to) / (n*m), eee.to / m, eee.to % m, eee.to, eee.flow);
                  }
              }
          }
        }
  }
  return(0);
}
