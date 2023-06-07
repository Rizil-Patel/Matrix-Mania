#include <stdio.h>
#include <stdlib.h>

int matrixInverse(int n, float **matrix, float **inverse)
{
    // Augmenting the matrix with an identity matrix
    float **augmented = (float **)malloc(n * sizeof(float *)); // Allocate memory for rows
    for (int i = 0; i < n; i++)
    {
        augmented[i] = (float *)malloc(2 * n * sizeof(float)); // Allocate memory for columns
    }
    float arr[n][2 * n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; i++)
    {
        if (augmented[i][i] == 0)
        {
            printf("Matrix is not invertible.\n");
            return 0;
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                float ratio = augmented[j][i] / augmented[i][i];
                for (int k = 0; k < 2 * n; k++)
                {
                    augmented[j][k] -= ratio * augmented[i][k];
                }
            }
        }
    }

    // Scaling the rows to make the diagonal elements equal to 1
    for (int i = 0; i < n; i++)
    {
        float scale = augmented[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            augmented[i][j] /= scale;
        }
    }

    // Extracting the inverse matrix from the augmented matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return 1;
}