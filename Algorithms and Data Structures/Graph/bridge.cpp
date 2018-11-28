#include <bits/stdc++.h>
using namespace std;

/* Explanation:
in[u] stores the time in which u was visited
low[u] stores the highest node u can reach
if (low[child of u] > in[u]) bridge

If we can somehow reach any node above u, then there are two paths, so the edge isn't a bridge
*/

void printSpacing(int i) { while(i --) printf("   "); }
void printGraph(vector<int> g[], int u, int depth)
{
  printSpacing(depth); printf("%d\n", u + 1);
  for (int v: g[u]) printGraph(g, v, depth + 1);
}

const int maxV = 1e5; int n, m;
vector<int> graph[maxV], tree[maxV];
bool visited[maxV]; int low[maxV], in[maxV], t = 0;
vector<pair<int, int>> bridges;
void dfs(int u, int prev)
{
  visited[u] = true;
  in[u] = low[u] = ++ t;
  for (auto v: graph[u])
    if (!visited[v])
    {
      tree[u].push_back(v);
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > in[u]) bridges.push_back({u, v});
    }
    else if (v != prev) low[u] = min(low[u], in[v]);
}
void findBridges()
{
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; i ++)
    if (!visited[i])
      dfs(i, -1);
}

int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i ++)
  {
    int u, v; scanf("%d %d", &u, &v); u --, v --;
    graph[u].push_back(v); graph[v].push_back(u);
  }
  findBridges();

  for (int i = 0; i < bridges.size(); i ++)
    printf("(%d, %d)\n", bridges[i].first + 1, bridges[i].second + 1);
  printGraph(tree, 0, 0);
  return(0);
}
