#include <stdio.h>

// function for square matrix
int isSquareMatrix(int rows, int cols)
{
    return rows == cols;
}

// function for diagonal matrix
int isDiagonalMatrix(float **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

// function for identity matrix
int isIdentityMatrix(float **matrix, int rows, int cols)
{
    if (!isDiagonalMatrix(matrix, rows, cols))
    {
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][i] != 1)
        {
            return 0;
        }
    }
    return 1;
}

// function for null matrix
int isZeroMatrix(float **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void transpose(int rows, int cols, float **matrix, float **copy)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            copy[i][j] = matrix[j][i];
        }
    }

    return;
}

int isSymmetric(int rows, int cols, float **matrix, float **copy)
{
    transpose(rows, cols, matrix, copy);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (copy[i][j] != matrix[i][j])
                return 0;
        }
    }
    return 1;
}

int isSkewSymmetric(int rows, int cols, float **matrix, float **copy)
{
    transpose(rows, cols, matrix, copy);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((copy[i][j]) != -matrix[i][j])
                return 0;
        }
    }
    return 1;
}

// function to print the type of a matrix
void printMatrixType(float **matrix, int rows, int cols, float **copy)
{
    if (isSquareMatrix(rows, cols))
    {
        printf("\033[1;36mSquare matrix\n\033[0m");

        if (isDiagonalMatrix(matrix, rows, cols))
        {
            printf("\033[1;36mDiagonal matrix\n\033[0m");

            if (isIdentityMatrix(matrix, rows, cols))
            {
                printf("\033[1;36mIdentity matrix\n\033[0m");
            }
        }

        if (isZeroMatrix(matrix, rows, cols))
        {
            printf("\033[1;36mZero matrix\n\033[0m");
        }
    }
    else
    {
        printf("\033[1;36mNot a square matrix\n\033[0m");
    }
    if (isSkewSymmetric(rows, cols, matrix, copy))
    {
       printf("\033[1;36mSkew-symmetric matrix\n\033[0m");
    }
    if (isSymmetric(rows, cols, matrix, copy))
    {
        printf("\033[1;36mSymmetric matrix\n\033[0m");
    }
}
// Types of matrix ends