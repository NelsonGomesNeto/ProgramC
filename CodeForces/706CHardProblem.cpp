#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli dp[(int) 1e5][4];

lli solve(lli cost[], string toSort[], int s)
{

}

int main()
{
  memset(dp, -1, sizeof(dp));
  int s; scanf("%d", &s);
  lli cost[s]; string toSort[s];
  for (int i = 0; i < s; i ++)
    scanf("%lld", &cost[i]);
  for (int i = 0; i < s; i ++)
  {
    getchar();
    cin >> toSort[i];
  }

  lli best = solve(cost, toSort, s);

  printf("%lld\n", best >= 1e9 ? -1 : best);

  return(0);
}