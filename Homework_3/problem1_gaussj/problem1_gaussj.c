#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../NRs/ansi/other/nr.h"

float *run_gaussj(int n, float **A, float *B)
{
    float **copy_A = calloc(n + 1, sizeof(float *));
    for (int i = 1; i < n + 1; i++)
    {
        copy_A[i] = calloc(n + 1, sizeof(float));
        memcpy(copy_A[i], A[i], (n + 1) * sizeof(float));
    }
    float **copy_B = calloc(n + 1, sizeof(float *));
    for (int i = 1; i < n + 1; i++)
    {
        copy_B[i] = calloc(2, sizeof(float));
        copy_B[i][1] = B[i];
    }

    gaussj(copy_A, n, copy_B, 1);
    float *ret = calloc(n + 1, sizeof(float));
    for (int i = 1; i < n + 1; i++)
    {
        ret[i] = copy_B[i][1];
    }
    return ret;
}
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

    inputAB = fopen(argv[1], "r");
    if (inputAB == NULL)
    {
        fprintf(stderr, "파일 열기 실패", argv[1]);
        return 1;
    }
    load_data(inputAB, &N, &A, &B);
    fclose(inputAB);

    float *answer = run_gaussj(N, A, B);

    printf("Linear Algebra answer for input matrix using gaussj:\n");
    for (int i = 1; i < N + 1; i++)
    {
        printf("%f\t", answer[i]);
    }
}