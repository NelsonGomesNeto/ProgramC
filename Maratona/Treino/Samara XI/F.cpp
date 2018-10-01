#include <bits/stdc++.h>
using namespace std;
int n;

void dfs(vector<int> tree[], vector<int> needed[], int u, set<int>& now)
{
  now.insert(u);
  for (auto v: tree[u]) dfs(tree, needed, v, now);
}

int valid(vector<int> tree[], vector<int> needed[])
{
  for (int i = 0; i < n; i ++)
  {
    set<int> now;
    dfs(tree, needed, i, now);
    if (now.size() - 1 != needed[i].size()) return(0);
    for (auto j: needed[i]) if (j == i || !now.count(j)) return(0);
  }
  return(1);
}

int main()
{
  scanf("%d", &n);
  vector<int> c[n], cb[n]; int vi, cc;
  pair<int, int> sucessors[n], father[n];
  for (int i = 0; i < n; i ++)
  {
    scanf("%d", &vi); father[i].first = 1001;
    for (int j = 0; j < vi; j ++)
    {
      scanf("%d", &cc); cc --;
      c[i].push_back(cc);
      cb[cc].push_back(i);
    }
    sucessors[i] = {vi, i};
  }
  sort(sucessors, sucessors+n);

  vector<int> tree[n]; int root = -1;
  for (int i = 0; i < n; i ++)
  {
    for (int j = 0; j < cb[i].size(); j ++)
      if (father[i].first > c[cb[i][j]].size())
      {
        father[i].first = c[cb[i][j]].size();
        father[i].second = cb[i][j];
      }
    if (father[i].first != 1001) tree[father[i].second].push_back(i);
    else root = i;
  }

  if (root == -1 || !valid(tree, c)) printf("NO\n");
  else
  {
    printf("YES\n");
    for (int i = 0; i < n; i ++)
      if (father[i].first != 1001)
        printf("%d %d\n", father[i].second + 1, i + 1);
  }

  return(0);
}