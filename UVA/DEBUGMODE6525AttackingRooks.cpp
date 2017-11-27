#include <bits/stdc++.h>
#define DEBUG if(1)
using namespace std;

clock_t start, stop;
const int MAX = 100;
char board[MAX][MAX + 1];
int line[MAX][MAX], row[MAX][MAX], inf = 1<<20, vertices = 0;
int matrixGraph[10012][10012], dist[10012], level[10012];

void fillAuxBoard(int size)
{
  int l = 1, r = 1, k;
  for (int i = 0; i < size; i ++)
    for (int j = 0; j < size; j ++)
    {
      if (board[j][i] != 'X' && line[j][i] == 0)
      {
        line[j][i] = l ++;
        k = i;
        while (k < size && board[j][k] != 'X')
        {
          if (k != i) line[j][k] = l - 1;
          k += board[j][k] != 'X';
        }
      }

      if (board[i][j] != 'X' && row[i][j] == 0)
      {
        row[i][j] = r ++;
        k = i;
        while (k < size && board[k][j] != 'X')
        {
          if (k != i) row[k][j] = r - 1;
          k += board[k][j] != 'X';
        }
      }
    }
}

void fillGraph(set<int> graph[], int size)
{

}

int bfs(set<int> graph[], int source, int target, int parent[])
{
  int visited[10012]; memset(visited, 0, sizeof(visited));
  deque<int> queue;
  queue.push_back(source);
  visited[source] = 1;
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop_front();
    for (auto v: graph[u])
      if (!visited[v] && matrixGraph[u][v] > 0)
      {
        queue.push_back(v);
        parent[v] = u;
        visited[v] = 1;
      }
  }
  return(visited[target]);
}

int fordFulkerson(set<int> graph[], int source, int target)
{
  int maxFlow = 0, parent[10012]; memset(parent, -1, sizeof(parent));
  while (bfs(graph, source, target, parent))
  {
    int pathFlow = inf, v = target, u;
    while (v != source)
    {
      u = parent[v];
      pathFlow = min(pathFlow, matrixGraph[u][v]);
      v = parent[v];
    }
    v = target;
    while (v != source)
    {
      u = parent[v];
      matrixGraph[u][v] -= pathFlow;
      matrixGraph[v][u] += pathFlow;
      v = parent[v];
    }
    maxFlow += pathFlow;
  }
  return(maxFlow);
}

int findPath(int visited[], int source, int target, int flow)
{
  if (source == target) return(flow);
  visited[source] = 1;
  for (int v = 0; v < 10012; v ++)
    if (!visited[v] && matrixGraph[source][v] > 0)
    {
      int pathFlow = findPath(visited, v, target, min(flow, matrixGraph[source][v]));
      if (pathFlow > 0)
      {
        matrixGraph[source][v] -= pathFlow;
        matrixGraph[v][source] += pathFlow;
        return(pathFlow);
      }
    }
  return(0);
}

int dfsFordFulkerson(int source, int target)
{
  int maxFlow = 0;
  while (1)
  {
    int visited[10012]; memset(visited, 0, sizeof(visited));
    int pathFlow = findPath(visited, source, target, inf);
    if (!pathFlow)
      return(maxFlow);
    maxFlow += pathFlow;
  }
}

int dinicBFS(set<int> graph[], int source, int target)
{
  memset(dist, -1, sizeof(dist));
  dist[source] = 0;
  int nowLevel = 0;
  level[nowLevel ++] = source;
  for (int i = 0; i < nowLevel; i ++)
  {
    int u = level[i];
    for (auto v: graph[u])
    {
      if (dist[v] < 0 && matrixGraph[u][v] > 0)
      {
        dist[v] = dist[u] + 1;
        level[nowLevel ++] = v;
      }
    }
  }
  return(dist[target] >= 0);
}

