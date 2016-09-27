#ifndef _T_FUNCTION_H_
#define _T_FUNCTION_H_

#include <string.h>

typedef struct {
	int favorite[3];						//	食物愛好順序
	int num;								//	能吃幾個水果
	int hpypt;
}Person;

typedef struct {
	int num;								//	水果有幾個
}Fruit;

int getMaxHappyPoint(Person per[3], Fruit fru[3]);

#endif /* _T_FUNCTION_H_ */
