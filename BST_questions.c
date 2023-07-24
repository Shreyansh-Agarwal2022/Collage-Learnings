#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* create(int data)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

node* insert(node* root,int data)
{
    if(root==NULL)
        root=create(data);
    else if(root->data > data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

int findMin(node* root)
{
    if(root==NULL)
        return 0;
    while(root->left!=NULL)
        root=root->left;
    return (root->data);
}

node* delete(node* root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data > key)
    {
        root->left=delete(root->left,key);
    }
    else if(root->data < key)
    {
        root->right=delete(root->right,key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
            root=NULL;
        else if (root->left ==  NULL)
            root=root->right;
        else if (root->right ==NULL)
            root=root->left;
        else
        {
            root->data=findMin(root->right);
            root->right=delete(root->right,root->data);
        }
    }
    return root;
}

node* inorder(node* root)
{
    if(root!=NULL)
    {
        //printf("%d\n",root->data);
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

int check(node* root)
{
    if (root==NULL)
        return 1;
    if (root->left!=NULL && root->left->data > root->data)
        return 0;
    if (root->right!=NULL && root->right->data < root->data)
        return 0;
    return (check(root->left) && check(root->right));
}

node* parent(node* root,int data)
{
    if (root==NULL)
        return NULL;
    else if ((root->left != NULL && root->left->data == data) || (root->right != NULL && root->right->data == data))
        return root;
    else if (root->data > data)
        return parent(root->left,data);
    else if (root->data < data)
        return parent(root->right,data);
    return NULL;
}

int search(node* root,int key)
{
    if (root==NULL)
        return 0;
    else if (root->data == key)
        return 1;
    else if (root->data > key)
        return search(root->left,key);
    else
        return search(root->right,key);
}

int pairs(node* root1,node* root2,int key)
{
    int count=0,l,r;
    if (root1==NULL || root2==NULL)
        return 0;
    else
    {
        if(search(root2,key - root1->data))
            count=1;
        l=pairs(root1->left,root2,key);
        r=pairs(root1->right,root2,key);
    }
    return (count+l+r);
}

int countLeaf(node* root)
{
    int l=0,r=0;
    if (root==NULL)
        return 0;
    else if (root->left==NULL && root->right==NULL)
        return 1;
    else
    {
        l=countLeaf(root->left);
        r=countLeaf(root->right);
    }
    return (l+r);
}

int countNonLeaf(node* root)
{
    int l=0,r=0;
    if (root==NULL)
        return 0;
    else if (root->left==NULL && root->right==NULL)
        return 0;
    else
    {
        l=countNonLeaf(root->left);
        r=countNonLeaf(root->right);
    }
    return (1+l+r);
}

node* lca(node* root,int a,int b)
{
    if (root==NULL)
        return NULL;
    else if (!(search(root,a) && search(root,b)))
        return NULL;
    else if (root->data > a && root->data > b)
        return lca(root->left,a,b);
    else if (root->data < a && root->data < b)
        return lca(root->right,a,b);
    else
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
    int l,r;
    if(root==NULL)
        return 0;
    else
    {
        l=height(root->left);
        r=height(root->right);
    }
    return (1+max(l,r));
}

int count(node* root)
{
    int l,r;
    if(root==NULL)
        return 0;
    else
    {
        l=count(root->left);
        r=count(root->right);
    }
    return (1+l+r);
}

int k_small(node* root,int k)
{
    int c = count(root->left) + 1;
    if (root==NULL)
        return 0;
    else if (k == c)
        return root->data;
    else if (k < c)
        return k_small(root->left,k);
    else
    {
        k = k - c;
        return k_small(root->right,k);
    } 
}

int k_large(node* root,int k)
{
    int c = count(root->right) + 1;
    if (root==NULL)
        return 0;
    else if (k == c)
        return root->data;
    else if (k < c)
        return k_large(root->right,k);
    else
    {
        k = k - c;
        return k_large(root->left,k);
    } 
}

int depth(node* root,int key,int d)
{
    if (root==NULL)
        return 0;
    else if (root->data == key)
        return d;
    else if (root-> data > key)
    {
        d++;
        return depth(root->left,key,d);
    }
    else
    {
        d++;
        return depth(root->right,key,d);
    }
}

int main() {
    node* root=NULL;
    root=insert(root,10);
    root=insert(root,1);
    root=insert(root,100);
    root=insert(root,30);
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,7);
    node* root1=NULL;
    root1=insert(root1,20);
    root1=insert(root1,2);
    root1=insert(root1,13);
    root1=insert(root1,4);
    root1=insert(root1,100);
    root1=insert(root1,35);
    root1=insert(root1,31);
    root1=insert(root1,40);
    //int pair=pairs(root,root1,50);
    //printf("Pairs : %d\n",pair);
    //root=delete(root,10);
    //root->right->left->data=7;
    //printf("%d\n",check(root));
    //printf("%d\n",search(root,30));
    //inorder(root);
    //inorder(root1);

    //printf("%d\n",parent(root,100)->data);
    //printf("%d\n",lca(root,100,1)->data);
    //printf("%d\n",height(root));
    //printf("%d\n",k_small(root,7));
    //printf("%d\n",k_large(root,2));
    //printf("%d\n",depth(root,4,0));
    printf("%d\n",countNonLeaf(root1));
}