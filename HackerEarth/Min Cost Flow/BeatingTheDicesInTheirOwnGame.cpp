#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int maxFaces = 100 * 100, maxQuery = 10, maxN = 100;
// source (0) -> dice (1-n) -> faces ((1+n)-((1+n)+n*maxFaces)) -> query ((1+((1+n)+n*maxFaces))-(1+((1+n)+n*maxFaces)+q*n)) -> target (1+((1+n)+n*maxFaces)+q*n+1)
const int maxVertices = (1 + maxN) + (1 + maxN*maxFaces) + (maxN*maxQuery) + 1 + 1;
lli matrixGraph[maxVertices][maxVertices][2], copyMatrix[maxVertices][maxVertices][2];
vector<int> graph[maxVertices];
unordered_map<lli, int> faceToInt;
unordered_map<int, lli> intToFace;
int n;

void copyResetGraph(int flag)
{
  for (int i = 0; i < maxVertices; i ++)
    for (int j = 0; j < maxVertices; j ++)
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

int main()
{
  scanf("%d", &n);
  int source = 0, target = maxVertices - 1, mi; lli u, c;
  for (int i = 0; i < n; i ++)
  {
    addEdge(source, 1 + i, 1, 0);
    scanf("%d", &mi);
    for (int j = 0; j < mi; j ++)
    {
      scanf("%lld %lld", &u, &c);
      intToFace[1 + maxN + (int) faceToInt.size()] = u;
      faceToInt[u] = 1 + maxN + faceToInt.size();
      addEdge(1 + i, faceToInt[u], 1, c);
    }
  }

  int q; scanf("%d", &q);
  while (q --)
  {
    lli can = 1, queryFaces[n];
    for (int i = 0; i < n; i ++)
    {
      scanf("%d", &queryFaces[i]);
      if (!faceToInt.count(queryFaces[i])) can = 0;
    }
    if (!can) printf("-1\n");
    else
    {
      copyResetGraph(1);

      for (int i = 0; i < n; i ++)
      {
        addEdge(faceToInt[queryFaces[i]], maxN * maxFaces + faceToInt[queryFaces[i]], 1, 0);
        addEdge(maxN * maxFaces + faceToInt[queryFaces[i]], 1, 0);
      }

      pair<lli, lli> ans = minCostFlow(source, target);
      printf("%lld\n", ans.first);

      copyResetGraph(0);
    }
  }
  return(0);
}
