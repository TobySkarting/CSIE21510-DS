#ifndef _T_STACKLIB_H_
#define _T_STACKLIB_H_

#define MAX 4

typedef struct {
	int value;
} element;

void createStack(element stack[]);
//�NStack��l�ƨ�Create

int IsFull(int top);
//�P�_���|�O�_���F

int IsEmpty(int top);
//�P�_���|�O�_�ŤF

int push(element stack[], int* top, int value);
//���|��JStack�Atop���W��

int pop(element stack[], int* top);
//���|��XStack�Atop���U��  �^�ǭ�int���ĤG�D�A�nreturn�ƭ�

void listAll(element stack[], int* top);
//���|�����L�X��

#endif /* _T_STACKLIB_H_ */
