#include <bits/stdc++.h>

int main()
{
  int n; scanf("%d", &n);
  while (n --)
  {
    int number[12]; char e[12]; int size = 0;
    while (scanf("%d%c", &number[size], &e[size]) && e[size] == '\n') size ++;
    for (int i = 0; i < size; i ++) printf("%d%c", number[i], e[i]);
    printf("\n");
  }
  return(0);
}