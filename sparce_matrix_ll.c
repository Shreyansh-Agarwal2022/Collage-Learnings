//Shreyansh Agarwal
//22UCS203
//Even-set
//Mid Term DSA LAB

#include<stdio.h>
#include<stdlib.h>

//Structure of Node of an Singly Linked LIst
typedef struct node
{
	int row;
	int column;
	int value;
	struct node*next;
}node;

//Function for adding a new node to a linked list
//Used in making linked list
//This function returns the head pointer of new linked list
node*add(node*head,int row,int column,int value)
{	
	node*head1=head;
	/*while(head1!=NULL)
	{
		printf("%d %d %d\n",head1->row,head1->column,head1->value);
		head1=head1->next;
	}*/
	//printf("You entered : %d \n",value);
	node*new=(node*)malloc(sizeof(node));
	new->row=row;
	new->column=column;
	new->value=value;
	//prev acts as previous node of temp
	node*prev=head;
	node*temp=NULL;
	//If head is empty
	if(head==NULL)
	{
		new->next=NULL;
		head=new;
		return(head);
	}
	else
	{
		temp=head->next;
		//Special Case : When we add node in beginning
		if(head->row >= row && head->column > column)
		{
			new->next=head;
			head=new;
			return(head);	
		}
		while(temp!=NULL)
		{
			//printf("%d %d %d\n",temp->row,temp->column,temp->value);
			if(temp->row < row)
			{
				prev=temp;
				temp=temp->next;
			}
			else if(temp->row == row && temp->column < column)
			{
				prev=temp;
				temp=temp->next;
			}
			else if(temp->row == row && temp->column > column)
			{
				prev->next=new;
				new->next=temp;
				return(head);
			}
			else if(temp->row > row)
			{
				prev->next=new;
				new->next=temp;
				return(head);
			}
		}
		if(temp==NULL)
		{
			prev->next=new;
			new->next=NULL;
			
		}
		return(head);
	}
}

//This function makes the linked list by taking input from user
//This function returns the head pointer of new linked list
node*create(int rows,int columns)
{
	int data;
	int i,j;
	node*head=NULL;
	printf("Give Data of Matrix :\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("Value of Matrix[%d][%d] : ",i,j);
			scanf("%d",&data);
			
			if(data!=0)
				head=add(head,i,j,data);
		}
	}
	return(head);
}

//Function for merging two linked list
//This function returns the head pointer of new linked list
node*merge(node*head1,node*head2)
{
	
	node*result=NULL;
	int value;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->row==head2->row)
		{
			if(head1->column==head2->column)
			{
				value=0;
				//printf("Hi 1\n");
				value=head1->value + head2->value;
				//printf("%d \n",value);
				//printf("%d %d %d\n",head1->row,head1->column,value);
				result=add(result,head1->row,head1->column,value);
				head1=head1->next;
				head2=head2->next;
			}
			else if(head1->column > head2->column)
			{
				//printf("Hi 2\n");
				//printf("%d %d %d\n",head2->row,head2->column,head2->value);
				result=add(result,head2->row,head2->column,head2->value);
				head2=head2->next;
			}
			else if(head1->column < head2->column)
			{
				//printf("Hi 3\n");
				//printf("%d %d %d\n",head1->row,head1->column,head1->value);
				result=add(result,head1->row,head1->column,head1->value);
				head1=head1->next;
			}
			
		}
		else if(head1->row < head2->row)
		{
			while(head1!=NULL && head1->row < head2->row)
			{	
				//printf("Hi 4\n");
				//printf("%d %d %d\n",head1->row,head1->column,head1->value);
				result=add(result,head1->row,head1->column,head1->value);
				head1=head1->next;
			}
		}
		else if(head1->row > head2->row)
		{
			while(head2!=NULL && head1->row > head2->row)
			{
				//printf("Hi 5\n");
				//printf("%d %d %d\n",head2->row,head2->column,head2->value);
				result=add(result,head2->row,head2->column,head2->value);
				head2=head2->next;
			}
		}
		if(head1==NULL || head2==NULL)
		{
			break;
		}
	}
	//printf("He 1\n");
	while(head1!=NULL)
	{
		//printf("Hi 6\n");
		result=add(result,head1->row,head1->column,head1->value);
		head1=head1->next;
	}
	//printf("He 2\n");
	while(head2!=NULL)
	{
		//printf("Hi 7\n");
		result=add(result,head2->row,head2->column,head2->value);
		head2=head2->next;
	}
	return(result);
}

//This function prints the normal matrix using sparse matrix
void display(node*head,int rows,int columns)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			if(head!=NULL && head->row==i && head->column==j)
			{
				printf("%d ",head->value);
				head=head->next;
			}
			else
			{
				printf("0 ");
			} 
		}
		printf("\n");
	}
}

//Our main function
void main()
{
	node*head1=NULL;
	node*head2=NULL;
	node*head3=NULL;
	int rows,columns;
	printf("Enter Number of Rows in Matrix : ");
	scanf("%d",&rows);
	printf("Enter Number of Columns in Matrix : ");
	scanf("%d",&columns);
	
	//For Matrix 1
	printf("\nEnter Details for Matrix 1:\n");
	head1=create(rows,columns);
	printf("\nEnter Details for Matrix 2:\n");
	head2=create(rows,columns);
	
	//For Matrix 2
	printf("\nDisplaying Matrix 1:\n");
	display(head1,rows,columns);
	printf("\nDisplaying Matrix 2:\n");
	display(head2,rows,columns);
	
	//Merging
	head3=merge(head1,head2);
	printf("\nDisplaying Matrix 3:\n");
	display(head3,rows,columns);	
}