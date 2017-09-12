#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
int tiago[MAX];
int depth[MAX], pai[MAX], vstd[MAX], ar[MAX];
int fila[MAX];
bool mycomp(int &a, int &b) {
  return depth[a] > depth[b];
}
vector< pair<int, int> > adj[MAX];
void dfs(int cur, int dep = 0){
  vstd[cur] = 1;
  for(auto x : adj[cur]){
      if(!vstd[x.first]) {
          pai[x.first] = cur;
          ar[x.first] = x.second;
          depth[x.first] = dep+1;
          dfs(x.first, dep+1);
      }
  }
}
int main() {
  int n, k;
  int u, v, w;
  scanf("%d %d", &n, &k);
  for(int i = 0;  i < n; ++i)scanf("%d", tiago+i);
  for(int i = 0; i < n-1; ++i){
    scanf("%d %d %d", &u, &v, &w);
    adj[u-1].push_back({v-1, w});
    adj[v-1].push_back({u-1, w});
  }
  dfs(0);
  for(int i = 0; i < n; ++i)fila[i] = i+1;
  sort(fila, fila+n, mycomp);
  int ans = 0;
  for(int i = 0; i < n-1; ++i) {
      int custo = 2 * ar[fila[i]] * (tiago[fila[i]]/k + ((tiago[fila[i]]%k == 0) ? 0 : 1));
      ans+=custo;
      tiago[pai[fila[i]]]+=tiago[fila[i]];
  }
  printf("%d\n", ans);
  return 0;
}