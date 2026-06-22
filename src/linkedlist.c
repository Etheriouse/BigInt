#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "macro.h"

linked_list *create_list()
{
    linked_list *list = (linked_list *)malloc(sizeof(linked_list));
    if (list == NULL)
        return NULL;
    *list = NULL;
    return list;
}

void free_list(linked_list *list, void (*free_data)(void *))
{
    CHECK_NOT_NULL_VOID(list);
    link_node *current = (*list);
    link_node *next;
    while (current != NULL)
    {
        next = current->next;
        if (free_data != NULL)
        {
            free_data(current->data);
        }
        free(current);
        current = next;
    }
    free(list);
}

void push(linked_list *list, void *data)
{
    CHECK_NOT_NULL_VOID(list);
    link_node *current = *list;
    link_node *new = (link_node *)malloc(sizeof(link_node));
    new->next = NULL;
    new->data = data;
    if (current == NULL)
    {
        *list = new;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = new;
}

link_node *pop(linked_list *list)
{
    CHECK_NOT_NULL_PTR(list);
    link_node *current = *list;
    if (current == NULL)
        return NULL;
    if (current->next == NULL)
    {
        *list = NULL;
        return current;
    }
    while (current->next->next != NULL)
        current = current->next;
    link_node *last;
    last = current->next;
    current->next = NULL;
    return last;
}

void print_list(linked_list *list, void (*print)(void *))
{
    CHECK_NOT_NULL_VOID(list);
    CHECK_NOT_NULL_VOID(print);
    link_node *current = *list;
    printf("{");
    if (current != NULL)
    {
        while (current->next != NULL)
        {
            print(current->data);
            printf(", ");
            current = current->next;
        }
        print(current->data);
    }
    printf("}\n");
}

link_node *__sort_node(link_node *n, int (*cmp)(void *, void *));

void sort_list(linked_list *list, int (*cmp)(void *, void *))
{
    CHECK_NOT_NULL_VOID(list);
    CHECK_NOT_NULL_VOID(cmp);
    *list = __sort_node(*list, cmp);
}

link_node *__merge_list(link_node *l1, link_node *l2, int (*cmp)(void *, void *));
void __split_list(link_node *list, link_node **start, link_node **mid);

link_node *__sort_node(link_node *n, int (*cmp)(void *, void *))
{
    link_node *l1 = NULL;
    link_node *l2 = NULL;
    if(n == NULL || n->next == NULL) return n;
    __split_list(n, &l1, &l2);
    return __merge_list(__sort_node(l1, cmp), __sort_node(l2, cmp), cmp);
}

void __split_list(link_node *list, link_node **start, link_node **mid)
{
    UNUSED(start);
    UNUSED(mid);

    link_node *fast = list;
    link_node *slow = list;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    *mid = slow->next;
    slow->next = NULL;
    *start = list;
}

link_node *__merge_list(link_node *l1, link_node *l2, int (*cmp)(void *, void *))
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    link_node dummy;
    link_node *current = &dummy;

    while (l2 != NULL && l1 != NULL)
    {
        if (cmp(l1->data, l2->data) < 0)
        { // if pos a < b
            current->next = l1;
            l1 = l1->next;
            current = current->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
            current = current->next;
        }
    }

    if (l1 != NULL)
        current->next = l1;
    else
        current->next = l2;

    return dummy.next;
}

void *get_list(linked_list *list, unsigned int index)
{
    CHECK_NOT_NULL_PTR(list);
    link_node *current = *list;
    unsigned int i = 0;
    while(current != NULL) {
        if(i == index) return current->data;
        i++;
        current = current->next;
    }
    return NULL;
}

void insert_list(linked_list *list, unsigned int index, void *data)
{
    CHECK_NOT_NULL_VOID(list);
    link_node *current = *list;
    unsigned int i = 1;
    while(current != NULL) {
        if(i == index) {
            link_node *new = (link_node *)malloc(sizeof(link_node));
            new->next = current->next;
            new->data = data;
            current->next = new;
            return;
        }
        i++;
        current = current->next;
    }
}