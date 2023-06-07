#include <stdlib.h>
// For determinant  starts.
void getCofactor(int p, int q, int n, float **mat, float **temp)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float determinant(int n, float **mat)
{
    float D = 0.0;

    if (n == 1)
        return mat[0][0];

    float **temp = (float **)malloc(n * sizeof(float *)); // Allocate memory for rows

    for (int i = 0; i < n; i++)
    {
        temp[i] = (float *)malloc(n * sizeof(float)); // Allocate memory for columns
    };

    int sign = 1.0;

    for (int f = 0; f < n; f++)
    {
        getCofactor(0, f, n, mat, temp);
        D += sign * mat[0][f] * determinant(n - 1, temp);

        sign = -sign;
    }

    return D;
}
// For determinants end.