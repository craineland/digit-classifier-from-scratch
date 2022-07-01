#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define MAXCHAR 50

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
			A->entries[i][j] = n;
		}
	}
}

/*
 * frees the memory of all entries in a selected matrix
 * as well as the matrix struct itself
 * param: 
 * 	Matrix* A - pointer to a matrix in memory
 */
void matrix_free(Matrix* A) {
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
void matrix_print(Matrix* A) {
	printf("Rows: %d, Columns: %d\n", A->rows, A->cols);
	for (int i = 0; i < A->rows; ++i) {
		for (int j = 0; j < A->rows; ++j) {
			printf("1.4f ", A->entries[i][j]);
		 }
		printf("\n");
	}
}

/*
 * creates a new matrix in memory and copies the values
 * from another matrix into the new matrix
 * param:
 * 		Matrix *A - matrix containing values to be copied
 * return:
 * 		copy of input matrix
 */
Matrix* matrix_copy(Matrix *A) {
	Matrix *copy_A = matrix_create(A->rows, A->cols);
	
	for (int i = 0; i < A->rows; ++i) {
		for (int j = 0; j < A->cols; ++i) {
			copy_A->entries[i][j] = A->entries[i][j];
		}
	}
	return copy_A;
}

/*
 * saves a selected matrix to an output file
 * param:
 * 		Matrix *A - matrix in memory
 * 		char *filename - string array of filename
 */
void matrix_file_save(Matrix *A, char* filename) {
	FILE* file = fopen(filename, "w");
	fprintf(file, "%d\n", A->rows);
	fprintf(file, "%d\n", A->cols);

	for (int i = 0; i < A->rows; ++i) {
		for (int j = 0; j < A->cols; ++i) {
			fprintf(file, "%.6f\n", A->entries[i][j]);
		}
	}

	printf("Successfully saved matrix to %s\n", filename);
	fclose(file);
}