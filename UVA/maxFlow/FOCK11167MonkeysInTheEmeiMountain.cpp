#include <bits/stdc++.h>
#define DEBUG if(1)
using namespace std;
const int maxVertices = 2 + 100 + 1000;
int **matrixGraph; int level[maxVertices], inf = 1<<20, used[maxVertices];

int bfs(int **graph, int source, int target)
{
  memset(level, -1, sizeof(level)); level[source] = 0;
  deque<int> queue; queue.push_back(source);
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop_front();
    for (int i = 0; i < graph[u][maxVertices]; i ++)
    {
      int v = graph[u][i];
      if (level[v] < 0 && matrixGraph[u][v] > 0)
      {
        level[v] = level[u] + 1;
        queue.push_back(v);
      }
    }
  }
  return(level[target] > 0);
}

int dfs(int **graph, int u, int target, int flow)
{
  if (u == target) return(flow);
  int actualFlow = 0;
  for (int i = 0; i < graph[u][maxVertices]; i ++)
  {
    int v = graph[u][i];
    if (level[u] + 1 == level[v] && matrixGraph[u][v] > 0)
    {
      int pathFlow = dfs(graph, v, target, min(flow, matrixGraph[u][v]));
      flow -= pathFlow;
      matrixGraph[u][v] -= pathFlow;
      matrixGraph[v][u] += pathFlow;
      actualFlow += pathFlow;
    }
  }
  return(actualFlow);
}

int dinic(int **graph, int source, int target)
{
  int maxFlow = 0, pathFlow;
  while (bfs(graph, source, target))
    do
    {
      pathFlow = dfs(graph, source, target, inf);
      maxFlow += pathFlow;
    }
    while (pathFlow);
  return(maxFlow);
}

void addEdge(int **graph, int u, int v, int c)
{
  graph[u][graph[u][maxVertices]] = v; graph[u][maxVertices] ++;
  matrixGraph[u][v] = c;
  graph[v][graph[v][maxVertices]] = u; graph[v][maxVertices] ++;
  matrixGraph[v][u] = 0;
}

int main()
{
  matrixGraph = (int**) malloc(maxVertices * sizeof(int*));
  for (int i = 0; i < maxVertices; i ++)
    matrixGraph[i] = (int*) malloc(maxVertices * sizeof(int));

  int **graph = (int**) malloc(maxVertices * sizeof(int*));
  for (int i = 0; i < maxVertices; i ++)
    graph[i] = (int*) malloc((maxVertices + 1) * sizeof(int));

  int monkeys, canDrink, test = 1;
  while (scanf("%d %d", &monkeys, &canDrink) != EOF && !(monkeys == 0))
  {
    for (int i = 0; i < maxVertices; i ++)
    {
      graph[i][maxVertices] = 0;
      memset(matrixGraph[i], 0, sizeof(int) * maxVertices);
    }

    int toDrink = 0, monkey[monkeys][3];
    set<int> intervals;
    for (int i = 0; i < monkeys; i ++)
    {
      int v, a, b; scanf("%d %d %d", &v, &a, &b);
      intervals.insert(a); intervals.insert(b);
      monkey[i][0] = a; monkey[i][1] = b; monkey[i][2] = v;
      addEdge(graph, 0, i + 1, v);
      toDrink += v;
    }

    int intervalsSize = intervals.size(), intervalsArray[intervals.size()], at = 0;
    for (auto i: intervals) intervalsArray[at ++] = i;
    sort(intervalsArray, intervalsArray + intervalsSize);

    int groups[intervalsSize - 1][2];
    for (int i = 0; i < intervalsSize - 1; i ++)
    {
      groups[i][0] = intervalsArray[i];
      groups[i][1] = intervalsArray[i + 1];
      DEBUG printf("%d -> (%d, %d)\n", i, groups[i][0], groups[i][1]);
      addEdge(graph, i + 100 + 1, maxVertices - 1, (groups[i][1] - groups[i][0]) * canDrink);
    }

    for (int i = 0; i < monkeys; i ++)
      for (int j = 0; j < intervalsSize - 1 && monkey[i][1] > groups[j][0]; j ++)
        if (groups[j][0] >= monkey[i][0])
        {
          //printf("%d -> %d\n", i, j);
          addEdge(graph, i + 1, j + 100 + 1, (groups[j][1] - groups[j][0]));
        }

    int maxFlow = dinic(graph, 0, maxVertices - 1);

    printf("Case %d: %s\n", test ++, maxFlow == toDrink ? "Yes" : "No");
    memset(used, 0, sizeof(used));
    if (maxFlow == toDrink)
      for (int i = 0; i < monkeys; i ++)
      {
        int drink[maxVertices][2], at = 0, actual = 0;
        for (int j = 0; j < intervalsSize - 1; j ++)
        {
          printf("Monkey: %d (Had: %d) -> Group: %d (%d) (%d, %d)\n", i, monkey[i][2], j, matrixGraph[j + 100 + 1][i + 1], groups[j][0], groups[j][1]);
          if (matrixGraph[j + 100 + 1][i + 1])
          {
            actual += groups[j][1] - groups[j][0];
            if (actual < monkey[i][2])
            {
              if (at > 0 && groups[j][0] == drink[at - 1][1])
                drink[at - 1][1] = groups[j][1];
              else
              {
                drink[at][0] = groups[j][0];
                drink[at ++][1] = groups[j][1];
              }
            }
            else
            {
              if (at > 0 && groups[j][0] == drink[at - 1][1])
              drink[at - 1][1] = groups[j][1] - (actual - monkey[i][2]);
              else
              {
                drink[at][0] = groups[j][0];
                drink[at ++][1] = groups[j][1] - (actual - monkey[i][2]);
              }
            }
            if (used[j] == canDrink) printf("FCOK\n");
            used[j] ++;
          }
        }
        printf("%d", at);
        for (int j = 0; j < at; j ++)
          printf(" (%d,%d)", drink[j][0], drink[j][1]);
        printf("\n");
      }
  }

  return(0);
}
