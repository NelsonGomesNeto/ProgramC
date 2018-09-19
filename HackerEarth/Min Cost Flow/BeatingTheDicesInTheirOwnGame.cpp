#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int maxFaces = 100 * 100, maxN = 100; lli inf = 1e16;
// source (0) -> dice (1-100) -> faces (101-100+100*100) -> target (101+100*100) MISSING ONE
const int maxVertices = 1 + maxN + maxFaces + 1;
lli matrixGraph[maxVertices][maxVertices][2];
unordered_map<int, unordered_map<int, lli> > cm[maxVertices];
vector<int> graph[maxVertices];
int source = 0, target, vertices, previ[maxVertices], visited[1], potential[1]; lli cost[maxVertices]; bool inq[1];
int n;
unordered_map<lli, int> faceMap;

void copyG(int flag)
{
  for (int u = 0; u < vertices; u ++)
    for (auto v: graph[u])
      if (flag)
        cm[u][v][0] = matrixGraph[u][v][0], cm[u][v][1] = matrixGraph[u][v][1];
      else
        matrixGraph[u][v][0] = cm[u][v][0], matrixGraph[u][v][1] = cm[u][v][1];
}

int bellmannFord()
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  cost[source] = 0; int done;
  for (int i = 0; i < vertices - 1; i ++)
  {
    done = 0;
    for (int u = 0; u < vertices; u ++)
      for (auto v: graph[u])
        if (matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
        {
          cost[v] = cost[u] + matrixGraph[u][v][1];
          previ[v] = u;
          done = 1;
        }
    if (!done) break;
  }
  return(cost[target] != inf);
}

int spfa()
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  memset(inq, false, sizeof(inq)); memset(visited, 0, sizeof(visited));
  cost[source] = 0;
  queue<int> queue; queue.push(source); inq[source] = true;
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop();
    // if (u == target) break;
    if (visited[u] >= vertices) break;
    inq[u] = false;
    for (auto v: graph[u])
      if (matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
      {
        cost[v] = cost[u] + matrixGraph[u][v][1];
        previ[v] = u;
        if (!inq[v])
        {
          visited[v] ++; queue.push(v);
          inq[v] = true;
        }
      }
  }
  return(cost[target] != inf);
}

int dijsktraWithPotentials()
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  memset(visited, 0, sizeof(visited));
  cost[source] = 0;
  priority_queue<pair<lli, int> > q;
  q.push({-0, source});
  while (!q.empty())
  {
    int u = q.top().second; q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (auto v: graph[u])
    {
      if (!matrixGraph[u][v][0]) continue;
      int newCost = cost[u] + matrixGraph[u][v][1] + potential[u] - potential[v];
      if (newCost < cost[v])
      {
        cost[v] = newCost; previ[v] = u;
        q.push({-newCost, v});
      }
    }
  }
  for (int i = 0; i  < vertices; i ++) potential[i] += cost[i];
  return(cost[target] != inf);
}

pair<lli, lli> minCostFlow()
{
  //memset(potential, 0, sizeof(potential));
  lli minCost = 0, maxFlow = 0;
  while (spfa()) //(dijsktraWithPotentials()) //(bellmannFord())
  {
    int v = target; lli flow = inf;
    while (v != source)
    {
      flow = min(flow, matrixGraph[previ[v]][v][0]);
      v = previ[v];
    }
    maxFlow += flow;

    v = target;
    while (v != source)
    {
      matrixGraph[previ[v]][v][0] -= flow;
      matrixGraph[v][previ[v]][0] += flow;
      minCost += matrixGraph[previ[v]][v][1] * flow;
      v = previ[v];
    }
  }
  pair<lli, lli> ans = {minCost, maxFlow};
  return(ans);
}

void addEdge(int u, int v, lli f, lli c)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = f, matrixGraph[u][v][1] = c;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = 0, matrixGraph[v][u][1] = -c;
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void printGraph()
{
  for (int i = 0; i < vertices; i ++)
  {
    printf("%d", i);
    for (auto v: graph[i])
      printf(" -> (%d, %lld, %lld)", v, matrixGraph[i][v][0], matrixGraph[i][v][1]);
    printf("\n");
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i ++)
  {
    int die = 1 + i;
    addEdge(source, die, 1, 0);
    int m; scanf("%d", &m); lli u, c;
    for (int j = 0; j < m; j ++)
    {
      scanf("%lld %lld", &u, &c);
      int s = faceMap.size();
      if (!faceMap.count(u)) faceMap[u] = 1 + n + s;
      addEdge(die, faceMap[u], 1, c);
    }
  }
  target = 1 + n + faceMap.size(); vertices = target + 1;
  int faceHasSink[vertices]; memset(faceHasSink, 0, sizeof(faceHasSink));
  // printGraph()
  copyG(1);

  int q; scanf("%d", &q);
  while (q --)
  {
    lli face[n]; int can = 1;
    for (int i = 0; i < n; i ++)
    {
      scanf("%lld", &face[i]);
      if (!faceMap.count(face[i])) can = 0;
    }
    if (can)
    {
      //swap(&source, &target); minCostFlow(); swap(&source, &target);
      for (auto i: faceMap) matrixGraph[i.second][target][0] = matrixGraph[target][i.second][0] = 0;
      for (int i = 0; i < n; i ++)
      {
        face[i] = faceMap[face[i]];
        if (!faceHasSink[face[i]]) addEdge(face[i], target, 0, 0), faceHasSink[face[i]] = 1;
        matrixGraph[face[i]][target][0] ++;
        matrixGraph[target][face[i]][0] = 0;
      }
      pair<lli, lli> ans = minCostFlow();
      // printf("%lld %lld\n", ans.first, ans.second);
      printf("%lld\n", ans.second == n ? ans.first : -1);
      copyG(0);
      //return(0);
    }
    else printf("-1\n");
  }
  return(0);
}
