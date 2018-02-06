#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; scanf("%d", &t);
  while (t --)
  {
    int n; scanf("%d", &n);
    string un[n], so[n];
    for (int i = 0; i < n; i ++)
      cin >> un[i];
    for (int i = 0; i < n; i ++)
      cin >> so[i];

    set<string> toChange; int q = 0;
    for (int i = n - 1, j = n - 1; i >= q; i --, j --)
    {
      if (j < 0 || so[i] != un[j])
      {
        q ++;
        toChange.insert(un[j]);
        for (j = n - 1; j >= 0; j --)
          if (so[i] == un[j]) break;
      }
      printf("%d\n", q);
    }
    printf("\n");
  }
  return(0);
}