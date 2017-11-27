#include <bits/stdc++.h>
using namespace std;

int graphM[100][100];
vector<set<int>> graph;
vector<int> level;

bool bfs(int f, int t) {
  level.clear();
  level.resize(graph.size(), -1);
  level[f] = 0;
  queue<int> q;
  q.push(f);

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : graph[v])
      if (level[u] < 0 && graphM[v][u]) {
        level[u] = level[v] + 1;
        q.push(u);
      }
  }

  return level[t] > 0;
}

int dfs(int f, int t, int flw) {
  if (f == t)
    return flw;
  int flow = 0;
  for (auto v : graph[f]) {
    if ((level[v] == 1 + level[f]) && (graphM[f][v])) {
      int fw = dfs(v, t, min(flw, graphM[f][v]));
      flw -= fw;
      graphM[f][v] -= fw;
      graphM[v][f] += fw;
      flow += fw;
    }
  }
  return flow;
}

int dinics(int f, int t) {
  int flow_max = 0;
  while (bfs(f, t)) {
    while (true) {
      int flow = dfs(f, t, 1 << 20);
      printf("Flow: %d\n", flow);
      flow_max += flow;
      if (!flow)
        break;
    }
  }
  return flow_max;
}

int main(int argc, char const *argv[]) {

  int V, E;
  cin >> V >> E;

  graph.resize(V);
  memset(graphM, 0, sizeof graphM);

  for (int i = 0; i < E; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].insert(v);
    graph[v].insert(u);
    graphM[u][v] = c;
  }

  printf("|%d|\n", dinics(0, 5));

  return 0;
}
