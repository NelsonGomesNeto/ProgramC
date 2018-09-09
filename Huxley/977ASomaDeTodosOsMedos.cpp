#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
// sadness, fear
int dp[2000][2001], events[2000][2], n;
int path[2000][2001], each[2000];

int solve(int i, int limit)
{
  if (i == n) return(0);

  if (dp[i][limit] == -1)
  {
    int ans = solve(i + 1, limit) + events[i][0];
    if (limit - events[i][1] >= 0)
      ans = min(ans, solve(i + 1, limit - events[i][1]));
    dp[i][limit] = ans;
  }

  return(dp[i][limit]);
}

void printArray(int a[], int size)
{
  for (int i = 0; i < size; i ++) printf("%d%c", a[i], i < size - 1 ? ' ' : '\n');
}

int findMax(int a[], int start, int size, int prev)
{
  int ans = 1<<20;
  for (int i = start; i < size; i ++)
  {
    if (a[i] == prev) return(prev);
    if (a[i] > -1) ans = min(ans, a[i]);
  }
  if (ans == 1<<20) ans = -1;
  return(ans);
}

int chooseEvents(vector<int>& chosen, int limit)
{
  int fear = 0;
  for (int i = 0; i < n - 1; i ++)
    if (dp[i][limit] == dp[i + 1][limit] + events[i][0])
      chosen.push_back(n - i - 1);
    else
    {
      fear += events[i][1]; limit -= events[i][1];
    }

  DEBUG { printf("%d %d\n", limit, dp[n - 1][limit]); printArray(dp[n - 1], 101); }
  if (dp[n - 1][limit] != 0)
    chosen.push_back(0);
  else
  {
    fear += events[n - 1][1]; limit -= events[n - 1][1];
  }

  return(fear);
}

int main()
{
  memset(dp, -1, sizeof(dp));
  memset(path, -1, sizeof(path));
  memset(each, 0, sizeof(each));
  int limit; scanf("%d %d", &n, &limit);
  for (int i = n - 1; i >= 0; i --) scanf("%d %d", &events[i][0], &events[i][1]);

  int sadness = solve(0, limit);
  vector<int> chosenEvents;
  int fear = chooseEvents(chosenEvents, limit);
  printf("%d %d\n", sadness, fear);
  reverse(chosenEvents.begin(), chosenEvents.end());
  printArray(&chosenEvents[0], chosenEvents.size());

  return(0);
}