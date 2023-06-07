#include<stdio.h>

void sum(int m, int n, int p, int q, float **a1, float **a2)
{
    if (m == p && n == q)
    {
        printf("Addition of matrices are:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("\033[1;36m%.2f\t\033[0m", a1[i][j] + a2[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Matrix addition is not possible!!\n");
    return;
}

void substraction(int m, int n, int p, int q, float **a1, float **a2)
{
    if (m == p && n == q)
    {
        printf("Substraction of matrices are:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("\033[1;36m%.2f\t\033[0m", a1[i][j] - a2[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Matrix substraction is not possible!!\n");
    return;
}

void multiply(int m, int n, int p, int q, float **a1, float **a2)
{
    if (n == p)
    {
        printf("The multiplication of two matrices is:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                float sum = 0.0;
                for (int k = 0; k < n; k++)
                {
                    sum = sum + a1[i][k] * a2[k][j];
                }
                printf("\033[1;36m%.2f\t\033[0m", sum);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrix multiplication is not possible!!\n");
    }
    return;
}

void scalar_multiply(int m, int n, float **a)
{
    int k;
    printf("\nEnter scaler value: ");
    scanf("%d", &k);
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = k * a[i][j];
        }
    }
    return;
}