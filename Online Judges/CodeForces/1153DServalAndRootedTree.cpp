#include <bits/stdc++.h>
using namespace std;

/* Explanation:
The core idea is to count how many leafs were wasted
*/

const int maxN = 3e5; int n, leafs;
vector<int> graph[maxN]; bool isMax[maxN];

int dfs(int u, int prv = -1)
{
  if (graph[u].size() == 1 && u) { leafs ++; return(1); }
  int sum = 0, maximum = 1e7;
  for (int v: graph[u])
    if (v != prv)
    {
      int received = dfs(v, u);
      sum += received, maximum = min(maximum, received);
    }
  if (isMax[u]) return(maximum);
  else return(sum);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0, a; i < n; i ++) { scanf("%d", &a); isMax[i] = a == 1; }
  for (int i = 1, p; i < n; i ++)
  {
    scanf("%d", &p); p --;
    graph[p].push_back(i), graph[i].push_back(p);
  }

  int ans = dfs(0);
  printf("%d\n", leafs - ans + 1);

  return(0);
}