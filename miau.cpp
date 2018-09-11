#include <bits/stdc++.h>
using namespace std;
int a, n, c;
const int MAX = 5010;
int DP[MAX][MAX];
char nxt[MAX];
int best[MAX];
int cm[MAX], ps[MAX], pv[MAX];
int dp(int y, int k){
	if(DP[y][k] != -1)return DP[y][k];
	int b, m;
	if(y == n){
		b = c+cm[0]-pv[k]-ps[1];
		m = cm[k] - ps[k+1];
		//printf("y = %d: m =  %d b = %d\n", y, m, b);
	}else{
		//printf("y = %d: m =  %d b = %d\n", y, cm[k], c+cm[0]-pv[k]);
		b = c+cm[0]-pv[k] + dp(y+1, 1);
		m = cm[k] + dp (y+1, k+1);
	}
	int bst = min(m, b);
	if(bst <= best[y]){
		best[y] = bst;
		if(best[y] == m)nxt[y] = 'M';
		else nxt[y] = 'B';
	}
	return DP[y][k] = bst;

}
int main(){
	cin >> a >> n >> c;
	memset(DP, -1, sizeof DP);
	memset(best, 123456, sizeof best);
	for(int i=0; i<=n+1; i++)cin >> cm[i];
	for(int i=1; i<=n+1; i++)cin >> pv[i];
	for(int i=1; i<=n+1; i++)cin >> ps[i];
	printf("%d\n", dp(1, a));
	int cost = 0, year = a;
	for(int i=1; i<=n; i++)
	{
	    printf("%c", nxt[i]);
	    if (nxt[i] == 'M') cost += cm[year], year ++;
	    else cost += -pv[year] + cm[0] + c, year = 1;
	} cost -= ps[year];
	printf("\n");
	printf("final cost: %d\n", cost);
}
