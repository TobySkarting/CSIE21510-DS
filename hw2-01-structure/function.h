#ifndef _T_FUNCTION_H_
#define _T_FUNCTION_H_

typedef struct {
	float h;		//	身高
	float w;		//	體重
	float a;		//	年齡
	float s;		//	性別，男為1，女為0。
}Person;

float getBMI(Person);
float getBodyFatRate(Person);

#endif /* _T_FUNCTION_H_ */
