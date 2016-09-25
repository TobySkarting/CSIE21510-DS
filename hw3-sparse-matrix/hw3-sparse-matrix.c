// hw3-sparse-matrix.cpp : Defines the entry point for the console application.
//

#include "MatrixStruct.h"

int main()
{
	int columns, elements;
	int i;

	sparse A[MAX];
	sparse B[MAX] = { 0 };
	sparse C[MAX] = { 0 };

	createSparseA(A);
	printSparseMatrix(A);
	printf("Enter columns and non-zero elements count of the second matrix, then B.\n");
	while (!!scanf("%d%d", &columns, &elements))
	{
		int r, c, v, e;
		sparse *header = &B[0];
		header->col = columns;
		while (!!scanf("%d", &e))
		{
			header->row++;
			makeSparseMatrix(B, header->row - 1, 0, e);
			for (int i = 1; i < columns; i++)
			{
				scanf("%d", &e);
				makeSparseMatrix(B, header->row - 1, i, e);
			}
		}
		printSparseMatrix(B);
		printf("end\n");

		multiply(A, B, C);
		printSparseMatrix(C);
		printf("end\n");
	}
    return 0;
}

