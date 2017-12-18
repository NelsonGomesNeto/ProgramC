#include <bits/stdc++.h>
using namespace std;

int n, m, inf = 1<<20;

int dijkstra(vector<pair<int, int> > graph[], int origin, int destination)
{
  int cost[n]; for (int i = 0; i < n; i ++) cost[i] = inf;
  cost[origin] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push({cost[origin], origin});
  while (!pq.empty())
  {
    int u = pq.top().second, c = pq.top().first; pq.pop();
    for (auto v: graph[u])
      if (v.second + c < cost[v.first])
      {
        cost[v.first] = v.second + c;
        pq.push({cost[v.first], v.first});
      }
  }
  return(cost[destination]);
}

int main()
{
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > graph[n]; int u, v, c;
  for (int i = 0; i < m; i ++)
  {
    scanf("%d %d %d", &u, &v, &c); u --; v --;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }

  int distance = dijkstra(graph, 0, n - 1);
  printf("%d\n", distance);

  return(0);
}