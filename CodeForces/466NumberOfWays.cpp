#include <bits/stdc++.h>
using namespace std;

int main()
{
  int size; scanf("%d", &size);
  int array[size]; long long int sum = 0;
  for (int i = 0; i < size; i ++)
  {
    scanf("%d", &array[i]);
    sum += array[i];
  }

  if (sum % 3 != 0)
    printf("0\n");
  else
  {
    long long int accumulated = 0;
    for (int i = 0; i < size; i ++)
    {
      accumulated += array[i];
      if (accumulated == target)
        count[i] = 1;
    }
    printf("%lld\n", count[size - 1]);
  }

  return(0);
}