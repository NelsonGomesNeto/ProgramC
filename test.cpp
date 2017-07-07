#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> array;
  int i = 0, num;
  while (scanf("%d", &num) != EOF)
  {
    array.push_back(num);
    i ++;
  } array.push_back(num);

  int j;
  for (j = 0; j < i; j ++)
    printf("%d\n", array[j]);
  printf("Ended\n");

  sort(array.begin(), array.end());

  for (j = 0; j < i; j ++)
    printf("%d\n", array[j]);
  printf("Ended\n");
  
  return(0);
}
