#include<stdio.h>

int calculateRank(float **matrix, int rows, int cols)
{
    int rank = cols;
    int pivotRow = 0;

    for (int j = 0; j < cols; j++)
    {
        int nonzeroRow = -1;

        // Finding a nonzero row for the current column
        for (int i = pivotRow; i < rows; i++)
        {
            if (matrix[i][j] != 0)
            {
                nonzeroRow = i;
                break;
            }
        }

        // Performing row operations
        if (nonzeroRow != -1)
        {
            // Swapping rows
            for (int k = 0; k < cols; k++)
            {
                float temp = matrix[pivotRow][k];
                matrix[pivotRow][k] = matrix[nonzeroRow][k];
                matrix[nonzeroRow][k] = temp;
            }

            // Reduce rows
            for (int i = pivotRow + 1; i < rows; i++)
            {
                float factor = matrix[i][j] / matrix[pivotRow][j];
                for (int k = j; k < cols; k++)
                {
                    matrix[i][k] -= factor * matrix[pivotRow][k];
                }
            }

            pivotRow++;
        }
        else
        {
            // All entries in this column are zero
            rank--;
        }
    }

    return rank;
}