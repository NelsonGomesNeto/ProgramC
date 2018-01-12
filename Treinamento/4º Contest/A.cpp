#include <bits/stdc++.h>

int main()
{
  int bracket[2][(int) 1e6]; char b;
  int open = 0, close = 0, at = 0;
  while (scanf("%c", &b) && b != '\n')
  {
    if (b == '(') open ++;
    else close ++;
    bracket[0][at] = open;
    bracket[1][at ++] = close;
  }

  int q; scanf("%d", &q);
  while (q -- > 0)
  {
    int lo, hi; scanf("%d %d", &lo, &hi); lo --; hi --;
    open = bracket[0][lo] + bracket[0][hi];
    close = bracket[1][lo] + bracket[1][hi];
    if (open == close)
      
  }
  return(0);
}