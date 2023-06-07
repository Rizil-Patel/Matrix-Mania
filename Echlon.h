#include <stdio.h>

void Echleon(int m, int n, float **matrix)
{
    int rows = m;
    int columns = n;
    int pivot_row = 0;
    for (int j = 0; j < columns; j++)
    {
        int nonzero_row = -1;

        // Find a nonzero row for current column
        for (int i = pivot_row; i < rows; i++)
        {
            if (matrix[i][j] != 0)
            {
                nonzero_row = i;
                break;
            }
        }

        // Perform row operations
        if (nonzero_row != -1)
        {
            // Swap rows
            float temp;
            for (int k = 0; k < columns; k++)
            {
                temp = matrix[pivot_row][k];
                matrix[pivot_row][k] = matrix[nonzero_row][k];
                matrix[nonzero_row][k] = temp;
            }

            // Reduce rows
            for (int i = pivot_row + 1; i < rows; i++)
            {
                float factor = matrix[i][j] / matrix[pivot_row][j];
                for (int k = j; k < columns; k++)
                {
                    matrix[i][k] -= factor * matrix[pivot_row][k];
                }
            }

            pivot_row++;
        }
    }
    return;
}