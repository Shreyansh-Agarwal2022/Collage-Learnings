#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;

node* create(int key)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}

int max(int a, int b)
{
    return (a<b ? b : a);
}

int height(node* root)
{
    if (root==NULL)
        return 0;
    else
        return(root->height);
}

node* left_rotate(node* root)
{
    node* temp = root->right;
    root->right=temp->left;
    temp->left=root;
    root=temp;
    root->height=1+max(height(root->left),height(root->right));
    root->left->height=1+max(height(root->left->left),height(root->left->right));
    return root;
}

node* right_rotate(node* root)
{
    node* temp = root->left;
    root->left=temp->right;
    temp->right=root;
    root=temp;
    root->height=1+max(height(root->left),height(root->right));
    root->right->height=1+max(height(root->right->left),height(root->right->right));
    return root;
}

node* insert(node* root,int key)
{
    int bf;
    if (root==NULL)
        return create(key);
    else if (root->data==key)
        return root;
    else if (root->data<key)
        root->right=insert(root->right,key);
    else
        root->left=insert(root->left,key);
    root->height=1+max(height(root->left),height(root->right));
    bf = height(root->left) - height(root->right);

    if (bf>1)
    {
        //LL
        if (height(root->left->left) < height(root->left->right))
        {
            //LR
            root->left=left_rotate(root->left);
        }
        root=right_rotate(root);
    }
    else if (bf<-1)
    {
        //RR
        if (height(root->right->left) > height(root->right->right))
        {
            //RL
            root->right=right_rotate(root->right);
        }
        root=left_rotate(root);

    }
    return root;
}

int findMin(node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return(root->data);
}

node* delete(node* root,int key)
{
    int del;
    if (root==NULL)
    {
        return NULL;
    }
    else if (root->data < key)
    {
        root->right=delete(root->right,key);
    }
    else if (root->data > key)
    {
        root->left=delete(root->left,key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            root=root->right;
        }
        else if (root->right == NULL)
        {
            root=root->left;
        }
        else
        {
            del = findMin(root->right);
            root->data=del;
            root->right=delete(root->right,del);
        }
    }
    return root;
}

void inorder(node* root)
{
    if (root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

int main(void)
{
    node* root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,25);
    root=insert(root,22);
    root=insert(root,27);
    root=insert(root,2);
    root=insert(root,7);
    root=insert(root,70);
    inorder(root);
    
}
