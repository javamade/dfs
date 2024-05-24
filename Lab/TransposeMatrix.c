// Write a C program to transpose a matrix within the same matrix

#include <stdio.h>

void input(int row, int col, int mat[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int main()
{
    int row, col;

    printf("Enter number of rows : ");
    scanf("%d", &row);
    printf("Enter number of columns : ");
    scanf("%d", &col);

    if(row!=col) 
    {
        printf("Matrix cannot be multiplied");
        return 0;
    }

    int A[row][col];

    int n = row;
    printf("Enter matrix :");
    input(row, col, A);

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Transpose the matrix
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap A[i][j] and A[j][i]
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    printf("Transposed Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
