#include <stdio.h>
#include <stdlib.h>
#include "../../NRs/ansi/other/nrutil.h"

void load_data(FILE *inputAB, int *N, float ***A, float **B)
{
    int M;
    fscanf(inputAB, "%d %d", &M, N);

    *A = calloc(*N + 1, sizeof(float *));
    for (int i = 1; i < *N + 1; i++)
    {
        (*A)[i] = calloc(*N + 1, sizeof(float));
    }
    *B = calloc(*N + 1, sizeof(float));

    for (int i = 1; i < *N + 1; i++)
    {
        for (int j = 1; j < *N + 1; j++)
        {
            fscanf(inputAB, "%f", &(*A)[i][j]);
        }
    }

    for (int i = 1; i < *N + 1; i++)
    {
        fscanf(inputAB, "%f", &(*B)[i]);
    }
}

int main(int argc, char *argv[])
{
    FILE *inputAB;
    int N;
    float **A = NULL;
    float *B = NULL;
    float d;

    inputAB = fopen(argv[1], "r");
    if (inputAB == NULL)
    {
        fprintf(stderr, "파일 열기 실패", argv[1]);
        return 1;
    }
    load_data(inputAB, &N, &A, &B);
    fclose(inputAB);

    float **V = matrix(1, N, 1, N);
    float *W = vector(1, N);
    float *X = malloc(N + 1 * sizeof(float));

    svdcmp(A, N, N, W, V);
    svbksb(A, W, V, N, N, B, X);

    printf("Linear Algebra answer for input matrix using svdcmp:\n");
    for (int i = 1; i < N + 1; i++)
    {
        printf("%f\t", X[i]);
    }

    // Free allocated memory
    free_matrix(A, 1, N, 1, N);
    free_vector(B, 1, N);

    return 0;
}