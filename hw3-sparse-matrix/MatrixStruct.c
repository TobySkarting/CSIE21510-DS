#include "MatrixStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createSparseA(sparse a[])
{
	s_header *header = (s_header *)&a[0];
	header->cols = 3;
	header->rows = 3;
	header->terms = 0;
	makeSparseMatrix(a, 0, 0, 1);
	makeSparseMatrix(a, 1, 0, 1);
	makeSparseMatrix(a, 2, 0, 1);
}

void printSparseMatrix(sparse matrix[])
{
	int i;
	const s_header *header = (s_header *)&matrix[0];
	for (i = 0; i < header->terms + 1; i++)
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
	int rowSize[MAX];
	int rowStart[MAX];
	int i, j;
	const s_header *headerA = (s_header *)&a[0];
	s_header *headerB = (s_header *)&b[0];

	headerB->rows = headerA->cols;
	headerB->cols = headerA->rows;
	headerB->terms = headerA->terms;

	if (headerA->terms > 0)
	{
		for (i = 0; i < headerA->cols; i++)
			rowSize[i] = 0;
		for (i = 1; i < headerA->terms; i++)
			rowSize[a[i].col]++;
		rowStart[0] = 1;
		for (i = 1; i < headerA->cols; i++)
			rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
		for (i = 1; i <= headerA->terms; i++)
		{
			j = rowStart[a[i].col];
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
			rowStart[a[i].col]++;
		}
	}
}

void storeSum(sparse d[], int * totald, int row, int column, int * sum)
{
	if (*sum != 0)
	{
		d[++*totald].row = row;
		d[*totald].col = column;
		d[*totald].value = *sum;
		*sum = 0;
	}
}

void printMatrix(sparse matrix[])
{
	const s_header *header = (s_header *)&matrix[0];
	int i, j;
	int *tmpMatrix = (int *)malloc(header->cols * header->rows * sizeof(int));
	memset(tmpMatrix, 0, header->cols * header->rows * sizeof(int));

	for (i = 1; i <= header->terms; i++)
		tmpMatrix[matrix[i].row * header->cols + matrix[i].col] = matrix[i].value;

	for (i = 0; i < header->rows; i++)
	{
		for (j = 0; j < header->cols; j++)
			printf("%d ", tmpMatrix[i * header->cols + j]);
		printf("\n");
	}

	free(tmpMatrix);
}

void multiply(sparse a[], sparse b[], sparse d[])
{
	int currRowIndex, currRowBegin = 1, currRowA = a[1].row;
	int currColB, currColIndex;
	int sum = 0;
	sparse bX[MAX];
	const s_header *headerA = (s_header *)&a[0];
	const s_header *headerB = (s_header *)&b[0];
	s_header *headerD = (s_header *)&d[0];
	if (a[0].col != b[0].row)
	{
		printf("Incompatible matrices.\n");
		return;
	}
	transposeMatrix(b, bX);

	headerD->rows = headerA->rows;
	headerD->cols = headerB->cols;
	headerD->terms = 0;

	a[headerA->terms + 1].row = headerA->rows;
	bX[headerB->terms + 1].row = headerB->cols;
	bX[headerB->terms + 1].col = -1;
	
	currRowIndex = 1;
	while (currRowIndex <= headerA->terms)
	{
		currColB = bX[1].row;
		currColIndex = 1;
		while (currColIndex <= headerB->terms + 1)
		{
			if (a[currRowIndex].row != currRowA)
			{
				storeSum(d, &headerD->terms, currRowA, currColB, &sum);
				currRowIndex = currRowBegin;
				while (bX[currColIndex].row == currColB)
					currColIndex++;
				currColB = bX[currColIndex].row;
			}
			else if (bX[currColIndex].row != currColB)
			{
				storeSum(d, &headerD->terms, currRowA, currColB, &sum);
				currRowIndex = currRowBegin;
				currColB = bX[currColIndex].row;
			}
			else if (a[currRowIndex].col < bX[currColIndex].col)
				currRowIndex++;
			else if (a[currRowIndex].col == bX[currColIndex].col)
			{
				sum += a[currRowIndex++].value * bX[currColIndex++].value;
			}
			else
				currColIndex++;
		}
		while (a[currRowIndex].row == currRowA)
			currRowIndex++;
		currRowBegin = currRowIndex;
		currRowA = a[currRowIndex].row;
	}
}
