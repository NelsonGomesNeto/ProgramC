#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1001
#define MIN -2000000
#define INF 9000000000000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int vec[101][101];
int n,m;
int pd[3];
int ansTot= -1;

int main(){
  ss(n,m);
    for(int i=0;i<m;i++){
      int a,b,c;
        cin >> a >> b >> c;
          vec[a][b] = vec[b][a] = c;
    }
    pd[1] = 1, pd[2] = 2, pd[3] = 3;

    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        for(int k=j+1;k<=n;k++){
          int aux = vec[i][j] + vec[i][k] + vec[j][k];
          if(aux >= ansTot){
            ansTot = aux;
            pd[1] = i, pd[2] = j, pd[3] = k;
          }
        }
      }
    }

    cout << pd[1] << " " << pd[2] << " " << pd[3] << endl;

  return 0;
}