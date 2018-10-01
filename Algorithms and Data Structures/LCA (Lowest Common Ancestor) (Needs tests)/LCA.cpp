#include <bits/stdc++.h>
using namespace std;
vector<int> eulerianPath;
int uMap[(int) 1e6], revMap[(int) 1e6], now = 0;
int first[(int) 1e6];
const int maxN = 1e6, maxLog = floor(log2(1e6)) + 1;
int sparseTable[maxN][maxLog], logdp[maxN + 1];

void fillLogDP()
{
  logdp[1] = 0;
  for (int i = 2; i <= maxN; i ++) logdp[i] = logdp[i >> 1] + 1;
}

void build(int n, int logn)
{
  for (int i = 0; i < n; i ++) sparseTable[i][0] = eulerianPath[i];
  for (int j = 1; j <= logn; j ++)
    for (int i = 0, shift = (1 << (j - 1)); i + shift < n; i ++)
      sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + shift][j - 1]);
}

void printSpacing(int depth)
{
  for (int i = 0; i < depth; i ++) printf("   ");
}

void printTree(vector<int> tree[], int u, int prev, int depth)
{
  printSpacing(depth);
  printf("%d\n", u);
  for (auto v: tree[u])
    if (v != prev)
      printTree(tree, v, u, depth + 1);
}

void dfs(vector<int> tree[], int u, int prev)
{
  revMap[now] = u; uMap[u] = now ++;
  first[uMap[u]] = eulerianPath.size();
  eulerianPath.push_back(uMap[u]);
  for (auto v: tree[u])
    if (v != prev)
    {
      dfs(tree, v, u);
      eulerianPath.push_back(uMap[u]);
    }
}

int LCA(int u, int v)
{
  int ans = 1 << 20, lo = min(first[u], first[v]), hi = max(first[u], first[v]);
  int qs = logdp[hi - lo + 1];
  return(revMap[min(sparseTable[lo][qs], sparseTable[hi - (1 << qs) + 1][qs])]);
  for (int j = maxLog; j >= 0; j --)
    if (lo + (1 << j) - 1 <= hi)
    {
      ans = min(ans, sparseTable[lo][j]);
      lo += (1 << j);
    }
  return(revMap[ans]);
}

int LCANaive(int u, int v)
{
  int ans = 1 << 20, lo = min(first[u], first[v]), hi = max(first[u], first[v]);
  while (lo <= hi)
  {
    ans = min(ans, eulerianPath[lo]);
    lo ++;
  }
  return(revMap[ans]);
}

int main()
{
  int n; scanf("%d", &n);
  vector<int> tree[n]; int u, v;
  for (int i = 0; i < n - 1; i ++)
  {
    scanf("%d %d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(tree, 0, -1);
  build(eulerianPath.size(), floor(log2(eulerianPath.size()))); fillLogDP();
  printTree(tree, 0, -1, 0);

  for (int i = 0; i < eulerianPath.size(); i ++)
    printf("%d%c", eulerianPath[i], i < eulerianPath.size() - 1 ? ' ' : '\n');
  for (int i = 0; i < n; i ++)
    printf("(%d -> %d, %d)%c", i, uMap[i], first[uMap[i]], i < n - 1 ? ' ' : '\n');

  while (scanf("%d %d", &u, &v) != EOF)
  {
    printf("LCA(%d, %d) = %d | %s\n", u, v, LCA(uMap[u], uMap[v]), LCA(uMap[u], uMap[v]) == LCANaive(uMap[u], uMap[v]) ? "true" : "false");
  }

  return(0);
}
