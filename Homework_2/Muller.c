#include <math.h>

#define MAXIT 100

float muller(float(func)(float), float p0, float p1, float p2, float xacc)
{
    float f0, f1, f2, a, b, c;

    for (int i = 0; i < MAXIT; i++)
    {
        f0 = (func)(p0);
        f1 = (func)(p1);
        f2 = (func)(p2);

        a = ((p1 - p2) * (f0 - f2) - (p0 - p2) * (f1 - f2)) / ((p0 - p2) * (p1 - p2) * (p0 - p1));
        b = (((p0 - p2) * (p0 - p2) * (f1 - f2)) - ((p1 - p2) * (p1 - p2) * (f0 - f2))) / ((p0 - p2) * (p1 - p2) * (p0 - p1));
        c = f2;

        float denominator;
        if (b > 0)
        {
            denominator = b + sqrt(b * b - 4 * a * c);
        }
        else
        {
            denominator = b - sqrt(b * b - 4 * a * c);
        }

        float dx = -2 * c / denominator;
        float p3 = p2 + dx;

        if (fabs(dx) < xacc)
        {
            return p3;
        }

        p0 = p1;
        p1 = p2;
        p2 = p3;
    }

    return 0.0;
}

#undef MAXIT