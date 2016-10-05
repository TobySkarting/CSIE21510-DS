#ifndef _T_STACKLIB_H_
#define _T_STACKLIB_H_

#define MAX 4

typedef struct {
	int value;
} element;

void createStack(element stack[]);
//將Stack初始化並Create

int IsFull(int top);
//判斷堆疊是否滿了

int IsEmpty(int top);
//判斷堆疊是否空了

int push(element stack[], int* top, int value);
//堆疊放入Stack，top往上移

int pop(element stack[], int* top);
//堆疊丟出Stack，top往下移  回傳值int為第二題，要return數值

void listAll(element stack[], int* top);
//堆疊全部印出來

#endif /* _T_STACKLIB_H_ */
