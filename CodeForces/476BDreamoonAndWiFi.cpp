#include <bits/stdc++.h>

int main()
{
  char com[2][20];
  scanf("%s\n%s", com[0], com[1]);

  int pos[2] = {0, 0}, neg[2] = {0, 0}, inter = 0;
  for (int i = 0; com[0][i]; i ++)
  {
    if (com[0][i] == '+') pos[0] ++;
    else neg[0] ++;

    if (com[1][i] == '+') pos[1] ++;
    else if (com[1][i] == '-') neg[1] ++;
    else inter ++;
  }

  if (pos[0] == pos[1] && neg[0] == neg[1]) printf("%.12lf\n", 1.0);
  else if (pos[0] > pos[1] + inter || neg[0] > neg[1] + inter) printf("%.12lf\n", 0.0);
  else if (pos[0] == pos[1]) printf("%.12lf\n", pow(0.5, neg[0] - neg[1]));
  else if (neg[0] == neg[1]) printf("%.12lf\n", pow(0.5, pos[0] - pos[1]));
  else printf("%.12lf\n", pow(0.5, 1 + abs(pos[0] - pos[1])) + pow(0.5, 1 + abs(neg[0] - neg[1])));

  return(0);
}