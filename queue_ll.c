#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
    int data;
    struct node*next;
}node;
typedef struct
{
    node*front;
    node*rear;
    int size;
}queue;
queue*create(void)
{
    queue*temp=(queue*)malloc(sizeof(queue));
    temp->front=temp->rear=NULL;
    temp->size=0;
    return(temp);
}
void push(queue*q,int item)
{
    if(q->rear==NULL)
    {
        q->rear=(node*)malloc(sizeof(node));
        q->rear->data=item;
        q->rear->next=NULL;
        q->front=q->rear;
        q->size=1;
        return;
    }
    else
    {
        q->rear->next=(node*)malloc(sizeof(node));
        q->rear=q->rear->next;
        q->rear->data=item;
        q->rear->next=NULL;
        q->size+=1;
        return;
    }
}
int pop(queue*q)
{
    node*temp=NULL;
    int value;
    if(q->front==NULL)
    {
        printf("UnderFlow\n");
        return(INT_MIN);
    }
    else
    {
        temp=q->front;
        value=q->front->data;
        if(q->rear==q->front)
        {
            q->rear=q->front=NULL;
            q->size=0;
        }
        else
        {
            q->front=q->front->next;
            q->size-=1;
        }
        free(temp);
        return(value);
    }
}
int peek(queue*q)
{
    int value;
    if(q->front==NULL)
    {
        printf("UnderFlow\n");
        return(INT_MIN);
    }
    else
    {
        value=q->front->data;
        return(value);
    }
}
void main()
{
    queue*q=create();
    push(q,10);
    push(q,20);
    push(q,30);
    //push(q,40);
    //push(q,50);
    printf("%d %d\n",pop(q),q->size);
    printf("%d %d\n",pop(q),q->size);
    printf("%d %d\n",peek(q),q->size);
    printf("%d %d\n",pop(q),q->size);
    printf("%d %d\n",pop(q),q->size);
}