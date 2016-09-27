#include <stdio.h>
#include "function.h"

int main()
{
	int i, j;
	Person p[3];
	Fruit f[3];

	for (i = 0; i < 3; i++)
	{
		p[i].hpypt = 0;
		printf("(Fruit 1 is Apple. Fruit 2 is Banana. Fruit 3 is Guava.)\n");
		printf("Please input Person(%d)'s num and favorite Fruit sequence: ", i + 1);
		scanf("%d", &p[i].num);
		for (j = 0; j < 3; j++)
			scanf("%d", &p[i].favorite[j]);
	}

	printf("Please input Apple's, Banana's, Guava's num: ");
	for (i = 0; i < 3; i++)
		scanf("%d", &f[i].num);

	printf("MaxHappyPoint: %d\n", getMaxHappyPoint(p, f));
    return 0;
}
