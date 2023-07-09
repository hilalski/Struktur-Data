#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* insert(struct node* root, int newdata){
    if(root==NULL)
        root=newnode(newdata);
    else
    {
        int is_left=0;
        struct node* cursor=root;
        struct node* prev=NULL;
        while(cursor != NULL)
        {
            prev=cursor;
            if(newdata < cursor->data)
            {
                is_left=1;
                cursor=cursor->left;
            }
            else if (newdata > cursor->data)
            {
                is_left=0;
                cursor=cursor->right;
            }
        }
        if(is_left==1)
            prev->left=newnode(newdata);
        else
            prev->right=newnode(newdata);
    }
    return root;
};


void displaypreorder(struct node* node){
    if(node==NULL)
        return;
    printf("%d ",node->data);
    displaypreorder(node->left);
    displaypreorder(node->right);
}

void displayinorder(struct node* node){
    if(node==NULL)
        return;
    displayinorder(node->left);
    printf("%d ",node->data);
    displayinorder(node->right);
}

void displaypostorder(struct node* node){
    if(node==NULL)
        return;
    displaypostorder(node->left);
    displaypostorder(node->right);
    printf("%d ",node->data);
}

int main(){
    struct node* root=newnode(20);

    root=insert(root,5);
    root=insert(root,1);
    root=insert(root,15);
    root=insert(root,9);
    root=insert(root,7);
    root=insert(root,12);
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,40);
    root=insert(root,45);
    root=insert(root,42);

    printf("Tampilan pre order : \n");
    displaypreorder(root);
    printf("\nTampilan in order : \n");
    displayinorder(root);
    printf("\nTampilan post order : \n");
    displaypostorder(root);
    printf("\n");
    
    return 0;
}
