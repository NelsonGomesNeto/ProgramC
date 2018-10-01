#include <bits/stdc++.h>

int circular(int a)
{
  if (a < 0) return(10 + a % 10);
  return(a % 10);
}

int main()
{
  char keyboard[3][11] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
  int position[256][2];
  for (int i = 0; i < 3; i ++)
    for (int j = 0; j < 10; j ++)
    {
      position[keyboard[i][j]][0] = i;
      position[keyboard[i][j]][1] = j;
    }

  char direction; scanf("%c", &direction);
  char s[101]; scanf("\n%s", s);
  char ns[101]; memset(ns, '\0', sizeof(ns));
  if (direction == 'R')
    for (int i = 0; s[i]; i ++)
      ns[i] = keyboard[position[s[i]][0]][circular(position[s[i]][1] - 1)];
  else
    for (int i = 0; s[i]; i ++)
      ns[i] = keyboard[position[s[i]][0]][circular(position[s[i]][1] + 1)];

  printf("%s\n", ns);
  return(0);
}
