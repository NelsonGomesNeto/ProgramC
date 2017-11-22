#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli inf = 1e16;
int cities, routes, friends, freeSeats;
int matrixGraph[101][101][2];

int dijkstra(vector<pair<int, int> > graph[], int source, int target, int parent[])
{
  int visited[cities]; memset(visited, 0, sizeof(visited));
  int cost[cities];
  for (int i = 0; i < cities; i ++) cost[i] = inf;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push({source, 0});
  parent[source] = -1;
  while (!pq.empty())
  {
    int u = pq.top().first, c = pq.top().second; pq.pop();
    for (auto v: graph[u])
      if (!visited[v.first] && matrixGraph[u][v.first][1] > 0 && matrixGraph[u][v.first][0] + c < cost[u])
      {
        cost[u] = matrixGraph[u][v.first][0] + c;
        pq.push({v.first, matrixGraph[u][v.first][0] + c});
        //queue.push_back(v.first);
        parent[v.first] = u;
        visited[v.first] = 1;
      }
  }
  return(visited[target]);
}

lli fordFulkerson(vector<pair<int, int> > graph[], int source, int target)
{
  lli maxFlow = 0, cost = 0;
  int parent[cities]; memset(parent, 0, sizeof(parent));
  while (dijkstra(graph, source, target, parent))
  {
    lli pathFlow = inf;
    int v = target, u;
    while (v != source)
    {
      printf("%d %d\n", v, parent[v]);
      u = parent[v];
      pathFlow = pathFlow < matrixGraph[u][v][1] ? pathFlow : matrixGraph[u][v][1];
      v = parent[v];
    }
    v = target;
    while (v != source)
    {
      u = parent[v];
      matrixGraph[u][v][1] = 0;
      matrixGraph[v][u][1] += pathFlow;
      cost += matrixGraph[u][v][0];
      v = parent[v];
    }
    maxFlow += pathFlow;
    if (maxFlow >= friends) return(cost);
  }

  return(inf);
}

int main()
{
  int run = 1;
  while (scanf("%d %d", &cities, &routes) != EOF)
  {
    memset(matrixGraph, 0, sizeof(matrixGraph));
    vector<pair<int, int> > graph[cities];
    int u, v, c;
    for (int i = 0; i < routes; i ++)
    {
      scanf("%d %d %d", &u, &v, &c); u --; v --;
      graph[u].push_back({v, c});
      graph[v].push_back({u, c});
      matrixGraph[u][v][0] = c; matrixGraph[v][u][0] = c;
    }
    scanf("%d %d", &friends, &freeSeats);

    for (int i = 0; i < cities; i ++)
    {
      for (auto j: graph[i])
      {
        matrixGraph[i][j.first][1] = freeSeats;
        matrixGraph[j.first][i][1] = freeSeats;
      }
    }


    lli ans = fordFulkerson(graph, 0, cities - 1);

    printf("Instancia %d\n", run ++);
    if (ans != inf)
      printf("%lld\n", ans * friends);
    else
      printf("impossivel\n");
  }


  return(0);
}