#include <bits/stdc++.h>

int lcs(char s[], char r[], int i, int size)
{
  if (i >= size) return(i == size);

}

int main()
{
  int size; scanf("%d", &size);
  char s[size + 1], r[size + 1]; scanf("\n%s", s);
  for (int i = 0; i < size; i ++) r[size - i - 1] = s[i];
  r[size] = '\0';
  int ans = lcs(s, r, 0, size);
  printf("%d\n", size - ans);
  return(0);
}