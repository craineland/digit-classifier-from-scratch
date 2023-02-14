#pragma once

#include "matrix.h"

Matrix* transpose(Matrix* m);
Matrix* dot_product(Matrix* m1, Matrix* m2);
Matrix* multiply(Matrix* m1, Matrix* m2);
Matrix* add(Matrix* m1, Matrix* m2);
Matrix* subtract(Matrix* m1, Matrix* m2);
Matrix* apply(double (*func)(double), Matrix* m);
Matrix* scale(double n, Matrix* m);
Matrix* add_scalar(double n, Matrix* m);