#include <bits/stdc++.h>
int minInf = INT_MIN;
using namespace std;
int dp1[501][501];
int dp2[501][501];

int knapsack1(pair<int, int> place[], int before, int i, int places, int priceLimit)
{
  if (i == places)
  {
    if (priceLimit - abs(place[0].second - place[before].second) >= 0)
      return(0);
    return(-10000);
  }

  //if (dp1[i][priceLimit] == -1)
  //{
    dp1[i][priceLimit] = knapsack1(place, before, i + 1, places, priceLimit);
    if (abs(place[i].second - place[before].second) <= priceLimit)
      dp1[i][priceLimit] = max(dp1[i][priceLimit], 1 + knapsack1(place, i, i + 1, places, priceLimit - abs(place[i].second - place[before].second)));
  //}

  return(dp1[i][priceLimit]);
}

int knapsack2(pair<int, int> place[], int before, int i, int places, int priceLimit)
{
  if (i == places)
  {
    if (priceLimit - abs(place[0].second - place[before].second) >= 0)
      return(0);
    return(-10000);
  }

  if (dp2[before][priceLimit] == -1)
  {
    dp2[before][priceLimit] = knapsack2(place, before, i + 1, places, priceLimit);
    if (abs(place[i].second - place[before].second) <= priceLimit)
      dp2[before][priceLimit] = max(dp2[before][priceLimit], 1 + knapsack2(place, i, i + 1, places, priceLimit - abs(place[i].second - place[before].second)));
  }

  return(dp2[before][priceLimit]);
}

int main()
{
  int places, priceLimit; scanf("%d %d", &places, &priceLimit);
  pair<int, int> aux[places], start; int i, j, f = 0;
  int lat, lon;
  for (i = 0; i < places; i ++)
  {
    memset(dp1[i], -1, sizeof(dp1[i]));
    memset(dp2[i], -1, sizeof(dp2[i]));
    scanf("%d %d", &lat, &lon);
    if (!i) start = {lon, lat};
    //if (lon < 0) lon = 180 + (-lon);
    aux[i] = {lon, lat};
  }

  sort(aux, aux + places);

  //for (i = 0; i < places; i ++)

  pair<int, int> place[places + 1];
  for (i = 0, j = 0; j < places; i ++)
  {
    //printf("%d %d %d\n", j, aux[i].second, aux[i].first);
    i %= places;
    if (aux[i] == start && f ++ == 0)
      place[j ++] = aux[i];
    else if (f == 1)
      place[j ++] = aux[i];
  }
  //for (i = 0; i < places; i ++)
  //  printf("%d %d\n", place[i].second, place[i].first);

  int answer = knapsack1(place, 0, 1, places, priceLimit);
  //answer = (answer + knapsack2(place, 0, 1, places, priceLimit)) / 2;

  printf("%d\n", answer);

  return(0);
}