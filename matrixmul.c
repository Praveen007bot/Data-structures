#include <stdio.h>

void multiply(int mat1[][10], int mat2[][10], int res[][10], int r1, int c1, int c2)
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < c1; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main()
{
    int mat1[10][10], mat2[10][10], res[10][10];
    int r1, c1, r2, c2, i, j;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &r2, &c2);

    while (c1 != r2)
    {
        printf("Error! column of first matrix not equal to row of second.\n\n");
        printf("Enter rows and columns for first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for second matrix: ");
        scanf("%d%d", &r2, &c2);
    }

    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);

    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);

    multiply(mat1, mat2, res, r1, c1, c2);

    printf("\nResult matrix is:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d\t", res[i][j]);
        printf("\n");
    }

    return 0;
}
