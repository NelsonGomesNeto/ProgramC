#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli inf = 1e12;
lli dp[(int) 1e5 + 1][3];

lli trySort(string word[], int cost[], int i, int strings, string prev, int can)
{
  if (i >= strings - 1) return(i == strings - 1 ? (prev <= word[i] ? 0 : inf) : 0);

  if (dp[i][can] == -1)
  {
    lli ans = inf;
    if (word[i] <= word[i + 1])
    {
      //printf("%d Nothing\n", i);
      ans = min(ans, trySort(word, cost, i + 1, strings, word[i], 2));
    }

    string aux1 = word[i], aux2 = word[i + 1];
    reverse(aux1.begin(), aux1.end());
    reverse(aux2.begin(), aux2.end());
    if (aux1 <= word[i + 1] && (can == 1 || can == 2))
    {
      //printf("%d Left", i);
      //cout << ' ' << aux1 << ' ' << word[i + 1] << endl;
      ans = min(ans, cost[i] + trySort(word, cost, i + 1, strings, aux1, 0));
    }
    if (word[i] <= aux2 && (can == 0 || can == 2))
    {
      //printf("%d Right", i);
      //cout << ' ' << word[i] << ' ' << aux2 << endl;
      string aux3 = word[i + 1];
      word[i + 1] = aux2;
      ans = min(ans, cost[i + 1] + trySort(word, cost, i + 1, strings, word[i], 1));
      word[i + 1] = aux3;
    }
    if (aux1 <= aux2 && can == 2)
    {
      //printf("%d Both", i);
      //cout << ' ' << aux1 << ' ' << aux2 << endl;
      string aux3 = word[i + 1];
      word[i + 1] = aux2;
      ans = min(ans, cost[i] + cost[i + 1] + trySort(word, cost, i + 1, strings, aux1, 1));
      word[i + 1] = aux3;
    }

    dp[i][can] = ans;
  }

  return(dp[i][can]);
}

int main()
{
  memset(dp, -1, sizeof(dp));
  int strings; scanf("%d", &strings);
  int cost[strings];
  for (int i = 0; i < strings; i ++)
    scanf("%d", &cost[i]);

  string word[strings];
  for (int i = 0; i < strings; i ++)
  {
    getchar();
    cin >> word[i];
  }

  lli ans = trySort(word, cost, 0, strings, "", 2);

  printf("%lld\n", ans == inf ? -1 : ans);

  return(0);
}