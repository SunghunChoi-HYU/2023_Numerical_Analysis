#include <stdio.h>
#include <time.h>
#include "Muller.h"
#include "../NRs/ansi/other/nr.h"
#include "../NRs/ansi/other/nrutil.h"

void bessj0d(float x, float *y, float *dy)
{
    *y = bessj0(x);
    *dy = -bessj1(x);
}

void homework2_1()
{
    printf("This is first part of Homework 2\n \n");

    const float X1 = 1.0;
    const float X2 = 10.0;
    const float XACC = 1e-6;
    const int MAX_ROOTS = 100;
    const int NUM_BRACKETS = 1e5;

    int num_roots = MAX_ROOTS;
    float xb1[MAX_ROOTS], xb2[MAX_ROOTS];
    time_t start_time, end_time, total_time;
    zbrak(bessj0, X1, X2, NUM_BRACKETS, xb1, xb2, &num_roots);

    printf("Bisection Method (using rtbis): \n");

    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*rtbis)(bessj0, xb1[i], xb2[i], XACC);
        printf("%d번째 근: %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", total_time * (int)1e6 / CLOCKS_PER_SEC);
    total_time = 0;

    printf("Linear interpolation (using rtflsp): \n");
    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*rtflsp)(bessj0, xb1[i], xb2[i], XACC);
        printf("%d번째 근 : %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", total_time * (int)1e6 / CLOCKS_PER_SEC);
    total_time = 0;

    printf("Secant Method (using rtsec): \n");
    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*rtsec)(bessj0, xb1[i], xb2[i], XACC);
        printf("%d번째 근: %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", total_time * (int)1e6 / CLOCKS_PER_SEC);
    total_time = 0;

    printf("Newton-Raphson (using rtnewt): \n");
    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*rtnewt)(bessj0d, xb1[i], xb2[i], XACC);
        printf("%d번째 근: %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", total_time * (int)1e6 / CLOCKS_PER_SEC);
    total_time = 0;

    printf("Newton with bracketing (using rtsafe): \n");
    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*rtsafe)(bessj0d, xb1[i], xb2[i], XACC);
        printf("%d번째 근: %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", total_time * (int)1e6 / CLOCKS_PER_SEC);
    total_time = 0;
}

void homework2_2()
{
    float f(float x)
    {
        return log(x) - 2;
    }

    void fd(float x, float *y, float *dy)
    {
        *y = log(x) - 2;
        *dy = 1 / x;
    }
    printf("This is part for second half of homework 2\n\n");

    const float X1 = 1.0;
    const float X2 = 10.0;
    const float XACC = 1e-6;
    const int MAX_ROOTS = 100;
    const int NUM_BRACKETS = 1e5;

    int num_roots = MAX_ROOTS;
    float xb1[MAX_ROOTS], xb2[MAX_ROOTS];
    time_t start_time, end_time, total_time;

    zbrak(bessj0, X1, X2, NUM_BRACKETS, xb1, xb2, &num_roots);
    printf("I am going to find solution using Muller Method\n");
    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*muller)(bessj0, xb1[i], (xb1[i] + xb2[i]) / 2, xb2[i], XACC);
        printf("%d번째 근 : %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", (int)1e6 / CLOCKS_PER_SEC);

    zbrak(f, X1, X2, NUM_BRACKETS, xb1, xb2, &num_roots);
    printf("I am going to slove nonlinear equation (ln(x) - 2) using rtsafe\n");
    for (int i = 1; i <= num_roots; i++)
    {
        start_time = clock();
        float root = (*rtsafe)(fd, xb1[i], xb2[i], XACC);
        printf("%d번째 근 : %.10f\n", i, root);
        end_time = clock();
        total_time += end_time - start_time;
    }
    printf("걸린 시간 : %ldus\n\n", (int)1e6 / CLOCKS_PER_SEC);
}

int main()
{
    homework2_1();
    homework2_2();
}