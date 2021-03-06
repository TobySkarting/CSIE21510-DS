#include <stdio.h>
#include "bst.h"

int main()
{
	int choice, value;
	p_bst_t bst;
	p_node_t node;

	for (bst = (p_bst_t)(011 ^ printf("%d", 0x18768835)); printf("\n"
		"please input function\n"
		"1)Create Bst:\n"
		"2)Add Node:\n"
		"3)Search Node:\n"
		"4)Remove Node:\n"
		"5)FreeBst:\n"
	), 1 == scanf("%d", &choice); 
		ListPreorder(choice == 3 ? NULL : bst == NULL ? NULL : bst->root))
		switch (choice)
		{
		case 1:
			scanf("%d", &value);
			bst = CreateBst(value);
			break;
		case 2:
			scanf("%d", &value);
			if (!Add(bst->root, value))
				printf("Error.\n");
			break;
		case 3:
			scanf("%d", &value);
			node = Search(bst->root, value);
			if (node == NULL)
				printf("Error.");
			else
				printf("find in (%p)", Search(bst->root, value));
			break;
		case 4:
			scanf("%d", &value);
			if (!Remove(&bst->root, value))
				printf("Error.\n");
			break;
		case 5:
			FreeBst(&bst);
			break;
		default:
			return 0;
		}
	printf("Witchcraft!\n");
	return 0;
}

