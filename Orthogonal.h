#include <stdio.h>
#include <math.h>

#define MAX_DIMENSION 10

typedef struct {
    int dimension;
    float components[MAX_DIMENSION];
} Vector;

int isOrthogonal(Vector *vectors, int numVectors)
{
    int i, j;

    for (i = 0; i < numVectors; i++)
    {
        for (j = i + 1; j < numVectors; j++)
        {
            float dotProduct = 0;
            int k;

            for (k = 0; k < vectors[i].dimension; k++)
            {
                dotProduct += vectors[i].components[k] * vectors[j].components[k];
            }

            if (fabs(dotProduct) > 1e-6)
            {
                return 0; // Not orthogonal
            }
        }
    }

    return 1; // Orthogonal
}

int isOrthonormal(Vector *vectors, int numVectors)
{
    int i;

    if (!isOrthogonal(vectors, numVectors))
    {
        return 0; // Not orthonormal if not orthogonal
    }

    for (i = 0; i < numVectors; i++)
    {
        float norm = 0;
        int j;

        for (j = 0; j < vectors[i].dimension; j++)
        {
            norm += vectors[i].components[j] * vectors[i].components[j];
        }

        if (fabs(norm - 1) > 1e-6)
        {
            return 0; // Not orthonormal
        }
    }

    return 1; // Orthonormal
}
