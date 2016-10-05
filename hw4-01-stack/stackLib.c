#include "stackLib.h"
#include <stdio.h>

void createStack(element stack[])
{
	int i;
	for (i = 0; i < MAX; i++)
		stack[i].value = 0;
}

int IsFull(int top)
{
	if (top >= MAX - 1)
		return 1;
	else
		return 0;
}

int IsEmpty(int top)
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int push(element stack[], int * top, int value)
{
	if (IsFull(*top))
	{
		printf("Stack Full\n");
		return -1;
	}
	else
		stack[++*top].value = value;
	return value;
}

int pop(element stack[], int * top)
{
	if (IsEmpty(*top))
	{
		printf("Stack Empty!\n");
		return -1;
	}
	else
		return stack[(*top)--].value;
}

void listAll(element stack[], int * top)
{
	int i;
	for (i = 0; i <= *top; i++)
		printf("%d ", stack[i].value);
	printf("\n");
}
