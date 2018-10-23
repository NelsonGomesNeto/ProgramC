#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; scanf("%d", &t);
  while (t --)
  {
    char s[(int) 1e5 + 1]; int n;
    scanf("\n%s %d", s, &n);
    deque<char> minimum, maximum; int nmin = n, nmax = n;

    minimum.push_back(s[0]);
    for (int i = 1; s[i]; i ++)
    {
      while (minimum.size() && nmin && minimum.back() > s[i]) nmin --, minimum.pop_back();
      minimum.push_back(s[i]);
    }
    while (nmin) nmin --, minimum.pop_back();

    maximum.push_back(s[0]);
    for (int i = 1, done; s[i]; i ++)
    {
      while (maximum.size() && nmax && maximum.back() < s[i]) nmax --, maximum.pop_back();
      maximum.push_back(s[i]);
    }
    while (nmax) nmax --, maximum.pop_back();

    for (auto i: minimum) printf("%c", i); printf("\n");
    for (auto i: maximum) printf("%c", i); printf("\n");
  }
  return(0);
}