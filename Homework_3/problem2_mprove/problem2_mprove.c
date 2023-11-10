#include <stdio.h>
#include <string.h>
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

    float **cpy_A = calloc(N + 1, sizeof(float *));
    for (int i = 1; i <= N; i++)
    {
        cpy_A[i] = calloc(N + 1, sizeof(float));
        memcpy(cpy_A[i], A[i], (N + 1) * sizeof(float));
    }

    float *cpy_b = calloc(N + 1, sizeof(float));
    memcpy(cpy_b, B, (N + 1) * sizeof(float));

    int *indx = ivector(1, N);

    ludcmp(A, N, indx, &d);
    lubksb(A, N, indx, B);

    printf("Linear Algebra answer for input matrix using ludcmp:\n");
    for (int i = 1; i <= N; i++)
    {
        printf("%f\t", B[i]);
    }
    printf("\n");

    mprove(cpy_A, A, N, indx, cpy_b, B);

    printf("Linear Algebra answer for input matrix using mprove:\n");
    for (int i = 1; i < N + 1; i++)
    {
        printf("%f\t", B[i]);
    }
    return 0;
}