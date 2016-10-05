#include <stdio.h>
#include <string.h>
#include "stackLib.h"

int main()
{
	char expr[100];
	int i, op1, op2;
	int top;
	element stack[MAX];
	createStack(stack);

	while (1 == scanf("%s", expr))
	{
		top = -1;
		i = 0;
		while (expr[i] != '\0')
		{
			if (expr[i] >= '0' && expr[i] <= '9')
				push(stack, &top, expr[i] - '0');
			else
			{
				if (IsEmpty(top))
					break;
				op2 = pop(stack, &top);

				if (IsEmpty(top))
					break;
				op1 = pop(stack, &top);
				switch (expr[i])
				{
				case '+':
					push(stack, &top, op1 + op2);
					break;
				case '-':
					push(stack, &top, op1 - op2);
					break;
				case '*':
					push(stack, &top, op1 * op2);
					break;
				case '/':
					push(stack, &top, op1 / op2);
					break;
				case '%':
					push(stack, &top, op1 % op2);
					break;
				}
			}
			i++;
		}
		if (top != 0)
			printf("Input Error\n");
		else
			printf("%d\n", pop(stack, &top));
	}
    return 0;
}

