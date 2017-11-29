#include <bits/stdc++.h>
using namespace std;

int main()
{
  int total = 0, l = 0, r = 0, u = 0, d = 0; char s[1000000];
  int size; scanf("%d", &size); getchar();
  scanf("%s", s);
  for (int i = 0; s[i]; i ++)
  {
    if (s[i] == 'R') r ++;
    if (s[i] == 'L') l ++;
    if (s[i] == 'U') u ++;
    if (s[i] == 'D') d ++;
  }
  total = min(r, l)*2 + min(u, d)*2;

  printf("%d\n", total);

  return(0);
}