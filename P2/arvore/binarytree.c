#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _binaryTree binaryTree_t;

binaryTree_t* createEmptyBinaryTree();
binaryTree_t* createBinaryTree(int item, binaryTree_t *left, binaryTree_t *right);
binaryTree_t* postFixExpression();

binaryTree_t* searchInBinaryTree(binaryTree_t *bt, int item);

bool isBinaryTreeEmpty(binaryTree_t *bt);
int ocorrencias(binaryTree_t *bt, int item);

void addInBinaryTree(binaryTree_t **bt, int item);
void addScanInBinaryTree(binaryTree_t **bt);

void printPreOrder(binaryTree_t *bt);
void printInOrder(binaryTree_t *bt);
void printPostOrder(binaryTree_t *bt);
void bfs(binaryTree_t *bt);

void deleteInBinaryTree(binaryTree_t **bt, int item);
void destroyBinaryTree(binaryTree_t *bt);

void printStuff(binaryTree_t *bt)
{
  printf("PreOrder: "); printPreOrder(bt); printf("\n");
  printf("InOrder: "); printInOrder(bt); printf("\n");
  printf("PosOrder: "); printPostOrder(bt); printf("\n");
}

int main()
{
  binaryTree_t *bt = createEmptyBinaryTree();

  addInBinaryTree(&bt, 11);
  addInBinaryTree(&bt, 2);
  addInBinaryTree(&bt, 1);
  addInBinaryTree(&bt, 13);
  addInBinaryTree(&bt, 12);
  addInBinaryTree(&bt, 1);
  addInBinaryTree(&bt, 1);
  addInBinaryTree(&bt, 1);
  addInBinaryTree(&bt, 6);
  addInBinaryTree(&bt, 15);
  addInBinaryTree(&bt, 30);

  printf("PreOrder: "); printPreOrder(bt); printf("\n");
  printf("InOrder:  "); printInOrder(bt); printf("\n");
  printf("PosOrder: "); printPostOrder(bt); printf("\n");
  printf("BFS:      "); bfs(bt); printf("\n");

  printf("%d\n", ocorrencias(bt, 1));

  binaryTree_t *expression = postFixExpression();

  printInOrder(expression); printf("\n");

  destroyBinaryTree(bt);

  return(0);
}

struct _binaryTree
{
  int item;
  binaryTree_t *left;
  binaryTree_t *right;
};

binaryTree_t* createEmptyBinaryTree()
{
  return(NULL);
}

binaryTree_t* createBinaryTree(int item, binaryTree_t *left, binaryTree_t *right)
{
  binaryTree_t *temp = (binaryTree_t*) malloc(1 * sizeof(binaryTree_t));
  temp->item = item;
  temp->left = left;
  temp->right = right;
  return(temp);
}

typedef struct _stack stack_t;
typedef struct _node node_t;

struct _stack
{
  int size;
  node_t *top;
};

struct _node
{
  binaryTree_t *tree;
  node_t *bot;
};

stack_t* createStack()
{
  stack_t *temp = (stack_t*) malloc(1 *  sizeof(stack_t));
  temp->size = 0;
  temp->top = NULL;
  return(temp);
}

node_t* createNode(binaryTree_t *tree)
{
  node_t *temp = (node_t*) malloc(1 * sizeof(node_t));
  temp->tree = tree;
  temp->bot = NULL;
  return(temp);
}

void push(stack_t *stack, binaryTree_t *expre)
{
  node_t *temp = createNode(expre);

  if (stack->size == 0)
  {
    stack->top = temp;
  }
  else
  {
    temp->bot = stack->top;
    stack->top = temp;
  }
  stack->size ++;
}

binaryTree_t* pop(stack_t *stack)
{
  binaryTree_t *temp = stack->top->tree;
  free(stack->top);
  stack->top = stack->top->bot;
  //node_t *toRemove = stack->top;
  stack->size --;
  return(temp);
}

binaryTree_t* postFixExpression()
{
  char expression;
  stack_t *stack = createStack();
  while (scanf("%c", &expression) && expression != '\n')
  {

    if (expression >= '0' && expression <= '9')
    {
      ungetc(expression, stdin);
      int num; scanf("%d", &num);
      binaryTree_t* leaf = createBinaryTree(num, NULL, NULL);
      push(stack, leaf);
    }
    else if (expression != ' ')
    {
      push(stack, createBinaryTree(expression, pop(stack), pop(stack)));
    }
  }

  return(pop(stack));
}

binaryTree_t* searchInBinaryTree(binaryTree_t *bt, int item)
{
  if ((isBinaryTreeEmpty(bt)) || bt->item == item)
  {
    return(bt);
  }
  else if (bt->item > item)
  {
    return(searchInBinaryTree(bt->left, item));
  }
  else
  {
    return(searchInBinaryTree(bt->right, item));
  }
}

bool isBinaryTreeEmpty(binaryTree_t *bt)
{
  return(bt == NULL);
}

int ocorrencias(binaryTree_t *bt, int item)
{
  if (isBinaryTreeEmpty(bt))
  {
    return(0);
  }
  if (bt->item > item)
  {
    return(ocorrencias(bt->left, item));
  }
  else if (bt->item < item)
  {
    return(ocorrencias(bt->right, item));
  }
  if (bt->item == item)
  {
    return(1 + ocorrencias(bt->left, item) + ocorrencias(bt->right, item));
  }
  return(0);
}

