#ifndef _T_MATRIXSTRUCT_H_
#define _T_MATRIXSTRUCT_H_

#define MAX 100

typedef struct {
	int row;
	int col;
	int value;
} sparse;

typedef struct {
	int rows;
	int cols;
	int terms;
} s_header;

void createSparseA(sparse a[]);     /* define�XA���}���x�}  */

void printSparseMatrix(sparse matrix[]); /*  �L�X�}���x�}  */

void makeSparseMatrix(sparse matrix[], int row, int col, int element);
/*  ��J�}���x�}�� row,column,value   */

//////////    �U�����ĤG�D�n�Ϊ�function   ////////////   
///���T��function���ҥ���ĳ�g�k�A�ǥ̥ͭi�H�̦ۤv���Q�k�P�t��k������                           
void transposeMatrix(sparse a[], sparse b[]); /* �Na�x�}��m�é��b�x�}���c*/

void storeSum(sparse d[], int *totald, int row, int column, int *sum);
/* �b���k����function�A�Nrow i ��column j �������Ȧs�_�� */

void printMatrix(sparse matrix[]);  /* �L�X���q�x�} */

void multiply(sparse a[], sparse b[], sparse d[]); /* �x�}�ۭ�. */


#endif /* _T_MATRIXSTRUCT_H_ */
