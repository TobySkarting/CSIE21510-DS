#include "function.h"

int getMaxHappyPoint(Person per[3], Fruit fru[3])
{
	int result = 0;
	int i, j, min;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			min = per[j].num;
			if (fru[per[j].favorite[i] - 1].num < min)
				min = fru[per[j].favorite[i] - 1].num;
			if (min != 0)
			{
				per[j].hpypt += min * (3 - i);
				per[j].num -= min;
				fru[per[j].favorite[i] - 1].num -= min;
			}
		}
	}
	for (i = 0; i < 3; i++)
		result += per[i].hpypt;
	return result;
}