int dinicDFS(set<int> graph[], int source, int target, int flow)
{
  if (source == target) return(flow);
  for (auto v: graph[source])
  {
    if (matrixGraph[source][v] <= 0) continue;
    if (dist[v] == dist[source] + 1)
    {
      int pathFlow = dinicDFS(graph, v, target, min(flow, matrixGraph[source][v]));
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

int dinic(set<int> graph[], int source, int target)
{
  int maxFlow = 0, pathFlow = 0;
  while (dinicBFS(graph, source, target))
  {
    do
    {
      pathFlow = dinicDFS(graph, source, target, inf);
      maxFlow += pathFlow;
    } while(pathFlow);
  }
  return(maxFlow);
}

int main()
{
  int size;
  while (scanf("%d", &size) != EOF)
  {
    start = clock();
    //memset(matrixGraph, 0, sizeof(matrixGraph));
    vertices = 0;
    memset(line, 0, sizeof(line)); memset(row, 0, sizeof(row));
    for (int i = 0; i < size; i ++)
    {
      char bug;
      for (int j = 0; j < size; j ++)
      {
        scanf("%c", &bug);
        if (!(bug == '.' || bug == 'X')) j --;
        else board[i][j] = bug;
      }
      DEBUG printf("%s\n", board[i]);
    }

    fillAuxBoard(size);
    DEBUG {
      for (int i = 0; i < size; i ++)
      for (int j = 0; j < size; j ++)
      printf("%2d%c", line[i][j], j < size - 1 ? ' ' : '\n');
      printf("\n");
      for (int i = 0; i < size; i ++)
      for (int j = 0; j < size; j ++)
      printf("%2d%c", row[i][j], j < size - 1 ? ' ' : '\n');
      printf("\n");
    }

    set<int> graph[10012];
    for (int i = 0; i < size; i ++)
      for (int j = 0; j < size; j ++)
      {
        if (board[i][j] == '.')
        {
          graph[line[i][j]].insert(row[i][j] + 5000);
          matrixGraph[line[i][j]][row[i][j] + 5000] = 1;
          graph[row[i][j] + 5000].insert(line[i][j]);
          matrixGraph[row[i][j] + 5000][line[i][j]] = 0;
        }
        /*
        if (line[i][j])
        {
          graph[0].insert(line[i][j]);
          matrixGraph[0][line[i][j]] = 1; matrixGraph[line[i][j]][0] = 0;
          graph[line[i][j]].insert(0);
          for (int k = j; k < size && board[i][k] != 'X'; k ++)
          {
            if (row[i][k])
            {
              graph[line[i][j]].insert(row[i][k] + 5000);
              matrixGraph[line[i][j]][row[i][k] + 5000] = 1; matrixGraph[row[i][k] + 5000][line[i][j]] = 0;
              graph[row[i][k] + 5000].insert(line[i][j]);
            }
          }
          for (int k = i, m = i; k < size && m >= 0 && (row[m][j] != 0 || row[k][j] != 0);)
          {
            if (row[k][j])
            {
              graph[line[i][j]].insert(row[k][j] + 5000);
              matrixGraph[line[i][j]][row[k][j] + 5000] = 1; matrixGraph[row[k][j] + 5000][line[i][j]] = 0;
              graph[row[k][j] + 5000].insert(line[i][j]);
            }
            if (row[m][j])
            {
              graph[line[i][j]].insert(row[m][j] + 5000);
              matrixGraph[line[i][j]][row[m][j] + 5000] = 1; matrixGraph[row[m][j] + 5000][line[i][j]] = 0;
              graph[row[m][j] + 5000].insert(line[i][j]);
            }
            if (row[m][j] != 0) m --;
            if (row[k][j] != 0) k ++;
            //k += k < size && board[k][j] != '#';
          }
        }
        */
      }

    for (int i = 0; i < size; i ++)
      for (int j = 0; j < size; j ++)
      {
        if (row[i][j])
        {
          graph[row[i][j] + 5000].insert(10011);
          matrixGraph[row[i][j] + 5000][10011] = 1; matrixGraph[10011][row[i][j] + 5000] = 0;
          graph[10011].insert(row[i][j] + 5000);
        }
        if (line[i][j])
        {
          graph[0].insert(line[i][j]);
          matrixGraph[0][line[i][j]] = 1;
          graph[line[i][j]].insert(0);
          matrixGraph[line[i][j]][0] = 0;
        }
      }
    //fillGraph(graph, size);

    DEBUG {
      for (int i = 0; i < 10012; i ++)
        if (graph[i].size() > 0)
        {
          printf("%d", i);
          for (auto j: graph[i])
            printf("-> %d", j);
          printf("\n");
        }
    }

    for (int i = 0; i < 10012; i ++) vertices += graph[i].size() > 0;
    //int ans = fordFulkerson(graph, 0, 10011);
    //int ans = dfsFordFulkerson(0, 10011);
    stop = clock();
    printf("Pre  : %ld; Vertices: %d\n", stop - start, vertices);
    start = clock();
    int ans = dinic(graph, 0, 10011);
    stop = clock();
    printf("Dinic: %ld\n", stop - start);

    DEBUG printf("Flow: %d\n", ans);
    printf("%d\n", ans);

  }
  return(0);
}