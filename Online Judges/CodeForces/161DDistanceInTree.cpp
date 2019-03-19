#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

const int maxN = 5e4, maxK = 5e2; int n, k;
vector<int> tree[maxN];

int memo[maxN][maxK + 1];
int dfs(int u, int prv, int depth)
{
  memo[u][depth] ++;
  if (depth < k)
    for (int v: tree[u])
      if (v != prv)
        dfs(v, u, depth + 1);
}

int main()
{
  scanf("%d %d", &n, &k);
  for (int i = 1, u, v; i < n; i ++)
  {
    scanf("%d %d", &u, &v); u --, v --;
    tree[u].push_back(v), tree[v].push_back(u);
  }

  for (int i = 0; i < n; i ++) dfs(i, -1, 0);

  int ans = 0;
  for (int i = 0; i < n; i ++)
  {
    DEBUG printf("%d %d\n", i + 1, memo[i][k]);
    ans += memo[i][k];
  }
  printf("%d\n", ans >> 1);
  return(0);
}