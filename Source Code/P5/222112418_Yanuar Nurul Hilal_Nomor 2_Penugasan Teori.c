#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *ptrnode;
ptrnode createnode(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return (p);
}
ptrnode insert_head(ptrnode head, int nilai)
{
    ptrnode newnode = createnode(nilai);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return (head);
}
ptrnode insert_tail(ptrnode head, int nilai)
{
    // perulangan mencari node terakhir
    ptrnode tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    // buat node baru
    ptrnode newnode = createnode(nilai);
    tail->next = newnode;
    return (head);
}
void display(ptrnode head)
{
    int count = 1;
    ptrnode temp = head;
    while (temp != NULL)
    {
        printf("node %d : %d \n", count, temp->value);
        count++;
        temp = temp->next;
    }
}
int main()
{
    int n, data, add, loop;
    loop = 1;
    struct node *head;
    printf("Input the number of node : ");
    scanf("%d", &n);
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
                printf("Input data for node %d : ", i + 1);
                scanf("%d", &data);
            {
                if (i == 0)
                {
                    head = createnode(data);
                }
                else
                {
                head = insert_tail(head, data);
                }
            }
        }
        printf("\nData entered in the list are : \n");
        display(head);
    }

    while (loop == 1)
    {
        printf("Input data for the first node : ");
        scanf("%d", &data);
        if (data != 0)
        {
        head = insert_head(head, data);
        printf("\nAfter insertion the new list are : \n");
        display(head);
        }
        else
        {
        loop = 0;
        }
    }
return 0;
}