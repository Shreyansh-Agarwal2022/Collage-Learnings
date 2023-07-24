#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int ht;
}node;
node* create(int data)
{
    node* root=(node*)malloc(sizeof(node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    root->ht=1;
    return(root);
}
int height(node* root)
{
    if(root==NULL)
        return(0);
    else
        return(root->ht);
}
int max(int a,int b)
{
    if(a<b)
        return(b);
    else
        return(a);
}
node* l_rotate(node* root)
{
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root->ht=1+max(height(root->left),height(root->right));
    temp->ht=1+max(height(temp->left),height(temp->right));
    root=temp;
    return(root);
}
node* r_rotate(node* root)
{
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root->ht=1+max(height(root->left),height(root->right));
    temp->ht=1+max(height(temp->left),height(temp->right));
    root=temp;
    return(root);
}
node* insert(node* root,int key)
{
    int bf;
    if(root==NULL)
        root=create(key);
    else if(root->data == key)
        return(root);
    else
    {
        if(root->data > key)
        {
            root->left=insert(root->left,key);
            bf=height(root->left) - height(root->right);
            if(bf>1)
            {
                if(key < root->left->data)
                    //LL
                    root=r_rotate(root);
                else
                {
                    //LR
                    root->left=l_rotate(root->left);
                    root=r_rotate(root);
                }
            }
        }
        else
        {
            root->right=insert(root->right,key);
            bf=height(root->left) - height(root->right);
            if(bf<-1)
            {
                if(key > root->right->data)
                    //RR
                    root=l_rotate(root);
                else
                {
                    //RL
                    root->right=r_rotate(root->right);
                    root=l_rotate(root);
                }
            }
        }
    }
    root->ht=1+max(height(root->left),height(root->right));
    return(root);
}
int findMin(node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return(root->data);
}
node* delete(node* root,int key)
{
    int bf;
    node* temp=NULL;
    if(root==NULL)
        return NULL;
    else if(root->data > key)
    {
        root->left=delete(root->left,key);
        bf=height(root->left) - height(root->right);
        if(bf<-1)
        {
            if(height(root->right->right) < height(root->right->left))
            {
                //RL
                root->right=r_rotate(root->right);
                root=l_rotate(root);
            }
            else
            {
                //RR
                root=l_rotate(root);
            }
        }
    }
    else if(root->data < key)
    {
        root->right=delete(root->right,key);
        bf=height(root->left) - height(root->right);
        if(bf>1)
        {
            if(height(root->left->right) > height(root->left->left))
            {
                //LR
                root->left=l_rotate(root->left);
                root=r_rotate(root);
            }
            else
            {
                //LL
                root=r_rotate(root);
            }
        }
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            return(NULL);
        }
        else if(root->left==NULL)
        {
            temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            root->data=findMin(root->right);
            root->right=delete(root->right,root->data);
        }
    }
    root->ht=1+max(height(root->left),height(root->right));
    return(root);
}
void preorder(node* root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    node* root=NULL;
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,10);
    /*root=delete(root,1);
    root=delete(root,4);
    root=delete(root,3);*/
    preorder(root);
    return 0;
}

//Some more code

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int ht;
}node;

node* create(int value)
{
    node* root = (node*)malloc(sizeof(node));
    
    root->ht = 1;
    root->data = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

int max(int a,int b)
{
    if (a>=b)
        return a;
    return b;
}

int height(node* root)
{
    if (root==NULL)
        return 0;
    return root->ht;
}

node* leftRotate(node* root)
{
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->ht = 1+max(height(root->left),height(root->right));
    temp->ht = 1+max(height(temp->left),height(temp->right));
    return temp;
}

node* rightRotate(node* root)
{
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->ht = 1+max(height(root->left),height(root->right));
    temp->ht = 1+max(height(temp->left),height(temp->right));
    return temp;
}

node* insert(node* root,int value)
{
    node* new = create(value);
    int bf;
    
    if (root==NULL)
        root=new;
    else
    {
        if (value < root->data)
            root->left = insert(root->left,value);
        else if (value > root->data)
            root->right = insert(root->right,value);
    }
    
    root->ht = 1+max(height(root->left),height(root->right));
    bf = height(root->left)  - height(root->right);
    
    if (bf > 1)
    {
        if (root->left->data < value)
            root->left=leftRotate(root->left);
        root=rightRotate(root);
    }
    else if (bf<-1)
    {
        if (root->right->data > value)
            root->right=rightRotate(root->right);
        root=leftRotate(root);
    }
    
    return root;
}

int findMin(node* root)
{
    while (root->left!=NULL)
        root=root->left;
    return root->data;
}

node* delete(node* root,int key)
{
    node* temp;
    int bf;
    
    if (root==NULL)
        return NULL;
    else if (root->data > key)
        root->left=delete(root->left,key);
    else if (root->data < key)
        root->right=delete(root->right,key);
    else
    {
        if (root->left!=NULL && root->right!=NULL)
        {
            temp=root;
            root=NULL;
            free(temp);
        }
        else if (root->left==NULL)
            root=root->right;
        else if (root->right==NULL)
            root=root->left;
        else
        {
            root->data=findMin(root->right);
            root->right=delete(root->right,root->data);
        }
    }
    if (root==NULL)
        return NULL;
    root->ht=1+max(height(root->left),height(root->right));
    bf = height(root->left) - height(root->right);
    
    if (bf > 1)
    {
        if (height(root->left->left) < height(root->left->right))
            root->left=leftRotate(root->left);
        root=rightRotate(root);
    }
    else if (bf<-1)
    {
        if (height(root->right->left) > height(root->right->right))
            root->right=rightRotate(root->right);
        root=leftRotate(root);
    }
    
    return root;
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    node* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,5);
    root=insert(root,4);
    
    root=delete(root,30);
    root=delete(root,40);
    
    preorder(root);
    
}
*/