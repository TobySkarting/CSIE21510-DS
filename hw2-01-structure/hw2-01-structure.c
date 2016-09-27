#include <stdio.h>
#include "function.h"

int main()
{
	int n;
	int i;
	Person p;

	printf("Please input how many people: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Please input Person(%d)'s height(m), weight(kg), age, sex(0 or 1): ", i + 1);
		scanf("%f%f%f%f", &p.h, &p.w, &p.a, &p.s);
		printf("Person(%d)'s BMI: %f\n", i + 1, getBMI(p));
		printf("            BFR: %f\n", getBodyFatRate(p));
	}
    return 0;
}
