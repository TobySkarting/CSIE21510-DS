#ifndef _T_FUNCTION_H_
#define _T_FUNCTION_H_

typedef struct {
	float h;		//	����
	float w;		//	�魫
	float a;		//	�~��
	float s;		//	�ʧO�A�k��1�A�k��0�C
}Person;

float getBMI(Person);
float getBodyFatRate(Person);

#endif /* _T_FUNCTION_H_ */
