#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int maxFaces = 100 * 100, maxQuery = 10, maxN = 100, inf = 1<<20;
// source (0) -> dice (1-n) -> faces ((1+n)-((1+n)+n*maxFaces)) -> query ((1+((1+n)+n*maxFaces))-(1+((1+n)+n*maxFaces)+q*n)) -> target (1+((1+n)+n*maxFaces)+q*n+1)
const int maxVertices = (1 + maxN) + (1 + maxN*maxFaces) + (maxN*maxQuery) + 1 + 1;
unordered_map<lli, lli> matrixGraph[maxVertices][2], copyGraph[maxVertices][2];
int hasVertex[maxVertices];
vector<int> graph[maxVertices];
unordered_map<lli, int> faceToInt;
unordered_map<int, lli> intToFace;
int n, vertices;
int previ[maxVertices];
lli cost[maxVertices];
vector<int> allVertex;

void copyResetGraph(int flag)
{
  printf("Here\n");
  for (auto i: allVertex)
    for (auto j: allVertex)
      for (int k = 0; k < 2; k ++)
        if (flag) copyGraph[i][j][k] = matrixGraph[i][j][k];
        else matrixGraph[i][j][k] = copyGraph[i][j][k];
}

void addEdge(int u, int v, lli f, lli c)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = f, matrixGraph[u][v][1] = c;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = 0, matrixGraph[v][u][1] = -c;
}

int bellmannFord(int source, int target)
{
  for (int i = 0; i < maxVertices; i ++) cost[i] = 1e18;
  cost[source] = 0;
  for (int i = 0; i < maxVertices - 1; i ++)
  {
    int done = 0;
    for (int u = 0; u < maxVertices; u ++)
      for (auto v: graph[u])
        if (matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
        {
          cost[v] = cost[u] + matrixGraph[u][v][1];
          previ[v] = u;
        }
    if (!done) break;
  }
  return(cost[target] != 1e18);
}

pair<int, int> minCostFlow(int source, int target)
{
  lli minCost = 0, maxFlow = 0;
  while (bellmannFord(source, target))
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
  pair<int, int> ans = {minCost, maxFlow};
  return(ans);
}

int main()
{
  scanf("%d", &n);
  int source = 0, target = maxVertices - 1, mi; lli u, c;
  allVertex.push_back(source); allVertex.push_back(target);
  for (int i = 0; i < n; i ++)
  {
    addEdge(source, 1 + i, 1, 0);
    allVertex.push_back(i + 1);
    scanf("%d", &mi);
    for (int j = 0; j < mi; j ++)
    {
      scanf("%lld %lld", &u, &c);
      if (!faceToInt.count(u))
      {
        intToFace[1 + maxN + (int) faceToInt.size()] = u;
        faceToInt[u] = 1 + maxN + faceToInt.size();
      }
      addEdge(1 + i, faceToInt[u], 1, c);
      allVertex.push_back(faceToInt[u]);
      allVertex.push_back(maxN * maxFaces + faceToInt[u]);
    }
  }

  int q; scanf("%d", &q);
  while (q --)
  {
    lli can = 1, queryFaces[n];
    for (int i = 0; i < n; i ++)
    {
      scanf("%lld", &queryFaces[i]);
      if (!faceToInt.count(queryFaces[i])) can = 0;
    }
    if (!can) printf("-1\n");
    else
    {
      // copyResetGraph(1);

      for (int i = 0; i < n; i ++)
        addEdge(faceToInt[queryFaces[i]], target, 1, 0);
        // addEdge(maxN * maxFaces + faceToInt[queryFaces[i]], target, 1, 0);

      pair<lli, lli> ans = minCostFlow(source, target);
      if (ans.second) printf("%lld\n", ans.first);
      else printf("-1\n");

      for (int i = 0; i < n; i ++)
      {
        matrixGraph[faceToInt[queryFaces[i]]][target][0] = 0;
        matrixGraph[target][faceToInt[queryFaces[i]]][0] = 0;
      }
      // copyResetGraph(0);
    }
  }
  return(0);
}
