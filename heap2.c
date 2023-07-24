#include <stdio.h>

void heapify(int arr[],int n,int i)
{
	int lc=2*i+1;
	int rc=2*i+2;
	int largest=i;
	int temp;
	while (lc<n)
	{
		if (lc<n && arr[lc]>arr[largest])
			largest=lc;
		if (rc<n && arr[rc]>arr[largest])
			largest=rc;
		if (largest!=i)
		{
			temp=arr[largest];
			arr[largest]=arr[i];
			arr[i]=temp;
			i=largest;
			lc=2*i+1;
			rc=2*i+2;
		}
		else
			break;
	}
}

void create_heap(int arr[],int n)
{
	int i;
	for (i=(n)/2-1;i>-1;i--)
	{
		heapify(arr,n,i);
	}
}


void heapsort(int arr[],int n)
{
	int i,temp;
	create_heap(arr,n);
	for(i=n-1;i>0;i--)
	{
		temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapify(arr,i,0);
	}
}

int isHeap(int arr[],int n)
{
	if (n==0 || n==1)
		return 1;
	int i,lc,rc;
	for(i=(n-1)/2;i>-1;i--)
	{
		lc=2*i+1;
		rc=2*i+2;
		if(lc<n && arr[lc]>arr[i])
			return 0;
		if(rc<n && arr[rc]>arr[i])
			return 0;
	}
	return 1;
}

int delete(int arr[],int* n)
{
	int result;
	if (*n==0)
		return 0;
	if (*n==1)
	{
		result=arr[*n-1];
		arr[*n-1]=0;
		*n=*n-1;
		return result;
	}
	result=arr[0];
	arr[0]=arr[*n-1];
	arr[*n-1]=0;
	*n=*n-1;
	heapify(arr,*n,0);
	return result;
}

/*void main1()
{
	int arr[]={100,30,12,40,2,200};
	int n=6;
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	//printf("Is Heap : %d\n",isHeap(arr,n));
	create_heap(arr,n);
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	printf("Is Heap : %d\n",isHeap(arr,n));
	
	//heapsort(arr,n);
	int res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	res=delete(arr,&n);
	printf("Deleted : %d\n",res);
	
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}*/

void printMenu()
{
	printf("\nMenu :\n\n");
	printf("1. Input Array\n");
	printf("2. Display Array\n");
	printf("3. Check whether the given array is max heap or not.\n");
	printf("4. To convert given array as max heap.\n");
	printf("5. Heap Sort the Given Array.\n");
	printf("6. Delete Max Element from Array.\n");
	printf("7. Exit.\n\n");
	printf("Enter Choice : ");
}

void display(int arr[],int n)
{
	int i;
	printf("{ ");
	for (i=0;i<n;i++)
		printf("%d, ",arr[i]);
	printf("}\n");
}

void make_array(int arr[],int* n)
{
	int data;
	printf("Enter Data in Array :\n\n");
	printf("Enter Positive Number : ");
	scanf("%d",&data);
	if(data<=0)
		return;
	while(data>0)
	{
		arr[*n]=data;
		*n=*n+1;
		printf("Enter Positive Number : ");
		scanf("%d",&data);
	}
	return;
}

void main()
{
	int arr[100]={0};
	int n=0,i,res,choice;
	int flag=1;
	while(1)
	{
		printMenu();
		scanf("%d",&choice);
		if (choice==1)
		{
			flag=0;
			make_array(arr,&n);
		}
		else if(choice==7)
			break;
		else if(flag)
		{
			printf("Please Create an Array First, Try Again :) \n");
		}
		else
		{
			if (choice==2)
			{
				display(arr,n);
			}
			else if (choice==3)
			{
				res=isHeap(arr,n);
				if(res)
					printf("It is a Heap\n");
				else
					printf("It is NOT a Heap\n");
			}
			else if (choice==4)
				create_heap(arr,n);
			else if (choice==5)
				heapsort(arr,n);
			else if (choice==6)
				printf("Deleted : %d\n",delete(arr,&n));
			//getchar();
		}
	}
}