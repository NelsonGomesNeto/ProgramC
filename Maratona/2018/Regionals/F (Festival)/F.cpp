#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > events[10];
int n, inf = 1<<20;
map<set<pair<int, int> >, int> dp[10];

int canGo(set<pair<int, int> > coming, vector<int> event)
{
  for (auto c: coming)
    if (event[0] >= c.second)
      return(1);
    else if (event[1] >= c.first)
      return(0);
  return(1);
}

int solve(int i, int j, set<pair<int, int> > coming, int one)
{
  // printf("%d\n", i);
  if (i == n) return(0);
  if (j == events[i].size()) return(one ? solve(i + 1, 0, coming, 0) : -inf);

  set<pair<int, int> > aux = coming;
  if (!dp[i].count(aux))
  {
    int ans = solve(i, j + 1, coming, one);
    if (canGo(coming, events[i][j]))
    {
      coming.insert({events[i][j][0], events[i][j][1]});
      ans = max(ans, events[i][j][2] + solve(i, j + 1, coming, 1));
    }
    dp[i][aux] = ans;
  }

  return(dp[i][aux]);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i ++)
  {
    int t, s, e, m; scanf("%d", &t);
    for (int j = 0; j < t; j ++)
    {
      scanf("%d %d %d", &s, &e, &m);
      events[i].push_back({s, e, m});
    }
    sort(events[i].begin(), events[i].end());
  }

  set<pair<int, int> > coming;
  int ans = solve(0, 0, coming, 0);
  printf("%d\n", ans < 0 ? -1 : ans);

  return(0);
}
/*
for (int i = 0; i < n; i ++)
{
  printf("%d:", i);
  for (int j = 0; j < events[i].size(); j ++)
    printf(" (%d, %d %d)", events[i][j][0], events[i][j][1], events[i][j][2]);
  printf("\n");
}
*/