#include <bits/stdc++.h>
using namespace std;

int knapsack(int **dp, int numObjects, int object[][2], int i, int weight)
{
  if (i == numObjects) return(0);

  if (dp[i][weight] == -1)
  {
    dp[i][weight] = knapsack(dp, numObjects, object, i + 1, weight);
    if (object[i][1] <= weight)
      dp[i][weight] = max(dp[i][weight], knapsack(dp, numObjects, object, i + 1, weight - object[i][1]) + object[i][0]);
  }

  return(dp[i][weight]);
}

int solve(int numObjects, int object[][2], int numPeople, int strongest, int people[])
{
  int **ksDP = (int**) malloc((numObjects + 1) * sizeof(int*));
  for (int i = 0; i <= numObjects; i ++)
  {
    ksDP[i] = (int*) malloc((strongest + 1) * sizeof(int));
    for (int j = 0; j <= strongest; j ++)
      ksDP[i][j] = -1;
  }

  int total = 0;
  for (int i = 0; i < numPeople; i ++)
  {
    int p = people[i];
    if (ksDP[0][p] == -1)
      ksDP[0][p] = knapsack(ksDP, numObjects, object, 0, p);
    total += ksDP[0][p];
  }

  //free(ksDP);
  return(total);
}

int main()
{
  int tests; scanf("%d", &tests);
  while (tests > 0)
  {
    int numObjects; scanf("%d", &numObjects);
    int object[numObjects][2];
    for (int i = 0; i < numObjects; i ++)
      scanf("%d %d", &object[i][0], &object[i][1]);

    int numPeople; scanf("%d", &numPeople);
    int people[numPeople], strongest = 0;
    for (int i = 0; i < numPeople; i ++)
    {
      scanf("%d", &people[i]);
      strongest = max(strongest, people[i]);
    }

    int answer = solve(numObjects, object, numPeople, strongest, people);
    printf("%d\n", answer);

    tests --;
  }
  return(0);
}