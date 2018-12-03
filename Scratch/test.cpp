#include <bits/stdc++.h>
using namespace std;

int main()
{
  set<int> a; for (int i = 0; i < 10; i ++) a.insert(i*10);
  set<int>::iterator lo = a.lower_bound(0), hi = a.upper_bound(0);
  printf("%d %d\n", *lo, *hi);
  return(0);
}
