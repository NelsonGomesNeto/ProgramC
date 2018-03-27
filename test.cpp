#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void Batalha(int Batalhas, int Vc, int Vb, int Dc, int Db)
{

  if(Vc <= 0)
  {
    printf("Bezaliel\n");
    return;
  }
  printf("%d %d %d %d %lf %lf\n", Vc, Vb, Dc, Db, ceil((double)Vb/Dc), ceil((double)Vc/Db));
  if(ceil(Vb/Dc) > ceil(Vc/Db))
  {
    Batalha(Batalhas,Vc-Db,Vb,Dc+50,Db);
  }
  else if(ceil(Vb/Dc) <= ceil(Vc/Db))
  {
    printf("Clodes\n");
    return;
  }
}
void lendo (int Batalhas, int Vc, int Vb, int Dc, int Db)
{
    if(Batalhas == 0)
    {
        return;
    }
    scanf("%d%d%d%d", &Vc, &Vb, &Dc, &Db);
    Batalha(Batalhas,Vc,Vb,Dc,Db);
    lendo(Batalhas-1,Vc,Vb,Dc,Db);
}
int main()
{
  int Batalhas,Vc,Vb,Dc,Db;
  scanf("%d", &Batalhas);
  lendo(Batalhas,Vc,Vb,Dc,Db);
}
