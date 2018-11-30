#include <bits/stdc++.h>
using namespace std;

int main()
{
  set<int> a; a.insert(1);
  set<int>::iterator it = a.find(2);
  printf("%d %d %d\n", a.begin(), a.end(), it);
  return(0);
}
