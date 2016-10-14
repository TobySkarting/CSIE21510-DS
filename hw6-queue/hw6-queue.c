#include <stdio.h>
#include "queue.h"

int main()
{
	int choice, input;

	createQueue();

	printf("�п�J�ﶵ(-1����)�G");
	while (!!scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1: // Add node
			scanf("%d", &input);
			enQueue(input);
			printQueue();
			break;
		case 2: // Remove node
			deQueue();
			printQueue();
			break;
		case 3: // Clear
			clearQueue();
			break;
		case -1:
			return 0;
		default:
			break;
		}
	}
    return 0;
}

