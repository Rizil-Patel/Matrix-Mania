void rowReducedEchelonForm(int ROWS, int COLS, float **matrix)
{
    int lead = 0;
    int rowCount = ROWS;
    int colCount = COLS;

    for (int r = 0; r < rowCount; r++)
    {
        if (lead >= colCount)
        {
            break;
        }

        int i = r;

        while (matrix[i][lead] == 0)
        {
            i++;

            if (i == rowCount)
            {
                i = r;
                lead++;

                if (lead == colCount)
                {
                    return;
                }
            }
        }

        // Swap rows
        for (int j = 0; j < colCount; j++)
        {
            float temp = matrix[r][j];
            matrix[r][j] = matrix[i][j];
            matrix[i][j] = temp;
        }

        // Divide row by pivot
        float pivot = matrix[r][lead];

        for (int j = 0; j < colCount; j++)
        {
            matrix[r][j] /= pivot;
        }

        // Eliminate other rows
        for (int j = 0; j < rowCount; j++)
        {
            if (j != r)
            {
                float factor = matrix[j][lead];

                for (int k = 0; k < colCount; k++)
                {
                    matrix[j][k] -= factor * matrix[r][k];
                }
            }
        }

        lead++;
    }
    return;
}