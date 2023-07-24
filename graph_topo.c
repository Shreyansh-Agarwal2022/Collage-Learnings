#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10
int graph1[MAX][MAX];

void addEdge(int u,int v)
{
    if (u==v || v>=MAX || u>=MAX)
        return;
    graph1[u][v]=1;
    graph1[v][u]=1;
}

typedef struct node
{
    int data;
    struct node* next;
}node;

typedef struct
{
    node* top;
}stack;

typedef struct
{
    node* front;
    node* tail;
}queue;

node* create(int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

stack* createStack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=NULL;
    return s;
}

queue* createQueue()
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->tail=NULL;
    return q;
}

void push(stack* s,int data)
{
    node* temp=s->top;
    s->top=create(data);
    s->top->next=temp;
}

int pop(stack* s)
{
    node* temp;
    int result;
    if (s->top==NULL)
        return (INT_MIN);
    result=s->top->data;
    temp=s->top;
    s->top=s->top->next;
    free(temp);
    return result;
}

void enqueue(queue* q,int data)
{
    if(q->front==NULL)
    {
        q->front=create(data);
        q->tail=q->front;
    }
    else
    {
        q->tail->next=create(data);
        q->tail=q->tail->next;
    }
}

int dequeue(queue* q)
{
    node* temp;
    int result;
    if(q->front==NULL)
        return INT_MIN;
    else if(q->front==q->tail)
    {
        temp=q->front;
        q->front=NULL;
        q->tail=NULL;
        result=temp->data;
        free(temp);
        return result;
    }
    else
    {
        temp=q->front;
        q->front=q->front->next;
        result=temp->data;
        free(temp);
        return result;
    }
}

node* append(node* head,int data)
{
    node* temp;
    if (head==NULL)
        head=create(data);
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==data)
                return head;
            temp=temp->next;
        }
        if(temp->data==data)
                return head;
        temp->next=create(data);
    }
    return head;
}

node* graph[MAX]={NULL};

void addedge(int u,int v)
{
    if(u>=MAX || v>=MAX || u==v)
        return;
    graph[u]=append(graph[u],v);
}

void printGraph()
{
    node* temp;
    for(int i=0;i<MAX;i++)
    {
        temp=graph[i];
        printf("\n[%d] -> ",i);
        while(temp!=NULL)
        {
            printf("%d, ",temp->data);
            temp=temp->next;
        }
    }
}

/*void bfs(int sv)
{
    int curr;
    node* temp;
    int visited[MAX]={0};
    queue* q=createQueue();
    enqueue(q,sv);
    visited[sv]=1;
    printf("\nBFS :\n");
    while(q->front!=NULL)
    {
        curr=dequeue(q);
        printf("%d\n",curr);
        temp=graph[curr];
        while(temp!=NULL)
        {
            if(visited[temp->data]==0)
            {
                enqueue(q,temp->data);
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}

void dfs(int sv)
{
    int curr;
    node* temp;
    int visited[MAX]={0};
    stack* s=createStack();
    push(s,sv);
    visited[sv]=1;
    printf("\nDFS :\n");
    while(s->top!=NULL)
    {
        curr=pop(s);
        printf("%d\n",curr);
        temp=graph[curr];
        while(temp!=NULL)
        {
            if(visited[temp->data]==0)
            {
                push(s,temp->data);
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}*/

void topo()
{
    int visited[MAX]={0};
    int in[MAX]={0};
    int curr;
    int i,j;
    node* temp;
    queue* q=createQueue();
    for(i=0;i<MAX;i++)
    {
        temp=graph[i];
        while(temp!=NULL)
        {
            in[temp->data]+=1;
            temp=temp->next;
        }
    }
    for(i=0;i<MAX;i++)
    {
        if(in[i]==0)
        {
            enqueue(q,i);
            visited[i]=1;
        }
    }
    printf("\nTopological Order : \n");
    while(q->front!=NULL)
    {
        curr=dequeue(q);
        printf("%d\n",curr);
        temp=graph[curr];
        while(temp!=NULL)
        {
            in[temp->data]-=1;
            if(in[temp->data]==0)
            {
                visited[temp->data]=1;
                enqueue(q,temp->data);
            }
            temp=temp->next;
        }
    }
}

int main() 
{
    addedge(1,1);
    addedge(1,2);
    addedge(1,3);
    //addedge(2,3);
    addedge(1,3);
    addedge(1,4);
    addedge(3,5);
    addedge(6,6);
    addedge(8,0);
    addedge(0,5);
    
    printGraph();
    
    topo();
    
    //printf("Hi\n");
    /*addEdge(1,1);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(3,5);
    addEdge(6,6);
    addEdge(9,7);
    addEdge(8,0);
    
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
            printf("%d ",graph1[i][j]);
        printf("\n");
    }*/
}