#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
    struct node*prev;
}node;
int prime(int num)
{
    if(num==0 || num==1)
    {
        //printf("a\n");
        return 1;
    }
    int temp=num/2;
    int flag=0;
    for(int i=2;i<=temp;i++)
    {
        if(num%i==0)
        {
            //printf("b\n");
            return 1;
        }
    }
    //printf("c\n");
    return 0;
    
}
void append(node**head,int value)
{
    node*new=(node*)malloc(sizeof(node));
    node*temp;
    new->data=value;
    new->next=NULL;
    if(*head==NULL)
    {
        new->prev=NULL;
        *head=new;
        return;
    }
    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
        return;
    }
}
void delete(node**head,int key)
{
    node*temp=*head;
    if(*head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*head)->data==key)
    {
        (*head)=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Key not found\n");
        return;
    }
    else
    {
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        if(temp->prev!=NULL)
            temp->prev->next=temp->next;
        free(temp);
        return;
    }
}
int main() {
    node*head=NULL;
    node*new=NULL;
    node*temp=NULL;
    int i,n;
    for(i=1;i<101;i++)
    {
        append(&head,i);
    }
    temp=head;
    while(temp!=NULL)
    {
        node*prev=temp->prev;
        if(prime(temp->data)==0)
        {
            int num=temp->data;
            delete(&head,num);
            append(&new,num);
            temp=prev->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    
    while(head->next!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("%d\nHi\n",head->data);
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->prev;
    }
    printf("\nHi\n");
    while(new!=NULL)
    {
        printf("%d\t",new->data);
        new=new->next;
    }
}