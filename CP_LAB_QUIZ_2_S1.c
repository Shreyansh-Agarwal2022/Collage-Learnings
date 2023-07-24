#include<stdio.h>

//For malloc function
#include<stdlib.h>

//This fuction takes input from user for number of rows and columns,
//Then Dynamically Allocate Memory to double pointer for making 2D Array,
//This fuction also takes input for elements of 2D Array from user,
//And in last, return the double pointer which is the 2D Array.
int**readMatrix(int*row,int*column)
{
    //Double Pointer for 2D Array.
    int**t;
    int i,j;

    //For Exception Handling for negative number for number of rows and columns.
    do
    {
    printf("Enter number of rows and columns: ");
    scanf("%d %d",row,column);
    if(*row<=0 || *column<=0)
        printf("Number of Rows and Columns are always positive numbers.\n");
    }
    while(*row<=0 || *column<=0);

    //Allocating Memory for array of pointers
    t=(int**)malloc(*row * sizeof(int*));
    
    //Taking Input of Elements of 2D Array from user.
    printf("Enter values of array:\n");
    for(i=0;i<*row;i++)
    {
        t[i] = (int*)malloc((*column)*sizeof(int));
        for(j=0;j<*column;j++)
        {
            scanf("%d",&t[i][j]);
        }
    }
    printf("\n");
    
    //Returning the 2D Array as double pointer.
    return t;
}

//This function is for checking 2D Array(Matrix) is upper triangle or not.
//1 for true and 0 for false.
int isTriangular(int**arr,int row,int column)
{
    //If number of rows and columns are not equal so not a upper triangle.
    if(row!=column)
        return 0;
    
    //Checking the upper triangle after number of rows and columns are equal.
    int i,j;
    for(i=1;i<row;i++)
    {
            for(j=0;j<i;j++)
            {
                    if(arr[i][j]!=0)
                    {
                        return 0;
                    }
            }
    }
    return 1;
}

//This first checks if Matrix(2D Array) is upper triangle or not.
//If false, return 0.
//If true, return 1 and using pointers give sum of diagonals and sum of all elements.
int sumTriangular(int**arr,int row,int column,int*sum_diagonal,int*sum_all)
{
    int i,j;
    *sum_diagonal=0;
    *sum_all=0;
    if(isTriangular(arr,row,column)==0)
    {
        return 0;
    }
    else
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(i==j)
                {
                    *sum_diagonal=*sum_diagonal+arr[i][j];
                }
            }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                *sum_all=*sum_all+*(*(arr+i)+j);
            }
        }
    }
    return 1;
}

//This is main function
void main()
{
    //Double pointer for 2D Array(Matrix).
    int**arr;
    
    int row,column,sum_diagonal,sum_all;
    int i,j;

    //Calling readMatrix function and saving returned 2D Array in arr double pointer.
    arr=readMatrix(&row,&column);
   
   //Printing the 2D Array(Matrix).
    printf("\nDisplay The array :\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
   
   //At last, calling function for upper triangle.
    if(sumTriangular(arr,row,column,&sum_diagonal,&sum_all)==0)
    {
        printf("The matrix is not an upper triangular matrix");
    }
    else
    {
        printf("The sum of the diagonal elements is: %d\n\nThe sum of all elements of upper triangular matrix is: %d\n",sum_diagonal,sum_all);
    }
}