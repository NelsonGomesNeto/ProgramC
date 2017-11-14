#include <bits/stdc++.h>

char s[100005];

int main()
{
  scanf("%s", s);

  int can = 0;
  for (int i = 0; s[i + 1]; i ++)
  {
    if ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'A'))
    {
      can ++;
      i ++;
    }
  }

  

  return(0);
}