#pragma once

typedef struct {
	double** entries;
	int rows;
	int cols;
} Matrix;

Matrix* matrix_create(int row, int col);
void matrix_fill(Matrix *A, int n);
void matrix_free(Matrix *A);
void matrix_print(Matrix *A);
Matrix* matrix_copy(Matrix *A);
void matrix_file_save(Matrix *A, char* filename);
Matrix* matrix_load(char* filename);
void random_matrix(Matrix *A, int n);
int matrix_argmax(Matrix *A);
Matrix* matrix_flatten(Matrix *A, int dim);
