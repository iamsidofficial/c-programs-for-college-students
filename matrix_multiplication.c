#include <stdio.h>

int res[20][20];

void val(int mat[20][20], int r, int c, int n)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            printf("Enter the Value of mat%d[%d][%d]\n", n, i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
}

void mul(int mat1[20][20], int mat2[20][20], int r1, int c2, int r2)
{
    for (int i = 1; i <= r1; i++)
    {
        for (int j = 1; j <= c2; j++)
        {
            for (int n = 1; n <= r2; n++)    

            {
                res[i][j] += mat1[i][n] * mat2[n][j];
            }
        }
    }
}

int main()
{
    int r1, r2, c1, c2;
    int mat1[20][20], mat2[20][20];
    printf("\n*****     For Matrix 1     *****\n");
    printf("Enter the number of Rows:\n");
    scanf("%d", &r1);
    printf("Enter the number of Columns:\n");
    scanf("%d", &c1);
    val(mat1, r1, c1, 1);
    printf("\n\n*****     For Matrix 2     *****\n");
    printf("Enter the number of Rows:\n");
    scanf("%d", &r2);
    printf("Enter the number of Columns:\n");
    scanf("%d", &c2);
    if (c1 == r2)
    {
        val(mat2, r2, c2, 2);
        mul(mat1, mat2, r1, c2, r2);
        for (int i = 1; i <= r1; i++)
        {
            for (int j = 1; j <= c2; j++)
            {
         
       printf("Value of res[%d][%d] is %d\n", i, j, res[i][j]);
            }
        }
    }
    else
    {
        printf("Multiplication is not Possible.\n");
    }
    
    return 0;
}
