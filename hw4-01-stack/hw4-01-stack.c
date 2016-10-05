#include <stdio.h>
#include <string.h>
#include "stackLib.h"


int main()
{
	char opcode[10];
	int operand;
	int top = -1;
	element stack[MAX];
	createStack(stack);

	while (scanf("%s", opcode) != EOF)
	{
		if (!strcmp(opcode, "push"))
		{
			scanf("%d", &operand);
			push(stack, &top, operand);
			listAll(stack, &top);
		}
		else if (!strcmp(opcode, "pop"))
		{
			pop(stack, &top);
			listAll(stack, &top);
		}
		else if (!strcmp(opcode, "end"))
		{
			printf("bye!\n");
			break;
		}
	}
    return 0;
}

