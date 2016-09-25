#pragma once
#ifndef MATRIXSTRUCT_H_
#define MATRIXSTRUCT_H_

#include <stdio.h>
#include <stdlib.h>

//#define row COLUMN
//#define col ROW
#define MAX 100

typedef struct {
	int row;
	int col;
	int value;
} sparse;

void createSparseA(sparse a[]);     /* define�XA���}���x�}  */

void printSparseMatrix(sparse matrix[]); /*  �L�X�}���x�}  */

void makeSparseMatrix(sparse matrix[], int row, int col, int element);
/*  ��J�}���x�}�� row,column,value   */

//////////    �U�����ĤG�D�n�Ϊ�function   ////////////   
///���T��function���ҥ���ĳ�g�k�A�ǥ̥ͭi�H�̦ۤv���Q�k�P�t��k������                           
void transposeMatrix(sparse a[], sparse b[]); /* �Na�x�}��m�é��b�x�}���c*/

int COMPARE(int a, int b); /*  ����e�ᶵ�j�p. */

void storesum(sparse d[], int *totald, int row, int column, int *sum);
/* �b���k����function�A�Nrow i ��column j �������Ȧs�_�� */

void printMatrix(sparse matrix[]);  /* �L�X���q�x�} */

void mutiply(sparse a[], sparse b[], sparse d[]); /* �x�}�ۭ�. */


#endif /* MATRIXSTRUCT_H_ */
