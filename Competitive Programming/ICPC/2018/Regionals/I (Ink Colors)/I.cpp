#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
vector<int> tree[maxN];
int dfs(int u, bool *couldBuild, int level)
{
  // Doesn't try
  int ans = 0;
  for (int v: tree[u])
    ans += dfs(v, couldBuild, -1);

  // Tries to build a stick man
  int ansTry = 0;
  bool c = true;
  for (int v: tree[u])
  {
    ansTry += dfs(v, &c, level + 1);
    // if ()
  }
}

int main()
{
  int n; scanf("%d", &n);
  for (int i = 1, j; i < n; i ++)
  {
    scanf("%d", &j); j --;
    tree[j].push_back(i);
  }
  bool c = false;
  int ans = dfs(0, &c, -1);
  return(0);
}