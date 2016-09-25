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
	sparse *header = &a[0];
	int *rowSize = (int *)malloc(a->col * sizeof(int));
	int *rowStart = (int *)malloc(a->col * sizeof(int));
	memset(rowSize, 0, a->col * sizeof(int));
	for (int i = 0; i < header->value; i++)
		rowSize[a[i + 1].col]++;
	rowStart[0] = 0;
	for (int i = 1; i < header->col; i++)
		rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	for (int i = 0; i < header->value; i++)
	{
		int j = rowStart[a[i + 1].col];
		b[j + 1].row = a[i + 1].col;
		b[j + 1].col = a[i + 1].row;
		b[j + 1].value = a[i + 1].value;
		rowStart[a[i + 1].col]++;
	}
	free(rowSize);
	free(rowStart);
}

int COMPARE(int a, int b)
{
	return 0;
}

void storeSum(sparse d[], int * totald, int row, int column, int * sum)
{
	sparse *header = &d[0];
	if (*sum != 0)
	{
		d[header->value].row = row;
		d[header->value].col = column;
		d[header->value++].value = *sum;
	}
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

void multiply(sparse a[], sparse b[], sparse d[])
{
	if (a[0].col != b[0].row)
	{
		printf("Incompatible matrices.\n");
		return;
	}
	sparse bX[MAX];
	transposeMatrix(b, bX);
	int currRowIndex = 0, currRowBegin = 0, currRowA = a[0].row;

	d[0].row = a[0].row;
	d[0].col = b[0].col;
	d[0].value = 0;

	a[a[0].value + 1].row = a[0].row;
	bX[b[0].value + 1].row = b[0].col;
	bX[b[0].value + 1].col = -1;
	int sum = 0;
	while (currRowIndex < a[0].value)
	{
		int currColB = bX[1].row;
		int currColIndex = 0;
		while (currColIndex <= b[0].value)
		{
			if (a[currRowIndex + 1].row != currRowA)
			{
				storeSum(d, NULL, currRowA, currColB, &sum);
				sum = 0;
				currRowIndex = currRowBegin;
				while (bX[currColIndex + 1].row == currColB)
					currColIndex++;
				currColB = bX[currColIndex + 1].row;
			}
			else if (bX[currColIndex + 1].row != currColB)
			{
				storeSum(d, NULL, currRowA, currColB, &sum);
				sum = 0;
				currRowIndex = currRowBegin;
				currColB = bX[currColIndex + 1].row;
			}
			else if (a[currRowIndex + 1].col < bX[currColIndex + 1].col)
				currRowIndex++;
			else if (a[currRowIndex + 1].col == bX[currColIndex + 1].col)
			{
				sum += a[currRowIndex + 1].value * bX[currColIndex + 1].value;
				currRowIndex++;
				currColIndex++;
			}
			else
				currColIndex++;
		}
		while (a[currRowIndex + 1].row == currRowA)
			currRowIndex++;
		currRowBegin = currRowIndex;
		currRowA = a[currRowIndex + 1].row;
	}
}
