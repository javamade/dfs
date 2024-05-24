// Write a C program to multiply two square matrices
/*  
    Condition: col1 == row2 for multiplication
    int mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int mat2[3][3] = {{1,1,1},{1,1,1},{1,1,1}}
*/

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

    int row1, col1, row2, col2;

    // Taking input for matrix-1
    printf("Enter number of rows : ");
    scanf("%d", &row1);
    printf("Enter number of columns : ");
    scanf("%d", &col1);
    printf("Enter matrix-1:\n");

    int mat1[row1][col1];
    input(row1, col1, mat1);

    // Taking input for matrix-2
    printf("Enter number of rows : ");
    scanf("%d", &row2);
    printf("Enter number of columns : ");
    scanf("%d", &col2);
    printf("Enter matrix-2:\n");

    int mat2[row2][col2];
    input(row2, col2, mat2);

    int mul[row1][col2];

    if (col1 == row2)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mul[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    mul[i][j] = mul[i][j] + mat1[i][k] * mat2[k][j];
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", mul[i][j]);
            }
            printf("\n");
        }
    }
    else 
    {
        printf("Multiplication condition not satisfied!!!\n");
    }

    return 0;
}