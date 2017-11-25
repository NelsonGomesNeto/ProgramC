#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
const int MAX = 100;
char board[MAX][MAX + 1];
int line[MAX][MAX], row[MAX][MAX], inf = 1<<20;
int matrixGraph[10002][10002];

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
  int visited[10002]; memset(visited, 0, sizeof(visited));
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
  int maxFlow = 0, parent[10002]; memset(parent, -1, sizeof(parent));
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

int main()
{
  int size;
  while (scanf("%d", &size) != EOF)
  {
    //memset(matrixGraph, 0, sizeof(matrixGraph));
    memset(line, 0, sizeof(line)); memset(row, 0, sizeof(row));
    for (int i = 0; i < size; i ++)
    {
      getchar();
      scanf("%s", board[i]);
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

    set<int> graph[10002];
    for (int i = 0; i < size; i ++)
      for (int j = 0; j < size; j ++)
      {
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
      }

    for (int i = 0; i < size; i ++)
      for (int j = 0; j < size; j ++)
        if (row[i][j])
        {
          graph[row[i][j] + 5000].insert(10001);
          matrixGraph[row[i][j] + 5000][10001] = 1; matrixGraph[10001][row[i][j] + 5000] = 0;
          graph[10001].insert(row[i][j] + 5000);
        }
    //fillGraph(graph, size);

    DEBUG {
      for (int i = 0; i < 10002; i ++)
      {
        if (graph[i].size() > 0)
        {
          printf("%d", i);
          for (auto j: graph[i])
            printf("-> %d", j);
          printf("\n");
        }
      }
    }

    int ans = fordFulkerson(graph, 0, 10001);

    // int aux[size][size]; memset(aux, 0, sizeof(aux));
    // for (auto v: graph[10001])
    // {
    //   if (matrixGraph[10001][v])
    //     for (auto u: graph[v])
    //       if (matrixGraph[v][u])
    //         printf("%d %d\n", v - 5000, u);
    // }
    // for (int i = 0; i < size; i ++)
    // {
    //   for (int j = 0; j < size; j ++)
    //     if (aux[i][j]) printf("R");
    //     else printf("%c", board[i][j]);
    //   printf("\n");
    // }

    DEBUG printf("Flow: %d\n", ans);
    printf("%d\n", ans);

  }
  return(0);
}