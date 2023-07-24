/*
    Dynamically Allocate Memory using function and double pointer for making Matriz with different number of columns in different rows.
*/

#include <stdio.h>
#include <stdlib.h>

int *read(int **arr, int *row)
{
    int i, j;
    int *column;

    column = (int *)malloc(*row * sizeof(int));

    for (i = 0; i < *row; i++)
    {
        printf("Enter Number of Columns of %dth row : ", i);
        scanf("%d", &column[i]);
        *(arr + i) = (int *)malloc(column[i] * sizeof(int));

        for (j = 0; j < column[i]; j++)
        {
            printf("Enter matrix[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    return column;
}

void main()
{
    int **matrix;
    int *column;
    int row;
    int i, j;

    printf("Enter Number of Rows of Matrix : ");
    scanf("%d", &row);
    matrix = (int **)malloc(row * sizeof(int *));

    column = read(matrix, &row);

    printf("\nNow Displaying the Matrix :\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column[i]; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}