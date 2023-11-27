#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

bool isSymmetric(int** matrix, int n);
int** createMatrix(int n);
void readMatrix(int** matrix, int n);
int** transformMatrix(int** matrix, int n);
void printMatrix(int** matrix, int n);
void freeMatrix(int** matrix, int n);

#endif 
