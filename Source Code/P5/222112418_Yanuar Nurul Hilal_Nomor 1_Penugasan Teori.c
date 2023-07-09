#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *prev;
    struct node *next;
};
struct node *create_node(int);
struct node *create_node(int nilai)
{
    struct node *ptr = malloc(sizeof(*ptr));
    ptr->value = nilai;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}
void right_insert(struct node **tail, int nilai)
{
    struct node *new_node = create_node(nilai);
    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
}
void right_delete(struct node **tail)
{
    if (*tail == NULL)
    return;
    (*tail)->prev->next = NULL;
    *tail = (*tail)->prev;
}
void display(struct node *tail)
{
    struct node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d", ptr->value);
        if (ptr->prev != NULL)
        printf(" -> ");
        ptr = ptr->prev;
    }
}
int main()
{
    struct node *head = malloc(sizeof(*head));
    struct node *tail = head;
    struct node *dua;
    struct node *tiga;
    struct node *empat;
    struct node *lima;
    dua = malloc(sizeof(*dua));
    tiga = malloc(sizeof(*tiga));
    empat = malloc(sizeof(*empat));
    head->value = 10;
    head->prev = NULL;
    head->next = dua;
    dua->value = 20;
    dua->prev = head;
    dua->next = tiga;
    tiga->value = 30;
    tiga->prev = dua;
    tiga->next = empat;
    empat->value = 40;
    empat->prev = tiga;
    lima = create_node(50);
    empat->next = lima;
    lima->prev = empat;
    tail = head;
    while (tail->next != NULL)
    tail = tail->next;
    printf("Tampilan list dari tail\n");
    display(tail);
    printf("\nTampilan list setelah insert kanan : \n");
    right_insert(&tail, 60);
    display(tail);
    printf("\nTampilan list setelah delete kanan : \n");
    right_delete(&tail);
    display(tail);
    return 0;
}