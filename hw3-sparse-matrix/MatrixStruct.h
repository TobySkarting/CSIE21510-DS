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

void createSparseA(sparse a[]);     /* define出A的稀疏矩陣  */

void printSparseMatrix(sparse matrix[]); /*  印出稀疏矩陣  */

void makeSparseMatrix(sparse matrix[], int row, int col, int element);
/*  輸入稀疏矩陣內 row,column,value   */

//////////    下面為第二題要用的function   ////////////   
///此三個function為課本建議寫法，學生們可以依自己的想法與演算法做取捨                           
void transposeMatrix(sparse a[], sparse b[]); /* 將a矩陣轉置並放到b矩陣結構*/

void storeSum(sparse d[], int *totald, int row, int column, int *sum);
/* 在乘法內的function，將row i 及column j 乘完的值存起來 */

void printMatrix(sparse matrix[]);  /* 印出普通矩陣 */

void multiply(sparse a[], sparse b[], sparse d[]); /* 矩陣相乘. */


#endif /* _T_MATRIXSTRUCT_H_ */
