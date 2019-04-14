#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

const int maxN = 3e5; int n;
bool isMax[maxN]; int minToLeaf[maxN], parentSons[maxN], value[maxN];vector<int> tree[maxN];

struct Leaf
{
  int id, m, p;
  bool operator<(const Leaf &a) const { return(m < a.m || (m == a.m && p < a.p)); }
};
vector<Leaf> leafs;

void printTree(int u, int depth = 0)
{
  printf("%*d | %s | %d | %d\n", depth * 5, u, isMax[u] ? "max" : "min", minToLeaf[u], parentSons[u]);
  for (int v: tree[u]) printTree(v, depth + 1);
}

void dfs(int u, int m = 0, int p = 0)
{
  minToLeaf[u] = m, parentSons[u] = p;
  for (int v: tree[u]) dfs(v, m + isMax[u] ? 1 : -1, p + !isMax[u]*tree[u].size());
  if (tree[u].size() == 0) leafs.push_back({u, m, p});
}

int eval(int u)
{
  if (tree[u].size() == 0) return(value[u]);
  int ans = isMax[u] ? -1e6 : 1e6;
  for (int v: tree[u]) ans = isMax[u] ? max(ans, eval(v)) : min(ans, eval(v));
  return(ans);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0, lol; i < n; i ++) { scanf("%d", &lol); isMax[i] = lol != 0; }

  for (int i = 1, s; i < n; i ++)
  {
    scanf("%d", &s);
    tree[s - 1].push_back(i);
  }

  dfs(0);
  DEBUG printTree(0);
  sort(leafs.begin(), leafs.end()); reverse(leafs.begin(), leafs.end());
  int v = 1; for (Leaf &l: leafs) value[l.id] = v ++;

  printf("%d\n", eval(0));

  return(0);
}