#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "determinant.h" //Header files for different operations.
#include "TypesOfMatrix.h"
#include "Inverse.h"
#include "Echlon.h"
#include "Orthogonal.h"
#include "ArithmeticOperations.h"
#include "RREF.h"
#include "Rank.h"

void getSize(int *a, int *b) // To get number of rows and columns as size.
{
    int rows, cols;
    printf("Enter number of rows:");
    scanf("%d", &rows);
    printf("Enter number of columns:");
    scanf("%d", &cols);
    *a = rows;
    *b = cols;
    return;
}

void getElements(int r, int c, float **mat) // To get elements in matrix.
{
    printf("\nEnter elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    printf("\n");
}

void printMatrix(int m, int n, float **matrix) // To print matrix.
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\033[1;36m%.2f\t\033[0m", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    printf("\n Welcome to \033[1;33mMATRIX MANIA!!\033[0m\n\n");
    while (1)
    {
        int k;
        printf("press\033[1;32m 1\033[0m to run the program and \033[1;32m0\033[0m to exit the program\n");
        scanf("%d", &k);

        if (k == 1)
        {
            int i; // Operational choice for user.
            printf("\nPress \033[1;32m1\033[0m to \033[1;31mfind the type of matrix:\n\033[0m");
            printf("Press \033[1;32m2\033[0m to \033[1;31mperform arithmetic operations on matrix:\n\033[0m");
            printf("Press \033[1;32m3\033[0m to \033[1;31mfind determinant:\n\033[0m");
            printf("Press \033[1;32m4\033[0m to \033[1;31mfind transpose of matrix:\n\033[0m");
            printf("Press \033[1;32m5\033[0m to \033[1;31mfind inverse:\n\033[0m");
            printf("Press \033[1;32m6\033[0m to \033[1;31mconvert to echlon form:\n\033[0m");
            printf("Press \033[1;32m7\033[0m to \033[1;31mconvert to row reduced echlon form:\n\033[0m");
            printf("Press \033[1;32m8\033[0m to \033[1;31mfind rank of matrix:\n\033[0m");
            printf("Press \033[1;32m9\033[0m to \033[1;31mcheck orthogonality of matrices:\n\033[0m");
            scanf("%d", &i);
            printf("\n");

            switch (i)
            {
            case 1:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                float **arr1 = (float **)malloc(n * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < n; i++)
                {
                    arr1[i] = (float *)malloc(m * sizeof(float)); // Allocate memory for columns
                }
                printMatrixType(arr, m, n, arr1);
                printf("\n");
                break;
            }
            case 2:
            {
                int y;
                printf("\nPress \033[1;32m1\033[0m to \033[1;31mfind addition of two matrices:\n\033[0m");
                printf("Press \033[1;32m2\033[0m to \033[1;31msubstract two matrices:\n\033[0m");
                printf("Press \033[1;32m3\033[0m to \033[1;31mmultilpy two matrices:\n\033[0m");
                printf("Press \033[1;32m4\033[0m to \033[1;31mmultilpy matrix with scalar:\n\033[0m");
                scanf("%d", &y);
                printf("\n");
                switch (y)
                {
                case 1:
                {
                    int m, n;
                    getSize(&m, &n);
                    float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < m; i++)
                    {
                        arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(m, n, arr);

                    int a, b;
                    getSize(&a, &b);
                    float **arr1 = (float **)malloc(a * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < a; i++)
                    {
                        arr1[i] = (float *)malloc(b * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(a, b, arr1);
                    printf("Resultant matrix:\n");
                    sum(m, n, a, b, arr, arr1);
                    printf("\n");
                    break;
                }
                case 2:
                {
                    int m, n;
                    getSize(&m, &n);
                    float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < m; i++)
                    {
                        arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(m, n, arr);

                    int a, b;
                    getSize(&a, &b);
                    float **arr1 = (float **)malloc(a * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < a; i++)
                    {
                        arr1[i] = (float *)malloc(b * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(a, b, arr1);
                    printf("Resultant matrix:\n");
                    substraction(m, n, a, b, arr, arr1);
                    printf("\n");
                    break;
                }
                case 3:
                {
                    int m, n;
                    getSize(&m, &n);
                    float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < m; i++)
                    {
                        arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(m, n, arr);

                    int a, b;
                    getSize(&a, &b);
                    float **arr1 = (float **)malloc(a * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < a; i++)
                    {
                        arr1[i] = (float *)malloc(b * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(a, b, arr1);
                    printf("Resultant matrix:\n");
                    multiply(m, n, a, b, arr, arr1);
                    printf("\n");
                    break;
                }
                case 4:
                {
                    int m, n;
                    getSize(&m, &n);
                    float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                    for (int i = 0; i < m; i++)
                    {
                        arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                    }
                    getElements(m, n, arr);
                    scalar_multiply(m, n, arr);
                    printMatrix(m, n, arr);
                    break;
                }
                default:
                    printf("Enter valid input.\n\n");
                }
            }
            break;
            case 3:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                float det = determinant(n, arr);
                printf("Determinant: \033[1;36m%.2f\n\n\033[0m", det);
                break;
            }
            case 4:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                float **arr1 = (float **)malloc(n * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < n; i++)
                {
                    arr1[i] = (float *)malloc(m * sizeof(float)); // Allocate memory for columns
                }
                transpose(m, n, arr, arr1);
                printf("Transpose matrix:\n");
                printMatrix(n, m, arr1);
            }
            break;
            case 5:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                float **arr1 = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr1[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                if (matrixInverse(n, arr, arr1))
                {
                    printf("\nInverse Matrix:\n");
                    printMatrix(m, n, arr1);
                }
            }
            break;
            case 6:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                Echleon(m, n, arr);
                printf("\nEchelon Form:\n");
                printMatrix(m, n, arr);
                break;
            }
            case 7:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                rowReducedEchelonForm(m, n, arr);
                printMatrix(m, n, arr);
            }
            break;
            case 8:
            {
                int m, n;
                getSize(&m, &n);
                float **arr = (float **)malloc(m * sizeof(float *)); // Allocate memory for rows
                for (int i = 0; i < m; i++)
                {
                    arr[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
                }
                getElements(m, n, arr);
                int rank = calculateRank(arr, m, n);
                printf("Rank of given matrix: %d.\n\n", rank);
                break;
            }
            case 9:
            {
                int numVectors, dimension;
                Vector vectors[MAX_DIMENSION];
                int i, j;

                printf("Enter the number of vectors: ");
                scanf("%d", &numVectors);

                printf("Enter the size of each vector: ");
                scanf("%d", &dimension);

                printf("Enter the elements of the vectors:\n");
                for (i = 0; i < numVectors; i++)
                {
                    printf("Vector %d:\n", i + 1);
                    for (j = 0; j < dimension; j++)
                    {
                        scanf("%f", &vectors[i].components[j]);
                    }
                    vectors[i].dimension = dimension;
                }

                // Check if vectors are orthogonal or orthonormal
                if (isOrthogonal(vectors, numVectors))
                {
                    printf("\nThe vectors are orthogonal.\n");
                    if (isOrthonormal(vectors, numVectors))
                    {
                        printf("The vectors are also orthonormal.\n\n");
                    }
                    else
                    {
                        printf("The vectors are not orthonormal.\n\n");
                    }
                }
                else
                {
                    printf("The vectors are not orthogonal.\n\n");
                }
            }
            break;
            default:
                printf("Enter valid input.\n\n");
            }
        }
        if (k == 0)
        {
            printf("\n\033[1;31mExiting program...\n\033[0m");
            exit(0);
        }
    }
    return 0;
}