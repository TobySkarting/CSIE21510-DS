#include "MatrixStruct.h"
#include <string.h>

void createSparseA(sparse a[])
{
	sparse *header = &a[0];
	header->col = 3;
	header->row = 3;
	header->value = 0;
	makeSparseMatrix(a, 0, 0, 1);
	makeSparseMatrix(a, 1, 0, 1);
	makeSparseMatrix(a, 2, 0, 1);
}

void printSparseMatrix(sparse matrix[])
{
	sparse *header = &matrix[0];
	for (int i = 0; i < header->value + 1; i++)
		printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
}

void makeSparseMatrix(sparse matrix[], int row, int col, int element)
{
	if (element == 0)
		return;
	sparse *e = &matrix[++matrix[0].value];
	e->row = row;
	e->col = col;
	e->value = element;
}

void transposeMatrix(sparse a[], sparse b[])
{
}

int COMPARE(int a, int b)
{
	return 0;
}

void printMatrix(sparse matrix[])
{
	sparse *header = &matrix[0];
	int *tmpMatrix = (int *)malloc(header->col * header->row * sizeof(int));
	memset(tmpMatrix, 0, header->col * header->row * sizeof(int));

	for (int i = 1; i <= header->value; i++)
		tmpMatrix[matrix[i].row * header->col + matrix[i].col] = matrix[i].value;

	for (int i = 0; i < header->row; i++)
	{
		for (int j = 0; j < header->col; j++)
			printf("%d ", tmpMatrix[i * header->col + j]);
		printf("\n");
	}

	free(tmpMatrix);
}

void mutiply(sparse a[], sparse b[], sparse d[])
{
}
