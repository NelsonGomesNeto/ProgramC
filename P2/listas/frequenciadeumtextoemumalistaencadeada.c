#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define list_t struct list_t
#define node_t struct node_t

node_t* newNode(int value, int quanti);
list_t* newList();

void printarLista(list_t *list);
bool isEmpty(list_t *list);

void pushBack(list_t *list, int value, int quanti);

void popFront(list_t *list);
void destroy(list_t *list);

int main()
{
  int i = 0; char *string = malloc(1 * sizeof(char));
  while (scanf("%c", &string[i]) != EOF)
  {
    i ++;
    string = realloc(string, (i + 1) * sizeof(char));
    string[i] = '\0';
  }
  //printf("%s", string);
  list_t *list = newList();
  int j, conta;
  for (j = 255; j >= 15; j --)
  {
    conta = 0;
    for (i = 0; string[i] != '\0'; i ++)
    {
      if (string[i] == (char) j)
      {
        conta ++;
      }
    }
    if (conta != 0)
    {
      pushBack(list, j, conta);
    }
  }
  printarLista(list);
  destroy(list);
  free(string);
  return(0);
}

node_t
{ //node_t
  int value, quanti;
  node_t *next;
};

list_t
{ //list_t
  int size;
  node_t *head;
  node_t *tail;
};

node_t* newNode(int value, int quanti)
{ //Novo Node
  node_t *temp = (node_t*) malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->quanti = quanti;
  temp->next = NULL;
  return(temp);
}

list_t* newList()
{ //Nova Lista
  list_t *temp = (list_t*) malloc(1 * sizeof(list_t));
  temp->head = NULL; temp->tail = NULL;
  temp->size = 0;
  return(temp);
}

void printarLista(list_t *list)
{
  node_t *head = list->head;
  while (head != NULL)
  {
    printf("%c %d\n", (char) head->value, head->quanti);
    head = head->next;
  } //printf("\n");
}

bool isEmpty(list_t *list)
{ //Verifica se a list_t está vazia
  return(!list->size);
}

void pushBack(list_t *list, int value, int quanti)
{
  node_t *temp = newNode(value, quanti);
  if (isEmpty(list))
  { //Se estiver vazia, o final e come�o apontam para o mesmo lugar
    list->tail = temp; list->head = temp;
  }
  else
  {
    list->tail->next = temp; //Node final aponta para o novo �ltimo
    list->tail = temp; //Fim da lista aponta para o novo �ltimo
  }
  list->size ++; //Aumenta o tamanho da lista
}

void popFront(list_t *list)
{
  if (isEmpty(list)) return;

  if (list->size == 1)
  {
    free(list->head);
    list->head = NULL; list->tail = NULL;
  }
  else
  {
    node_t *curr = list->head->next;
    free(list->head);
    list->head = curr;
  }
  list->size --;
}

void destroy(list_t *list)
{
  while (!isEmpty(list))
  {
    popFront(list);
  }
  free (list);
}
