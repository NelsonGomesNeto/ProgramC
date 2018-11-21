#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6, maxLog = floor(log2(1e6)) + 1;
vector<int> tree[maxN];
int level[maxN], ancestor[maxN][maxLog];
int n, logn;

void printBinary(int num)
{
  if (!num) return;
  printBinary(num >> 1);
  printf("%d", num & 1);
}
void printMatrix()
{
  printf("   |"); for (int i = 0; i <= logn; i ++) printf("%3d%c", i, i < logn ? '|' : '\n');
  for (int i = 0; i < n; i ++)
  {
    printf("%3d|", i);
    for (int j = 0; j <= logn; j ++)
      printf("%3d%c", ancestor[i][j], j < logn ? '|' : '\n');
  }
}
void printSpacing(int s)
{
  while (s --) printf("   ");
}

void dfs(int u)
{
  printSpacing(level[u]); printf("%3d\n", u);
  for (int v: tree[u])
  {
    level[v] = level[u] + 1, ancestor[v][0] = u;
    dfs(v);
  }
}

void build()
{
  level[0] = ancestor[0][0] = 0; dfs(0);
  for (int i = 1; i <= logn; i ++)
    for (int u = 0; u < n; u ++)
      ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
}

int LCA(int u, int v)
{
  if (level[v] > level[u]) swap(u, v);

  printf("(%d - %d) = %d ", level[u], level[v], level[u] - level[v]); printBinary(level[u] - level[v]); printf("\n");
  for (int diff = level[u] - level[v], i = 0; diff; diff >>= 1, i ++)
    if (diff & 1) u = ancestor[u][i];

  if (u == v) return(u);

  for (int i = 0; ancestor[u][i] != ancestor[v][i]; i ++)
    u = ancestor[u][i], v = ancestor[v][i];

  return(ancestor[u][0]);
}

int main()
{
  scanf("%d", &n); logn = floor(log2(n)) + 1;
  int u, v;
  for (int i = 0; i < n - 1; i ++)
  {
    scanf("%d %d", &u, &v);
    tree[u].push_back(v);
  }
  build();
  printMatrix();

  while (scanf("%d %d", &u, &v) != EOF)
  {
    printf("LCA(%d, %d) = %d\n\n", u, v, LCA(u, v));
  }
  return(0);
}
