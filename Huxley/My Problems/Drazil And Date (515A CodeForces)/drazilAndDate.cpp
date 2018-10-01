#include <bits/stdc++.h>

int main()
{
  int a, b, s; scanf("%d %d %d", &a, &b, &s);
  int dist = abs(a) + abs(b);
  printf("%s\n", (dist == s || (dist < s && (s - dist) % 2 == 0)) ? "Yes" : "No");
  return(0);
}