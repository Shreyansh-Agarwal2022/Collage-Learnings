#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    int data;
    struct node*next;
}node;
typedef struct
{
    node*front;
    node*rear;
}queue;
typedef struct
{
    node*top;
}stack;
void push(stack*s,int value)
{
    node*new;
    if(s->top==NULL)
    {
        s->top=(node*)malloc(sizeof(node));
        s->top->data=value;
        s->top->next=NULL;
        return;
    }
    new=(node*)malloc(sizeof(node));
    new->data=value;
    new->next=s->top;
    s->top=new;
    return;
}
int pop(stack*s)
{
    node*temp;
    int value;
    if(s->top==NULL)
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    temp=s->top;
    value=s->top->data;
    s->top=s->top->next;
    free(temp);
    return(value);
}
void enqueue(queue*q,int value)
{
    if(q->front==NULL)
    {
        q->rear=(node*)malloc(sizeof(node));
        q->rear->data=value;
        q->rear->next=NULL;
        q->front=q->rear;
        return;
    }
    q->rear->next=(node*)malloc(sizeof(node));
    q->rear=q->rear->next;
    q->rear->data=value;
    q->rear->next=NULL;
    return;
}
int dequeue(queue*q)
{
    int value;
    node*temp;
    if(q->front==NULL)
    {
        printf("Queue id Empty\n");
        return INT_MIN;
    }
    else if(q->front==q->rear)
    {
        temp=q->front;
        value=q->rear->data;
        q->rear=NULL;
        q->front=NULL;
        free(temp);
        return(value);
    }
    temp=q->front;
    value=q->front->data;
    q->front=q->front->next;
    free(temp);
    return(value);
}
int main() {
    char arr[50];
    int i,flag=0;
    int value;
    printf("Enter String : ");
    scanf("%s",arr);
    stack*s=(stack*)malloc(sizeof(stack));
    queue*q=(queue*)malloc(sizeof(queue));
    s->top=NULL;
    q->front=NULL;
    q->rear=NULL;
    
    /*push(s,10);
    push(s,80);
    push(s,70);
    push(s,60);
    printf("%d\n",pop(s));
    push(s,50);
    push(s,40);
    push(s,30);
    do
    {
        value=pop(s);
        printf("%d\n",value);
    }while(value!=INT_MIN);
    
    
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    printf("%d\n",dequeue(q));
    enqueue(q,50);
    enqueue(q,60);
    enqueue(q,70);
    enqueue(q,80);
    enqueue(q,90);
    do
    {
        value=dequeue(q);
        printf("%d\n",value); 
    }while(value!=INT_MIN);*/
    
    for(i=0;i<strlen(arr);i++)
    {
        push(s,tolower(arr[i]));
        enqueue(q,tolower(arr[i]));
    }
    for(i=0;i<strlen(arr);i++)
    {
        if(dequeue(q)!=pop(s))
            flag=1;
    }
    if(flag==0)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
}