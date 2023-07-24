//AVL Tree
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
    int height;
}node;
node*create(int key)
{
    node*root=(node*)malloc(sizeof(node));
    root->data=key;
    root->left=NULL;
    root->right=NULL;
    root->height=1;
    return root;
}
int max(int a,int b)
{
    if (a>=b)
        return a;
    else
        return b;
}
int get_h(node*root)
{
    if (root==NULL)
    {
        return 0;
    }
    return(root->height);
}
node* lrotate(node* root) {
    node* x = root->right;
    node* y = x->left;
    x->left = root;
    root->right = y;
    root->height = 1 + max(get_h(root->left), get_h(root->right));
    x->height = 1 + max(get_h(x->left), get_h(x->right));
    return x;
}
node* rrotate(node* root) {
    node* x = root->left;
    node* y = x->right;
    x->right = root;
    root->left = y;
    root->height = 1 + max(get_h(root->left), get_h(root->right));
    x->height = 1 + max(get_h(x->left), get_h(x->right));
    return x;
}
node*insert(node*root,int key)
{
    node*new=create(key);
    node*temp=root;
    int bf;
    if (root==NULL)
    {
        return new;
    }
    if (temp->data>key)
    {
        root->left=insert(root->left,key);
    }
    else if (temp->data<key)
    {
        root->right=insert(root->right,key);
    }
    root->height=1+max(get_h(root->left),get_h(root->right));
    bf=get_h(root->left)-get_h(root->right);
    if(bf>1 && key<root->left->data)
    {
        //LL
        root=rrotate(root);
    }
    else if (bf>1 && key>root->left->data)
    {
        //RL
        root->left=lrotate(root->left);
        root=rrotate(root);
    }
    else if (bf<-1 && key > root->right->data)
    {
        //RR
        root=lrotate(root);
    }
    else if (bf<-1 && key < root->right->data)
    {
        //LR
        root->right=rrotate(root->right);
        root=lrotate(root);
    }
    return root;
}
void preorder(node* root)
{
    if (root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    node*root=create(3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,6);
    preorder(root);
}