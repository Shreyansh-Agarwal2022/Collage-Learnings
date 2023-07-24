#include <stdio.h>
#include <stdlib.h>

int arr[20];
int N=0;

void insert(int data)
{
    arr[++N]=data;
    int n=N;
    while (n/2>0 && arr[n/2]<data)
    {
        arr[n]=arr[n/2];
        n=n/2;
    }
    arr[n]=data;
}
void heapify(int i,int n)
{
    int lc=2*i;
    int rc=2*i+1;
    int largest=i;
    int temp;
    if(lc<n && arr[lc]>arr[largest])
        largest=lc;
    if(rc<n && arr[rc]>arr[largest])
        largest=rc;
    if (largest!=i)
    {
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(largest,n);
    }
}
int delete()
{
    int result=arr[1];
    arr[1]=arr[N];
    arr[N]=0;
    heapify(1,N);
    N--;
    return result;
}


int main() {
    insert(10);
    insert(-2);
    insert(100);
    insert(-10);
    insert(2);
    insert(111);
    insert(12);
    
    printf("Deleted : %d\n",delete());
    printf("Deleted : %d\n",delete());
    /*printf("Deleted : %d\n",delete());
    printf("Deleted : %d\n",delete());
    printf("Deleted : %d\n",delete());
    printf("Deleted : %d\n",delete());
    printf("Deleted : %d\n",delete());*/
    
    for(int i=0;i<20;i++)
    {
        printf("%d\t",arr[i]);
    }
}

//Heap Sort

/*

#include <stdio.h>

void heapify(int arr[],int i,int n)
{
    int lc=2*i+1;
    int rc=2*i+2;
    int largest=i;
    int temp;
    if(lc<n && arr[lc]>arr[largest])
        largest=lc;
    if(rc<n && arr[rc]>arr[largest])
        largest=rc;
    if (largest!=i)
    {
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,largest,n);
    }
}

void heapsort(int arr[],int n)
{
    int temp;
    for (int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,0,i);
    }
    
}

int main() {
    int arr[]={10,100,2,12,-2,111,-12,-11,14};
    heapsort(arr,9);
    for(int i=0;i<9;i++)
    {
        printf("%d\t",arr[i]);
    }
}

*/
