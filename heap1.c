#include <stdio.h>
#include <stdlib.h>
int arr[100];
int n=0;
int parent(int i)
{
    return ((i-1)/2);
}
int lchild(int i)
{
    return (2*i+1);
}
int rchild(int i)
{
    return (2*i+2);
}
void insert(int data)
{
    arr[n++]=data;
    int i=n-1;
    int p=parent(i);
    int temp;
    while (i>0 && arr[i]>arr[p])
    {
        temp=arr[i];
        arr[i]=arr[p];
        arr[p]=temp;
        i=p;
        p=parent(i);
    }
    printf("Done %d\n",data);
}
int delete()
{
    int result,temp;
    int lc,rc,i,largest;
    if (n==0)
        return 0;
    else if (n==1)
    {
        result=arr[n-1];
        arr[--n]=0;
        return result;
    }
    result=arr[0];
    arr[0]=arr[n-1];
    arr[--n]=0;
    i=0;
    largest=i;
    lc=lchild(i);
    rc=rchild(i);
    while ((lc<n && arr[lc]>arr[i]) || (rc<n && arr[rc]>arr[i]))
    {
        if (lc<n && arr[lc]>arr[largest])
            largest=lc;
        if (rc<n && arr[rc]>arr[largest])
            largest=rc;
        if (largest!=i)
        {
            temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            i=largest;
            lc=lchild(i);
            rc=rchild(i);
        }
        else
            break;
    }
    return result;
}
int main() {
    int i;
    insert(10);
    insert(100);
    insert(-2);
    insert(111);
    insert(122);
    insert(2);
    insert(15);
    insert(-12);
    insert(1200);
    insert(17);
    printf("%d\n\n",delete());
    printf("%d\n\n",delete());
    printf("%d\n\n",delete());
    printf("%d\n\n",delete());
    printf("%d\n\n",delete());
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
