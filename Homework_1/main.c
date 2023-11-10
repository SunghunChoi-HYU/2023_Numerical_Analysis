#include <stdio.h>
#include "nr.h"

void get_eps(float *eps)
{
	*eps = 0.f;
	float Machine_Accuracy_float = 1.0f;
	while (1.0 + (Machine_Accuracy_float / 2.0f) != 1.0f)
	{
		Machine_Accuracy_float /= 2.0f;
	}
	*eps = Machine_Accuracy_float;
}

void get_eps_for_double(double *deps)
{
	*deps = 0.f;
	double Machine_Accuracy_double = 1.0f;
	while (1.0 + (Machine_Accuracy_double / 2.0f) != 1.0f)
	{
		Machine_Accuracy_double /= 2.0f;
	}
	*deps = Machine_Accuracy_double;
}

int main()
{
	int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
	float eps, eps2, epsneg, xmin, xmax;
	double deps, deps2, depsneg, dxmin, dxmax;

	machar(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
		   &eps, &epsneg, &xmin, &xmax);
	printf("Float Machine Accuracy (machar): \t%0.20f\n", eps);

	machar_for_double(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
					  &deps, &depsneg, &dxmin, &dxmax);
	printf("Double Machine Accuracy (machar): \t%0.20f\n", deps);

	get_eps(&eps2);
	printf("Float Machine Accuracy (get_eps): \t%0.20f\n", eps);

	get_eps_for_double(&deps2);
	printf("Double Machine Accuracy (get_eps): \t%0.20f\n", deps);

	return 0;
}
