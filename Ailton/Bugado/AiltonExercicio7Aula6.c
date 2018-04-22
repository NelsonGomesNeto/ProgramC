#include <stdio.h>

int continuar()
{
  char veri;
  printf("Vamos calcular?(S/N)");
  getchar();
  scanf("%c", &veri);
  if (veri == 'S' || veri == 's')
  {
    return(1);
  }
  return(0);
}

float calcular(float num)
{
  if (num <= 1)
  { return(1); }
  else if (num <= 2)
  { return(2); }
  else if (num <= 5)
  { return(num * num); }
  else { return(num * num * num); }
}

int main()
{
  float a, b;
  do
  {
    printf("Digite a e b:\n");
    scanf("%f%f", &a, &b);
    while (a <= b)
    {
      printf("%f\n", calcular(a));
      a += 0.5;
    }
  } while (continuar() == 1);
  return(0);
}
