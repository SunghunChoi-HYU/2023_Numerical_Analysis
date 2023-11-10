#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../NRs/ansi/other/nrutil.h"

void find_inverse(float **input_matrix, float **inverse_matrix, int N)
{
    double d;

    ludcmp(input_matrix, N, 1, &d);

    for (int i = 1; i <= N; i++)
    {
        double *column = dvector(1, N);
        for (int j = 1; j <= N; j++)
        {
            column[j] = 0.0;
        }
        column[i] = 1.0;
        lubksb(input_matrix, N, 1, column);
        for (int j = 1; j <= N; j++)
        {
            inverse_matrix[j][i] = column[j];
        }
        free_dvector(column, 1, N);
    }
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
    float determinant;
    float **A = NULL;
    float *col = NULL;
    float **inverse_matrix = NULL;
    float *B = NULL;

    inputAB = fopen(argv[1], "r");
    if (inputAB == NULL)
    {
        fprintf(stderr, "파일 열기 실패", argv[1]);
        return 1;
    }
    load_data(inputAB, &N, &A, &B);
    int *indx = ivector(1, N);
    float d = 1;
    ludcmp(A, N, indx, &d);

    inverse_matrix = calloc(N + 1, sizeof(float *));
    for (int i = 1; i < N + 1; i++)
    {
        (inverse_matrix)[i] = calloc(N + 1, sizeof(float));
    }
    col = calloc(N + 1, sizeof(float));

    for (int i = 1; i <= N; i++)
    {
        d *= A[i][i];
    }

    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            col[i] = 0.0;
        }
        col[j] = 1.0;
        lubksb(A, N, indx, col);
        for (int i = 1; i <= N; i++)
        {
            inverse_matrix[i][j] = col[i];
        }
    }

    printf("Inverse Matrix for input matrix:\n");
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            printf("%f\t", inverse_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Determinant for input matrix is : %f", d);
}