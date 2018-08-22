#include <stdio.h> //biblioteca para entrada e saída de texto;
#include <math.h> //biblioteca para funções matematicas;
#include <locale.h> //biblioteca para localização internacional, acentos, etc.
#include <string.h>
//Inicia funcao principal do programa
int main()
{
setlocale(LC_ALL,""); //localiza programa para idioma do so.
char c[10][10]={"Jean", "Faby", "Fátima", "Marta", "Ben", "Márc",
"Rhai", "Kari", "Ya", "Mel"};
char n[10];
int i, verify;


printf("Digite um nome que direi se o encontro");
scanf("%s", n);
verify=-1;

for (i=0; i<10; i++)
{
if (strcmp(c[i],n)==0) verify++;
printf("Variação do verificador: %d. \n\n", verify);
}


printf("O tamanho do nome digitado é: %d. \n", (int) strlen(n));
printf("O tamanho do primeiro nome do vetor é: %d. \n", (int) strlen(c[0]));
printf("O número do verificador é: %d", verify);
if (verify>-1)
{
printf("Achei. %s é o %dº da lista.", c[verify], verify+1);
}
else
{
printf("Não achei. %s não está na lista.", n);
}
return 0;
}
