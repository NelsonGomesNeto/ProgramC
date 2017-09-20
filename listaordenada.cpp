#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int tam; scanf("%d", &tam);
  int ler, lista[tam];
  for (ler = 0; ler < tam; ler ++)
  {
    scanf("%d", &lista[ler]);
  }
  sort(lista, lista + tam);
  for (ler = 0; ler < tam; ler ++)
  {
    printf("%d\n", lista[ler]);
  }
  return(0);
}
