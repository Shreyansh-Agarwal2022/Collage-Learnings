/*
Ques. Write a program in C that performs the following task:

1. Create an integer array of a size specified by the user
2. Read the values in the interval 0 to 20. The program should read the numbers from keyboard and prompt for replacement number if input has value outside 0 to 20.
3. Display the values of the array
4. Determine the even number in the array which occurs the most number of times. Also print the number of occurrences. If two or more even numbers meet the most occurrences criteria, print the smallest even number.
Don't use any global variable and don't create any other array.

Test Case 1

Input: Size of array: 10
Array: 11 14 3 3 1 4 14 14 3 20
Output: 14 occur 3 times

Test Case 2

Input: Size of array: 10
Array: 11 14 4 4 1 4 14 14 3 20
Output: 4 occur 3 times
*/

//CODE :
#include<stdio.h>

//For Reading Values of element of an array from user in interval 0 to 20.
void read(int a[],int n);

//For Displaying all elements of an array.
void display(int a[],int n);

//Which even number element occur highest (return element value)
int find(int a[],int n);

//For finding occurance of highest occuring of even number.
int occur(int num,int a[],int n);

//Our Main function.
void main()
{
    int arr[50];    //Declaration of array.
    int n;          //n is size of array.
    int element,occurance;
    
    do
    {
        printf("Size of array: ");
        scanf("%d",&n);
        if(n<=0)
            printf("Size should be Positive.\n");
    }
    while(n<=0);
    //We have used this do-while loop for checking is size is positive number or not.
    
    //Reading values of element of array in main function.
    read(arr,n);
    
    //Displaying the array.
    display(arr,n);
    
    //Finding Even Element Occuring highest.
    element=find(arr,n);
    
    //How many times it occur.
    occurance=occur(element,arr,n);
    
    //Printing the result
    printf("The element value is %d and its occurance in array is %d.\n",element,occurance);
}

void read(int a[],int n)
{
    int i;
    
    printf("Reading Elements of Array\n");
    
    for(i=0;i<n;i++)
    {
        do
        {
            printf("Element %d is ",i);
            scanf("%d",&a[i]);
            if(a[i]>20 || a[i]<0)
                printf("Enter Number between interval 0 to 20.\n");
        }
        while(a[i]>20 || a[i]<0);
        //We have used do-while loop to check if number is between interval 0 to 20
    }
    printf("\n");
}

void display(int a[],int n)
{
    int i;
    
    printf("Displaying Elements of Array\n");
    
    for(i=0;i<n;i++)
        printf(" %d ",a[i]);
    //Printing elements of array one-by-one using for-loop.
    
    printf("\n\n");
}

int find(int a[],int n)
{
    //"count" is for occurance of current iteration
    //"max" is for highest occurance till now
    //"check" is for smallest even number
    //"ele" value of resultant element of array
    int i,j,count=0,max=0;
    int check;
    int ele;
    for(i=0;i<n;i++)
    {   
        count=0;
        if(a[i]%2!=0)
            continue;
            
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j])
                count++;
        }
            
        if(count>max)
        {
            max=count;
            ele=a[i];
            check=a[i];
        }
        else if(count==max)
        {
            if(check>a[i])
                ele=a[i];
            else
                ele=check;
        }
    }
    
    return ele;
}

int occur(int num,int a[],int n)
{
    //"count" is for occurance.
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(num==a[i])
            count++;
    }
    return count;
}

/*
//Better Find Function

int find(int a[], int n) {
    int count[21] = {0};
    int maxCount = 0, maxNum;

    // Iterate through the array and store the count of each element in count[]
    for(int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    // Iterate through count[] and check for highest count for each even number
    for(int i = 0; i < 21; i++) {
        if(i % 2 == 0 && count[i] > maxCount) {
            maxCount = count[i];
            maxNum = i;
        }
    }

    return maxNum;
}
*/

//Terminal Commands :

//Input : Size of array: 10
//...
//Output : ...