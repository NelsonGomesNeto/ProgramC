#include <bits/stdc++.h>
using namespace std;

const int maxVertices = 100;
bool toPrint[maxVertices][maxVertices];
vector<pair<int, int>> graph[maxVertices];
vector<pair<int, int>> edges;
map<string, int> cityToNumber;
string numberToCity[maxVertices];

bool visited[maxVertices];
int used[maxVertices][maxVertices];
void dfs(int u, int prev)
{
  for (auto &v: graph[u])
    if (!v.second)
    {
      v.second ++, used[v.first][u] ++;
      dfs(v.first, u);
    }
}

int main()
{
  int n, m, r = 0;
  while (scanf("%d %d", &n, &m) && !(!n && !m))
  {
    if (r ++) printf("\n");
    cityToNumber.clear(), edges.clear();
    for (int i = 0; i < n; i ++)
    {
      graph[i].clear();
      string city; cin >> city;
      cityToNumber[city] = i, numberToCity[i] = city;
    }

    for (int i = 0; i < m; i ++)
    {
      string u, v; cin >> u >> v;
      // graph[cityToNumber[u]].push_back(cityToNumber[v]);
      // printf("%d %d\n", cityToNumber[v], cityToNumber[u]);
      graph[cityToNumber[v]].push_back({cityToNumber[u], 0}); // reverse edge
      edges.push_back({cityToNumber[u], cityToNumber[v]});
    }

    memset(used, 0, sizeof(used));
    dfs(0, -1);

    memset(toPrint, false, sizeof(toPrint));
    for (int i = 0; i < n; i ++)
    {
      int sum = 0;
      for (auto j: graph[i])
        if (used[i][j.first])
        {
          toPrint[i][j.first] = true;
          sum ++;
        }
      if (sum != 1)
        for (auto j: graph[i])
          toPrint[i][j.first] = false;
    }

    for (auto edge: edges) if (toPrint[edge.first][edge.second]) cout << numberToCity[edge.first] << " " << numberToCity[edge.second] << endl;
  }
  return(0);
}