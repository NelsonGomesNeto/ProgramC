#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
int inf = INT_MAX - 10000;
int rooms;
int canWin;

int canReachEnd(vector<pair<int, int> > graph[], int visited[], int start, int end)
{
  if (start == end) return(1); // Reached the end

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
  cost[start] = 100; // Starts with 100 of energy
  for (i = 0; i < rooms - 1; i ++)
    for (u = 1; u <= rooms; u ++)
      for (auto v : graph[u])
        if (cost[u] + v.second > cost[v.first] && cost[u] + v.second > 0) // Remember, except the start, every place has -inf energy, so if it's bigger the 0: It's worth going there, and if I've found a better path then previous, I should update that too
          cost[v.first] = cost[u] + v.second;

  if (cost[destiny] > 0) // If I've reached the end with more then 0 energy
    return(1); // Win

  for (u = 1; u <= rooms; u ++)
    for (auto v : graph[u])
      if (cost[u] + v.second > cost[v.first] && cost[u] + v.second > 0) // If I've found a loop, let's try to reach the end from here, since I have a infinite energy source
      {
        int visited[rooms + 1]; memset(visited, 0, sizeof(visited));
        if (canReachEnd(graph, visited, u, destiny)) // Try to reach the end through the node I am (DFS)
          return(1); // Win
      }
  return(0); // Lose
}

int main()
{
  while (scanf("%d", &rooms) != EOF && rooms != -1)
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
      cost[i] = -inf; // Starts dead everywhere

    canWin = bellmanFord(graph, cost, 1, rooms); // Try to find a path
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
