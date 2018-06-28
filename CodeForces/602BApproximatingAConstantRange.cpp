#include <bits/stdc++.h>
#define DEBUG if(1)
using namespace std;

void printArray(int a[], int size)
{
  for (int i = 0; i < size; i ++) printf("%d%c", a[i], i < size - 1 ? ' ' : '\n');
}

int main()
{
  int n; scanf("%d", &n);
  int a[n]; for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

  vector<int> num[n];
  for (int i = 0; i < n; i ++)
    num[a[i]].push_back(i);


  return(0);
}