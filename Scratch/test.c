#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_NUMERIC, "fr_FR");
  printf("%lf\n", 3000.14);
  return(0);
}