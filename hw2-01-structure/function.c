#include "function.h"

float getBMI(Person p)
{
	return p.w / (p.h * p.h);
}

float getBodyFatRate(Person p)
{
	return 1.2 * getBMI(p) + 0.23 * p.a - 5.4 - 10.8 * p.s;
}
