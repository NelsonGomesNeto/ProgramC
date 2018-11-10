#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct MinimumCostMaximumFlow {
	typedef int Index; typedef int Flow; typedef int Cost;
	static const Flow InfCapacity = INF; static const Cost InfCost = INF;
	struct Edge {
		Index to; Index rev;
		Flow capacity; Cost cost;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
		add(i, j, capacity, cost);
		add(j, i, capacity, cost);
	}
	pair<Cost,Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool useSPFA = false) {
		int n = g.size();
		vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
		pair<Cost,Flow> total = make_pair(0, 0);
		vector<Cost> potential(n);
		while(f > 0) {
			fill(dist.begin(), dist.end(), InfCost);
			if(useSPFA || total.second == 0) {
				deque<Index> q;
				q.push_back(s); dist[s] = 0; vector<bool> inqueue(n);
				while(!q.empty()) {
					Index i = q.front(); q.pop_front(); inqueue[i] = false;
					for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
						const Edge &e = g[i][ei]; Index j = e.to; Cost d = dist[i] + e.cost;
						if(e.capacity > 0 && d < dist[j]) {
							if(!inqueue[j]) {
								inqueue[j] = true;
								q.push_back(j);
							}
							dist[j] = d; prev[j] = i; prevEdge[j] = ei;
						}
					}
				}
			}else {
				vector<bool> vis(n);
				priority_queue<pair<Cost,Index> > q;
				q.push(make_pair(-0, s)); dist[s] = 0;
				while(!q.empty()) {
					Index i = q.top().second; q.pop();
					if(vis[i]) continue;
					vis[i] = true;
					for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
						const Edge &e = g[i][ei];
						if(e.capacity <= 0) continue;
						Index j = e.to; Cost d = dist[i] + e.cost + potential[i] - potential[j];
						if(dist[j] > d) {
							dist[j] = d; prev[j] = i; prevEdge[j] = ei;
							q.push(make_pair(-d, j));
						}
					}
				}
			}
			if(dist[t] == InfCost) break;
			if(!useSPFA) for(Index i = 0; i < n; i ++) potential[i] += dist[i];

			Flow d = f; Cost distt = 0;
			for(Index v = t; v != s; ) {
				Index u = prev[v]; const Edge &e = g[u][prevEdge[v]];
				d = min(d, e.capacity); distt += e.cost; v = u;
			}
			f -= d; total.first += d * distt; total.second += d;
			for(Index v = t; v != s; v = prev[v]) {
				Edge &e = g[prev[v]][prevEdge[v]];
				e.capacity -= d; g[e.to][e.rev].capacity += d;
			}
		}
		return total;
	}
};


