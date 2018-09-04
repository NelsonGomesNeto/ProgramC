
#include <stdio.h> //biblioteca para entrada e sa?da de texto;
#include <math.h> //biblioteca para fun??es matematicas;
//#include <locale.h> //biblioteca para localiza??o internacional, acentos, etc.
char *eh_primo(int x)
{
int i, div = 0;
for (i=1; i<=x; i++)
{
if (x==2) return "True";
    if (x % i == 0)
{
          div++;
}
}

if (div == 2)
{
return "True";
}
else
{
return "False";
}
}

long int Fatorial(int n)
{
long int Fat;
int i;
if (n==0 || n==1)
{
Fat = 1;
return Fat;
}
else
{
Fat=1;
}

for (i = 2; i <= n; i = i + 1)  Fat = Fat * i;
return (Fat);
}


int proximo_primo(int y)
{
if (eh_primo(y) == "True")
{
return y;
}
else
{
y++;
proximo_primo(y);
}
}

//Inicia funcao principal do programa
int main()
{
//setlocale(LC_ALL,""); //localiza programa para idioma do so.
int numero, i;
double fat=0;
double soma=0;
scanf("%d", &numero);

for (i=1; i<=numero; i++)
{
if (numero==1)
{
fat=Fatorial(i);
soma=soma+(fat/i);
fat=0;
printf("%d!/%d\n", i, i);
}
if (i<2 && i<numero)
{
fat=Fatorial(i);
soma=soma+(fat/i);
fat=0;
printf("%d!/%d + ", i, i);
}


if (i>=2 && i<numero)
{
if (eh_primo(i)=="True")
{
fat=Fatorial(i);
soma=soma+(fat/proximo_primo(i));
printf("%d!/%d + ", i, proximo_primo(i));
fat=0;
}
else
{
fat=Fatorial(i);
soma=soma+fat/proximo_primo(i);
printf("%d!/%d + ", i, proximo_primo(i));
}
}
if (i>1 && i==numero)
{
if (eh_primo(i)=="True")
{
fat=Fatorial(i);
soma=soma+(fat/proximo_primo(i));
printf("%d!/%d\n", i, proximo_primo(i));
fat=0;
}
else
{
fat=Fatorial(i);
soma=soma+fat/proximo_primo(i);
printf("%d!/%d\n", i, proximo_primo(i));
fat=0;
}
}
}

printf("%.2f\n", soma);
return 0;
}
