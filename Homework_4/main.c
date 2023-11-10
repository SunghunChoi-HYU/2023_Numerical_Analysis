#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

float ran0(long *idum);
float gasdev(long *idum);

int main(int argc, char *argv[])
{
    int array[4] = {100, 1000, 10000, 100000};
    int m = 0.5;
    int s = 1.5;
    int a = -3;
    int b = 4;

    long long idum = time(NULL);
    for (int i = 0; i < 3; i++)
    {
        printf("Random numbers #%d \n", array[i]);
        for (int j = 0; j < array[i]; j++)
        {
            printf("%f\t", a + (b - a) * ran0(&idum));
        }
        printf("\n");
    }
    for (int i = 0; i < 100000; i++)
    {
        printf("Random numbers #%d \n", array[i]);
        for (int j = 0; j < array[i]; j++)
        {
            long long idum2 = clock();
            long long time = ran1(&idum2);
            printf("%f\t", m + s * gasdev(&time));
        }
        printf("\n");
    }

    return 0;
}