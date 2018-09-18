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