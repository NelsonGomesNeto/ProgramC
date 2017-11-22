#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

int main()
{
  int size; scanf("%d", &size);
  int sequence[size];
  for (int i = 0; i < size; i ++)
    scanf("%d", &sequence[i]);

  int left[size], right[size], now = 1; left[0] = 1; right[size - 1] = 1;
  for (int i = 1; i < size; i ++)
  {
    if (sequence[i - 1] < sequence[i]) now ++;
    else now = 1;
    left[i] = now;
  }

  now = 1;
  for (int i = size - 2; i >= 0; i --)
  {
    if (sequence[i] < sequence[i + 1]) now ++;
    else now = 1;
    right[i] = now;
  }

  DEBUG for (int i = 0; i < size; i ++) printf("%d%c", left[i], i < size - 1 ? ' ' : '\n');
  DEBUG for (int i = 0; i < size; i ++) printf("%d%c", right[i], i < size - 1 ? ' ' : '\n');

  int ans = 1 + (size >= 2);
  for (int i = 1; i < size - 1; i ++)
  {
    if (sequence[i - 1] < sequence[i + 1] - 1)
      ans = max(ans, left[i - 1] + 1 + right[i + 1]);
    if (sequence[i - 1] >= sequence[i])
      ans = max(ans, right[i] + 1);
    if (sequence[i + 1] <= sequence[i])
      ans = max(ans, left[i] + 1);
  }

  printf("%d\n", ans);

  return(0);
}