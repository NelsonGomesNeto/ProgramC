#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
double prob[301][301];
int n, tree[602][2];
int nextRace[602];
vector<pair<int, double> > race[602];

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = *a;
}

void go(int u)
{
  if (u <= n) return;
  if (tree[u][0] <= n && tree[u][1] <= n)
  {
    race[u].push_back({tree[u][0], prob[tree[u][0]][tree[u][1]]});
    race[u].push_back({tree[u][1], prob[tree[u][1]][tree[u][0]]});
    return;
  }
  go(tree[u][0]);
  go(tree[u][1]);
  if (tree[u][0] <= n)// && tree[u][1] > n)
  {
    double win = 0;
    for (auto v: race[tree[u][1]])
    {
      win += prob[tree[u][0]][v.first] * v.second;
      // printf("%d (%d) - %d %d\n", u, (int) race[u].size(), tree[u][0], v.first);
      race[u].push_back({v.first, prob[v.first][tree[u][0]] * v.second});
    }
    race[u].push_back({tree[u][0], win});
    return;
  }
  else
  {
    for (auto v: race[tree[u][0]])
    {
      double win = 0;
      for (auto w: race[tree[u][1]])
        win += prob[v.first][w.first] * w.second * v.second;
      race[u].push_back({v.first, win});
    }
    for (auto w: race[tree[u][1]])
    {
      double win = 0;
      for (auto v: race[tree[u][0]])
        win += prob[w.first][v.first] * v.second * w.second;
      race[u].push_back({w.first, win});
    }
    return;
  }
}

int main()
{
  while (scanf("%d", &n) != EOF && n)
  {
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j ++)
        scanf("%lf", &prob[i + 1][j + 1]);

    memset(nextRace, -1, sizeof(nextRace));
    for (int i = n + 1; i < 2*n; i ++)
    {
      scanf("%d %d", &tree[i][0], &tree[i][1]);
      if (tree[i][1] <= n && tree[i][0] > n) swap(&tree[i][1], &tree[i][0]);
      nextRace[tree[i][0]] = nextRace[tree[i][1]] = i;
      race[i].clear();
    }

    int root = 0, at = nextRace[1];
    while (at != -1)
    {
      root = at;
      at = nextRace[at];
    }
    go(root);
    DEBUG for (int i = n + 1; i < 2*n; i ++)
    {
      printf("%d", i);
      for (auto j: race[i])
        printf(" (%d %.2lf)", j.first, j.second);
      printf("\n");
    }

    int done = 0;
    for (auto winner: race[root])
      if (winner.first == 1)
      {
        printf("%.6lf\n", winner.second);
        done = 1; break;
      }
    if (!done) printf("0.000000\n");
  }
  return(0);
}
/*

  if (tree[i][0] > n) go(tree[i][0], nextRace[i][0]);
  else nextRace[i][0].push_back({tree[i][0], 1});
  if (tree[i][1] > n) go(tree[i][1], nextRace[i][1]);
  else nextRace[i][1].push_back({tree[i][1], 1});
}

for (int i = n + 1; i < 2 * n; i ++)
{
  printf("%d |", i);
  for (int j = 0; j < nextRace[i][0].size(); j ++)
    printf(" %d", nextRace[i][0][j]);
  printf(" |");
  for (int j = 0; j < nextRace[i][1].size(); j ++)
    printf(" %d", nextRace[i][1][j]);
  printf("\n");
}
printf("\n");
*/