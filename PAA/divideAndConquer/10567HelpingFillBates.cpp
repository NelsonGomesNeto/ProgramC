#include <bits/stdc++.h>
#define DEBUG if(1)
using namespace std;

int main()
{
  string s;
  cin >> s;
  DEBUG for (int i = 0; s[i]; i ++)
    printf("(%c, %d) ", s[i], i);
  DEBUG printf("\n");

  int letters[256]; memset(letters, 0, sizeof(letters));
  for (int i = 'a'; i <= 'z'; i ++)
    for (int j = 0, q = 0; s[j]; j ++)
    {
      q += s[j] == i;
      letters[i] = q;
    }
  for (int i = 'A'; i <= 'Z'; i ++)
    for (int j = 0, q = 0; s[j]; j ++)
    {
      q += s[j] == i;
      letters[i] = q;
    }

  int queries; scanf("%d", &queries);
  while (queries -- > 0)
  {
    string ss;
    getchar(); cin >> ss;
    char at = ss[0], prev = ss[0]; int i = 0, quantity = 0;
    while (s[i] && at == prev)
    {
      i ++;
    }
  }

  return(0);
}