int main() {
	int N;
	scanf("%d", &N);
	assert(1 <= N && N <= 100);
	vector<map<int,int> > costs(N);
	rep(i, N) {
		int M;
		scanf("%d", &M);
		assert(1 <= M && M <= 100);
		rep(j, M) {
			int u, c;
			scanf("%d%d", &u, &c);
			assert(1 <= u && u <= 1000000000);
			assert(1 <= c && c <= 1000000);
			assert(!costs[i].count(u));
			costs[i][u] = c;
		}
	}
	int Q;
	scanf("%d", &Q);
	assert(1 <= Q && Q <= 10);
	rep(ii, Q) {
		MinimumCostMaximumFlow mcf;
		int src = N + N, dst = src + 1;
		mcf.init(dst + 1);
		rep(i, N)
			mcf.add(src, i, 1);
		rep(j, N)
			mcf.add(N + j, dst, 1);
		rep(i, N) {
			int a;
			scanf("%d", &a);
			assert(1 <= a && a <= 1000000000);
			rep(j, N) if(costs[j].count(a))
				mcf.add(i, N + j, 1, costs[j][a]);
		}
		pair<int,int> res = mcf.minimumCostMaximumFlow(src, dst);
		if(res.second != N)
			puts("-1");
		else
			printf("%d\n", res.first);
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int maxFaces = 100 * 100, maxN = 100; lli inf = 1e16;
// source (0) -> dice (1-100) -> faces (101-100+100*100) -> target (101+100*100) MISSING ONE
const int maxVertices = 1 + maxN + maxFaces + 1;
map<int, map<int, lli> > matrixGraph[maxVertices];// cm[maxVertices][maxVertices][2];
map<int, lli> backUpFlow[maxVertices];
vector<int> graph[maxVertices];
int source = 0, target, vertices, previ[maxVertices], visited[maxVertices], potential[maxVertices]; bool inq[maxVertices];
lli cost[maxVertices]; bool activated[maxVertices];
int n;
map<lli, int> faceMap;

void copyG(int flag)
{
  for (int u = 0; u < vertices; u ++)
    for (auto v: graph[u])
      if (flag)
        backUpFlow[u][v] = matrixGraph[u][v][0];
      else
        matrixGraph[u][v][0] = backUpFlow[u][v];
}

int bellmannFord()
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  cost[source] = 0; int done;
  for (int i = 0; i < vertices - 1; i ++)
  {
    if (!activated) continue;
    done = 0;
    for (int u = 0; u < vertices; u ++)
    {
      if (!activated[u]) continue;
      for (auto v: graph[u])
        if (activated[v] && matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
        {
          cost[v] = cost[u] + matrixGraph[u][v][1];
          previ[v] = u;
          done = 1;
        }
    }
    if (!done) break;
  }
  return(cost[target] != inf);
}

int spfa()
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  memset(inq, false, sizeof(inq)); memset(visited, 0, sizeof(visited));
  cost[source] = 0;
  queue<int> queue; queue.push(source); inq[source] = true;
  while (!queue.empty())
  {
    int u = queue.front(); queue.pop();
    // if (u == target) break;
    if (visited[u] >= vertices) break;
    inq[u] = false;
    for (auto v: graph[u])
      if (activated[v] && matrixGraph[u][v][0] && cost[u] + matrixGraph[u][v][1] < cost[v])
      {
        cost[v] = cost[u] + matrixGraph[u][v][1];
        previ[v] = u;
        if (!inq[v])
        {
          visited[v] ++; queue.push(v);
          inq[v] = true;
        }
      }
  }
  return(cost[target] != inf);
}

int dijkstraWithPotentials()
{
  for (int i = 0; i < vertices; i ++) cost[i] = inf;
  memset(visited, 0, sizeof(visited));
  cost[source] = 0;
  priority_queue<pair<lli, int> > q;
  q.push({-0, source});
  while (!q.empty())
  {
    int u = q.top().second; q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (auto v: graph[u])
    {
      if (!activated[v] || !matrixGraph[u][v][0]) continue;
      int newCost = cost[u] + matrixGraph[u][v][1] + potential[u] - potential[v];
      if (newCost < cost[v])
      {
        cost[v] = newCost; previ[v] = u;
        q.push({-newCost, v});
      }
    }
  }
  for (int i = 0; i  < vertices; i ++) potential[i] += cost[i];
  return(cost[target] != inf);
}

pair<lli, lli> minCostFlow()
{
  memset(potential, 0, sizeof(potential));
  lli minCost = 0, maxFlow = 0;
  while (dijkstraWithPotentials())//(spfa()) (bellmannFord())
  {
    int v = target; lli flow = inf;
    while (v != source)
    {
      flow = min(flow, matrixGraph[previ[v]][v][0]);
      v = previ[v];
    }
    maxFlow += flow;

    v = target;
    while (v != source)
    {
      matrixGraph[previ[v]][v][0] -= flow;
      matrixGraph[v][previ[v]][0] += flow;
      minCost += matrixGraph[previ[v]][v][1] * flow;
      v = previ[v];
    }
  }
  pair<lli, lli> ans = {minCost, maxFlow};
  return(ans);
}

void addEdge(int u, int v, lli f, lli c)
{
  graph[u].push_back(v);
  matrixGraph[u][v][0] = f, matrixGraph[u][v][1] = c;
  graph[v].push_back(u);
  matrixGraph[v][u][0] = 0, matrixGraph[v][u][1] = -c;
}

void printGraph()
{
  for (int i = 0; i < vertices; i ++)
  {
    printf("%d", i);
    for (auto v: graph[i])
      printf(" -> (%d, %lld, %lld)", v, matrixGraph[i][v][0], matrixGraph[i][v][1]);
    printf("\n");
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i ++)
  {
    int die = 1 + i;
    addEdge(source, die, 1, 0);
    int m; scanf("%d", &m); lli u, c;
    for (int j = 0; j < m; j ++)
    {
      scanf("%lld %lld", &u, &c);
      int s = faceMap.size();
      if (!faceMap.count(u)) faceMap[u] = 1 + n + s;
      addEdge(die, faceMap[u], 1, c);
    }
  }
  target = 1 + n + faceMap.size(); vertices = target + 1;
  //int faceHasSink[vertices]; memset(faceHasSink, 0, sizeof(faceHasSink));
  for (auto i: faceMap) addEdge(i.second, target, 0, 0);
  // printGraph()
  copyG(1);
  memset(activated, true, sizeof(activated));

  int q, lel = 0; scanf("%d", &q); lli face[n];
  while (q --)
  {
    int can = 1;
    for (int i = 0; i < n; i ++)
    {
      scanf("%lld", &face[i]);
      if (!faceMap.count(face[i])) can = 0;
    }
    if (can)
    {
      if (lel) copyG(0);
      lel = 1;

      for (auto i: faceMap) activated[i.second] = false;
      for (int i = 0; i < n; i ++)
      {
        face[i] = faceMap[face[i]];
        matrixGraph[face[i]][target][0] ++;
        matrixGraph[target][face[i]][0] = 0;
        activated[face[i]] = true;
      }
      pair<lli, lli> ans = minCostFlow();
      //printf("%lld %lld\n", ans.first, ans.second);
      printf("%lld\n", ans.second == n ? ans.first : -1);

    }
    else printf("-1\n");
  }
  return(0);
}
*/
