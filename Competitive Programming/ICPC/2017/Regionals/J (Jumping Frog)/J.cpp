#include <bits/stdc++.h>
using namespace std;
int cantDP[(int) 1e5 + 1];
char s[(int) 1e5 + 1];
int biggestSpacing = 0, spacing = 0, n = 0;

void markDivisors(int k)
{
  int end = sqrt(k);
  for (int i = 2; i <= end; i ++)
    if (k % i == 0) cantDP[i] = cantDP[k / i] = 1;
}

bool can(int k)
{
  bool c = false;
  for (int i = 0; i < min(k, n - k) && !c; i ++)
  {
    c = true; int j = i;
    do
    {
      if (s[j] == 'P') { c = false; break; }
      j = (j + k) % n;
    } while(i != j);
  }
  return(c);
}

int main()
{
  scanf("%s", s);
  memset(cantDP, 0, sizeof(cantDP));
  for (int i = 0; s[i]; i ++)
  {
    if (s[i] == 'R') spacing = 0;
    else spacing ++;
    biggestSpacing = max(biggestSpacing, spacing);
    n ++;
  }
  if (!biggestSpacing) biggestSpacing = 1;

  int works = 0;
  for (int k = n - 1; k >= biggestSpacing; k --)
  {
    // printf("%d\n", k);
    if (!cantDP[k] && can(k)) works ++;
    else markDivisors(k);
  }
  printf("%d\n", works);
  return(0);
}
/*
try the contrary
biggestSpacing to n - 1
but marks all multiples of working ones
*/
