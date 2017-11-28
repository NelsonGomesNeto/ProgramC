#include <bits/stdc++.h>
using namespace std;
const int maxVertices = 2 + 100 + 50000;
map<int, int> matrixGraph[maxVertices]; int level[maxVertices], inf = 1<<20;

int bfs(vector<int> graph[], int source, int target)
{
  memset(level, -1, sizeof(level)); level[source] = 0;
  deque<int> queue; queue.push_back(source);
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop_front();
    for (auto v: graph[u])
      if (level[v] < 0 && matrixGraph[u][v] > 0)
      {
        level[v] = level[u] + 1;
        queue.push_back(v);
      }
  }
  return(level[target] > 0);
}

int dfs(vector<int> graph[], int u, int target, int flow)
{
  if (u == target) return(flow);
  int actualFlow = 0;
  for (auto v: graph[u])
    if (level[u] + 1 == level[v] && matrixGraph[u][v] > 0)
    {
      int pathFlow = dfs(graph, v, target, min(flow, matrixGraph[u][v]));
      flow -= pathFlow;
      matrixGraph[u][v] -= pathFlow;
      matrixGraph[v][u] -= pathFlow;
      actualFlow += pathFlow;
    }
  return(actualFlow);
}

int dinic(vector<int> graph[], int source, int target)
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

void addEdge(vector<int> graph[], int u, int v, int c)
{
  graph[u].push_back(v);
  matrixGraph[u][v] = c;
  graph[v].push_back(u);
}

int main()
{
  int monkeys, canDrink;
  while (scanf("%d %d", &monkeys, &canDrink) != EOF && !(monkeys == 0))
  {
    for (int i = 0; i < maxVertices; i ++) matrixGraph[i].clear();
    vector<int> graph[maxVertices];

    for (int i = 100; i < 25100; i ++)
    {
      addEdge(graph, i, i + 25000, canDrink);
      //addEdge(graph, i + 1, i + 25000, canDrink);
      addEdge(graph, i + 25000, 50101, canDrink);
    }

    int toDrink = 0;
    for (int i = 0; i < monkeys; i ++)
    {
      int v, a, b; scanf("%d %d %d", &v, &a, &b);
      toDrink += v;
      addEdge(graph, 0, i + 1, v);
      for (int j = a; j < b; j ++)
      {
        addEdge(graph, i + 1, j + 100, 1);
        addEdge()
      }
    }


    int maxFlow = dinic(graph, 0, 50101);

    for (int i = 0; i < monkeys; i ++)
    {
      printf("%d", i + 1);
      for (auto j: graph[i + 1])
        if (matrixGraph[j][i + 1])
          printf(" -> %d", j);
      printf("\n");
    }

    printf("%d maxFlow: %d\n", maxFlow == toDrink, maxFlow);
  }

  return(0);
}