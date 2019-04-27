#include <stdio.h>
typedef struct Person person_t;

struct Person
{
  int id;
  char name[100];
  double grade;
};

void printPeople(int n, person_t people[], double mean)
{
  printf("Alunos abaixo da media:\n");
  int i;
  for (i = 0; i < n; i ++)
    if (people[i].grade < 7)
      printf("Matricula: %d Nome: %s Nota: %.1lf\n", people[i].id, people[i].name, people[i].grade);
  printf("Alunos iguais ou acima da media:\n");
  for (i = 0; i < n; i ++)
    if (people[i].grade >= 7)
      printf("Matricula: %d Nome: %s Nota: %.1lf\n", people[i].id, people[i].name, people[i].grade);
  printf("Media = %.2lf\n", mean);
}

void swap(person_t *a, person_t *b)
{
  person_t aux = *a;
  *a = *b;
  *b = aux;
}

void sort(int n, person_t people[])
{
  int i, j;
  for (i = 0; i < n; i ++)
    for (j = i + 1; j < n; j ++)
      if (people[i].grade > people[j].grade || (people[i].grade == people[j].grade && people[i].id > people[j].id))
        swap(&people[i], &people[j]);
}

int main()
{
  person_t p;
  int n, i;
  double mean = 0;
  scanf("%d", &n);
  person_t people[n];
  for (i = 0; i < n; i ++)
  {
    scanf("%d-%[^-]-%lf", &people[i].id, people[i].name, &people[i].grade);
    mean += people[i].grade;
  }
  mean /= n;

  sort(n, people);
  printPeople(n, people, mean);

  return(0);
}