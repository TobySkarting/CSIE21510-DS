#ifndef _T_FUNCTION_H_
#define _T_FUNCTION_H_

#include <string.h>

typedef struct {
	int favorite[3];						//	�����R�n����
	int num;								//	��Y�X�Ӥ��G
	int hpypt;
}Person;

typedef struct {
	int num;								//	���G���X��
}Fruit;

int getMaxHappyPoint(Person per[3], Fruit fru[3]);

#endif /* _T_FUNCTION_H_ */
