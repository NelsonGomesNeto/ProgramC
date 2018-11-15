#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
char s[(int) 1e5 + 1];

int gcd(int a, int b)
{
  if (!b) return(a);
  return(gcd(b, a % b));
}

int main()
{
  scanf("%s", s); int n = 0; while (s[n]) n ++;
  set<int> d;
  for (int i = 1; i < n; i ++) d.insert(gcd(i, n));

  DEBUG
  {
    printf("n: %d, d size: %d\n", n, (int) d.size());
    for (int i: d) printf("%d ", i); printf("\n");
  }

  bool works[n]; memset(works, false, sizeof(works));
  for (int k: d)
  {
    bool can = false;
    for (int i = 0; i < k && !can; i ++)
    {
      can = true; int pos = i;
      do
      {
        if (s[pos] == 'P') { can = false; break; }
        pos = (pos + k) % n;
      } while (pos != i);
    }
    works[k] = can;
  }

  int ans = 0; for (int i = 1; i < n; i ++) ans += works[gcd(i, n)];
  printf("%d\n", ans);

  return(0);
}
