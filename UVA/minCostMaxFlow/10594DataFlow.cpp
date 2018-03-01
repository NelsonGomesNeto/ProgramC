#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const lli maxVertices = 1000 + 2;
lli matrixGraph[maxVertices][maxVertices][2], inf = 1<<20, friends, capacity, vertices;

void printGraph(vector<lli> graph[])
{
  for (lli i = 0; i < vertices; i ++)
  {
    printf("%lld", i);
    for (auto j: graph[i])
      printf(" -> (%lld, %lld, %lld)", j, matrixGraph[i][j][0], matrixGraph[i][j][1]);
    printf("\n");
  }
}

lli dijkstra(vector<lli> graph[], lli source, lli target, lli parent[])
{
  lli cost[vertices];
  for (lli i = 0; i < vertices; i ++) cost[i] = inf;
  cost[source] = 0;
  priority_queue<pair<lli, lli>, vector<pair<lli, lli> >, greater<pair<lli, lli> > > pq;
  pq.push({cost[source], source});
  while (!pq.empty())
  {
    int c = pq.top().first, v = pq.top().second; pq.pop();
    for (auto u: graph[v])
    {
      if (c + matrixGraph[v][u][0] < cost[u] && matrixGraph[v][u][1] > 0)
      {
        cost[u] = c + matrixGraph[v][u][0];
        parent[u] = v;
        pq.push({cost[u], u});
      }
    }
  }
  return(cost[target] != inf);
}

lli bellmanFord(vector<lli> graph[], lli source, lli target, lli parent[], lli *minCost)
{
  lli cost[vertices];
  for (lli i = 0; i < vertices; i ++) cost[i] = inf;
  cost[source] = 0;

  for (lli i = 0; i < vertices - 1; i ++)
    for (lli u = 0; u < vertices; u ++)
      for (auto v: graph[u])
        if (cost[u] + matrixGraph[u][v][0] < cost[v] && matrixGraph[u][v][1] > 0)
        {
          cost[v] = cost[u] + matrixGraph[u][v][0];
          parent[v] = u;
        }

  // for (lli u = 0; u < vertices; u ++)
  //   for (auto v: graph[u])
  //     if (cost[u] + matrixGraph[u][v][0] < cost[v] && matrixGraph[u][v][1] > 0)
  //       return(0);

  //printf("cost: %lld\n", cost[target]);
  (*minCost) = cost[target];
  return(cost[target] != inf);
}

lli minMax(vector<lli> graph[], lli source, lli target)
{
  lli maxFlow = 0, cost = 0, parent[maxVertices]; memset(parent, -1, sizeof(parent));
  // printGraph(graph);
  lli minCost;
  while (bellmanFord(graph, source, target, parent, &minCost))
  {
    lli pathFlow = inf, v = target, u;
    // while (v != source)
    // {
    //   u = parent[v];
    //   pathFlow = min(pathFlow, matrixGraph[u][v][1]);
    //   v = parent[v];
    // }
    //printf("\npathFlow: %lld\n", pathFlow);
    pathFlow = capacity;
    v = target;
    while (v != source)
    {
      u = parent[v];
      matrixGraph[u][v][1] -= pathFlow;
      matrixGraph[v][u][1] += pathFlow;
      v = parent[v];
    }
    cost += minCost * min(pathFlow, friends - maxFlow);
    maxFlow += min(pathFlow, friends);
    if (maxFlow >= friends) break;
    //printf("maxFlow: %lld\n", maxFlow);
  }
  if (maxFlow < friends) cost = inf;
  return(cost);
}

void addEdge(vector<lli> graph[], lli u, lli v, lli dist, lli cap)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = dist;
  matrixGraph[u][v][1] = cap;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = -dist;
  matrixGraph[v][u][1] = 0;
}

int main()
{
  lli cities, flights, run = 1;
  while (scanf("%lld %lld", &cities, &flights) != EOF)
  {
    vertices = cities; memset(matrixGraph, 0, sizeof(matrixGraph));
    vector<lli> graph[maxVertices];
    lli u, v, c, input[flights][3];
    for (lli i = 0; i < flights; i ++)
    {
      scanf("%lld %lld %lld", &u, &v, &c); u --; v --;
      input[i][0] = u; input[i][1] = v; input[i][2] = c;
    }
    scanf("%lld %lld", &friends, &capacity);
    for (lli i = 0; i < flights; i ++)
      addEdge(graph, input[i][0], input[i][1], input[i][2], capacity);

    lli maxFlow = minMax(graph, 0, cities - 1);
    //if (run > 1) printf("\n");
    //printf("Instancia %lld\n", run ++);
    if (maxFlow == inf) printf("Impossible.\n");
    else printf("%lld\n", maxFlow);
  }


  return(0);
}