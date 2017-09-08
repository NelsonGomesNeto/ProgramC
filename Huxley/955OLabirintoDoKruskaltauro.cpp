#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define inf INT_MAX

void dijkstra(vector<vector<pair<int, int> > > graph, int cost[], int visited[], int start, int period)
{
  cost[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push({cost[start], start});
  while (!pq.empty())
  {
    int tempo = pq.top().first, v = pq.top().second; pq.pop();
    if (visited[v] == period) continue;
    visited[v] ++;
    for (auto u : graph[v])
    {
      if (u.second == 0 || tempo % u.second == 0)
      {
        if (tempo + 1 < cost[u.first])
          cost[u.first] = tempo + 1;
        pq.push({tempo + 1, u.first});
      }
      else
      {
        if (tempo + (u.second - tempo % u.second) + 1 < cost[u.first])
          cost[u.first] = tempo + (u.second - tempo % u.second) + 1;
        pq.push({tempo + (u.second - tempo % u.second) + 1, u.first});
      }
    }
  }
}

int main()
{
  int run = 0, tests; scanf("%d", &tests);
  while (run < tests)
  {
    int y, x; scanf("%d %d", &y, &x);

    vector<vector<pair<int, int> > > graph(y*x);
    int totalSize = y*x;
    for (int i = 0; i < totalSize; i ++)
    {
      char line[10];
      scanf("%s", line);
      for (int j = 0; line[j] != '\0'; j ++)
      {
        if (line[j] == 'N')
          graph[i].pb(mp(i - x, 0));
        else if (line[j] == 'E')
          graph[i].pb(mp(i + 1, 0));
        else if (line[j] == 'S')
          graph[i].pb(mp(i + x, 0));
        else // 'W'
          graph[i].pb(mp(i - 1, 0));
      }
    }

    int portals, period; scanf("%d %d", &portals, &period);
    for (int i = 0; i < portals; i ++)
    {
      int ui, uj, vi, vj; scanf("%d %d %d %d", &ui, &uj, &vi, &vj);
      graph[ui*x + uj].pb(mp(vi*x + vj, period));
    }

    int visited[totalSize], cost[totalSize];
    for (int i = 0; i < totalSize; i ++)
    {
      visited[i] = 0;
      cost[i] = inf;
    }

    dijkstra(graph, cost, visited, 0, period);

    printf("%d: %d\n", run, cost[totalSize - 1]);

    run ++;
  }
  return(0);
}