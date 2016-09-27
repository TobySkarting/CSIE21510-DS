#include <stdio.h>
#include "matrixStruct.h"

int main()
{
	int columns, elements;
	int i, e;

	sparse A[MAX];
	sparse B[MAX] = { 0 };
	sparse C[MAX] = { 0 };
	s_header *headerB = &B[0];

	createSparseA(A);
	printSparseMatrix(A);
	printf("輸入第二個陣列的Column及非零元素，再來輸入B的矩陣\n");
	scanf("%d%d", &columns, &elements);

	headerB->cols = columns;
	while (1 == scanf("%d", &e))
	{
		headerB->rows++;
		makeSparseMatrix(B, headerB->rows - 1, 0, e);
		for (i = 1; i < columns; i++)
		{
			scanf("%d", &e);
			makeSparseMatrix(B, headerB->rows - 1, i, e);
		}
	}

	printf("\nRow Col Value\n");
	printSparseMatrix(B);
		
	printf("\nA * B 結果為\n");
	multiply(A, B, C);
	printMatrix(C);
	
    return 0;
}
