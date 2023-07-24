#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}node;

void new(node*head,node**odd,node**even)
{
    node*e,*o;
    int i=0,j=0;
    while(head!=NULL)
    {
        if((head->data)%2==0)
        {
            if(i==0)
            {
                *even=(node*)malloc(sizeof(node));
                e=*even;
                e->data=head->data;
                e->next=NULL;
                head=head->next;
                i=1;
            }
            else
            {
                e->next=(node*)malloc(sizeof(node));
                e=e->next;
                e->data=head->data;
                e->next=NULL;
                head=head->next;
            }
        }
        else
        {
            if(j==0)
            {
                *odd=(node*)malloc(sizeof(node));
                o=*odd;
                o->data=head->data;
                o->next=NULL;
                head=head->next;
                j=1;
            }
            else
            {
                o->next=(node*)malloc(sizeof(node));
                o=o->next;
                o->data=head->data;
                o->next=NULL;
                head=head->next;
            }
        }
    }
}

void main() {
    node*head=(node*)malloc(sizeof(node));
    int i=0,data;
    char ch;
    node*n=head,*odd=NULL,*even=NULL;
    while(1)
    {
        printf("Enter number : ");
        scanf("%d",&data);
        n->data=data;
        printf("Do you want to add more[y/n] : ");
        getchar();
        ch=getchar();
        //printf("%c\n",ch);
        if(ch=='y')
        {
            n->next=(node*)malloc(sizeof(node));
            n=n->next;
        }
        else
            break;
    }
    n->next=NULL;
    new(head,&odd,&even);
    printf("Entries Are :\n");
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
    printf("Entries Even Are :\n");
    while(even!=NULL)
    {
        printf("%d\n",even->data);
        even=even->next;
    }
    printf("Entries Odd Are :\n");
    while(odd!=NULL)
    {
        printf("%d\n",odd->data);
        odd=odd->next;
    }
}