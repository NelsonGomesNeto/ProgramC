#include <bits/stdc++.h>
using namespace std;
#define lli long long int
// source (0) -> dice (1-n) -> faces ((1+n)-(1+n)+n*m) -> query ((1+n)-2*n) -> target (1 + 2*n)
const int maxVertices = 1 + 2 * 100 + 1;
lli matrixGraph[maxVertices][maxVertices][2];
vector<int> graph[maxVertices];
int n;

void addEdge(int u, int v, int f, int c)
{

}

int main()
{
  scanf("%d", &n);
  int source = 0, target = 1 + 2 * n + 1 - 1, mi, f, c;
  for (int i = 0; i < n; i ++)
  {
    addEdge(source, 1 + i, 1, 0);
    scanf("%d", &mi);
    for (int j = 0; j < mi; j ++)
    {
      scanf("%d %d", &f, &c);
      addEdge(1 + i, )
    }
  }

  int q; scanf("%d", &q);
  while (q --)
  {
    for (int i = 0; i < n; i ++)
  }
  return(0);
}