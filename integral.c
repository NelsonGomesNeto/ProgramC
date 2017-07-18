#include <stdio.h>
#include <math.h>

double xForth(double x)
{
  return(x*x*x*x);
}

double someBug(double x)
{
  return(1/(x*x + 1));
}

double integral(double (*func)(double x), double start, double end, double blocks)
{
  double result = 0, dx = (end - start)/blocks, i;
  for (i = start + dx; i <= end; i += dx)
    result += func(i) * dx;

  return(result);
}

void aTest(double (*func)(double x), double start, double end)
{
  printf("%.3lf\n", integral(&*func, start, end, 10));
  printf("%.3lf\n", integral(&*func, start, end, 30));
  printf("%.3lf\n", integral(&*func, start, end, 50));
  printf("%.3lf\n", integral(&*func, start, end, 100));
}

int main()
{
  double start, end;
  while (scanf("%lf %lf", &start, &end) != EOF)
  {
    aTest(*someBug, start, end);
  }
  return(0);
}
