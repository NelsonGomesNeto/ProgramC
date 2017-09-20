void quick_sort(int *v, int size)
{
  if (size <= 1) //size deve ser < 1
  {
    return;
  }
  else
  {
    int pivot = v[size / 2]; //Correto
    int a = 0, b = size - 1; //Nope, b = size;

    while (a < b) //a deve chegar em b: a <= b
    {
      //É necessário limitar ambos os whiles
      //Primeiro: a < size
      //Segundo: b > 0
      while (v[a] < pivot) a ++;
      while (v[b] > pivot) b --;
      if (a < b) //a deve chegar em b: a <= b
      {
        //Falta um a ++; //Falta um b --;
        //Do contrário, iria ficar preso no while
        swap(&v[a], &v[b]);
      }
    }
    quick_sort(v, b); //Correto
    quick_sort(v + a, size - a); //Correto
  }
}
