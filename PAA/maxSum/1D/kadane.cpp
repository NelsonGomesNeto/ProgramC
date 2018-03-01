#include <bits/stdc++.h>
using namespace std;

vector<int> kadane(int array[], int size)
{
  int best = array[0], now = 0, j = 0, iStart, iEnd;
  for (int i = 0; i < size; i ++)
  {
    now += array[i];
    if (now > best)
    {
      best = now;
      iStart = j; iEnd = i;
    }
    if (now < 0)
    {
      j = i + 1;
      now = 0;
    }
  }
  vector<int> ans = {iStart, iEnd, best};
  return(ans);
}

int main()
{
  int size; scanf("%d", &size);
  int array[size];
  for (int i = 0; i < size; i ++)
    scanf("%d", &array[i]);

  vector<int> maxSum = kadane(array, size);
  printf("[%d, %d] = %d\n", maxSum[0], maxSum[1], maxSum[2]);
  return(0);
}