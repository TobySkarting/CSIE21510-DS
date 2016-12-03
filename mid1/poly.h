#ifndef _T_POLY_H_
#define _T_POLY_H_

void input();
void poly_add();
void show_ans();

struct poly
{
	int coef;
	int exp;
	struct poly *next;
};

#endif // !_T_POLY_H_
