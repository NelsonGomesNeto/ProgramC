#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;

int ans;

int min(int a, int b)
{
  return(a > b ? b : a);
}

int max(int a, int b)
{
  return(a > b ? a : b);
}

int bt(int **dp, vector<pair<int, int> > b, int weight, int i, int atual)
{
  if (weight < 0) return(-1);
  if (i < 0)
  {
    if (atual > ans)
      ans = atual;
    return(0);
  }
  int j, total = 0, aux = 0;
  for (j = i; j >= 0; j --)
  {
    if (dp[i][j] == -1)
    {
      if (atual == 0)
        aux = bt(dp, b, b[j].first - 2 * b[j].second, j - 1, atual + 1) + 1;
      else
        aux = bt(dp, b, min(weight - b[j].second, b[j].first - 2 * b[j].second), j - 1, atual + 1) + 1;
      dp[i][j] = max(bt(dp, b, weight, j - 1, atual), aux);
    }
    total = max(dp[i][j], total);
  }
    //printf("Efficient\n");

  //printf("%d %d\n", i, total);
  return(total);
}

int main()
{
  int boxes; scanf("%d", &boxes);
  int **dp = (int**) malloc(1001 * sizeof(int*));
  int i, j, p, r;
  for (i = 0; i <= 1000; i ++)
    dp[i] = (int*) malloc(1001 * sizeof(int));

  while (scanf("%d", &boxes) != EOF)
  {
    vector<pair<int, int> > box;
    //memset(dp, -1, sizeof(1001 * 1001 * sizeof(int)));
    for (i = 0; i <= 1000; i ++)
      for (j = 0; j <= 1000; j ++)
        dp[i][j] = -1;
    //printf("done\n");
    int real = 0;
    for (i = 0; i < boxes; i ++)
    {
      cin >> p >> r;
      if (r - p >= 0)
      {
        box.pb(mp(r + p, p));
        real ++;
      }
    }
    sort(box.begin(), box.end());
    //for (i = 0; i < boxes; i ++)
      //printf("%d %d\n", box[i].first, box[i].second);

    ans = bt(dp, box, 0, real - 1, 0);
    printf("%d\n", ans);
  }
  return(0);
}
