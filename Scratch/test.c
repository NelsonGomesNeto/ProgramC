#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    void *item;
    struct n *next;
} node;

typedef struct
{
    int num;
} data;

node *add_node(node *head, void *item)
{
    node *new_node = (node *)(malloc(sizeof(node)));
    new_node->item = item;
    new_node->next = head;

    return new_node;
}

node *add_node_incre(node *head, void *item, int (*f_compair)(void *item_1, void *item_2))
{
    node *current = head, *previous = NULL;
    node *new_node = (node *)(malloc(sizeof(node)));
    new_node->item = item;

    if (current == NULL)
    {
        new_node->next = NULL;
        head = new_node;
    }
    else
    {
        while (current != NULL && f_compair(item, current->item) == 1)
        {
            previous = current;
            current = current->next;
        }

        new_node->next = current;

        if (previous == NULL)
        {
            head = new_node;
        }
        else
        {
            previous->next = new_node;
        }
    }

    return head;
}

void clear_list(node *head)
{
    node *node_aux;

    while (head != NULL)
    {
        node_aux = head->next;
        free(head);
        head = node_aux;
    }
}

node *search_list(node *head, void *item, int (*compair)(void *item1, void *item2))
{
    while ((head != NULL) && ((*compair)(head->item, item) != 1))
    {
        head = head->next;
    }

    return head;
}

node *check_intersection_list(node *head_1, node *head_2, int (*f_equal)(void *item_1, void *item_2), void *(*f_copy)(void *item), int (*f_hightest)(void *item_1, void *item_2))
{
    node *head_inters = NULL;
    node *aux_head_2;

    while (head_1 != NULL)
    {
        aux_head_2 = head_2;

        while (aux_head_2 != NULL)
        {
            if ((f_equal(head_1->item, aux_head_2->item) == 1))// && (search_list(head_inters, head_1->item, f_equal) == NULL))
            {
                head_inters = add_node(head_inters, f_copy(head_1->item));
                // head_inters = add_node_incre(head_inters, f_copy(head_1->item), f_hightest);
            }

            aux_head_2 = aux_head_2->next;
        }

        head_1 = head_1->next;
    }

    return head_inters;
}

void apply_all_list(node *head, void (*function)(void *item))
{
    while (head != NULL)
    {
        function(head->item);

        head = head->next;
    }
}

int compair_equal_data(void *_item_1, void *_item_2)
{
    data *item_1 = (data *)_item_1;
    data *item_2 = (data *)_item_2;

    if (item_1->num == item_2->num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int compair_hightest_data(void *_node_1, void *_node_2)
{
    data *node_1 = (data *)_node_1;
    data *node_2 = (data *)_node_2;

    if (node_1->num > node_2->num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

data *generate_data(int num)
{
    data *new_data = (data *)(malloc(sizeof(data)));
    new_data->num = num;

    return new_data;
}

void *copy_data(void *_old_data)
{
    data *old_data = (data *)_old_data;
    data *new_data = (data *)(malloc(sizeof(data)));

    new_data->num = old_data->num;

    return new_data;
}

void print_all_data(void *_item)
{
    data *item = (data *)_item;

    printf("%d\n", item->num);
}

int main()
{
    int i, aux;
    node *head_1 = NULL;
    node *head_2 = NULL;

    for (i = 0; i < 20; i++)
    {
        scanf("%d", &aux);
        head_1 = add_node(head_1, generate_data(aux));
    }

    for (i = 0; i < 20; i++)
    {
        scanf("%d", &aux);
        head_2 = add_node(head_2, generate_data(aux));
    }

    node *head_inters = check_intersection_list(head_1, head_2, compair_equal_data, copy_data, compair_hightest_data);

    if (head_inters != NULL)
    {
        apply_all_list(head_inters, print_all_data);
    }
    else
    {
        printf("VAZIO\n");
    }

    return 0;
}