void addInBinaryTree(binaryTree_t **bt, int item)
{
  if (isBinaryTreeEmpty(*bt))
    (*bt) = createBinaryTree(item, NULL, NULL);
  else if ((*bt)->item > item)
    addInBinaryTree(&(*bt)->left, item);
  else
    addInBinaryTree(&(*bt)->right, item);
}

void addScanInBinaryTree(binaryTree_t **bt)
{
  char where;
  if (scanf("%c[^0-9]", &where) != EOF && where != '\n')
  {
    int num = INT_MIN;
    scanf("%d", &num);
    //printf("##%c%d\n", where, num);
    if (where == ')' && num == INT_MIN)
      return;

    if (isBinaryTreeEmpty(*bt))
    {
      if (num != INT_MIN)
      {
        (*bt) = createBinaryTree(num, NULL, NULL);
        addScanInBinaryTree(&(*bt)->left);
        addScanInBinaryTree(&(*bt)->right);
        getchar(); //Limpar para pegar o próximo nó
      }
      else
      {
        addScanInBinaryTree(&(*bt));
      }
    }
  }
}

void printPreOrder(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    printf("%d ", bt->item);
    printPreOrder(bt->left);
    printPreOrder(bt->right);
  }
}

void printInOrder(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    printInOrder(bt->left);
    if (bt->left == NULL && bt->right == NULL)
      printf("%c ", bt->item);
    else
      printf("%c ", bt->item);
    printInOrder(bt->right);
  }
}

void printPostOrder(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    printPostOrder(bt->left);
    printPostOrder(bt->right);
    printf("%d ", bt->item);
  }
}

int max(int a, int b)
{
  return(a > b ? a : b);
}

int height(binaryTree_t *bt)
{
  if (isBinaryTreeEmpty(bt)) return(0);

  return(1 + max(height(bt->left), height(bt->right)));
}

void printLevel(binaryTree_t *bt, int i, int level)
{

  if (isBinaryTreeEmpty(bt)) return;

  if (i == level)
  {
    printf("%d ", bt->item);
    return;
  }

  printLevel(bt->left, i + 1, level);
  printLevel(bt->right, i + 1, level);

}

void bfs(binaryTree_t *bt)
{
  int lastLevel = height(bt), i;
  for (i = 1; i <= lastLevel; i ++)
    printLevel(bt, 1, i);

  printf("\n");
}

binaryTree_t* minimumNode(binaryTree_t *bt, binaryTree_t **parent)
{
  binaryTree_t *curr = bt;
  while (!isBinaryTreeEmpty(curr->left))
  {
    *parent = curr;
    curr = curr->left;
  }
  return(curr);
}

binaryTree_t* findParent(binaryTree_t *bt, binaryTree_t **parent, int item)
{
  if ((isBinaryTreeEmpty(bt)) || bt->item == item)
  {
    return(bt);
  }
  else if (bt->item > item)
  {
    *parent = bt;
    return(findParent(bt->left, parent, item));
  }
  else
  {
    *parent = bt;
    return(findParent(bt->right, parent, item));
  }
}

void deleteInBinaryTree(binaryTree_t **bt, int item)
{
  printf("Removing node: %d...", item); fflush(stdout);
  binaryTree_t *atual = (*bt), *toRemove, *parent = NULL, *successor;
  if (isBinaryTreeEmpty(atual)) return;

  toRemove = findParent(atual, &parent, item);

  if (isBinaryTreeEmpty(toRemove)) return;

  if (!isBinaryTreeEmpty(toRemove->left) && !isBinaryTreeEmpty(toRemove->right))
  {
    parent = toRemove;
    successor = toRemove->right;

    successor = minimumNode(successor, &parent);

    toRemove->item = successor->item;
    toRemove = successor;
  }

  if (isBinaryTreeEmpty(toRemove->left) && isBinaryTreeEmpty(toRemove->right))
  {
    if (parent != NULL)
    {
      if (parent->right == toRemove)
        parent->right = NULL;
      else
        parent->left = NULL;
    }

    if (toRemove == (*bt))
      (*bt) = NULL;
    else
      free(toRemove);
    return;
  }

  if (!isBinaryTreeEmpty(toRemove->left) && isBinaryTreeEmpty(toRemove->right))
  {
    if (parent == NULL)
    {
      parent = (*bt);
      (*bt) = (*bt)->left;
      free(parent);
      return;
    }
    if (parent->left == toRemove)
      parent->left = toRemove->left;
    else
      parent->right = toRemove->left;

    free(toRemove);
    return;
  }

  if (isBinaryTreeEmpty(toRemove->left) && !isBinaryTreeEmpty(toRemove->right))
  {
    if (parent == NULL)
    {
      parent = (*bt);
      (*bt) = (*bt)->right;
      free(parent);
      return;
    }
    if (parent->left == toRemove)
      parent->left = toRemove->right;
    else
      parent->right = toRemove->right;

    free(toRemove);
    return;
  }
}

void destroyBinaryTree(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    destroyBinaryTree(bt->left);
    destroyBinaryTree(bt->right);
    free(bt);
  }
}
