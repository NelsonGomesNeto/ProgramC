#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define lli long long int
<<<<<<< HEAD
int n, t, tap[31];
lli now, previ, a0, x, y;

lli next()
{
  previ = now;
  int bit = now & 1;
  for (int i = 1; i < t; i ++) bit ^= (now >> tap[i]) & 1;
  now = (now >> 1) | (bit << (n - 1));
  return(previ);
}

pair<int, int> solve()
{
  int firstApp[x]; memset(firstApp, -1, sizeof(firstApp));
  lli sum = 0; firstApp[0] = 0;
  for (int i = 0; ; i ++)
  {
    lli value = next();
    sum = (sum + value) % x;
    if (firstApp[sum] != -1)
    {
      if (i - firstApp[sum] + 1 >= y) return(make_pair(firstApp[sum], i));
    }
    else
      firstApp[sum] = i + 1;
  }
=======
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
>>>>>>> 56eb7b497b6b3122088c1ce44e156402209ef6fa
}

pair<int, int> solve()
{
<<<<<<< HEAD
  scanf("%d %d %lld %lld %lld", &n, &t, &a0, &x, &y); now = a0;
  for (int i = 0; i < t; i ++) scanf("%d", &tap[i]);

=======
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
>>>>>>> 56eb7b497b6b3122088c1ce44e156402209ef6fa
  pair<int, int> ans = solve();
  printf("%d %d\n", ans.first, ans.second);

  return(0);
}
