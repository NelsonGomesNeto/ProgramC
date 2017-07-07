#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _deque deque_t;
typedef struct _node node_t;

// Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
  node_t *prev;
  node_t *next;
  int value;
};

// Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o
// tamanho do deque
struct _deque {
  node_t *front;
  node_t *rear;
  int size;
};

// Cria um node que guarda os valores que são enfileirados no deque
node_t *node_new(int value);

// Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t *construct();
// Libera a memória do conteúdo e do próprio deque
void destruct(deque_t *deque);

// Retorna o tamanho do deque
int size(deque_t *deque);
// Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool empty(deque_t *deque);

// Retorna o valor da frente da lista, retorna int_min quando a lista estiver
// vazia
int front(deque_t *deque);
// Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int rear(deque_t *deque);

// Cria um nó que guarda um valor e o adiciona ao fim do deque
void enqueue_rear(deque_t *deque, int value);
// Cria um nó que guarda um valor e o adiciona ao inicio do deque
void enqueue_front(deque_t *deque, int value);
// Retira o valor do final caso não esteja vazia
void dequeue_rear(deque_t *deque);
// Retira o valor da frente caso não esteja vazia
void dequeue_front(deque_t *deque);
// Limpa o conteudo do deque(deixa ele vazio)
void erase(deque_t *deque);

// Imprime o deque enquanto o desinfileira, adicionando os elementos em outra
// lista,
// e desinfileira a segunda, enfileirando de volta na primeira. Não imprime se o
// deque esta vazio
void print(deque_t *deque);

int main() {
  int i, num;
  scanf("%d", &num);

  deque_t *deque = construct();

  int vector[num];
  for (i = 0; i < num; ++i)
    scanf("%d", &vector[i]);

  for (i = 0; i < num; ++i)
    enqueue_rear(deque, vector[i]);

  printf("%d\n", front(deque));
  printf("%d\n", rear(deque));

  if (!empty(deque))
    printf("The size of the deque %d\n", size(deque));
  else
    printf("The deque is empty\n");

  scanf("%d", &num);
  for (i = 0; i < num; ++i)
    enqueue_front(deque, i);

  print(deque);
  dequeue_front(deque);
  print(deque);
  dequeue_rear(deque);
  print(deque);

  erase(deque);
  for (i = 0; i < 3; ++i)
    enqueue_rear(deque, i);

  print(deque);
  destruct(deque);

  return 0;
}

// Cria um node que guarda os valores que são enfileirados no deque
node_t *node_new(int value)
{
	node_t *temp = malloc(1 * sizeof(node_t));
	temp->next = NULL;
	temp->prev = NULL;
	temp->value = value;
	return(temp);
}

// Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t *construct()
{
	deque_t *temp = (deque_t*) malloc(1 * sizeof(deque_t));
	temp->front = NULL;
	temp->rear = NULL;
	temp->size = 0;
	return(temp);
}

// Libera a memória do conteúdo e do próprio deque
void destruct(deque_t *deque)
{
	erase(deque);
	free(deque);
}

// Retorna o tamanho do deque
int size(deque_t *deque)
{
	return(deque->size);
}

// Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool empty(deque_t *deque)
{
	return(!deque->size);
}

// Retorna o valor da frente da lista, retorna int_min quando a lista estiver
// vazia
int front(deque_t *deque)
{
	if (empty(deque)) return(INT_MIN);
	return(deque->front->value);
}

// Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int rear(deque_t *deque)
{
	if (empty(deque)) return(INT_MIN);
	return(deque->rear->value);
}

// Cria um nó que guarda um valor e o adiciona ao fim do deque
void enqueue_rear(deque_t *deque, int value)
{
	node_t *temp = node_new(value);
	if (empty(deque))
	{
		deque->front = temp;
		deque->rear = temp;
	}
	else
	{
		deque->rear->next = temp;
		temp->prev = deque->rear;
		deque->rear = temp;
	}
	deque->size ++;
}

// Cria um nó que guarda um valor e o adiciona ao inicio do deque
void enqueue_front(deque_t *deque, int value)
{
	node_t *temp = node_new(value);
	if (empty(deque))
	{
		deque->front = temp;
		deque->rear = temp;
	}
	else
	{
		deque->front->prev = temp;
		temp->next = deque->front;
		deque->front = temp;
	}
	deque->size ++;
}

// Retira o valor do final caso não esteja vazia
void dequeue_rear(deque_t *deque)
{
	if (empty(deque)) return;
	node_t *temp = deque->rear;
	if (deque->front == deque->rear)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		deque->rear = deque->rear->prev;
	}
	free(temp);
	deque->size --;
}

// Retira o valor da frente caso não esteja vazia
void dequeue_front(deque_t *deque)
{
	if (empty(deque)) return;
	node_t *temp = deque->front;
	if (deque->front == deque->rear)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		deque->front = deque->front->next;
	}
	free(temp);
	deque->size --;
}

// Limpa o conteudo do deque(deixa ele vazio)
void erase(deque_t *deque)
{
	while (!empty(deque))
		dequeue_front(deque);
}

// Imprime o deque enquanto o desinfileira, adicionando os elementos em outra
// lista,
// e desinfileira a segunda, enfileirando de volta na primeira. Não imprime se o
// deque esta vazio
void print(deque_t *deque)
{
	if (empty(deque)) return;
	deque_t *temp = construct();
	int espaco = 0;
	while (!empty(deque))
	{
		if (espaco > 0) printf(" ");
		printf("%d", front(deque));
		enqueue_rear(temp, front(deque));
		dequeue_front(deque);
		espaco ++;
	} printf("\n");

	while (!empty(temp))
	{
		enqueue_rear(deque, front(temp));
		dequeue_front(temp);
	}

	destruct(temp);
}
