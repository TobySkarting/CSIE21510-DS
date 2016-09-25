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

void createSparseA(sparse a[]);     /* define出A的稀疏矩陣  */

void printSparseMatrix(sparse matrix[]); /*  印出稀疏矩陣  */

void makeSparseMatrix(sparse matrix[], int row, int col, int element);
/*  輸入稀疏矩陣內 row,column,value   */

//////////    下面為第二題要用的function   ////////////   
///此三個function為課本建議寫法，學生們可以依自己的想法與演算法做取捨                           
void transposeMatrix(sparse a[], sparse b[]); /* 將a矩陣轉置並放到b矩陣結構*/

int COMPARE(int a, int b); /*  比較前後項大小. */

void storesum(sparse d[], int *totald, int row, int column, int *sum);
/* 在乘法內的function，將row i 及column j 乘完的值存起來 */

void printMatrix(sparse matrix[]);  /* 印出普通矩陣 */

void mutiply(sparse a[], sparse b[], sparse d[]); /* 矩陣相乘. */


#endif /* MATRIXSTRUCT_H_ */
