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
ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari)
{
    // cari node sebelumnya, mulai dari the first node
    ptrnode cursor = head;
    while (cursor->value != nilai_dicari)
    cursor = cursor->next;
    ptrnode newnode = createnode(nilai);
    newnode->next = cursor->next;
    cursor->next->prev = newnode;
    newnode->prev = cursor;
    cursor->next = newnode;
    return (head);
}
ptrnode insert_before(ptrnode head, int nilai, int next_nilai)
{
    if (head->value == next_nilai)
    head = insert_head(head, nilai);
    else
    {
        // pencarian nilai sama seperti insert after
        ptrnode cursor = head;
        while (cursor->value != next_nilai)
        cursor = cursor->next;
        ptrnode newnode = createnode(nilai);
        newnode->prev = cursor->prev;
        cursor->prev->next = newnode;
        newnode->next = cursor;
        cursor->prev = newnode;
    }
    return (head);
}

ptrnode remove_first(ptrnode head)
{
    if (head == NULL)
    return NULL;
    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;
    free(first);
    return (head);
}

ptrnode remove_last(ptrnode head)
{
    if (head == NULL)
    return NULL;
    // cursor bantuan satu lagi (prev_tail) tidak dibutuhkan
    ptrnode tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail = tail->prev;
    tail->next = NULL;
    free(tail->next);
    return (head);
}

ptrnode remove_middle(ptrnode head, int nilai)
{
    ptrnode cursor = head;
    while (cursor != NULL)
    {
        if (cursor->next->value == nilai)
        break;
        cursor = cursor->next;
    }
    if (cursor != NULL)
    {
        ptrnode tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next->prev = cursor;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }
    return (head);
}

ptrnode reversed(ptrnode head)
{
    ptrnode temp = NULL;
    ptrnode cursor = head;
    while (cursor != NULL)
    {
        temp = cursor->prev;
        cursor->prev = cursor->next;
        cursor->next = temp;
        cursor = cursor->prev;
        if (temp != NULL)
        head = temp->prev;
    }
    return (head);
}

void display(ptrnode head)
{
    ptrnode temp = head;
    printf("Start Pointer -> ");
    while (temp != NULL)
    {
        printf("%d", temp->value);
        if (temp->next != NULL)
        printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL");
}

int main()
{
    ptrnode head = NULL;
    ptrnode tail = NULL;
    ptrnode tiga = NULL;
    struct node node_dua;
    ptrnode dua = &node_dua;
    head = (ptrnode)malloc(sizeof(struct node));
    tiga = (ptrnode)malloc(sizeof(struct node));
    tail = head;
    head->value = 1;
    head->next = dua;
    head->prev = NULL;
    dua->value = 2;
    dua->next = tiga;
    dua->prev = head;
    tiga->value = 3;
    tiga->next = NULL;
    tiga->prev = dua;
    printf("Sebelum reverse :\n");
    display(head);
    printf("\n");
    head = reversed(head);
    printf("Setelah reverse :\n");
    display(head);
return 0;
}