#include <bits/stdc++.h>
using namespace std;

int main()
{
  int numbers; scanf("%d", &numbers);
  int array[numbers], dp[100001], i; memset(dp, 0, sizeof(dp));
  for (i = 0; i < numbers; i ++)
  {
    scanf("%d", &array[i]);
    dp[array[i]] ++;
  }

  sort(array, array + numbers);

  int total = 0;
  for (i = 100000; i >= 1; i --)
  {
    //printf("%d %d %d %d\n", i, dp[i - 1] * (i - 1), dp[i] * i, dp[i + 1] * (i + 1));
    if (dp[i] * i >= dp[i - 1] * (i - 1) + (dp[i + 1] * (i + 1)))
    {
      total += (dp[i] * i);
      dp[i - 1] = 0;
      //i --;
    }
    else
    {
      if (dp[i - 1] * (i - 1) && (dp[i + 1] * (i + 1)))
        total += dp[i - 1] * (i - 1) + (dp[i + 1] * (i + 1));
      //dp[i - 1] = 0;
      i --;
    }
  }

  printf("%d\n", total);

  return(0);
}