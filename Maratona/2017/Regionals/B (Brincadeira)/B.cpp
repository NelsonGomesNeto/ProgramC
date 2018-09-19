#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define lli long long int
int n, t, a0, x, y, tap[31], inf = 1<<16;
vector<lli> sequence;

void generateSequence()
{
  lli now = a0;
  while (true)
  {
    int bit = now & 1;
    for (int i = 1; i < t; i ++) bit ^= (now >> tap[i]) & 1;
    now = (now >> 1) | (bit << (n - 1));
    if (now != sequence[0]) sequence.push_back(now);
    else break;
  }
  DEBUG for (int i = 0; i < sequence.size(); i ++)
    printf("%lld%c", sequence[i], i < sequence.size() - 1 ? ' ' : '\n');
}

pair<int, int> solve()
{
  int app[(int) 1e6 + 1]; memset(app, -1, sizeof(app));
  lli sum = 0; app[0] = 0;
  for (int i = 0; i <= 2e6; i ++)
  {
    lli value = sequence[i % sequence.size()];
    sum = (sum + value) % x;
    if (app[sum] != -1)
    {
      if (i - app[sum] + (i == 0) >= y) return(make_pair(app[sum], i));
    }
    else
      app[sum] = i + 1;
  }
  return(make_pair(-1, -1));
}

int main()
{
  scanf("%d %d %d %d %d", &n, &t, &a0, &x, &y);
  for (int i = 0; i < t; i ++) scanf("%d", &tap[i]);

  sequence.push_back(a0);
  generateSequence();
  pair<int, int> ans = solve();
  printf("%d %d\n", ans.first, ans.second);

  return(0);
}