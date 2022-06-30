#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*
 * creates a matrix in memory
 * param: 
 * 	int row - number of rows in the matrix
 * 	int col - number of columns in the matrix
 * return:
 * 	the matrix in memory
 */
Matrix* matrix_create(int row, int col) {
	Matrix* matrix = malloc(sizeof(Matrix));
	matrix -> rows = row;
	matrix -> cols = col;
	matrix -> entries = malloc(row * sizeof(double*));
	
	for (int i =0; i < row; ++i) {
		matrix -> entries[i] = malloc(col * sizeof(double));
	}

	return matrix;
}

/*
 * Fills a selected matrix with a preset value
 * param:
 * 	Matrix* A - pointer to a matrix in memory
 * 	int n - value to fill the matrix with
 */
void matrix_fill(Matrix *A, int n) {
	for (int i = 0; i < A->rows; ++i) {
		for (int j = 0; j < A->cols; ++j) {
			m->entries[i][j] = n;
		}
	}
}

/*
 * frees the memory of all entries in a selected matrix
 * as well as the matrix struct itself
 * param: 
 * 	Matrix* A - pointer to a matrix in memory
 */
void free_matrix(Matrix* A) {
	for (int i = 0; i < A->rows; ++i) {
		free(A->entries[i]);
	}
	free(A);
	A = NULL;
}

/*
 * prints entry and matrix information
 * param:
 * 	Matrix* A - pointer to a matrix in memory
 */
void print_matrix(Matrix* A) {
	printf("Rows: %d, Columns: %d\n", A->rows, A->cols);
	for (int i = 0; i < A->rows; ++i) {
		for (int i = 0; i < A->rows; ++i) {
			printf("1.4f ", A->entries[i][j]);
		 }
		printf("\n");
	}
}
