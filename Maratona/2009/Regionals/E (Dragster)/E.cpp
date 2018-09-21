#include <bits/stdc++.h>
using namespace std;
double prob[301][301];
int n, tree[602][2];
vector<pair<int, double > > race[602];

void go(int u, vector<pair<int, double > >& r)
{
  if (tree[u][0] <= n && tree[u][1] <= 1)
  {
    r.push_back({tree[u][0], prob[tree[u][0]][tree[u][1]]});
    r.push_back({tree[u][1], prob[tree[u][1]][tree[u][0]]});
    return;
  }
  if (tree[u][0] > n)
  go(tree[u][0], r);
  go(tree[u][1], r);
}

int main()
{
  while (scanf("%d", &n) != EOF && n)
  {
    for (int i = 0; i < 602; i ++) race[i][0].clear(), race[i][1].clear();
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j ++)
        scanf("%lf", &prob[i + 1][j + 1]);

    for (int i = 0; i < n - 1; i ++)
      scanf("%d %d", &tree[n + i + 1][0], &tree[n + i + 1][1]);

    for (int i = n + 1; i < 2 * n; i ++)
    {
      go(i, race[i]);
    }
  }
  return(0);
}
/*

  if (tree[i][0] > n) go(tree[i][0], race[i][0]);
  else race[i][0].push_back({tree[i][0], 1});
  if (tree[i][1] > n) go(tree[i][1], race[i][1]);
  else race[i][1].push_back({tree[i][1], 1});
}

for (int i = n + 1; i < 2 * n; i ++)
{
  printf("%d |", i);
  for (int j = 0; j < race[i][0].size(); j ++)
    printf(" %d", race[i][0][j]);
  printf(" |");
  for (int j = 0; j < race[i][1].size(); j ++)
    printf(" %d", race[i][1][j]);
  printf("\n");
}
printf("\n");
*/