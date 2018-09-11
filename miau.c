#include <stdio.h>
#include <string.h>

void labirinto(int n, int m, int i,int j,int qtd, char comandos[],int num[][m],int all,int ant_i, int ant_j)
{
  if(all == qtd)
  {
    printf("(%d,%d)\n",i,j);
  }
  else
  {
    if(comandos[all] == 'C') i--;
    if(comandos[all] == 'B') i++;
    if(comandos[all] == 'D') j++;
    if(comandos[all] == 'E') j--;

    if(num[i][j] == 0)
    {
      i = ant_i;
      j = ant_j;
    }
    labirinto(n,m,i,j,qtd,comandos,num,all+1,i,j);
  }

}
void ler_comandos(int n, int i, char comandos[])
{
  // getchar();
  if(i == n)
  {
    return;
  }
  else
  {
    scanf("%c",&comandos[i]);
    getchar();
    ler_comandos(n,i+1,comandos);
  }
}

void ler(int n,int m, int i, int j, int num[][m])
{
  if(i == n)
  {
    return;
  }
  else
  {
    scanf("%d",&num[i][j]);
    if(j == m-1) // muda de linha
    {
      i++;
      j=-1;
    }
    ler(n,m,i,j+1,num);
  }
}

int main()
{
  int n,m,qtd;
  scanf("%d\n%d",&n,&m);
  getchar();
  int num[n][m];
  ler(n,m,0,0,num);
  scanf("%d",&qtd);
  getchar();
  char comandos[qtd];
  ler_comandos(qtd,0,comandos);
  int pi,pj;
  scanf("%d\n%d",&pi,&pj);
  labirinto(n,m,pi,pj,qtd,comandos,num,0,pi,pj);
  return 0;
}
