#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
int inf = INT_MAX;
int rooms;
int canWin;

int canReachEnd(vector<pair<int, int> > graph[], int visited[], int start, int end)
{
  if (start == end) return(1);

  if (visited[start]) return(0);
  visited[start] = 1;

  for (auto u : graph[start])
    if (canReachEnd(graph, visited, u.first, end))
      return(1);

  return(0);
}

int bellmanFord(vector<pair<int, int> > graph[], int cost[], int start, int destiny)
{
  int i, u;
  cost[start] = 100;
  for (i = 0; i < rooms - 1; i ++)
    for (u = 1; u <= rooms; u ++)
      for (auto v : graph[u])
        if (cost[u] + v.second > cost[v.first] && cost[u] + v.second > 0 && cost[u] != inf)
          cost[v.first] = cost[u] + v.second;
  if (cost[destiny] >= 0 && cost[destiny] != inf)
    return(1);

  for (u = 1; u <= rooms; u ++)
    for (auto v : graph[u])
      if (cost[u] + v.second < cost[v.first] && cost[u] + v.second > 0 && cost[u] != inf)
      {
        int visited[rooms + 1]; memset(visited, 0, sizeof(visited));
        if (canReachEnd(graph, visited, v.first, destiny))
          return(1);
      }
  return(0);
}

int main()
{
  while (scanf("%d", &rooms) != EOF && rooms > 0)
  {
    vector<pair<int, int> > graph[rooms + 1];
    vector<int> preGraph[rooms + 1];
    int energy[rooms + 1], i, j;
    for (i = 1; i <= rooms; i ++)
    {
      int quantity; scanf("%d %d", &energy[i], &quantity);
      for (j = 0; j < quantity; j ++)
      {
        int u; scanf("%d", &u);
        preGraph[i].push_back(u);
      }
    }

    for (i = 1; i <= rooms; i ++)
      for (auto u : preGraph[i])
        graph[i].push_back({u, energy[u]});

    int cost[rooms + 1];
    for (i = 1; i <= rooms; i ++)
      cost[i] = inf;

    canWin = bellmanFord(graph, cost, 1, rooms);
    DEBUG
    {
      for (i = 1; i <= rooms; i ++)
        printf("%d ", cost[i]);
      printf("\n");
    }

    printf("%s\n", canWin ? "winnable" : "hopeless");

  }
  return(0);
}
