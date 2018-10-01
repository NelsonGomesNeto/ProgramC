#include <stdio.h>
#include <string.h>

typedef struct card
{
  char name[41], nextCard[41];
  int hSize, habilities[51];
} card_t;

void swap(card_t *a, card_t *b)
{
  card_t aux = *a;
  *a = *b;
  *b = aux;
}

void sort(card_t cards[], int n)
{
  for (int i = 0; i < n; i ++)
    for (int j = i + 1; j < n; j ++)
      if (strcmp(cards[i].name, cards[j].name) > 0)
        swap(&cards[i], &cards[j]);
}

int main()
{
  int n; scanf("%d", &n);
  card_t cards[n];
  for (int i = 0; i < n; i ++)
  {
    scanf("\n%[^\n]", cards[i].name);
    scanf("%d", &cards[i].hSize);
    for (int j = 0; j < cards[i].hSize; j ++)
      scanf("%d", &cards[i].habilities[j]);
    scanf("\n%[^\n]", cards[i].nextCard);
  }
  sort(cards, n);

  char name

  return(0);
}
