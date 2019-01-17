#include <bits/stdc++.h>
#define VERBOSE if(0)
using namespace std;
int height = 500, width = 3000;
double scale = 0.005;

complex<double> f(complex<double> z, complex<double> c) { return(z*z + c); }

bool exploded(double number) { return(number < -1000000 || number > 1000000); }
bool diverges(complex<double> c)
{
  complex<double> z = 0;
  for (int i = 0; i < 10; i ++)
  {
    complex<double> res = f(z, c);
    VERBOSE printf("\tf(%3.3lf + %3.3lfi) = %3.3lf + %3.3lfi\n", z.real(), z.imag(), res.real(), res.imag());
    z = res;
    if (exploded(z.real()) || exploded(z.imag())) return(true);
  }
  return(false);
}

int main()
{
  bool bitmap[height + 1][width + 1];
  for (double i = -height / 2 * scale, ii = 0; i <= height / 2 * scale; i += scale, ii ++)
    for (double j = -width / 2 * scale, jj = 0; j <= width / 2 * scale; j += scale, jj ++)
    {
      bitmap[(int) ii][(int) jj] = diverges(complex(j, i));
      VERBOSE printf("(c = %3.3lf + %3.3lfi): %s\n", j, i, bitmap ? "Diverges" : "Converges");
    }

  for (int i = 0; i <= height; i ++)
  {
    for (int j = 0; j <= width; j ++)
      printf("%c", bitmap[i][j] ? '*' : ' ');
    printf("\n");
  }
  return(0);
}