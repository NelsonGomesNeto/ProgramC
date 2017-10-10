#include <bits/stdc++.h>
using namespace std;
int inf = INT_MAX;
int buildCost, airports;

int prim(vector<pair<int, int> > graph[], int cost[], int visited[], int start)
{
  int v, c, total = 0;
  cost[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push({cost[start], start});
  while (!pq.empty())
  {
    v = pq.top().second; c = pq.top().first; pq.pop();
    if (visited[v]) continue;
    visited[v] = 1;

    if (c == buildCost) airports ++;

    total += c;
    for (auto u : graph[v])
    {
      cost[u.first] = u.second;
      pq.push({cost[u.first], u.first});
    }
  }
  return(total);
}

int main()
{
  int tests, run = 1; scanf("%d", &tests);
  while (run <= tests)
  {
    int locations, roads; scanf("%d %d %d", &locations, &roads, &buildCost);
    vector<pair<int, int> > graph[locations + 1]; int i;
    int u, v, c;
    for (i = 0; i < roads; i ++)
    {
      scanf("%d %d %d", &u, &v, &c);
      if (c > buildCost)
        c = buildCost;
      graph[u].push_back({v, c});
      graph[v].push_back({u, c});
    }

    int minCost = 0;
    int visited[locations + 1], cost[locations + 1];
    memset(visited, 0, sizeof(visited));
    for (i = 0; i <= locations; i ++) cost[i] = inf;

    airports = 0;
    for (i = 1; i <= locations; i ++)
    {
      if (!visited[i])
      {
        airports ++;
        minCost += prim(graph, cost, visited, i) + buildCost;
      }
    }

    printf("Case #%d: %d %d\n", run, minCost, airports);

    run ++;
  }
  return(0);
}