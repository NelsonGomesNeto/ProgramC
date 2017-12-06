#include <bits/stdc++.h>
using namespace std;

int main()
{
  int size; scanf("%d\n", &size);
  int s[size], m[size];
  for (int i = 0; i < size; i ++)
    scanf("%01d", &s[i]);
  for (int i = 0; i < size; i ++)
    scanf("%01d", &m[i]);

  sort(m, m+size);
  int damage = 0, hit = 0;
  for (int i = 0, j = size - 1; i < size; i ++, j --)
  {
    if (s[i] > m[i]) damage ++;
    if (s[i] < m[j]) hit ++;
  }

  printf("%d\n%d\n", damage, hit);

  return(0);
}