#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack{
    struct node *top;
}Stack;

typedef struct node{
    int item;
    struct node *next;
}Node;

void print(Node *node){
    Node *cursor;
    cursor=node;
    while(cursor!=NULL){
      printf("%d ",cursor->item);
      cursor=cursor->next;
    }
    printf("\n");
}
Node *HEAD(Node *node, int item){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->item=item;
    new_node->next=NULL;
    //printf("Cabeca: %d\n",new_node->item);
    return new_node;
}

Node *add_end(Node *node, int item){
    Node *cursor;
    cursor=node;
    if(node==NULL){//criar cabeca
        printf("cabeca nula\n");
        return HEAD(node,item);
    }else{
        Node *new_node=(Node*)malloc(sizeof(Node));
        while(cursor->next!=NULL){
           cursor=cursor->next;
        }
        new_node->item=item;
        cursor->next=new_node;
        return node;
    }

}

Stack *creat_stack(){
    Stack *new_stack= (Stack*)malloc(sizeof(Stack));
    new_stack->top=NULL;
    return new_stack;
}

int pop(Stack *stack){
    Node *aux;
    int valor;
    aux=stack->top;
    valor= aux->item;
    stack->top=stack->top->next;
    printf("VALOR: %d\n",valor);
    free(stack);
    return valor;
}

void push(Stack *stack,  int item){
    Node *new_top=(Node*)malloc(sizeof(Node*));
    new_top->item=item;
    printf("New TOP: %d\n",new_top->item);
    new_top->next=stack->top;
    stack->top=new_top;
    //printf("TOPO da stack %d\n",stack->top->item);
}

int items(Node *node){
    int num;
    char end;
    if(node==NULL){
        //printf("aqui\n");
    }

    scanf("%d%c",&num,&end);

    if(end=='\n'){
        return node;
    }else{
        printf("Numero a ser add: %d\n",num);
        node=add_end(node,num);
        //print(node);
        items(node);
    }
}

void read(Stack *stack){

    char comando[5];
    if(scanf("%s",comando)==EOF){
        printf("OK!");
        return;
    }else{
        printf("%s",comando);
        printf("\n");
        Node *list;
        list=NULL;
        list=items(list);
        print(list);
        //printf("CABECA: %d\n",head);
        printf("LISTA: %d\n",list->item);
        if(comando[1]=='O'){
            pop(stack);
        }else{
          push(stack,list->item);
        }

       if(comando[1]=='U'){
            printf("chegou aqui\n");
            push(stack,list);
        }else{

       }
        read(stack);
    }

}

int main() {
    Stack *stack1;
    stack1=creat_stack();
    read(stack1);
	return 0;
}